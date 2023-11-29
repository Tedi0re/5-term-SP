#include "pch.h"
#pragma comment(lib, "D:/OS10_HTAPI.lib")
extern ULONG g_Components;

IHT* pIHT = nullptr;
IElement* pIElement = nullptr;

OS13::OS13() : m_Ref(1)
{
	SEQ;
	InterlockedIncrement((LONG*)&g_Components);//??
	LOG("OS13::Adder g_Components = ", g_Components);
}

OS13::~OS13()
{
	SEQ;
	InterlockedDecrement((LONG*)&g_Components);
	LOG("OS13::~Adder g_Components = ", g_Components);
}

HRESULT __stdcall  OS13::QueryInterface(REFIID riid, void** ppv)
{
	SEQ;
	HRESULT rc = S_OK;
	*ppv = NULL;
	if (riid == IID_IUnknown) *ppv = (IHT*)this;//??
	else if (riid == IID_IHT) *ppv = (IHT*)this;
	else if (riid == IID_IElement) *ppv = (IElement*)this;
	else rc = E_NOINTERFACE;
	if (rc == S_OK) this->AddRef();
	LOG("OS13::QueryInterface rc = ", rc);
	return rc;
}

ULONG __stdcall  OS13::AddRef(void)
{
	SEQ;
	InterlockedIncrement((LONG*)&(this->m_Ref));
	LOG("OS13::AddRef m_Ref = ", this->m_Ref);
	return this->m_Ref;
}

ULONG __stdcall  OS13::Release(void)
{
	SEQ;
	ULONG rc = this->m_Ref;
	if ((rc = InterlockedDecrement((LONG*)&(this->m_Ref))) == 0) delete this;
	LOG("OS13::Release rc = ", rc);
	return rc;
}

HRESULT __stdcall  OS13::createGetElement(ht::Element** getElement, const void* key, int keyLength)
{
	SEQ;
	*getElement = new ht::Element(key, keyLength);
	LOG("OS13::Create ht::Element ", &getElement);
	return S_OK;
}

HRESULT __stdcall  OS13::createInsertElement(ht::Element** newElement, const void* key, int keyLength, const void* payload, int  payloadLength)
{
	SEQ;
	*newElement = new ht::Element(key, keyLength, payload, payloadLength);
	LOG("OS13::Create ht::Element ", &newElement);
	return S_OK;
}

HRESULT __stdcall  OS13::createUpdateElement(ht::Element** updateElement, const ht::Element* oldElement, const void* newPayload, int  newPayloadLength)
{
	SEQ;
	*updateElement = new ht::Element(oldElement, newPayload, newPayloadLength);
	LOG("OS13::Create ht::Element ", &updateElement);
	return S_OK;
}

HRESULT __stdcall  OS13::create(ht::HtHandle** htHandle, int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName)
{
	SEQ;
	*htHandle = ht::create(capacity, secSnapshotInterval, maxKeyLength, maxPayloadLength, fileName);
	LOG("OS13::Create ht", &htHandle);
	return S_OK;
}
HRESULT __stdcall  OS13::open(ht::HtHandle** htHandle, const wchar_t* fileName)
{
	SEQ;
	*htHandle = ht::open(fileName);
	LOG("OS13::Open ht", &htHandle);
	return S_OK;
}

HRESULT __stdcall  OS13::openExist(ht::HtHandle** htHandle, const wchar_t* fileName)
{
	SEQ;
	*htHandle = ht::openExist(fileName);
	LOG("OS13::Open ht", &htHandle);
	return S_OK;
}

HRESULT __stdcall  OS13::snap(BOOL& rc, ht::HtHandle* htHandle)
{
	SEQ;
	rc = ht::snap(htHandle);
	LOG("OS13::Snap ht", &htHandle->fileName);
	return S_OK;
}
HRESULT __stdcall  OS13::close(BOOL& rc, ht::HtHandle* htHandle)
{
	SEQ;
	rc = ht::close(htHandle);
	LOG("OS13::Close ht", &htHandle->fileName);
	return S_OK;
}
HRESULT __stdcall  OS13::insert(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* Element)
{
	SEQ;
	rc = ht::insert(htHandle, Element);
	LOG("OS13::Insert ht", &htHandle->fileName);
	return S_OK;
}
HRESULT __stdcall  OS13::remove(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* Element)
{
	SEQ;
	rc = ht::remove(htHandle, Element);
	LOG("OS13::Remove ht", &htHandle->fileName);
	return S_OK;
}
HRESULT __stdcall  OS13::get(ht::Element** rcElement, ht::HtHandle* htHandle, const ht::Element* Element)
{
	SEQ;
	*rcElement = ht::get(htHandle, Element);
	LOG("OS13::Get ht", &htHandle->fileName);
	return S_OK;
}
HRESULT __stdcall  OS13::update(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* oldElement, const void* newPayload, int newPayloadLength)
{
	SEQ;
	rc = ht::update(htHandle, oldElement, newPayload, newPayloadLength);
	LOG("OS13::Update ht", &htHandle->fileName);
	return S_OK;
}
HRESULT __stdcall  OS13::getLastError(const char** lastError, ht::HtHandle* htHandle)
{
	SEQ;
	*lastError = ht::getLastError(htHandle);
	LOG("OS13::ERROR", lastError);
	return S_OK;
}
HRESULT __stdcall  OS13::print(const ht::Element* Element)
{
	SEQ;
	ht::print(Element);
	LOG("OS13::print ht", Element);
	return S_OK;
}


