// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NodCoord.h"
#include "Trojkat.h"

#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
using namespace std;

int main()
{
	cout.precision(3);

	//Zadanie 1 ------
	cout << "******Zadanie 1******" << endl;
	CNodCoord a(2.3, 4.2, 5.1, 1);
	a.Disp();
	system("pause");

	//Zadanie 2 ------
	cout << "******Zadanie 2******" << endl;
	CNodCoord *b;
	try
	{
		b = new CNodCoord();
	}
	catch (bad_alloc)
	{
		cout << "error alloc memory\n" << endl;
		system("pause");
		exit(1);
	}
	b->SetCoord(6.3, 2.4, 12.5, 2);
	b->Disp();
	delete b;
	b = NULL;
	system("pause");

	//Zadanie 3 -------
	cout << "******Zadanie 3******" << endl;
	static CNodCoord tab[3];
	tab[0] = CNodCoord();
	tab[1] = CNodCoord(1.0, 2.0, 0.0, 1);
	tab[2] = CNodCoord(3.0, 2.0, 0.0, 2);

	for (int i = 0; i < size(tab); i++)
	{
		tab[i].Disp();
	}
	system("pause");

	//Zadanie 4 ---------
	cout << "******Zadanie 4-5******" << endl;
	CNodCoord startKola(0,0,0,0);
	int n;
	double r;
	double fi;
	double pointX;
	double pointY;
	bool OnOff = true;

	cout << "Podaj promen okregu o wspolrzednych srodka (0,0,0)" << endl;
	//walidacja promenia R
	while (OnOff)
	{
		cin >> r;
		cout << "Podaj ilosc punktów " << endl;
		cin >> n;
		if (r > 0 && n > 0)
		{
			OnOff = false;
		}
		else
		{
				cout << "liczba musi byc wieksza od 0" << endl;			
		}
	}
	
	CNodCoord * list = new CNodCoord[n];
	int i = 0;
	for (int x = 1; x <= n; x++)
	{
		fi = 2 * M_PI * (x-1)/n;
		pointX = r * cos(fi) + 0; // 0 to x - kola
		pointY = r * sin(fi) + 0; // 0 to y - kola

		CNodCoord *temp = new CNodCoord(pointX, pointY, 0.0, i+1);
		list[i].SetCoord(temp);
		delete temp;
		i++;
	}
	system("pause");

	//Zadanie 5 --------
	for (int i = 0; i < n; i++)
	{
		cout << "Obiekt nr:" << i+1 << endl;
		CNodCoord *ob = &list[i].GetCoord();
		ob->Disp();
	}
	delete[] list;
	list = NULL;
	cout << endl;
	system("pause");

	//Zadanie 6 --------
	cout << "******Zadanie 6*******" << endl;
	//Trojkat posiadajacy konstruktor dziedziczacy po klasie CNoodCoord
	CTrojkat tr(CNodCoord(1,2,3,1), CNodCoord(2,3,4,2) , CNodCoord(3,4,5,3));
	tr.disp();

	//inny konstruktor
	CNodCoord * trojkat = new CNodCoord[3];
	for (i = 0; i < 3; i++)
	{
		trojkat[i].SetCoord((rand() % 100), (rand() % 40), (rand() % 10), i + 1);
	}

	CTrojkat tr2(trojkat);
	tr2.disp();

	system("pause");
    return 0;
}

