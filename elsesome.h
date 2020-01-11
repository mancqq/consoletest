#pragma once
#include"stdafx.h"
#include<vector>
#include"class.h"
#include<iostream>
std::vector<int> *newvectrans(std::string a);
#define zpout(point) \
	#point<<":("<<(point).x<<","<<(point).y<<","<<(point).z<<")"

#define ppout(point) \
#point<<":("<<(point).x<<","<<(point).y<<")"

class run
{
public:
	run();
	~run();
	zpoint eyep;
	zpoint cenp;

	zline l;
	CPoint pbefore,pnow;
	zpoint _lp,_dbefore1,_dnow1,_h1;
	//CRect rect;//显示条件窗口
	bool adown;

	bool zzcanbepz(zpoint zz);//over***********************
	zpoint zz_pz(zpoint zz);//over************************
	CPoint pz_pp(zpoint pz);//over************************
	zpoint pp_pz(CPoint pp);//over
	zpoint renew_dnow1();
	zpoint renew_h1();//over************************
	zpoint renew_lp();
	void renew();
};


