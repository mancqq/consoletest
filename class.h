#pragma once
#include "stdafx.h"
#include<iostream>
#define create(theclass,theobject) \
	theclass theobject(#theobject)
struct str
	{
		char *name;
		str *pp;
	};
class fa
{
	static const char *const m_classname;
public:
	//fa(int sd);
	fa(char *c="某类对象");
	~fa();
	virtual void confun() const;
	bool fun(int a);
	void fun();
	
	int m_b;
	/*const*/ int m_a;
	char *mp_c;
	str m_s;
protected:
	bool mb_l;
private:
	char *m_fa_name;
};
class sunx:virtual public fa
{
public:
	sunx(char *c="某类对象");
	~sunx();
	void xfun();
	char *m_psun;
	int m_sun_a,m_sun_b;
	str m_xs;
protected:
	bool m_sunx_b;
private:
	char *m_sunx_name;

};
class suny:virtual public fa
{
public:
	suny(char *c="某类对象");
	~suny();
	void yfun();
	int m_suny_a,m_suny_b;
	char *m_psuny;
	str m_ys;
protected:
	bool m_bol;
private:
	char *m_suny_name;
};
class ssun:public sunx,public suny
{
public:
	ssun(char *c="某类对象");
	~ssun();
	void ssfun();
	int m_ssun_a,m_ssun_b;
	char *m_pssun;
	str m_sss;
protected:
	bool m_ssunbol;
private:
	char *m_ssun_name;
};




class zpoint
{
public:
	zpoint(double ax=0.0,double by=0.0,double cz=0.0);
	~zpoint();
	zpoint(const zpoint &a);
	double x,y,z;
	void operator=(const zpoint &a);

	zpoint operator+(const zpoint &a) const;

	zpoint operator+(double _d) const;
	zpoint operator-(const zpoint &a) const;
	zpoint operator-(double _d) const;  	
	double operator*(const zpoint &a) const;//返回两向量的点乘积(可为负数)
	zpoint operator*(double d) const;
	zpoint operator/(double d) const;

	double _dlong()const;
	// 计算此点表示的向量的长度(绝对值)over

	static double dlong(const zpoint &a,const zpoint &b);
	//计算两点间的距离(绝对值)over
	
	bool _isvertical(const zpoint &_a);
	//判断此点表示的向量与另一点表示的向量是否垂直over
	
	static bool isvertical(const zpoint &_a,const zpoint &_b);
	//判断两点表示的向量之间是否垂直over
	
	zpoint _unit_p() const;
	//返回此点表示向量的单位向量over
	
	static zpoint unit_p(const zpoint &a,const zpoint &b);
	//返回向量ab的单位向量//**********over
	
	zpoint p_p(const zpoint &a) const;
	//返回此点关于点a的对称点//*******over
	
	static zpoint p_p(const zpoint &a,const zpoint &b);
	//返回a点关于b点的对称点over
	
	double _longin(const zpoint &_a);//over
	double _longin(const zpoint &a,zpoint &b);
	    //返回此点表示向量在另一向量上的投影长度(同向正,异向负,垂直为0)


	zpoint _pin(const zpoint &_a);//有-0情况发生over
	zpoint _pin(const zpoint &a,zpoint &b);//有-0情况发生over
	    //返回此点表示向量
	double _cosv(const zpoint &_a) const;//返回此向量与
	//_a之间的角度单位(π)


	static double cosv(const zpoint &_a,const zpoint &_b);
	//返回_a与_b之间的角度单位(π)

	//virtual void Serialize(CArchive &ar);//**********************
	
};
class zline
{
public:
	zpoint pointa;
	zpoint pointb;
	//CPen pena;
	//virtual void Serialize(CArchive &ar);//*******************
};

class CPoint
{
public:
	CPoint(int a=0,int b=0);
	int x,y;
};
