/*
Laboratorum 1
Zadanie laboratoryjne nr 8

@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int var_switch;
int a, b;

void setABInterface()
{
	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "Wynik to:";
}

int main()
{
	cout << "Kalkulator" << endl << endl;
	cout << "1.Dodawanie\t2.Odejmowanie\t3.Mnozenie\t4.Dzielenie\n";
	cout << "Podaj liczbe: ";
	cin >> var_switch;
	cout << endl << endl;
	switch (var_switch)
	{
	case 1:
		setABInterface();
		cout << a + b << endl;
		break;
	case 2:
		setABInterface();
		cout << a - b << endl;
		break;
	case 3:
		setABInterface();
		cout << a * b << endl;
		break;
	case 4:
		setABInterface();
		if (b == 0)
		{
			cout << " jest niemozliwy" << endl;
		}
		else
		{
			cout << (double) a / b << endl;
		}
		break;
	default:
		cout << "Nie ma takie obslugi\nProgram zostanie zamkniety\n";
		break;
	}

	cout << endl;
 	system("pause");
    return 0;
}

