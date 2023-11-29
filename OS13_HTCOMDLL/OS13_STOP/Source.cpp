#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma comment(lib,"D:/OS13_HTCOM_LIB.lib")
#include "../OS13_HTCOM_LIB/pch.h"
#include "../OS13_HTCOM_LIB/OS13.h"




int main(int argc, char* argv[])
{
	HANDLE hStopEvent = CreateEvent(NULL,
		TRUE, //FALSE - автоматический сброс; TRUE - ручной
		FALSE,
		L"Stop");
	SetEvent(hStopEvent);
}
