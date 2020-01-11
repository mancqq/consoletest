#pragma once
#include "stdafx.h"
#include<iostream>
#include "class.h"
char const *const fa::m_classname="fa";

fa::fa(char *c):m_fa_name(c),m_a(3)
{
	std::cout<<"构造fa()   "<<m_fa_name<<"*******************"<<std::endl;
}
fa::~fa()
{
	std::cout<<"****************kill ~fa()   "<<m_fa_name<<std::endl;
}
bool fa::fun(int a)
{
	
	std::cout<<"bool fa::fun() 多了个int a="<<a<<std::endl;
	return 1;
}
void fa::fun()
{

	std::cout<<"运行"<<m_fa_name<<".fun()"<<std::endl;
	std::cout<<m_fa_name<<"的常量数据成员m_a="<<m_a<<std::endl;
	//this指针是对象的指针，不是数据的指针，故this可调用所指向的对象的const数据成员
	
}
void fa::confun() const
{
	
	std::cout<<"运行"<<m_fa_name<<".confun()"<<std::endl;
}

sunx::sunx(char *c):m_sunx_name(c)
{
	//fa::fa();父类构造函数出现在子类构造函数中时,执行完父类构造函数还会执行父类析构函数
	m_xs.name="sunx";
	m_xs.pp=&(fa::m_s);
	std::cout<<"构造sunx() "<<m_sunx_name<<"*******************"<<std::endl;
}
sunx::~sunx()
{
	std::cout<<"****************kill ~sunx() "<<m_sunx_name<<std::endl;
}
void sunx::xfun()
{
	std::cout<<"运行"<<m_sunx_name<<".xfun()"<<std::endl;
}

suny::suny(char *c):m_suny_name(c)
{
	m_ys.name="suny";
	m_ys.pp=&(fa::m_s);
	std::cout<<"构造suny() "<<m_suny_name<<"*******************"<<std::endl;
}
suny::~suny()
{
	std::cout<<"****************kill ~suny() "<<m_suny_name<<std::endl;
}
void suny::yfun()
{
	std::cout<<"运行"<<m_suny_name<<".yfun()"<<std::endl;
}

ssun::ssun(char *c):m_ssun_name(c)
{
	m_sss.name="ssun";
	m_sss.pp=&(sunx::m_xs);
	std::cout<<"构造ssun() "<<m_ssun_name<<"*******************"<<std::endl;
}
ssun::~ssun()
{
	std::cout<<"****************kill ~ssun() "<<m_ssun_name<<std::endl;
}
void ssun::ssfun()
{
	std::cout<<"运行"<<m_ssun_name<<".ssfun()"<<std::endl;
}
zpoint::zpoint(double ax,double by,double cz):x(ax),y(by),z(cz)
{
}
zpoint::~zpoint()
{
}
zpoint::zpoint(const zpoint &a)
{
	x=a.x;
	y=a.y;
	z=a.z;
}
void zpoint::operator=(const zpoint &a) 
{
	x=a.x;
	y=a.y;
	z=a.z;
}
zpoint zpoint::operator+(const zpoint &a) const
{
	zpoint point;
	point.x=x+a.x;
	point.y=y+a.y;
	point.z=z+a.z;
	return point;
}
zpoint zpoint::operator+(double _d) const
{
	double l;
	l=_dlong()+_d;
	zpoint point;
	point=_unit_p()*l;
	return point;
}
zpoint zpoint::operator-(const zpoint &a) const
{
	zpoint point;
	point.x=x-a.x;
	point.y=y-a.y;
	point.z=z-a.z;
	return point;
}
zpoint zpoint::operator-(double _d) const
{
	double l;
	l=_dlong()-_d;
	zpoint point;
	point=_unit_p()*l;
	return point;
}
double zpoint::operator*(const zpoint& a) const
{
	double d;
	d=x*a.x+y*a.y+z*a.z;
	return d;
}
zpoint zpoint::operator*(double d) const
{
	zpoint point;
	point.x=x*d;
	point.y=y*d;
	point.z=z*d;
	return point;
}
zpoint zpoint::operator/(double d) const
{
	zpoint point;
	point.x=x/d;
	point.y=y/d;
	point.z=z/d;
	return point;
}
double zpoint::_dlong() const
{
	return sqrt((*this)*(*this));
}
double zpoint::dlong(const zpoint &a,const zpoint &b)
{
	zpoint _point;
	_point=b-a;
	return _point._dlong();
}
bool zpoint::_isvertical(const zpoint &_a)
{
	if((*this)*_a==0)
		return true;
	else
		return false;
}
bool zpoint::isvertical(const zpoint &_a,const zpoint &_b)
{
	if(_a*_b==0)
		return true;
	else
		return false;
}
zpoint zpoint::_unit_p() const
{
	zpoint _p;
	_p=(*this)/_dlong();
	return _p;
}
zpoint zpoint::unit_p(const zpoint &a,const zpoint &b)//*******************
{
	zpoint _p=(b-a);
	return _p._unit_p();//**************
}
zpoint zpoint::p_p(const zpoint &a) const//*******************
{
	zpoint point;
	point=(a*2-(*this));//*********
	return point;
}
zpoint zpoint::p_p(const zpoint &a,const zpoint &b)
{
	return a.p_p(b);
}
double zpoint::_longin(const zpoint &_a)
{
	return (*this)*_a._unit_p();
}
double zpoint::_longin(const zpoint &a,zpoint &b)
{
	zpoint _p=b-a;
	return _longin(_p);
}
zpoint zpoint::_pin(const zpoint &_a)
{
	double lg=_longin(_a);
	return _a._unit_p()*lg;
}
zpoint zpoint::_pin(const zpoint &a,zpoint &b)
{
	zpoint _p=b-a;
	return _pin(_p);
}
double zpoint::_cosv(const zpoint &_a) const
{
	double data;
	data=(*this)*_a;
	double cosv=data/(_dlong()*_a._dlong());
	return cosv;
}
double zpoint::cosv(const zpoint &_a,const zpoint &_b)
{
	return _a._cosv(_b);
}



//void zpoint::Serialize(CArchive &ar)
//{
//	if(ar.IsStoring())
//	{
//		ar<<x<<y<<z;
//	}
//	else
//	{
//		ar>>x>>y>>z;
//	}
//}
//void zline::Serialize(CArchive &ar)
//{
//	pointa.Serialize(ar);
//	pointb.Serialize(ar);
//	//pena.Serialize(ar);
//
CPoint::CPoint(int a,int b):x(a),y(b)
{
}
