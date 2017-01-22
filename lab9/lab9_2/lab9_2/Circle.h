#pragma once
#include "Figura.h"

#include <iostream>
using namespace std;

class Circle :
	public Figura
{
	double *dat;
	const double PI = 3.14;
public:
	Circle(){ dat = NULL; }
	Circle(int rr);
	~Circle();
	void disp();
	void area();
};

