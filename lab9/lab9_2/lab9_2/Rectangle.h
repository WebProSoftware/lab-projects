#pragma once
#include "Figura.h"

#include <iostream>
using namespace std;

class Rectangle :
	public Figura
{
	double *dat;
public:
	Rectangle() { dat = NULL; };
	Rectangle(int aa, int bb);
	~Rectangle();
	void area();
	void disp();
};

