#pragma once
#include "Zaklad.h"
class Koszykarski :
	public Zaklad
{
private:
	double kurs1;
	double kurs2;
public:
	Koszykarski() { this->typ = 2; }
	Koszykarski(string nazwa, double k1, double k2, int wygra, int idd);
	virtual ~Koszykarski();

	virtual string getKursy();
	virtual double getKursWygranej();
	virtual void disp();

};

