// lab9_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Figura
{
public:
	static int alloc;
protected:
	double s;
public:
	Figura(){ Figura::alloc++; }
	virtual void area() = 0;
	virtual void disp() = 0;
};

class Rectangle :
	public Figura
{
	double *dat;
public:
	Rectangle();
	~Rectangle();
	Rectangle(int aa, int bb);

};

Rectangle::Rectangle()
{
	try
	{
		this->dat = new double[2];
		this->dat[0] = 1;
		this->dat[1] = 2;

	}
	catch (bad_alloc)
	{
		cout << "Bad alloc" << endl;
		exit(1);
	}
}

int main()
{

	Figura *prt, *prt_rect;


	system("pause");
     return 0;
}

