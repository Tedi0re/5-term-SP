#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma comment(lib,"D:/OS11_HTAPI.lib")
#include "../OS11_HTAPI/HT.h"
#include "../OS11_HTAPI/Element.h"




bool checkInt(char* input);
using namespace ht;

int main(int argc, char* argv[]) // OS11_CREATE d:/HTspaceSP03.ht 2000 5 20 10              OS11_CREATE ./files/os11_04.ht 2000 3 4 4
{
	setlocale(LC_ALL, "Russian");

	try
	{
		if (argc != 6)
		{
			throw "введите количество аргументов: 6";
		}
		if (!checkInt(argv[2]) || !checkInt(argv[3]) || !checkInt(argv[4]) || !checkInt(argv[5]))
		{
			throw "введите корректные значения";
		}
		const size_t csize = strlen(argv[1]) + 1;
		wchar_t* wc = new wchar_t[csize];
		mbstowcs(wc, argv[1], csize);

	/*	if (ht::getfileattributes(wc) != invalid_file_attributes)
		{
			throw "файл уже существует";
		}*/

		int capacity = std::stoi(argv[2]);
		int snapshotinterval = std::stoi(argv[3]);
		int maxkeylength = std::stoi(argv[4]);
		int maxpayloadlength = std::stoi(argv[5]);


		HtHandle* ht = create(capacity, snapshotinterval, maxkeylength, maxpayloadlength, wc);
		if (ht == NULL)
		{
			throw "хранилище не создано";
		}

		std::cout << "ht-storage created!" << std::endl;
		std::wcout << "filename = " << wc << std::endl;
		std::cout << "snapshotinterval = " << snapshotinterval << std::endl;
		std::cout << "capacity = " << capacity << std::endl;
		std::cout << "maxkeylength = " << maxkeylength << std::endl;
		std::cout << "maxdatalength = " << maxpayloadlength << std::endl;

		close(ht);
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
		exit(-1);
	}

	exit(0);
}

bool checkInt(char* input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] < '0' || input[i] > '9')
			return false;
		i++;
	}
	return true;
}