#pragma once
#include "pch.h"

#define FNAME L"Smw.OS13.COM"
#define VINDX L"Smw.OS13.1"
#define PRGID L"Smw.OS13"

// {472C45FF-90B5-4047-9F07-06FCEB1AA468}
static const GUID CLSID_OS13 =
{ 0x472c45ff, 0x90b5, 0x4047, { 0x9f, 0x7, 0x6, 0xfc, 0xeb, 0x1a, 0xa4, 0x68 } };

class OS13 : public IHT, public IElement
{
public:
	OS13();
	~OS13();

	// IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject);
	virtual ULONG __stdcall AddRef(void);
	virtual ULONG __stdcall Release(void);

	//IElement
	virtual HRESULT __stdcall createGetElement(ht::Element** getElement, const void* key, int keyLength);
	virtual HRESULT __stdcall createInsertElement(ht::Element** newElement, const void* key, int keyLength, const void* payload, int  payloadLength);
	virtual HRESULT __stdcall createUpdateElement(ht::Element** updateElement, const ht::Element* oldElement, const void* newPayload, int  newPayloadLength);

	// IHT
	virtual HRESULT __stdcall create(ht::HtHandle** htHandle, int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName);
	virtual HRESULT __stdcall open(ht::HtHandle** htHandle, const wchar_t* fileName);
	virtual HRESULT __stdcall openExist(ht::HtHandle** htHandle, const wchar_t* fileName);
	virtual HRESULT __stdcall snap(BOOL& rc, ht::HtHandle* htHandle);
	virtual HRESULT __stdcall close(BOOL& rc, ht::HtHandle* htHandle);
	virtual HRESULT __stdcall insert(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element);
	virtual HRESULT __stdcall remove(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element);
	virtual HRESULT __stdcall get(ht::Element** rcElement, ht::HtHandle* htHandle, const ht::Element* element);
	virtual HRESULT __stdcall update(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* oldElement, const void* newPayload, int newPayloadLength);
	virtual HRESULT __stdcall getLastError(const char** lastError, ht::HtHandle* htHandle);
	virtual HRESULT __stdcall print(const ht::Element* element);
private:
	volatile ULONG m_Ref;
};
