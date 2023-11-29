#pragma once
#include "pch.h"
#include "../../Lab_2_File_Mapping/OS10/OS10_HTAPI/pch.h"
#include "../../Lab_2_File_Mapping/OS10/OS10_HTAPI/Element.h"
#include "../../Lab_2_File_Mapping/OS10/OS10_HTAPI/HT.h"


// {EBACF4A2-A0A4-43ED-B263-F61C9EE4C7D6}
static const GUID IID_IElement =
{ 0xebacf4a2, 0xa0a4, 0x43ed, { 0xb2, 0x63, 0xf6, 0x1c, 0x9e, 0xe4, 0xc7, 0xd6 } };


interface IElement : IUnknown {
	virtual HRESULT __stdcall createGetElement(ht::Element** getElement, const void* key, int keyLength) = 0;
	virtual HRESULT __stdcall createInsertElement(ht::Element** newElement, const void* key, int keyLength, const void* payload, int  payloadLength) = 0;
	virtual HRESULT __stdcall createUpdateElement(ht::Element** updateElement, const ht::Element* oldElement, const void* newPayload, int  newPayloadLength) = 0;
};