#include "stdafx.h"
#include "Skoki.h"


Skoki::Skoki(string nazwa, double kV, int wygra, int idd) : Zaklad(nazwa,3,wygra,idd)
{
	this->kursV = kV;
}

Skoki::~Skoki()
{
}

string Skoki::getKursy()
{
	return string(to_string(this->kursV));
}

double Skoki::getKursWygranej()
{
	if (this->win != 1)
	{
		return this->kursV;
	}
	else
	{
		return 0.0;
	}
}

void Skoki::disp()
{
	cout << this->nazwa_typ(this->typ) << endl;
	cout << " Numer zakladu: " << this->id << endl;
	cout << " Nazwa: " << this->nazwa << endl;
	cout << " Zwyciestwo: " << this->kursV << endl;
	cout << " Wygral: " << this->nazwa_wygranej(this->win) << endl;
	cout << endl;
	cout << endl;
}
