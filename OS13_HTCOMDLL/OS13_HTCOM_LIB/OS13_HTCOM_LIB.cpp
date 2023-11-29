// OS13_HTCOM_LIB.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "../OS13_HTCOM/IElement.h"
#include "../OS13_HTCOM/IHT.h"
#include "../OS13_HTCOM/OS13.h"

//#include "../OS_13_HT_DLL_COM/OS13.h"

IHT* pIHT = nullptr;
IElement* pIElement = nullptr;

OS13_HTCOM_HANDEL OS13_HTCOM::Init() {
	IUnknown* pIUnknown = NULL;
	CoInitialize(NULL);                        // инициализация библиотеки OLE32
	HRESULT hr0 = CoCreateInstance(CLSID_OS13, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown);
	if (SUCCEEDED(hr0))
	{
		return pIUnknown;
	}
	else {
		throw (int)hr0;
		return NULL;
	}
}

void OS13_HTCOM::Dispose(OS13_HTCOM_HANDEL h) {
	((IUnknown*)h)->Release();
	CoFreeUnusedLibraries();
	CoUninitialize();
}

ht::HtHandle* OS13_HTCOM::HT::create(OS13_HTCOM_HANDEL h, int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName)
{
	ht::HtHandle** ht = new ht::HtHandle*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->create(ht, capacity, secSnapshotInterval, maxKeyLength, maxPayloadLength, fileName);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIHT->Release();
			return *ht;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}

ht::HtHandle* OS13_HTCOM::HT::open(OS13_HTCOM_HANDEL h, const wchar_t* fileName)
{
	ht::HtHandle** ht = new ht::HtHandle*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->open(ht, fileName);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIHT->Release();
			return *ht;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}


ht::HtHandle* OS13_HTCOM::HT::openExist(OS13_HTCOM_HANDEL h, const wchar_t* fileName)
{
	ht::HtHandle** ht = new ht::HtHandle*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->openExist(ht, fileName);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIHT->Release();
			return *ht;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}

BOOL OS13_HTCOM::HT::snap(OS13_HTCOM_HANDEL h, ht::HtHandle* htHandle)
{
	BOOL rc = false;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->snap(rc, htHandle);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return rc;
		}
		else {
			pIHT->Release();
			return rc;
		}
	}
	else {

		throw (int)hr0;
		return rc;
	}
}

BOOL OS13_HTCOM::HT::close(OS13_HTCOM_HANDEL h, ht::HtHandle* htHandle)
{
	BOOL rc = false;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->close(rc, htHandle);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return rc;
		}
		else {
			pIHT->Release();
			return rc;
		}
	}
	else {

		throw (int)hr0;
		return rc;
	}
}

BOOL OS13_HTCOM::HT::insert(OS13_HTCOM_HANDEL h, ht::HtHandle* htHandle, const ht::Element* element)
{
	BOOL rc = false;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->insert(rc, htHandle, element);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return rc;
		}
		else {
			pIHT->Release();
			return rc;
		}
	}
	else {

		throw (int)hr0;
		return rc;
	}
}

BOOL OS13_HTCOM::HT::remove(OS13_HTCOM_HANDEL h, ht::HtHandle* htHandle, const ht::Element* element)
{
	BOOL rc = false;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->remove(rc, htHandle, element);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return rc;
		}
		else {
			pIHT->Release();
			return rc;
		}
	}
	else {

		throw (int)hr0;
		return rc;
	}
}

ht::Element* OS13_HTCOM::HT::get(OS13_HTCOM_HANDEL h, ht::HtHandle* htHandle, const ht::Element* element)
{
	ht::Element** rcElement = new ht::Element*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->get(rcElement, htHandle, element);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIHT->Release();
			return *rcElement;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}

BOOL OS13_HTCOM::HT::update(OS13_HTCOM_HANDEL h, ht::HtHandle* htHandle, const ht::Element* oldElement, const void* newPayload, int newPayloadLength)
{
	BOOL rc = false;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->update(rc, htHandle, oldElement, newPayload, newPayloadLength);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return rc;
		}
		else {
			pIHT->Release();
			return rc;
		}
	}
	else {

		throw (int)hr0;
		return rc;
	}
}

const char* OS13_HTCOM::HT::getLastError(OS13_HTCOM_HANDEL h, ht::HtHandle* htHandle)
{
	const char** rcLastError = new const char*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->getLastError(rcLastError, htHandle);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIHT->Release();
			return *rcLastError;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}

void OS13_HTCOM::HT::print(OS13_HTCOM_HANDEL h, const ht::Element* element)
{
	BOOL rc = false;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IHT, (void**)&pIHT);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIHT->print(element);
		if (!SUCCEEDED(hr1)) {
			pIHT->Release();
			throw (int)hr1;
		}
		else {
			pIHT->Release();
		}
	}
	else {

		throw (int)hr0;
	}
}

ht::Element* OS13_HTCOM::Element::createGetElement(OS13_HTCOM_HANDEL h, const void* key, int keyLength)
{
	ht::Element** rcElement = new ht::Element*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IElement, (void**)&pIElement);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIElement->createGetElement(rcElement, key, keyLength);
		if (!SUCCEEDED(hr1)) {
			pIElement->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIElement->Release();
			return *rcElement;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}

ht::Element* OS13_HTCOM::Element::createInsertElement(OS13_HTCOM_HANDEL h, const void* key, int keyLength, const void* payload, int  payloadLength)
{
	ht::Element** rcElement = new ht::Element*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IElement, (void**)&pIElement);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIElement->createInsertElement(rcElement, key, keyLength, payload, payloadLength);
		if (!SUCCEEDED(hr1)) {
			pIElement->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIElement->Release();
			return *rcElement;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}

ht::Element* OS13_HTCOM::Element::createUpdateElement(OS13_HTCOM_HANDEL h, const ht::Element* oldElement, const void* newPayload, int  newPayloadLength)
{
	ht::Element** rcElement = new ht::Element*;

	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IElement, (void**)&pIElement);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIElement->createUpdateElement(rcElement, oldElement, newPayload, newPayloadLength);
		if (!SUCCEEDED(hr1)) {
			pIElement->Release();
			throw (int)hr1;
			return nullptr;
		}
		else {
			pIElement->Release();
			return *rcElement;
		}
	}
	else {

		throw (int)hr0;
		return nullptr;
	}
}
