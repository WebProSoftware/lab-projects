/*
Laboratorum 2
Zadanie laboratoryjne nr 2
@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class my_vol
{
	double result;
	double a, b, c;
public:
	my_vol();
	my_vol(double aa, double bb, double cc);
	void oblicz();
	void disp();
};

my_vol::my_vol()
{
	this->a = 1.0;
	this->b = 1.0;
	this->c = 1.0;
}

my_vol::my_vol(double aa, double bb, double cc)
{
	this->a = aa;
	this->b = bb;
	this->c = cc;
}

void my_vol::oblicz() 
{
	this->result = this->a * this->b * this->c;
}

void my_vol::disp()
{
	cout << "Wartosci" << endl;
	cout << "a = " << this->a << endl;
	cout << "b = " << this->b << endl;
	cout << "c = " << this->c << endl;
	cout << "V = a*b*c = " << this->result << endl;
}

int main()
{
	my_vol v1(1.0, 2.0, 3.0);
	v1.oblicz();
	v1.disp();

	system("pause");
    return 0;
}

