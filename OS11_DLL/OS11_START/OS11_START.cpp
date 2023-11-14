#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma comment(lib,"D:/OS11_HTAPI.lib")
#include "../OS11_HTAPI/HT.h"
#include "../OS11_HTAPI/Element.h"





int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	HMODULE libModule = NULL;
	argc++;
	argv[1] = (char*)"d:/HTspaceSP03.ht";
	try
	{
		HMODULE libModule = LoadLibrary(L"d:/OS11_HTAPI.dll");
		if (!libModule)
		{
			throw "Невозможно загрузить библиотеку";
		}
		if (argc != 2)
		{
			throw "Введите количество аргументов: 2";
		}
		const size_t cSize = strlen(argv[1]) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, argv[1], cSize);

		ht::HtHandle* HT = ht::open(wc);
		if (HT == NULL)
		{
			throw "Хранилище не создано";
		}
		DWORD processId = GetCurrentProcessId();
		std::cout << "PID:" << processId << std::endl;
		std::cout << "HT-Storage Start !" << std::endl;
		std::wcout << "filename = " << wc << std::endl;
		std::cout << "snapshotinterval = " << HT->secSnapshotInterval << std::endl;
		std::cout << "capacity = " << HT->capacity << std::endl;
		std::cout << "maxkeylength = " << HT->maxKeyLength << std::endl;
		std::cout << "maxdatalength = " << HT->maxPayloadLength << std::endl;

		while (true) {
			Sleep((HT->secSnapshotInterval) * 1000);
			snap(HT);
			std::cout << "----SNAPSHOT in Thread----" << std::endl;
		}
		ht::snap(HT);
		ht::close(HT);
		FreeLibrary(libModule);
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
		FreeLibrary(libModule);
		exit(-1);
	}

	exit(0);
}

//
// d:/HTspaceSP03.ht