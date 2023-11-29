﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma comment(lib,"D:/OS11_HTAPI.lib")
#include "../OS11_HTAPI/HT.h"
#include "../OS11_HTAPI/Element.h"

void PrintError(char* str);

int main(int argc, char* argv[])
{
	setlocale(0, "ru");
	srand(time(nullptr));
	if (argc == 1) 
	{
		argc++;
		argv[1] = (char*)"d:/HTspaceSP03.ht";
	}
		
	try
	{
		if (argc != 2)
		{
			throw "Введите количество аргументов: 2";
		}

		const size_t cSize = strlen(argv[1]) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, argv[1], cSize);

		ht::HtHandle* HT = ht::openExist(wc);
		if (HT == NULL)
		{
			throw "Хранилище не создано";
		}

		std::string key, payload = "0";

		while (true)
		{
			Sleep(1000);
			
			key = std::to_string(rand() % 50);
			
			ht::Element* element = new ht::Element(key.c_str(), (int)key.length() + 1, payload.c_str(), (int)payload.length() + 1);
			ht::print(element);
			std::cout << "Elements amount: " << HT->count << std::endl;
			WaitForSingleObject(HT->mutex, INFINITE);
			if (!ht::insert(HT, element))
			{
				PrintError(HT->lastErrorMessage);
			}
			ReleaseMutex(HT->mutex);
		}

		ht::close(HT);
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