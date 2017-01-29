#include "stdafx.h"
#include "Koszykarski.h"

Koszykarski::Koszykarski(string nazwa, double k1, double k2, int wygra, int idd) : Zaklad(nazwa, 2, wygra, idd)
{
	this->kurs1 = k1;
	this->kurs2 = k2;
}

Koszykarski::~Koszykarski()
{
}

string Koszykarski::getKursy()
{
	return string(to_string(this->kurs1)+" "+to_string(this->kurs2));
}

double Koszykarski::getKursWygranej()
{
	if (this->win != -1)
	{
		if (this->win == 1) {
			return this->kurs1;
		} else if (this->win == 2) {
			return this->kurs2;
		}
	}
	else {
		return 0.0;
	}
}

void Koszykarski::disp()
{
	cout << this->nazwa_typ(this->typ) << endl;
	cout << " Numer zakladu: " << this->id << endl;
	cout << " Nazwa: " << this->nazwa << endl;
	cout << " 1: " << this->kurs1 << endl;
	cout << " 2: " << this->kurs2 << endl;
	cout << " Wygral: " << this->nazwa_wygranej(this->win) << endl;
	cout << endl;
	cout << endl;
}
