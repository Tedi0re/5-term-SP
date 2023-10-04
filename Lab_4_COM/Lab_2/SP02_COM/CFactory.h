#pragma once
#include "pch.h"

class CFactory : public IClassFactory
{
public:
	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppv);
	virtual ULONG __stdcall AddRef(void);
	virtual ULONG __stdcall Release(void);


	virtual HRESULT __stdcall CreateInstance(IUnknown* pUO, const IID& id, void** ppv);
	virtual HRESULT __stdcall LockServer(BOOL b);

	CFactory();
	~CFactory();

private:
	ULONG m_lRef;
};

