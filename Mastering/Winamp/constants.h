#pragma once

//**************************************************************
// DG_WINNT is not defined for Windows 95 builds and is
// used to control calls to NT-and-later specific functions
#ifndef DG_WINNT
#if defined(UNICODE) || defined(_UNICODE)
#define DG_WINNT 1
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#else
#undef _WIN32_DCOM
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0300
#endif
#endif

//**************************************************************
// Attention customizers!!!!
// DG_CUSTOMIZE
//
// Change theses setting for your organization
//
// Also change source/c/log/n_alt/eventlog.reg
//
#ifndef DG_PLAIN_COMPANY_NAME
#define DG_PLAIN_COMPANY_NAME "Nullsoft, Inc."
#endif

// This string appears in resource files
#ifndef DG_COMPANY_NAME
#define DG_COMPANY_NAME /*CFGMGMT_COMPANY_NAME*/ "Nullsoft, Inc."
#endif

// This string appears in resource files
#ifndef DG_VERSION
#define   DG_VERSION /*CFGMGMT_VERSION*/   "5.7.0 Beta"
#endif

// This string appears in resource files
#ifndef DG_COPYRIGHT_YEAR
#define DG_COPYRIGHT_YEAR /*CFGMGMT_COPYRIGHT_YEAR*/ "1997-2013"
#endif

// Root registry key
#ifndef DG_REGISTRY_KEY
#define DG_REGISTRY_KEY _T("SOFTWARE\\") _T(DG_PLAIN_COMPANY_NAME)
#endif

//
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************

















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































