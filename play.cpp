#include "stdafx.h"
#include<iostream>
#include "play.h"
#include "class.h"
#include"elsesome.h"
#include<math.h>
#include "func.h"
#include <Windows.h>
#include <winbase.h>
using namespace std;
DWORD WINAPI cls(LPVOID)
{
	Sleep(1);
	system("cls");
	return 1;
}
void play()
{
	HANDLE hThread = CreateThread(NULL, 0, cls, 0, true, 0);
	CloseHandle(hThread);
}
ADDF(play);
void play1()//������
{
	create(fa,fa1);
	create(sunx,sunx1);
	create(suny,suny1);
	create(ssun,ssun1);
	
}
ADDF(play1);
void play2()
{
	fa fa2("fa2");
	fa2.m_b=222;
	void (fa::*pf)();
	const int fa::*p;
	p=&fa::m_a;
	pf=&fa::fun;
	cout<<"fa2.*p=fa2.m_a="<<fa2.*p<<"(fa2.*pf)()->fa2.fun()���н��"<<endl;
	(fa2.*pf)();

}
ADDF(play2);
void play3()//��Ӧ��
{
	const create(fa,fa3);
	fa3.confun();
	//fa3.fun();
	// �˾��������Ǵ���ģ�fa3��const(����)���󣬳���������ó�Ա����ֻ�ܵ���
	//���ڵĳ���Ա����,��Ϊconst(����)����ֻ�ó���thisָ�룬��ֻ�ܱ������������ա�

	//fa3.m_b=98;   �˾��������Ǵ���ģ��������õ��ǳ�ָ�룬����õ����ݳ�Ա���ɸ��ġ�
	cout<<"����������÷ǳ������ݳ�Աfa3.m_b="<<fa3.m_b<<endl;
	cout<<"����������ó������ݳ�Աfa3.m_a="<<fa3.m_a<<endl<<endl;
	//������ɵ����������ݳ�Ա�������ɸ������ǡ�

	create(fa,fa31);
	cout<<"��ͨ������÷ǳ������ݳ�Աfa31.m_b="<<fa31.m_b<<endl;
	cout<<"��ͨ������ó������ݳ�Աfa31.m_a="<<fa31.m_a<<endl;
	//��ͨ������Ե������⹲�У�������ǳ��������ݳ�Ա�ͳ�Ա����
}
ADDF(play3);
void play4()
{
	create(fa,fa4);
	fa4.fun();
}
ADDF(play4);
void play5()  //��̬���鴴������Ԫ�ظ���������
{	
	int v=0;
	cout<<"�����봴����̬����Ԫ�ظ���"<<endl;
	cin>>v;
	newarry(a,v);//��̬�����һά����Ϊ��������̬���鲻����sizeof()����
	for(int i=0;i<v;i++)
	{
		cout<<"������a["<<i<<"]"<<endl;
		cin>>a[i];
	}
	cout<<"���a[]����Ԫ��"<<endl;
	for(int i=0;i<v;i++)
	{
		if(i!=0)
			cout<<","<<a[i];
		else
			cout<<a[i];
	}
	delarry(a);
	cout<<endl;
}
ADDF(play5);
void play6()
{
	fa fa6("3");
	cout<<"���"<<endl;
}
ADDF(play6);
void play7()//zpoint����Ӧ��
{
	zpoint px(1, 0, 0);
	zpoint py(0, 1, 0);
	zpoint pz(0, 0, 1);
	zpoint cenp(0, 0, 0);
	zpoint eyep(10, 10, 0);
	zpoint point(-1, 0, 0);


	run runa;
	runa.cenp = cenp;
	runa.eyep = eyep;
	runa.renew();// �������


	CPoint pp(-14, -1);
	cout << zpout(runa.pp_pz(pp)) << endl;

}
ADDF(play7);
void play8()//vetorӦ��
{
	vector<int> a;
	a.push_back(1);
	a.push_back(9);
	cout<<a[0]<<","<<a[1]<<"\nsize="<<a.size()<<",capacity="<<a.capacity()<<endl;
}
ADDF(play8);
void play9()//zpoint����Ӧ��
{
	zpoint _a(1,0,0);
	zpoint _b(-1,-1,0);
	cout<<_a._cosv(_b)<<endl;
	cout<<cosh(_a._cosv(_b))<<endl;
	cout<<acos(_a._cosv(_b))<<endl;//����0-�м��arccos()ֵ
}
ADDF(play9);
void play10()
{    
}
ADDF(play10);
template<class T,int b>//ģ�溯��
void some(const T (&a)[b])
{
	for(int i=0;i<b;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<"ok"<<endl;
}

void play11()
{
	double a[3]={1.2,265.965,56.66};
	some(a);
	cout<<"over"<<endl;
}
ADDF(play11);
void play12()
{
	GetCurrentDirectory(60,cCurrPath);
	cout << cCurrPath << end;

}
ADDF(play12);
void play13()
{
	
}
ADDF(play13);
void play14()
{
	

}
ADDF(play14);
void play15()
{

}
ADDF(play15);
void play16()
{

}
ADDF(play16);
void play17()
{

}
ADDF(play17);
void play18()
{

}
ADDF(play18);
void play19()
{

}
ADDF(play19);