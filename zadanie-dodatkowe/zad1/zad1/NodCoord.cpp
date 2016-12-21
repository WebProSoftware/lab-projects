#include "stdafx.h"
#include "NodCoord.h"

#include <iostream>
using namespace std;

CNodCoord::CNodCoord(double xx, double yy, double zz, double n)
{
	this->x = xx;
	this->y = yy;
	this->z = zz;
	this->numb = n;
}

CNodCoord CNodCoord::GetCoord()
{
	CNodCoord ob(x, y, z, numb);
	return ob;
}

void CNodCoord::SetCoord(double xx, double yy, double zz, double n)
{
	this->x = xx;
	this->y = yy;
	this->z = zz;
	this->numb = n;
}

void CNodCoord::SetCoord(CNodCoord *ob)
{
	this->x = ob->x;
	this->y = ob->y;
	this->z = ob->z;
	this->numb = ob->numb;
}

void CNodCoord::Disp()
{
	cout << "_______________" << endl;
	cout << " x = " << x << endl;
	cout << " y = " << y << endl;
	cout << " z = " << z << endl;
	cout << " numb = " << numb << endl;
	cout << "_______________" << endl;
}

CNodCoord::~CNodCoord()
{
}
