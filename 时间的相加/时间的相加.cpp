// 时间的相加.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Ctime
{
public:
	int shi;
	int fen;
	int miao;
	Ctime operator +(Ctime &oc1);
	void setvalue(int a, int b, int c);
	void display();
};
Ctime Ctime::operator + (Ctime & oc1) 
{
	Ctime temp;
	temp.setvalue(shi + oc1.shi, fen + oc1.fen, miao + oc1.miao);
	return temp;
}
void Ctime::display()
{
	if (miao == 60)
	{
		fen = fen + 1;
		miao = 0;
	}
	else if (miao > 0)
	{
		miao = miao - miao * (miao / 60);
		fen = fen + miao / 60;
	}
	 if (fen == 60)
	{
		fen = 0;
		shi = shi + 1;
	}
	else if (fen > 60)
	{
		fen = fen - fen * (fen / 60);
		shi = shi + 1;
	}
	
	cout << shi<<"小时" << fen <<"分钟"<< miao<<"秒" << endl;
};
void Ctime::setvalue(int a, int b, int c)
{
	shi = a;
	fen = b;
	miao = c;
};

int main()
{
	Ctime A, B, C;
	A.setvalue(26, 22, 6);
	B.setvalue(2, 37, 54);
	C = A + B;
	C.display();
    return 0;
}

