#pragma once
#include "pch.h"

// {1C8309D8-7D3F-4C78-AEBC-F8AED1254AE3}
static const GUID IID_IAdder =
{ 0x1c8309d8, 0x7d3f, 0x4c78, { 0xae, 0xbc, 0xf8, 0xae, 0xd1, 0x25, 0x4a, 0xe3 } };

interface IAdder : IUnknown
{
	virtual HRESULT __stdcall Add(const double x, const double y, double& z) = 0;

	virtual HRESULT __stdcall Sub(const double x, const double y, double& z) = 0;
};
