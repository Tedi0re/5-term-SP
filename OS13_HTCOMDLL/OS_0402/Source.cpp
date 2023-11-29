#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma comment(lib,"D:/OS13_HTCOM_LIB.lib")

#include "../OS13_HTCOM_LIB/pch.h"
#include "../OS13_HTCOM_LIB/OS13.h"

void PrintError(char* str);

int main(int argc, char* argv[])
{
	setlocale(0, "ru");
	srand(time(nullptr));

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

		ht::HtHandle* ht = OS13_HTCOM::HT::openExist(h,wc);
		if (ht == NULL)
		{
			throw "Хранилище не создано";
		}

		std::string key, payload = "0";
		HANDLE hStopEvent = CreateEvent(NULL, TRUE, FALSE, L"Stop");
		while (true)
		{
			Sleep(1000);
			DWORD result = WaitForSingleObject(hStopEvent, 0);
			if (result == WAIT_OBJECT_0) {
				OS13_HTCOM::HT::snap(h, ht);
				OS13_HTCOM::HT::close(h, ht);
				return 0;
			}
			key = std::to_string(rand() % 50);

			ht::Element* element = OS13_HTCOM::Element::createInsertElement(h,key.c_str(), (int)key.length() + 1, payload.c_str(), (int)payload.length() + 1);
			OS13_HTCOM::HT::print(h,element);
			
			WaitForSingleObject(ht->mutex, INFINITE);
			if (!OS13_HTCOM::HT::insert(h,ht, element))
			{
				PrintError(ht->lastErrorMessage);
				return -1;
			}
			ReleaseMutex(ht->mutex);
		}

		OS13_HTCOM::HT::close(h, ht);
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
		exit(-1);
	}

	exit(0);
}

void PrintError(char* str) {
	std::cout << "error: \t" << str << std::endl;
}

//d:/HTspaceSP03.ht