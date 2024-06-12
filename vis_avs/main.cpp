//#define PLUGIN_NAME "Advanced Visualization Studio"
#define PLUGIN_VERSION "v2.83"

#include <windows.h>
#include <math.h>
#include <process.h>
#include "draw.h"
#include "wnd.h"
#include "r_defs.h"
#include "render.h"
#include "../winamp/vis.h"
#include "cfgwnd.h"
#include "resource.h"
#include "bpm.h"

#ifdef WA3_COMPONENT
#include "wasabicfg.h"
#include "../studio/studio/api.h"
#else
#include "../winamp/wa_ipc.h"
#include "../Agave/Language/api_language.h"
#include <api/service/waServiceFactory.h>
#endif

#include "avs_eelif.h"

extern void GetClientRect_adj(HWND hwnd, RECT *r);

static unsigned char g_logtab[256];
HINSTANCE g_hInstance;

static unsigned int WINAPI RenderThread(LPVOID a);

static void config(struct winampVisModule *this_mod);
static int init(struct winampVisModule *this_mod);
static int render(struct winampVisModule *this_mod);
static void quit(struct winampVisModule *this_mod);

HANDLE g_hThread;
volatile int g_ThreadQuit;

#ifndef WA3_COMPONENT
static CRITICAL_SECTION g_cs;
#endif

static unsigned char g_visdata[2][2][576];
static int g_visdata_pstat;

#ifndef WA3_COMPONENT

/* wasabi based services for localisation support */
api_service *WASABI_API_SVC = 0;
api_language *WASABI_API_LNG = 0;
HINSTANCE WASABI_API_LNG_HINST = 0, WASABI_API_ORIG_HINST = 0;
static char module1[128];

static winampVisModule *getModule(int which);
static winampVisHeader hdr = { VIS_HDRVER, 0, getModule };

// use this to get our own HINSTACE since overriding DllMain(..) causes instant crashes (should see why)
static HINSTANCE GetMyInstance()
{
	MEMORY_BASIC_INFORMATION mbi = {0};
	if(VirtualQuery(GetMyInstance, &mbi, sizeof(mbi)))
		return (HINSTANCE)mbi.AllocationBase;
	return NULL;
}

extern "C" {
	__declspec( dllexport ) winampVisHeader* winampVisGetHeader(HWND hwndParent)
	{
		if(!WASABI_API_LNG_HINST)
		{
			// loader so that we can get the localisation service api for use
			WASABI_API_SVC = (api_service*)SendMessage(hwndParent, WM_WA_IPC, 0, IPC_GET_API_SERVICE);
			if (WASABI_API_SVC == (api_service*)1) WASABI_API_SVC = NULL;

			waServiceFactory *sf = WASABI_API_SVC->service_getServiceByGuid(languageApiGUID);
			if (sf) WASABI_API_LNG = reinterpret_cast<api_language*>(sf->getInterface());

			// need to have this initialised before we try to do anything with localisation features
			WASABI_API_START_LANG(GetMyInstance(),VisAVSLangGUID);
		}

		#ifndef LASER
		static char szDescription[256];
		wsprintfA(szDescription,"%s "PLUGIN_VERSION,WASABI_API_LNGSTRING_BUF(IDS_AVS,module1,128));
		hdr.description = szDescription;
		#else
		hdr.description = "AVS/Laser "PLUGIN_VERSION;
		#endif

		return &hdr;
	}
}

static winampVisModule *getModule(int which)
{
	static winampVisModule mod =
	{
#ifdef LASER
		"Advanced Visualization Studio/Laser",
#else
		module1,
#endif
		NULL,	// hwndParent
		NULL,	// hDllInstance
		0,		// sRate
		0,		// nCh
		1000/70,// latencyMS
		1000/70,// delayMS
		2,		// spectrumNch
		2,		// waveformNch
		{ 0, },	// spectrumData
		{ 0, },	// waveformData
		config,
		init,
		render, 
		quit
	};
	if (which==0) return &mod;
	return 0;
}
#endif

