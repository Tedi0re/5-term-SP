#include "pch.h"
	
extern ULONG g_ServerLocks;

CFactory::CFactory() :m_lRef(1)
{
	SEQ; LOG("CFactory::CFactory", "");
};

CFactory::~CFactory()
{
	SEQ; LOG("CFactory::~CFactory", "");
};

HRESULT __stdcall CFactory::QueryInterface(REFIID riid, void** ppv)
{
	SEQ;
	HRESULT rc = S_OK;
	*ppv = NULL;
	if (riid == IID_IUnknown)
		*ppv = (IUnknown*)this;
	else if (riid == IID_IClassFactory)
		*ppv = (IClassFactory*)this;
	else
		rc = E_NOINTERFACE;

	if (rc == S_OK)
		this->AddRef();
	LOG("Cfactory::QueryInterface rc = ", rc);
	return rc;
};

ULONG __stdcall CFactory::AddRef(void)
{
	SEQ;
	InterlockedIncrement((LONG*)&(this->m_lRef));
	LOG("CFactory::AddRef m_Ref = ", this->m_lRef);
	return this->m_lRef;
};

ULONG __stdcall CFactory::Release(void)
{
	SEQ;

	ULONG rc = this->m_lRef;
	if ((rc = InterlockedDecrement((LONG*)&(this->m_lRef))) == 0)
		delete this;
	LOG("CFactory::Release rc = ", rc);
	return rc;
};

HRESULT __stdcall CFactory::CreateInstance(IUnknown* pUO, const IID& id, void** ppv)
{
	SEQ;
	HRESULT rc = E_UNEXPECTED;

	SP02* pSP02;

	if (pUO != NULL)
		rc = CLASS_E_NOAGGREGATION;
	else if ((pSP02 = new SP02()) == NULL)
		rc = E_OUTOFMEMORY;
	else {
		rc = pSP02->QueryInterface(id, ppv);
		pSP02->Release();
	}

	LOG("CFactory::CreateInstance rc = ", rc);
	return rc;
};

HRESULT __stdcall CFactory::LockServer(BOOL b)
{
	SEQ;
	HRESULT rc = S_OK;

	if (b)
		InterlockedIncrement((LONG*)&(g_ServerLocks));
	else
		InterlockedDecrement((LONG*)&(g_ServerLocks));

	LOG("CFactory::LockServer b = ", b);
	return rc;
};

