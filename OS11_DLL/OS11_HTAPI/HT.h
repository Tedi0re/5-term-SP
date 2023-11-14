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
	// API HT - ����������� ��������� ��� ������� � ��-��������� 
	//          ��-��������� ������������� ��� �������� ������ � �� � ������� ����/��������
	//          ���������������� (�����������) ������ �������������� � ������� snapshot-���������� 
	//          create - �������  � ������� HT-��������� ��� �������������   
	//          open   - ������� HT-��������� ��� �������������
	//          insert - ������� ������� ������
	//          remove - ������� ������� ������    
	//          get    - ������  ������� ������
	//          update - �������� ������� ������
	//          snap   - �������� snapshot
	//          close  - ��������� snap � ������� HT-��������� ��� �������������
	//          getLastError - �������� ��������� � ��������� ������


	extern "C" OS11HTAPI struct  HtHandle    // ���� ���������� HT
	{
		HtHandle();
		HtHandle(int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName);
		int     capacity;               // ������� ��������� � ���������� ��������� 
		int     secSnapshotInterval;    // ������������� ���������� � ���. 
		int     maxKeyLength;           // ������������ ����� �����
		int     maxPayloadLength;       // ������������ ����� ������
		wchar_t fileName[512];          // ��� ����� 
		HANDLE  file;                   // File HANDLE != 0, ���� ���� ������
		HANDLE  fileMapping;            // Mapping File HANDLE != 0, ���� mapping ������  
		LPVOID  addr;                   // Addr != NULL, ���� mapview ��������  
		char    lastErrorMessage[512];  // ��������� �� ��������� ������ ��� 0x00  
		time_t  lastSnaptime;           // ���� ���������� snap'a (time())

		int count;						// ������� ���������� ��������� � ���-�������
		HANDLE snapshotTimer;			// ������ ��� snapshot
		HANDLE mutex;					// mutex ��� ������������� ���������� ����������� HtHandle
		//int elementCount;
		//HANDLE snapShotTheard;
	};

	extern "C" OS11HTAPI HtHandle* create   //  ������� HT             
	(
		int	  capacity,					   // ������� ���������
		int   secSnapshotInterval,		   // ������������� ���������� � ���.
		int   maxKeyLength,                // ������������ ������ �����
		int   maxPayloadLength,            // ������������ ������ ������
		const wchar_t* fileName           // ��� ����� 
	); 	// != NULL �������� ����������  

	extern "C" OS11HTAPI HtHandle* open     //  ������� HT             
	(
		const wchar_t* fileName         // ��� ����� 
	); 	// != NULL �������� ����������  

	extern "C" OS11HTAPI HtHandle * openExist(const wchar_t* fileName);

	extern "C" OS11HTAPI BOOL snap         // ��������� Snapshot
	(
		HtHandle* htHandle           // ���������� HT (File, FileMapping)
	);

	extern "C" OS11HTAPI BOOL close        // snap � ������� HT  �  �������� htHandle
	(
		const HtHandle* htHandle           // ���������� HT (File, FileMapping)
	);	//  == TRUE �������� ����������   


	extern "C" OS11HTAPI BOOL insert      // �������� ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT
		const Element* element              // �������
	);	//  == TRUE �������� ���������� 


	extern "C" OS11HTAPI BOOL removeE   // ������� ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT (����)
		const Element* element              // ������� 
	);	//  == TRUE �������� ���������� 

	extern "C" OS11HTAPI Element* get     //  ������ ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT
		const Element* element              // ������� 
	); 	//  != NULL �������� ���������� 


	extern "C" OS11HTAPI BOOL update     //  ������� ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT
		const Element* oldElement,          // ������ ������� (����, ������ �����)
		const void* newPayload,          // ����� ������  
		int             newPayloadLength     // ������ ����� ������
	); 	//  != NULL �������� ���������� 

	extern "C" OS11HTAPI const char* getLastError  // �������� ��������� � ��������� ������
	(
		const HtHandle* htHandle                         // ���������� HT
	);

	extern "C" OS11HTAPI void print                               // ����������� ������� 
	(
		const Element* element              // ������� 
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
		int	  capacity,					// ������� ���������
		int   secSnapshotInterval,		// ������������� ���������� � ���.
		int   maxKeyLength,             // ������������ ������ �����
		int   maxPayloadLength,			// ������������ ������ ������
		const wchar_t* fileName);		// ��� ����� 
	HtHandle* openHtFromFile(const wchar_t* fileName);
	HtHandle* openHtFromMapName(const wchar_t* fileName);
	BOOL runSnapshotTimer(HtHandle* htHandle);
};