void about(HWND hwndParent)
{
	static int about_here = 0;
	char aboutbuf[1024] = {0}, aboutTitle[48] = {0};
	if (about_here)
	{
		SetActiveWindow(FindWindow("#32770",WASABI_API_LNGSTRING_BUF(IDS_ABOUT_AVS,aboutTitle,48)));
		return;
	}
	about_here = 1;
	wsprintf(aboutbuf,WASABI_API_LNGSTRING(IDS_ABOUT_STRING),hdr.description);
	MessageBox(hwndParent,aboutbuf,WASABI_API_LNGSTRING_BUF(IDS_ABOUT_AVS,aboutTitle,48),0);
	about_here = 0;
}

HWND GetDialogBoxParent(HWND winamp)
{
	HWND parent = (HWND)SendMessage(winamp, WM_WA_IPC, 0, IPC_GETDIALOGBOXPARENT);
	if (!parent || parent == (HWND)1)
		return winamp;
	return parent;
}

static void config(struct winampVisModule *this_mod)
{
	if (!g_hwnd || !IsWindow(g_hwnd))
	{
		about(GetDialogBoxParent(this_mod->hwndParent));
	}
	else
	{
		SendMessage(g_hwnd,WM_USER+33,0,0);
	}
}

CRITICAL_SECTION g_render_cs;
static int g_is_beat;
char g_path[1024];

int beat_peak1,beat_peak2, beat_cnt,beat_peak1_peak;

void main_setRenderThreadPriority()
{
	int prios[]={
		GetThreadPriority(GetCurrentThread()),
		THREAD_PRIORITY_IDLE,
		THREAD_PRIORITY_LOWEST,
		THREAD_PRIORITY_NORMAL,
	    THREAD_PRIORITY_HIGHEST,
	};
	SetThreadPriority(g_hThread,prios[cfg_render_prio]);
}

extern void previous_preset(HWND hwnd);
extern void next_preset(HWND hwnd);
extern void random_preset(HWND hwnd);

#if 0//syntax highlighting
HINSTANCE hRich;
#endif

static int init(struct winampVisModule *this_mod)
{
	DWORD id;
	FILETIME ft;
#if 0//syntax highlighting
	if (!hRich) hRich=LoadLibrary("RICHED32.dll");
#endif
	GetSystemTimeAsFileTime(&ft);
	srand(ft.dwLowDateTime|ft.dwHighDateTime^GetCurrentThreadId());
	g_hInstance=this_mod->hDllInstance;
#ifdef WA3_COMPONENT
	GetModuleFileName(GetModuleHandle(NULL),g_path,MAX_PATH);
#else
	GetModuleFileName(g_hInstance,g_path,MAX_PATH);
#endif
	char *p=g_path+strlen(g_path);
	while (p > g_path && *p != '\\') p--;
	*p = 0;

#ifdef WA2_EMBED
	if (SendMessage(this_mod->hwndParent,WM_USER,0,0) < 0x2900)
	{
		char title[16];
	    MessageBox(this_mod->hwndParent,WASABI_API_LNGSTRING(IDS_REQUIRES_2_9_PLUS),
				   WASABI_API_LNGSTRING_BUF(IDS_AVS_ERROR,title,16),MB_OK|MB_ICONSTOP);
		return 1;
	}
#endif

#ifndef NO_MMX
	extern int is_mmx(void);
	if (!is_mmx())
	{
		char title[16];
		MessageBox(this_mod->hwndParent,WASABI_API_LNGSTRING(IDS_NO_MMX_SUPPORT),
				   WASABI_API_LNGSTRING_BUF(IDS_AVS_ERROR,title,16),MB_OK|MB_ICONSTOP);
		return 1;
	}
#endif

#ifdef WA3_COMPONENT
	strcat(g_path,"\\wacs\\data");
#endif

#ifdef LASER
	strcat(g_path,"\\avs_laser");
#else
	strcat(g_path,"\\avs");
#endif
	CreateDirectory(g_path,NULL);

#ifndef WA3_COMPONENT
	InitializeCriticalSection(&g_cs);
#endif
	InitializeCriticalSection(&g_render_cs);
	g_ThreadQuit=0;
	g_visdata_pstat=1;

	AVS_EEL_IF_init();

	if (Wnd_Init(this_mod)) return 1;

	for (int x = 0; x < 256; x ++)
	{
		double a=log(x*60.0/255.0 + 1.0)/log(60.0);
		int t=(int)(a*255.0);
		if (t<0)t=0;
		if (t>255)t=255;
		g_logtab[x]=(unsigned char )t;
	}

	initBpm();

	Render_Init(g_hInstance);

	CfgWnd_Create(this_mod);

	g_hThread=(HANDLE)_beginthreadex(NULL,0,RenderThread,0,0,(unsigned int *)&id);
	main_setRenderThreadPriority();
	SetForegroundWindow(g_hwnd);
	SetFocus(g_hwnd);

	return 0;
}

