#pragma once
#include "pch.h"
#define SEQ LONG __XXCSEQ=InterlockedIncrement(&sequence)
#define LOG(x,y) logCOM<<__XXCSEQ<<":"<<x<<y<<std::endl

extern std::fstream logCOM;
extern LONG sequence;