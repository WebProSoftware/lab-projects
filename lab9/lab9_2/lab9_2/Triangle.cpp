#include "stdafx.h"
#include "Triangle.h"


Triangle::Triangle(int aa, int hh)
{
	try
	{
		this->dat = new double[2];
		this->dat[0] = aa;
		this->dat[1] = hh;
	}
	catch (bad_alloc)
	{
		cout << "bad alloc memory \n";
		exit(1);
	}
}

void Triangle::area()
{
	this->s = (dat[0] / 2)*dat[1];
}

void Triangle::disp()
{
	cout << "Pole trojkata: " << this->s << endl;
}

Triangle::~Triangle()
{
	delete[] dat;
	dat = NULL;
}