static int render(struct winampVisModule *this_mod)
{
#ifndef WA3_COMPONENT
	int x,avs_beat=0,b;
	if (g_ThreadQuit) return 1;
	EnterCriticalSection(&g_cs);
	if (g_ThreadQuit)
	{
		LeaveCriticalSection(&g_cs);
		return 1;
	}
	if (g_visdata_pstat)
		for (x = 0; x<  576*2; x ++)
			g_visdata[0][0][x]=g_logtab[(unsigned char)this_mod->spectrumData[0][x]];
	else 
	{
		for (x = 0; x < 576*2; x ++)
		{ 
			int t=g_logtab[(unsigned char)this_mod->spectrumData[0][x]];
			if (g_visdata[0][0][x] < t)
				g_visdata[0][0][x] = t;
		}
	}
	memcpy(&g_visdata[1][0][0],this_mod->waveformData,576*2);
	{
    int lt[2]={0,0};
    int x;
    for (int ch = 0; ch < 2; ch ++)
    {
		unsigned char *f=(unsigned char*)&this_mod->waveformData[ch][0];
		for (x = 0; x < 576; x ++)
		{
			int r= *f++^128;
			r-=128;
			if (r<0)r=-r;
			lt[ch]+=r;
		}
    }
    lt[0]=max(lt[0],lt[1]);

    beat_peak1=(beat_peak1*125+beat_peak2*3)/128;

    beat_cnt++;

    if (lt[0] >= (beat_peak1*34)/32 && lt[0] > (576*16)) 
    {
		if (beat_cnt>0)
		{
			beat_cnt=0;
			avs_beat=1;
		}
		beat_peak1=(lt[0]+beat_peak1_peak)/2;
		beat_peak1_peak=lt[0];
    }
    else if (lt[0] > beat_peak2)
    {
		beat_peak2=lt[0];
    } 
    else beat_peak2=(beat_peak2*14)/16;

	}
	b=refineBeat(avs_beat);
	if (b) g_is_beat=1;
	g_visdata_pstat=0;
	LeaveCriticalSection(&g_cs);
#endif
	return 0;
}

static void quit(struct winampVisModule *this_mod)
{
	if (g_hThread)
	{
		g_ThreadQuit=1;
		if (WaitForSingleObject(g_hThread,10000) != WAIT_OBJECT_0)
		{
			TerminateThread(g_hThread,0);
		}
		DDraw_Quit();

		CfgWnd_Destroy();
		Render_Quit(this_mod->hDllInstance);

		Wnd_Quit();

		CloseHandle(g_hThread);
		g_hThread=NULL;

		AVS_EEL_IF_quit();

#ifndef WA3_COMPONENT
		DeleteCriticalSection(&g_cs);
#endif
		DeleteCriticalSection(&g_render_cs);    

		C_RenderListClass::smp_cleanupthreads();
	}
#if 0//syntax highlighting
	if (hRich) FreeLibrary(hRich);
	hRich=0;
#endif
}

#ifdef WA3_COMPONENT
static winampVisModule dummyMod;

void init3(void)
{
	extern HWND g_wndparent;
	dummyMod.hwndParent=g_wndparent;
	dummyMod.hDllInstance=g_hInstance;
	init(&dummyMod);
}

