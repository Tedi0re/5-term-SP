#include "pch.h"

extern ULONG g_Components;

SP02::SP02() : m_Ref(1)
{
	SEQ;
	InterlockedIncrement((LONG*)&g_Components);//??
	LOG("SP2::Adder g_Components = ", g_Components);
}

SP02::~SP02()
{
	SEQ;
	InterlockedDecrement((LONG*)&g_Components);
	LOG("SP2::~Adder g_Components = ", g_Components);
}

HRESULT __stdcall SP02::QueryInterface(REFIID riid, void** ppv)
{
	SEQ;
	HRESULT rc = S_OK;
	*ppv = NULL;
	if (riid == IID_IUnknown) *ppv = (IAdder*)this;//??
	else if (riid == IID_IAdder) *ppv = (IAdder*)this;
	else if (riid == IID_IMultiplier) *ppv = (IMultiplier*)this;
	else rc = E_NOINTERFACE;
	if (rc == S_OK) this->AddRef();
	LOG("SP2::QueryInterface rc = ", rc);
	return rc;
}

ULONG __stdcall SP02::AddRef(void)
{
	SEQ;
	InterlockedIncrement((LONG*)&(this->m_Ref));
	LOG("SP2::AddRef m_Ref = ", this->m_Ref);
	return this->m_Ref;
}

ULONG __stdcall SP02::Release(void)
{
	SEQ;
	ULONG rc = this->m_Ref;
	if ((rc = InterlockedDecrement((LONG*)&(this->m_Ref))) == 0) delete this;
	LOG("SP2::Release rc = ", rc);
	return rc;
}

HRESULT __stdcall SP02::Add(const double x, const double y, double& z)
{
	SEQ;
	z = x + y;
	return S_OK;
}

HRESULT __stdcall SP02::Sub(const double x, const double y, double& z)
{
	z = x - y;
	return S_OK;
}

HRESULT __stdcall SP02::Mul(const double x, const double y, double& z)
{
	z = x * y;
	return S_OK;
}

HRESULT __stdcall SP02::Div(const double x, const double y, double& z)
{
	z = x / y;
	return S_OK;
}


