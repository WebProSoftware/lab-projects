#pragma once
#include "Zaklad.h"

#include <iostream>
#include <string>
using namespace std;


class Pilkarski :
	public Zaklad
{
private:
	double kurs1;
	double kursx;
	double kurs2;

public:
	Pilkarski(string nazwa, double k1, double kx, double k2, int wygra, int idd);
	virtual ~Pilkarski();

	virtual string getKursy();
	virtual double getKursWygranej();
	virtual void disp();

};

