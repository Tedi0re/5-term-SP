#pragma once
#pragma comment(lib, "D:/OS10_HTAPI")
#include "../OS10_HTAPI/pch.h"


namespace test
{
	BOOL TC1(ht::HtHandle* ht, const void* key , const void* payload);

	BOOL TC2(ht::HtHandle* ht, const void* key, const void* payload);

	BOOL TC3(ht::HtHandle* ht, const void* key);

	BOOL TC4(ht::HtHandle* ht, const void* key);
}


//namespace test
//{
//	BOOL TC1(const wchar_t* name, const void* key, int keyLength, const void* payload, int  payloadLength);
//
//	BOOL TC2(const wchar_t* name, const void* key, int keyLength, const void* payload, int  payloadLength);
//
//	BOOL TC3(const wchar_t* name, const void* key, int keyLength);
//
//	BOOL TC4(const wchar_t* name, const void* key, int keyLength);
//}