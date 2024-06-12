#ifndef NULLSOFT_DROPBOX_PLUGIN_CF_HDROP_PROCESSOR_HEADER
#define NULLSOFT_DROPBOX_PLUGIN_CF_HDROP_PROCESSOR_HEADER

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "./cfpInterface.h"

class CfHDropProcessor : public IClipboardFormatProcessor
{
public:
	CfHDropProcessor(IDataObject *pDataObject, HWND hwndDropBox);
	 ~CfHDropProcessor();

public:
	static HRESULT CanProcess(IDataObject *pDataObject, HWND hwndDropBox);

public:
	/*** IUnknown ***/
	STDMETHOD(QueryInterface)(REFIID riid, PVOID *ppvObject);
	STDMETHOD_(ULONG, AddRef)(void);
	STDMETHOD_(ULONG, Release)(void);

	/*** IClipboardFormatProcessor ***/
	STDMETHOD(Process)(INT iInsert);
	
protected:
	ULONG ref;
	HWND hDropBox;
	IDataObject *pObject;
};

#endif //NULLSOFT_DROPBOX_PLUGIN_CF_HDROP_PROCESSOR_HEADER