void quit3(void)
{
	extern HWND last_parent;
	if (last_parent) 
	{
		ShowWindow(GetParent(last_parent),SW_SHOWNA);
	}
	quit(&dummyMod);
}
#endif

#define FPS_NF 64

static unsigned int WINAPI RenderThread(LPVOID a)
{
	int framedata[FPS_NF]={0,};
	int framedata_pos=0;
	int s=0;
	char vis_data[2][2][576];
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	srand(ft.dwLowDateTime|ft.dwHighDateTime^GetCurrentThreadId());
	while (!g_ThreadQuit)
	{
		int w,h,*fb=NULL, *fb2=NULL,beat=0;
#ifdef WA3_COMPONENT
		char visdata[576*2*2];
		int ret=api->core_getVisData(0,visdata,sizeof(visdata));

		if (!ret) 
		{
			memset(&vis_data[0][0][0],0,576*2*2);
			beat=0;
		}
		else
		{
			int x;
			unsigned char *v=(unsigned char *)visdata;
			for (x = 0; x < 576*2; x ++)
				vis_data[0][0][x]=g_logtab[*v++];
			for (x = 0; x < 576*2; x ++)
				((unsigned char *)vis_data[1][0])[x]=*v++;

			v=(unsigned char *)visdata+1152;
			{
				int lt[2]={0,0};
				int ch;
				for (ch = 0; ch < 2; ch ++)
				{
					for (x = 0; x < 576; x ++)
					{
						int r=*v++^128;
						r-=128;
						if (r<0)r=-r;
							lt[ch]+=r;
					}
				}
				lt[0]=max(lt[0],lt[1]);

				beat_peak1=(beat_peak1*125+beat_peak2*3)/128;
				beat_cnt++;

				if (lt[0] >= (beat_peak1*34)/32 && lt[0] > (576*16)) 
				{
					if (beat_cnt>0)
					{
						beat_cnt=0;
						beat=1;
					}
					beat_peak1=(lt[0]+beat_peak1_peak)/2;
					beat_peak1_peak=lt[0];
				}
				else if (lt[0] > beat_peak2)
				{
					beat_peak2=lt[0];
				} 
				else beat_peak2=(beat_peak2*14)/16;
			}
		    beat=refineBeat(beat);
		}
#else
		EnterCriticalSection(&g_cs);
		memcpy(&vis_data[0][0][0],&g_visdata[0][0][0],576*2*2);
		g_visdata_pstat=1;
		beat=g_is_beat;
		g_is_beat=0;
		LeaveCriticalSection(&g_cs);
#endif

		if (!g_ThreadQuit)
		{
			if (IsWindow(g_hwnd)&&!g_in_destroy) DDraw_Enter(&w,&h,&fb,&fb2);
			else break;
			if (fb&&fb2)
			{
				extern int g_dlg_w, g_dlg_h, g_dlg_fps;
#ifdef LASER
				g_laser_linelist->ClearLineList();
#endif
				EnterCriticalSection(&g_render_cs);
				int t=g_render_transition->render(vis_data,beat,s?fb2:fb,s?fb:fb2,w,h);
				LeaveCriticalSection(&g_render_cs);
				if (t&1) s^=1;
#ifdef LASER
				s=0;
				memset(fb,0,w*h*sizeof(int));
				LineDrawList(g_laser_linelist,fb,w,h);
#endif
				if (IsWindow(g_hwnd)) DDraw_Exit(s);

				int lastt=framedata[framedata_pos];
				int thist=GetTickCount();
				framedata[framedata_pos]=thist;
				g_dlg_w=w;
				g_dlg_h=h;
				if (lastt)
				{
					g_dlg_fps=MulDiv(sizeof(framedata)/sizeof(framedata[0]),10000,thist-lastt);
				}
				framedata_pos++;
				if (framedata_pos >= sizeof(framedata)/sizeof(framedata[0])) framedata_pos=0;
			}
			int fs=DDraw_IsFullScreen();
			int sv=(fs?(cfg_speed>>8):cfg_speed)&0xff;
			Sleep(min(max(sv,1),100));
		}
	}
	_endthreadex(0);
	return 0;
}