#pragma once
#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

//#ifdef OS11HTAPI_EXPORTS
//#define OS11HTAPI __declspec(dllexport)
//#else
//#define OS11HTAPI __declspec(dllimport)
//#endif

#define OS11HTAPI __declspec(dllexport)

namespace ht
{
	extern "C" OS11HTAPI  struct Element   // ������� 
	{
		__declspec(dllexport) Element();
		__declspec(dllexport) Element(const void* key, int keyLength);                                             // for get
		__declspec(dllexport) Element(const void* key, int keyLength, const void* payload, int  payloadLength);    // for insert
		__declspec(dllexport) Element(const Element* oldElement, const void* newPayload, int  newPayloadLength);   // for update
		const void* key;                 // �������� ����� 
		int         keyLength;           // ������ �����
		const void* payload;             // ������ 
		int         payloadLength;       // ������ ������
	};

	int getSizeElement(
		int   maxKeyLength,                // ������������ ������ �����
		int   maxPayloadLength);           // ������������ ������ ������
}