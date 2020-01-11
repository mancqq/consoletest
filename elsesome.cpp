#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include"elsesome.h"

std::vector<int> *newvectrans(std::string a)//string类转化为vector类数组（string有格式要求）
{
	try
	{
		std::string serr="";
		std::vector<int> *translate=new std::vector<int>;
		int t[]={0,0};
		int ti=0;
		for(unsigned int i=0;i<a.length();i++)
		{
			if(a[i]==(' '))
			{
				if(i==(a.length()-1))
				{
					if(ti==0)
					{
						translate->push_back(t[ti]);
						t[ti]=0;
					}
					else if(ti==1)
					{
						for(int j=t[0];j<=t[1];j++)
						{
							translate->push_back(j);

						}
						t[1]=0;
						t[0]=0;
						ti=0;
					}
				}
				else
				{
					continue;
				}
			}
			else if((('0')<=a[i])&&(a[i]<=('9')))
			{
				t[ti]=t[ti]*10+((int)(a[i]-'0'));
				if(i==(a.length()-1))
				{
					if(ti==0)
					{
						translate->push_back(t[ti]);
						t[ti]=0;
					}
					else if(ti==1)
					{
						for(int j=t[0];j<=t[1];j++)
						{
							translate->push_back(j);

						}
						t[1]=0;
						t[0]=0;
						ti=0;
					}
				}
			}
			else if(a[i]=='-')
			{
				if(ti==0)
					ti=1;
				else
				{
					delete translate;
					serr+="关于 - 符号使用错误,可能有两个 - 没有 , 分开使用";
					throw(serr);
				}
			}
			else if(a[i]==',')
			{
				if(ti==0)
				{
					translate->push_back(t[ti]);
					t[ti]=0;
				}
				else if(ti==1)
				{
					for(int j=t[0];j<=t[1];j++)
					{
						translate->push_back(j);
					
					}
					t[1]=0;
					t[0]=0;
					ti=0;
				}
				else
				{
					delete translate;
					serr+="- 符号前后压入出错,(ti!=0,ti!=1)";
					throw(serr);
				}
			}
			else
			{
				delete translate;
				serr+="字符串中只应有数字,逗号,短横号和尾字符\'\\0\'";
				throw(serr);
			}
		}
	
		return translate;
	}
	catch(std::string &ss)
	{
		std::cout<<ss<<std::endl;
		std::cerr<<"error for "<<ss<<std::endl;
		return NULL;
	}
}	


run::run():eyep(1,1,0),cenp(0,0,0)
{
	renew_lp();
	renew_dnow1();
	_dbefore1=_dnow1;
	renew_h1();
}
run::~run()
{
}
bool run::zzcanbepz(zpoint zz)//****************
{
	zpoint _zz_cenp=cenp-zz;
	double l1=_zz_cenp._longin(_lp);
	if(l1>0)
		return true;
	else
		return false;
}
zpoint run::zz_pz(zpoint zz)//over/**************
{
		zpoint pz;//***************
		zpoint _zz_cenp=cenp-zz;//****************
		double l1=_zz_cenp._longin(_lp);
		double l2=_lp._dlong();
		zpoint _cenp_pz;
		if(l1!=0)
		{
			_cenp_pz=_zz_cenp*(l2/l1);
		}
		else
		{
			std::cout<<"视觉边界,投影不到"<<std::endl;
		}
		pz=_cenp_pz+cenp;//***********
		return pz;
	//}

}
CPoint run::pz_pp(zpoint pz)//over//******************
{
	CPoint pp(0,0);//***************
	zpoint _eyep_pz;
	_eyep_pz=pz-eyep;//**********************
	std::cout<<zpout(_eyep_pz)<<std::endl
		<<zpout(_lp)<<std::endl
		<<"_eyep_pz*_lp="<<_eyep_pz*_lp<<std::endl;
	if(abs(_eyep_pz*_lp)<0.0000000001)
	{
		if(_eyep_pz._longin(_dnow1)>0)
		{
			pp.x=(int)(_eyep_pz._longin(_dnow1)+0.5);
		}
		else if(_eyep_pz._longin(_dnow1)<0)
		{
			pp.x=(int)(_eyep_pz._longin(_dnow1)-0.5);
		}
		std::cout<<"_eyep_pz._longin(_h1)="<<_eyep_pz._longin(_h1)<<std::endl;
		if(_eyep_pz._longin(_h1)>0)
		{
			pp.y=(int)(_eyep_pz._longin(_h1)+0.5);//有误如果为正则+0.5,
		}
		else if(_eyep_pz._longin(_h1)<0)
		{
			pp.y=(int)(_eyep_pz._longin(_h1)-0.5);
		}
	}
	else
	{
		std::cout<<"pz_pp(zpoint pz)错误,参数不在输出面上"<<std::endl;
	}
	return pp;	
}
zpoint run::pp_pz(CPoint pp)//over
{

	zpoint pz;//***************
	zpoint _pz;
	_pz=_dnow1*pp.x+_h1*pp.y;
	pz=eyep+_pz;//*****************
	return pz;
	//}



}
zpoint run::renew_dnow1()//更新_dnow1 over
{
	if((_lp.x!=0.0)||(_lp.y!=0.0))
	{
		_dnow1.x=-_lp.y;
		_dnow1.y=_lp.x;
		_dnow1.z=0.0;
		_dnow1=_dnow1._unit_p();
		return _dnow1;
	}
	else
	{
		_dnow1=_dbefore1._unit_p();
		return _dnow1;
	}
	
}
zpoint run::renew_h1()//更新_h1 over//**************************
{
		_h1.x=_dnow1.y*_lp.z-_lp.y*_dnow1.z;
		_h1.y=_dnow1.z*_lp.x-_lp.z*_dnow1.x;
		_h1.z=_dnow1.x*_lp.y-_lp.x*_dnow1.y;
		_h1=_h1._unit_p();
		return _h1;
	
}
zpoint run::renew_lp()//更新_lp over
{
	_lp = eyep - cenp;//*****************
	return _lp;
}

void run::renew()
{
	renew_lp();
	_dbefore1=_dnow1;
	renew_dnow1();
	renew_h1();
}

