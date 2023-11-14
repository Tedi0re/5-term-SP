#pragma once
#include "pch.h"

#define SECOND 10000000

namespace ht    // HT API
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


	struct HtHandle    // ���� ���������� HT
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
	};

	HtHandle* create   //  ������� HT             
	(
		int	  capacity,					   // ������� ���������
		int   secSnapshotInterval,		   // ������������� ���������� � ���.
		int   maxKeyLength,                // ������������ ������ �����
		int   maxPayloadLength,            // ������������ ������ ������
		const wchar_t* fileName           // ��� ����� 
	); 	// != NULL �������� ����������  

	HtHandle* open     //  ������� HT             
	(
		const wchar_t* fileName         // ��� ����� 
	); 	// != NULL �������� ����������  

	BOOL snap         // ��������� Snapshot
	(
		HtHandle* htHandle           // ���������� HT (File, FileMapping)
	);

	BOOL close        // snap � ������� HT  �  �������� htHandle
	(
		const HtHandle* htHandle           // ���������� HT (File, FileMapping)
	);	//  == TRUE �������� ����������   


	BOOL insert      // �������� ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT
		const Element* element              // �������
	);	//  == TRUE �������� ���������� 


	BOOL remove      // ������� ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT (����)
		const Element* element              // ������� 
	);	//  == TRUE �������� ���������� 

	Element* get     //  ������ ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT
		const Element* element              // ������� 
	); 	//  != NULL �������� ���������� 


	BOOL update     //  ������� ������� � ���������
	(
		HtHandle* htHandle,            // ���������� HT
		const Element* oldElement,          // ������ ������� (����, ������ �����)
		const void* newPayload,          // ����� ������  
		int             newPayloadLength     // ������ ����� ������
	); 	//  != NULL �������� ���������� 

	const char* getLastError  // �������� ��������� � ��������� ������
	(
		const HtHandle* htHandle                         // ���������� HT
	);

	void print                               // ����������� ������� 
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
