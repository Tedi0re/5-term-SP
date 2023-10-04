#pragma once
#include "pch.h"

#define FNAME L"Smw.SP02.COM"
#define VINDX L"Smw.SP02.1"
#define PRGID L"Smw.SP02"

// {472C45FF-90B5-4047-9F07-06FCEB1AA468}
static const GUID CLSID_SP02 =
{ 0x472c45ff, 0x90b5, 0x4047, { 0x9f, 0x7, 0x6, 0xfc, 0xeb, 0x1a, 0xa4, 0x68 } };

class SP02 : public IAdder, public IMultiplier
{
public:
	SP02();
	~SP02();

	// IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject);
	virtual ULONG __stdcall AddRef(void);
	virtual ULONG __stdcall Release(void);

	//IAdder
	virtual HRESULT __stdcall Add(const double x, const double y, double& z);
	virtual HRESULT __stdcall Sub(const double x, const double y, double& z);

	// IMultiplier
	virtual HRESULT __stdcall Mul(const double x, const double y, double& z);
	virtual HRESULT __stdcall Div(const double x, const double y, double& z);
private:
	volatile ULONG m_Ref;
};
