#include "stdafx.h"
#include "ShareMem.h"
#include <string>
#include "ShareMem.h"
#include <winbase.h>

using namespace std;

HANDLE hFileMap(NULL);
void* SMbuf(NULL);
string SMerror("");
bool bLoaded(NULL),bInited(NULL);
bool SMinit(int nSize = 100, HANDLE hFile = INVALID_HANDLE_VALUE)
{
	if (bInited) {
		SMerror = "Can't init again!";
		return false;
	}
	SMbuf = NULL;
	if (!hFileMap) {
		hFileMap = OpenFileMapping(FILE_MAP_WRITE, false, _T("FmapTest"));
	}
	else {
		SMerror = "hFileMap is not NULL!";
		return false;
	}
	if (!hFileMap) {
		hFileMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, nSize, _T("FmapTest"));
	}
	if (!hFileMap) {
		SMerror = "hFileMap create error!";
		return false;
	}
	return true;
}
bool KillSMbuf()
{
	if (bLoaded) {
		SMerror = "There is a loaded buffer not be relaseed!";
		return false;
	}
	if (SMbuf) {
		UnmapViewOfFile(SMbuf);
		SMbuf = NULL;	
	}
	
	return true;
}
bool KillMap()
{
	if (SMbuf) {
		SMerror = "There is SMbuf, can't kill map!";
		return false;
	}
	if (hFileMap) {
		CloseHandle(hFileMap);
	}
	return true;
}
template <class T>
bool LoadMem( T **pp, int nSize = 100 )
{
	if (!(*pp)) {
		SMerror = "Can't load a useful pointer!";
		return false;
	}
	if (hFileMap && !SMbuf) {
		SMbuf = MapViewOfFile(hFileMap, FILE_MAP_WRITE, 0, 0, nSize);
	}
	if (SMbuf) {
		*pp = (T*)SMbuf;
	}
	else {
		SMerror = "SMbuf map error!";
		return false;
	}
	bLoaded = (NULL != (*pp));
	return bLoaded;
}

//Must bu used after relase loaded buffer
bool DeLoadMem()
{	
	bLoaded = false;
}