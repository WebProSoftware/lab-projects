#include "stdafx.h"
#include "Circle.h"


Circle::Circle(int rr)
{
	try
	{
		this->dat = new double[1];
		this->dat[0] = rr;
	}
	catch (bad_alloc)
	{
		cout << "bad alloc memory \n";
		exit(1);
	}
}

void Circle::area()
{
	this->s = this->PI * this->dat[0] * this->dat[0];
}

void Circle::disp()
{
	cout << "Pole kola: " << this->s << endl;
}

Circle::~Circle()
{
	delete[] dat;
	dat = NULL;

}
