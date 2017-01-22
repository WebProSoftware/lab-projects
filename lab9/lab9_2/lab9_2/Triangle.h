#pragma once
#include "Figura.h"

#include <iostream>
using namespace std;

class Triangle :
	public Figura
{
	double *dat;
public:
	Triangle(){ dat = NULL; }
	Triangle(int aa, int hh);
	void disp();
	void area();
	~Triangle();
};

