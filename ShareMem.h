#pragma once


extern HANDLE hFileMap;
extern void* SMbuf;

bool SMinit(int nSize, HANDLE hFile);

bool KillSMbuf();
bool KillMap();
template <class T>
bool LoadMem(T** pp);
bool DeLoadMem();

