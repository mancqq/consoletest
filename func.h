#pragma once

#include <string>
#include <iostream>

extern char cCurrPath[60];

#define ADDF(temp) addfunc Func##temp(temp,#temp,addfunc::nNum)  

class addfunc
{
public:
	static addfunc* find(std::string strFname);
	static addfunc* find(int nNum);
	static addfunc *pFuncFist, *pFuncCur, *pFuncEnd;
	static int nNum;

	addfunc* pFuncNext;
	addfunc(void (*pfunc)(), std::string strFname,int nNum = -1);
	std::string strFname;
	int nFuncID;
	void (*pExacute)();
};
bool ExecAddf(std::string strname);
bool ExecAddf(int nFid);