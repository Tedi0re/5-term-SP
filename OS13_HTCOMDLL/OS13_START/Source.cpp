#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#pragma comment(lib,"D:/OS13_HTCOM_LIB.lib")
#include "../OS13_HTCOM_LIB/pch.h"
#include "../OS13_HTCOM_LIB/OS13.h"




int main(int argc, char* argv[])
{
	HANDLE hStopEvent = CreateEvent(NULL,TRUE,FALSE,L"Stop");
	setlocale(LC_ALL, "Russian");
	argc++;
	argv[1] = (char*)"d:/HT_Table.ht";
	try
	{
		if (argc != 2)
		{
			throw "Введите количество аргументов: 2";
		}
		OS13_HTCOM_HANDEL h = OS13_HTCOM::Init();

		const size_t cSize = strlen(argv[1]) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, argv[1], cSize);

		ht::HtHandle* ht = OS13_HTCOM::HT::open(h,wc);
		if (ht == NULL)
		{
			throw "Хранилище не создано";
		}
		DWORD processId = GetCurrentProcessId();
		std::cout << "PID:" << processId << std::endl;
		std::cout << "HT-Storage Start !" << std::endl;
		std::wcout << "filename = " << wc << std::endl;
		std::cout << "snapshotinterval = " << ht->secSnapshotInterval << std::endl;
		std::cout << "capacity = " << ht->capacity << std::endl;
		std::cout << "maxkeylength = " << ht->maxKeyLength << std::endl;
		std::cout << "maxdatalength = " << ht->maxPayloadLength << std::endl;

		while (true) {
			Sleep((ht->secSnapshotInterval) * 1000);
			OS13_HTCOM::HT::snap(h,ht);
			std::cout <<"----SNAPSHOT in Thread----" << std::endl;
			DWORD result = WaitForSingleObject(hStopEvent, 0);
			if (result == WAIT_OBJECT_0) {
				OS13_HTCOM::HT::snap(h, ht);
				OS13_HTCOM::HT::close(h, ht);
				std::cout<< "-----------STOP-----------" << std::endl;
				return 0;
			}
		}



		OS13_HTCOM::HT::snap(h, ht);
		OS13_HTCOM::HT::close(h,ht);
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
		exit(-1);
	}

	exit(0);
}

//
// d:/HTspaceSP03.ht