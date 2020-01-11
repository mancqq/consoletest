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
	fa(char *c="ĳ�����");
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
	sunx(char *c="ĳ�����");
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
	suny(char *c="ĳ�����");
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
	ssun(char *c="ĳ�����");
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
	double operator*(const zpoint &a) const;//�����������ĵ�˻�(��Ϊ����)
	zpoint operator*(double d) const;
	zpoint operator/(double d) const;

	double _dlong()const;
	// ����˵��ʾ�������ĳ���(����ֵ)over

	static double dlong(const zpoint &a,const zpoint &b);
	//���������ľ���(����ֵ)over
	
	bool _isvertical(const zpoint &_a);
	//�жϴ˵��ʾ����������һ���ʾ�������Ƿ�ֱover
	
	static bool isvertical(const zpoint &_a,const zpoint &_b);
	//�ж������ʾ������֮���Ƿ�ֱover
	
	zpoint _unit_p() const;
	//���ش˵��ʾ�����ĵ�λ����over
	
	static zpoint unit_p(const zpoint &a,const zpoint &b);
	//��������ab�ĵ�λ����//**********over
	
	zpoint p_p(const zpoint &a) const;
	//���ش˵���ڵ�a�ĶԳƵ�//*******over
	
	static zpoint p_p(const zpoint &a,const zpoint &b);
	//����a�����b��ĶԳƵ�over
	
	double _longin(const zpoint &_a);//over
	double _longin(const zpoint &a,zpoint &b);
	    //���ش˵��ʾ��������һ�����ϵ�ͶӰ����(ͬ����,����,��ֱΪ0)


	zpoint _pin(const zpoint &_a);//��-0�������over
	zpoint _pin(const zpoint &a,zpoint &b);//��-0�������over
	    //���ش˵��ʾ����
	double _cosv(const zpoint &_a) const;//���ش�������
	//_a֮��ĽǶȵ�λ(��)


	static double cosv(const zpoint &_a,const zpoint &_b);
	//����_a��_b֮��ĽǶȵ�λ(��)

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
