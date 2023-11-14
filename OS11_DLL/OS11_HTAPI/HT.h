#pragma once
#include "pch.h"

#define SECOND 10000000

#define _CRT_SECURE_NO_WARNINGS

//#ifdef OS11HTAPI_EXPORTS
//#define OS11HTAPI __declspec(dllexport)
//#else
//#define OS11HTAPI __declspec(dllimport)
//#endif

#define OS11HTAPI __declspec(dllexport)
extern "C" namespace ht    // HT API
{
	// API HT - программный интерфейс для доступа к НТ-хранилищу 
	//          НТ-хранилище предназначено для хранения данных в ОП в формате ключ/значение
	//          Персистестеность (сохранность) данных обеспечивается с помощью snapshot-менханизма 
	//          create - создать  и открыть HT-хранилище для использования   
	//          open   - открыть HT-хранилище для использования
	//          insert - создать элемент данных
	//          remove - удалить элемент данных    
	//          get    - читать  элемент данных
	//          update - изменить элемент данных
	//          snap   - выпонить snapshot
	//          close  - выполнить snap и закрыть HT-хранилище для использования
	//          getLastError - получить сообщение о последней ошибке


	extern "C" OS11HTAPI struct  HtHandle    // блок управления HT
	{
		HtHandle();
		HtHandle(int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName);
		int     capacity;               // емкость хранилища в количестве элементов 
		int     secSnapshotInterval;    // переодичность сохранения в сек. 
		int     maxKeyLength;           // максимальная длина ключа
		int     maxPayloadLength;       // максимальная длина данных
		wchar_t fileName[512];          // имя файла 
		HANDLE  file;                   // File HANDLE != 0, если файл открыт
		HANDLE  fileMapping;            // Mapping File HANDLE != 0, если mapping создан  
		LPVOID  addr;                   // Addr != NULL, если mapview выполнен  
		char    lastErrorMessage[512];  // сообщение об последней ошибке или 0x00  
		time_t  lastSnaptime;           // дата последнего snap'a (time())

		int count;						// текущее количество элементов в хэш-таблице
		HANDLE snapshotTimer;			// таймер для snapshot
		HANDLE mutex;					// mutex для синхронизации нескольких экземпляров HtHandle
		//int elementCount;
		//HANDLE snapShotTheard;
	};

	extern "C" OS11HTAPI HtHandle* create   //  создать HT             
	(
		int	  capacity,					   // емкость хранилища
		int   secSnapshotInterval,		   // переодичность сохранения в сек.
		int   maxKeyLength,                // максимальный размер ключа
		int   maxPayloadLength,            // максимальный размер данных
		const wchar_t* fileName           // имя файла 
	); 	// != NULL успешное завершение  

	extern "C" OS11HTAPI HtHandle* open     //  открыть HT             
	(
		const wchar_t* fileName         // имя файла 
	); 	// != NULL успешное завершение  

	extern "C" OS11HTAPI HtHandle * openExist(const wchar_t* fileName);

	extern "C" OS11HTAPI BOOL snap         // выполнить Snapshot
	(
		HtHandle* htHandle           // управление HT (File, FileMapping)
	);

	extern "C" OS11HTAPI BOOL close        // snap и закрыть HT  и  очистить htHandle
	(
		const HtHandle* htHandle           // управление HT (File, FileMapping)
	);	//  == TRUE успешное завершение   


	extern "C" OS11HTAPI BOOL insert      // добавить элемент в хранилище
	(
		HtHandle* htHandle,            // управление HT
		const Element* element              // элемент
	);	//  == TRUE успешное завершение 


	extern "C" OS11HTAPI BOOL removeE   // удалить элемент в хранилище
	(
		HtHandle* htHandle,            // управление HT (ключ)
		const Element* element              // элемент 
	);	//  == TRUE успешное завершение 

	extern "C" OS11HTAPI Element* get     //  читать элемент в хранилище
	(
		HtHandle* htHandle,            // управление HT
		const Element* element              // элемент 
	); 	//  != NULL успешное завершение 


	extern "C" OS11HTAPI BOOL update     //  именить элемент в хранилище
	(
		HtHandle* htHandle,            // управление HT
		const Element* oldElement,          // старый элемент (ключ, размер ключа)
		const void* newPayload,          // новые данные  
		int             newPayloadLength     // размер новых данных
	); 	//  != NULL успешное завершение 

	extern "C" OS11HTAPI const char* getLastError  // получить сообщение о последней ошибке
	(
		const HtHandle* htHandle                         // управление HT
	);

	extern "C" OS11HTAPI void print                               // распечатать элемент 
	(
		const Element* element              // элемент 
	);

	int hashFunction(const char* key, int capacity);
	int nextHash(int currentHash, const char* key, int capacity);

	int findFreeIndex(const HtHandle* htHandle, const Element* element);
	BOOL writeToMemory(const HtHandle* const htHandle, const Element* const element, int index);
	int incrementCount(HtHandle* const htHandle);

	int findIndex(const HtHandle* htHandle, const Element* element);
	Element* readFromMemory(const HtHandle* const htHandle, Element* const element, int index);
	BOOL clearMemoryByIndex(const HtHandle* const htHandle, int index);
	int decrementCount(HtHandle* const htHandle);
	
	void CALLBACK snapAsync(LPVOID prm, DWORD, DWORD);
	const char* writeLastError(HtHandle* const htHandle, const char* msg);

	HtHandle* createHt(
		int	  capacity,					// емкость хранилища
		int   secSnapshotInterval,		// переодичность сохранения в сек.
		int   maxKeyLength,             // максимальный размер ключа
		int   maxPayloadLength,			// максимальный размер данных
		const wchar_t* fileName);		// имя файла 
	HtHandle* openHtFromFile(const wchar_t* fileName);
	HtHandle* openHtFromMapName(const wchar_t* fileName);
	BOOL runSnapshotTimer(HtHandle* htHandle);
};
