// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

HMODULE hmodule;
LONG sequence = 0;
std::fstream logCOM;

ULONG g_Components = 0;
ULONG g_ServerLocks = 0;

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        hmodule = hModule;
        logCOM.open("D:/logCOM.log", std::ios_base::out);
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    {
        logCOM.close();
        break;
    }
    }
    return TRUE;
}


