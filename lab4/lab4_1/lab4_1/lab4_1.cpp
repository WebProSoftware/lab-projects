/*
Laboratorum 4
Zadanie laboratoryjne nr 1
@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class prostokat
{
	int dl, szer, id;
public:
	prostokat() { dl = 2; szer = 4; id = 1; }
	prostokat(int dd, int ssz, int idd);
	int get_dl();
	int get_szer();
	friend void czy_kwadrat(prostokat &prost);
};

prostokat::prostokat(int dd, int szz, int idd)
{
	this->dl = dd;
	this->szer = szz;
	this->id = idd;
}

int prostokat::get_dl()
{
	return this->dl;
}

int prostokat::get_szer()
{
	return this->szer;
}

void czy_kwadrat(prostokat &prost)
{
	if (prost.get_dl() == prost.get_szer())
	{
		cout << "ten prostokat jest kwadratem" << endl;
	}
	else
	{
		cout << "to dalej prostokat" << endl;
	}
}

int main()
{
	//inicjacja obiektow z konstrukorem bez parametrow
	prostokat p1;
	prostokat p2;

	//sprawdzenie czy jest to kwadrat
	czy_kwadrat(p1);
	czy_kwadrat(p2);

	//iniciowanie obiektow z kontruktorami sparametryzowanymi
	prostokat p3(2, 4, 5);
	prostokat p4(5, 5, 6);
	prostokat p5(6, 7, 8);

	//spawdzenie czy te obiekty to kwadraty
	czy_kwadrat(p3);
	czy_kwadrat(p4);
	czy_kwadrat(p5);

	system("pause");
    return 0;
}

