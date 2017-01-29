#include "stdafx.h"
#include "Pilkarski.h"


Pilkarski::Pilkarski(string nazwa, double k1, double kx, double k2, int wygra, int idd) : Zaklad(nazwa, 1, wygra, idd)
{
	this->kurs1 = k1;
	this->kursx = kx;
	this->kurs2 = k2;
}


Pilkarski::~Pilkarski()
{
}


string Pilkarski::getKursy()
{
	return string(to_string(this->kurs1) + " " + to_string(this->kursx) + " " + to_string(this->kurs2));
}

double Pilkarski::getKursWygranej()
{
	if (this->win != -1)
	{
		if (this->win == 1){
			return this->kurs1;
		} else if (this->win == 0){
			return this->kursx;
		} else if (this->win == 2){
			return this->kurs2;
		}
	}
	else{
		return 0.0;
	}
}

void Pilkarski::disp()
{
	cout << this->nazwa_typ(this->typ) << endl;
	cout << " Numer zakladu: " << this->id << endl;
	cout << " Nazwa: " << this->nazwa << endl;
	cout << " 1: " << this->kurs1 << endl;
	cout << " X: " << this->kursx << endl;
	cout << " 2: " << this->kurs2 << endl;
	cout << " Wygral: " << this->nazwa_wygranej(this->win) << endl;
	cout << endl;
	cout << endl;
}
