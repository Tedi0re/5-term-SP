#pragma once
#include "pch.h"

// {7F4BBD3F-FE9B-4DA5-B033-3AB2154739CB}
static const GUID IID_IMultiplier =
{ 0x7f4bbd3f, 0xfe9b, 0x4da5, { 0xb0, 0x33, 0x3a, 0xb2, 0x15, 0x47, 0x39, 0xcb } };

interface IMultiplier : IUnknown
{
	virtual HRESULT __stdcall Mul(const double x, const double y, double& z) = 0;

	virtual HRESULT __stdcall Div(const double x, const double y, double& z) = 0;
};
