/*
Laboratorum 3
Zadanie laboratoryjne nr 1
@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class KOLO
{
	float r;
	int color;
public:
	KOLO() { r = 1.3; color = 1; }
	KOLO(float rr, int ccolor);
	float oblicz();
	void set_r(float rr);
	void set_color(int ccolor);
	friend void porownaj(KOLO &k1, KOLO &k2);
};

KOLO::KOLO(float rr, int ccolor)
{
	this->r = rr;
	this->color = ccolor;
}

float KOLO::oblicz()
{
	return (float)(3.14 * pow(this->r, 2));
}

void KOLO::set_r(float rr)
{
	this->r = rr;
}

void KOLO::set_color(int ccolor)
{
	this->color = ccolor;
}

void porownaj(KOLO &k1, KOLO &k2)
{
	float kolo1 = k1.oblicz();
	float kolo2 = k2.oblicz();

	cout << endl << endl;
	if (kolo1 < kolo2)
	{
		cout << "Pole kola 2 jest wieksze" << endl;
	}
	else if (kolo1 == kolo2)
	{
		cout << "Pola sa rowne" << endl;
	}
	else 
	{
		cout << "Pole kola 2 jest mniejsze od 1" << endl;
	}

	cout << "Kolo 1: " << kolo1 << " Kolo 2: " << kolo2 << endl;

	if (k1.color == k2.color)
	{
		cout << "kolory sa takie same" << endl;
	}
	else
	{
		cout << "kolor sa rozne" << endl;
	}

	cout << "kolor kola 1: " << k1.color << " kolor kola 2: " << k2.color << endl;

}

int main()
{
	//inicjowanie obiektow kola 1,2
	KOLO k1;
	KOLO k2(4.2,2);

	//Porowanie wstêpne
	porownaj(k1, k2);

	//zmiana kolorow na taki sam
	k1.set_color(20);
	k2.set_color(20);

	//Porowanie nr 2
	porownaj(k1, k2);

	//zmiana promienai na taki sam
	k1.set_r(2.3);
	k2.set_r(2.3);

	//porownanie nr 3
	porownaj(k1, k2);

	system("pause");
    return 0;
}

