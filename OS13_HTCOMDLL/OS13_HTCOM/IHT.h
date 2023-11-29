#pragma once
#include "pch.h"
#include "../../Lab_2_File_Mapping/OS10/OS10_HTAPI/pch.h"
#include "../../Lab_2_File_Mapping/OS10/OS10_HTAPI/Element.h"
#include "../../Lab_2_File_Mapping/OS10/OS10_HTAPI/HT.h"
// {60D1B3B7-3E3F-487F-9892-5CE1FABA67EE}
static const GUID  IID_IHT =
{ 0x60d1b3b7, 0x3e3f, 0x487f, { 0x98, 0x92, 0x5c, 0xe1, 0xfa, 0xba, 0x67, 0xee } };


interface IHT : IUnknown {
    virtual HRESULT __stdcall create(ht::HtHandle** htHandle, int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName) = 0;
    virtual HRESULT __stdcall open(ht::HtHandle** htHandle, const wchar_t* fileName) = 0;
    virtual HRESULT __stdcall openExist(ht::HtHandle** htHandle, const wchar_t* fileName) = 0;
    virtual HRESULT __stdcall snap(BOOL& rc, ht::HtHandle* htHandle) = 0;
    virtual HRESULT __stdcall close(BOOL& rc, ht::HtHandle* htHandle) = 0;
    virtual HRESULT __stdcall insert(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element) = 0;
    virtual HRESULT __stdcall remove(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element) = 0;
    virtual HRESULT __stdcall get(ht::Element** rcElement, ht::HtHandle* htHandle, const ht::Element* element) = 0;
    virtual HRESULT __stdcall update(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* oldElement, const void* newPayload, int newPayloadLength) = 0;
    virtual HRESULT __stdcall getLastError(const char** lastError, ht::HtHandle* htHandle) = 0;
    virtual HRESULT __stdcall print(const ht::Element* element) = 0;
};
