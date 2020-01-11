#include "stdafx.h"
#include "func.h"
using namespace std;

char cCurrPath[60] = "";
addfunc::addfunc(void(*pfunc)(), string strFname, int nNum) :strFname(strFname), nFuncID(nNum), pExacute(pfunc)
{
	pFuncNext = this;
	if (addfunc::pFuncFist)
	{
		addfunc::pFuncEnd->pFuncNext = this;
		pFuncNext = addfunc::pFuncFist;
		addfunc::pFuncEnd = this;
	}
	else {
		addfunc::pFuncFist = this;
		addfunc::pFuncEnd = this;
		addfunc::pFuncCur = this;
	}
	addfunc::nNum++;
}
addfunc* addfunc::pFuncFist = NULL;
addfunc* addfunc::pFuncCur = NULL;
addfunc* addfunc::pFuncEnd = NULL;
int addfunc::nNum = 0;

addfunc* addfunc::find(string strFname)
{
	addfunc* pTemp = addfunc::pFuncCur;
	addfunc::pFuncCur = pTemp->pFuncNext;
	if (!pTemp) {
		return NULL;
	}
	if (strFname == pTemp->strFname) {
		return pTemp;
	}
	while ( (addfunc::pFuncCur != pTemp) && addfunc::pFuncCur ) {
		if (strFname == addfunc::pFuncCur->strFname) {
			return addfunc::pFuncCur;
		}
		addfunc::pFuncCur = addfunc::pFuncCur->pFuncNext;
	}
	return NULL;
}
addfunc* addfunc::find(int nNum)
{
	addfunc* pTemp = addfunc::pFuncCur;
	addfunc::pFuncCur = pTemp->pFuncNext;
	while ((addfunc::pFuncCur != pTemp) && addfunc::pFuncCur) {
		if (nNum == addfunc::pFuncCur->nFuncID) {
			return addfunc::pFuncCur;
		}
		addfunc::pFuncCur = addfunc::pFuncCur->pFuncNext;
	}
	return NULL;
}
bool ExecAddf(string strname)
{	
	bool bResult = true;
	void (*pFunc)() = NULL;
	addfunc* pAddf = NULL;
	pAddf = addfunc::find(strname);
	if (!pAddf) {
		cout << "�Ҳ���" << strname << "()������" << endl;
		bResult = false;
	}
	else {
		cout << "��ʼ����" << pAddf->strFname << "()\n" << endl;
		pFunc = pAddf->pExacute;
		if (!pFunc) {
			cout << pAddf->strFname << "������Ч�ĺ������޷�ִ��" << endl;
			bResult = false;
		}
		else {
			pFunc();
		}
		cout << "\n��������" << pAddf->strFname << "()" << endl;
	}
	return bResult;
}
bool ExecAddf(int nFid)
{
	bool bResult = true;
	void (*pFunc)() = NULL;
	addfunc* pAddf = NULL;
	pAddf = addfunc::find(nFid);
	if (!pAddf) {
		cout << "�Ҳ���IDΪ" << nFid << "�ĺ�����" << endl;
		bResult = false;
	}
	else {
		cout << "��ʼ����" << pAddf->strFname << "()\n" << endl;
		pFunc = pAddf->pExacute;
		if (!pFunc) {
			cout << pAddf->strFname << "������Ч�ĺ������޷�ִ��" << endl;
			bResult = false;
		}
		else {
			pFunc();
		}
		cout << "\n��������" << pAddf->strFname << "()" << endl;
	}
	return bResult;
}