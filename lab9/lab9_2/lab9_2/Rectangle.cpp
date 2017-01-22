#include "stdafx.h"
#include "Rectangle.h"


Rectangle::Rectangle(int aa, int bb)
{
	try
	{
		this->dat = new double[2];
		this->dat[0] = aa;
		this->dat[1] = bb;
		Figura::alloc++;

	}
	catch (bad_alloc)
	{
		cout << "Bad alloc" << endl;
		exit(1);
	}
}

void Rectangle::area()
{
	this->s = dat[0] * dat[1];
}

void Rectangle::disp()
{
	cout << "Pole prostokat:" << this->s << endl;
}

Rectangle::~Rectangle()
{
	delete[] dat;
	dat = NULL;
	Figura::alloc--;
}
