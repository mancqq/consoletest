// ѧϰ����̨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include "play.h"
#include "class.h"
#include"elsesome.h"
#include<vector>
#include "func.h"
using namespace std;
extern std::vector<int> *newvectrans(std::string a);

int main(int argc, _TCHAR* argv[])
{
	//void (*pf[])()={play,play1,play2,play3,play4,play5,play6,play7,
	//	play8,play9,play10,play11,play12,play13,play14,play15,play16,
	//	play17,play18,play19/**/}; 
	

	bool bRun = true;
	vector<int>* series;
	void (*pFunc)() = NULL;
	addfunc* pAddf = NULL;


	string ser;
	//play9();
	while (bRun) {


		cout << "���������к���������к�n1-n2,n3,n4....!" << endl;
		cin >> ser;
		if (0 == strcmp("exit", ser.c_str())) {
			bRun = false;
			continue;
		}
		if (addfunc::find(ser)) {
			if (!ExecAddf(ser)) {
				cout << "run error from \"" << ser << "\"" << endl;
			}
			continue;
		}
		//��ָ����ʽ����vector<int>����
		series = newvectrans(ser);//newvectransΪstring��ת��Ϊvector�����飨string�и�ʽҪ��
		if (series == NULL)
		{
			cout << "Get wrong series from \"" << ser<<"\" or can't find the functon" << endl;
		}
		else if ((int)series->size() == 0)
		{
			cout << "series->size()Ϊ0,���г��������Ϊ��" << endl;
		}
		else
		{
			for (unsigned int i = 0; i < series->size(); i++)
			{			
				//if ((*series)[i] > sizeof(pf) / 4) {
				//	cout << "���г����ų�������ָ�����鷶Χ" << endl;
				//	break;
				//}
				cout << "Try to run number:" << (*series)[i] << endl;
				if (!ExecAddf((*series)[i])) {
					cout << "Run error!" << endl;
				}
				else {
					cout << "Finish number:" << (*series)[i] << endl;
				}
				
			}
		}
		delete series;
		series = NULL;
	}
	cout<<"\n�������н���!"<<endl;
	system("pause");
	return 0;
}
