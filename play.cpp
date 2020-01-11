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
void play1()//宏声明
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
	cout<<"fa2.*p=fa2.m_a="<<fa2.*p<<"(fa2.*pf)()->fa2.fun()运行结果"<<endl;
	(fa2.*pf)();

}
ADDF(play2);
void play3()//类应用
{
	const create(fa,fa3);
	fa3.confun();
	//fa3.fun();
	// 此句在这里是错误的，fa3是const(常量)对象，常量对象调用成员函数只能调用
	//类内的常成员函数,因为const(常量)对象只用常量this指针，其只能被常量函数接收。

	//fa3.m_b=98;   此句在这里是错误的，常对象用的是常指针，其调用的数据成员不可更改。
	cout<<"常量对象调用非常量数据成员fa3.m_b="<<fa3.m_b<<endl;
	cout<<"常量对象调用常量数据成员fa3.m_a="<<fa3.m_a<<endl<<endl;
	//常对象可调用任意数据成员，但不可更改他们。

	create(fa,fa31);
	cout<<"普通对象调用非常量数据成员fa31.m_b="<<fa31.m_b<<endl;
	cout<<"普通对象调用常量数据成员fa31.m_a="<<fa31.m_a<<endl;
	//普通对象可以调用任意共有（常量或非常量）数据成员和成员函数
}
ADDF(play3);
void play4()
{
	create(fa,fa4);
	fa4.fun();
}
ADDF(play4);
void play5()  //动态数组创建任意元素个数的数组
{	
	int v=0;
	cout<<"请输入创建动态数组元素个数"<<endl;
	cin>>v;
	newarry(a,v);//动态数组第一维不必为常数，动态数组不能用sizeof()函数
	for(int i=0;i<v;i++)
	{
		cout<<"请输入a["<<i<<"]"<<endl;
		cin>>a[i];
	}
	cout<<"输出a[]所有元素"<<endl;
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
	cout<<"你好"<<endl;
}
ADDF(play6);
void play7()//zpoint测试应用
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
	runa.renew();// 必须语句


	CPoint pp(-14, -1);
	cout << zpout(runa.pp_pz(pp)) << endl;

}
ADDF(play7);
void play8()//vetor应用
{
	vector<int> a;
	a.push_back(1);
	a.push_back(9);
	cout<<a[0]<<","<<a[1]<<"\nsize="<<a.size()<<",capacity="<<a.capacity()<<endl;
}
ADDF(play8);
void play9()//zpoint测试应用
{
	zpoint _a(1,0,0);
	zpoint _b(-1,-1,0);
	cout<<_a._cosv(_b)<<endl;
	cout<<cosh(_a._cosv(_b))<<endl;
	cout<<acos(_a._cosv(_b))<<endl;//返回0-π间的arccos()值
}
ADDF(play9);
void play10()
{    
}
ADDF(play10);
template<class T,int b>//模版函数
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