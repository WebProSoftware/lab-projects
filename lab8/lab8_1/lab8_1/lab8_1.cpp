// lab8_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PERSONEL.h"
#include "PRACOWNIK.h"
#include "DYREKTOR.h"
#include "SPRZEDAWCA.h"

#include "DYREKTOR_HANDL.h"

#include <iostream>
#include <string>
using namespace std;


void showNumber(pracownicy pracownik)
{
	cout << "\nTelefon dla pracownika: " << pracownik.telefon << endl;
}

int main()
{
	int cin_controller;

	pracownicy listapracownikow[4];
	for (int i = 0; i < 4; i++)
	{
		listapracownikow[i].nazwisko = "nazwisko" + to_string(i+1);
		listapracownikow[i].biuro = i + 1;
		listapracownikow[i].telefon = rand() % 999999999 + 500000000;
		listapracownikow[i].stanowisko = i;
	}

	cout << "Wprowadz numer pokoju [1 - 4]" << endl;
	cin >> cin_controller;

	if (cin_controller > 0 && cin_controller < 5)
	{
		showNumber(listapracownikow[cin_controller - 1]);

		//wybrany pracownik przez nr pokoju
		pracownicy prac = listapracownikow[cin_controller - 1];

		if(prac.stanowisko == 0)
		{
			double stgodz;
			int godz;

			cout << "\n\nJEST TO PRACOWNIK FIRMY" << endl;
			cout << "Podaj stawke godzinowa z umowy" << endl;
			cin >> stgodz;
			cout << "Podaj ile godzin przepracowal" << endl;
			cin >> godz;

			PRACOWNIK prac1;
			prac1.setPracownik(prac, godz, stgodz);
			prac1.wyswietlPensje();
		}
		else if (prac.stanowisko == 1)
		{
			int kwota_zarobku;

			cout << "\n\nJEST TO HANDLOWIEC FIRMY" << endl;
			cout << "Podaj ile zarobil dla firmy w tym miesiacu" << endl;
			cin >> kwota_zarobku;
			cout << "Szef przypisal dla mniego 15%";

			SPRZEDAWCA sprzedawca(prac, kwota_zarobku);
			sprzedawca.wyswietlPensje();
		}

		else if (prac.stanowisko == 2)
		{
			int ilu;
			cout << "\n\nJEST TO DYREKTOR FIRMY" << endl;
			cout << "Podaj ilu ma pracownikow" << endl;
			cin >> ilu;
			
			DYREKTOR dyre1(prac, ilu, 240);
			dyre1.wyswietlPensje();
		}

		else if (prac.stanowisko == 3)
		{
			int ilu_prac;
			int ile_zarobil;

			cout << "\n\nJEST TO DYREKTOR HANLOWY FIRMY" << endl;
			cout << "Podaj ilu ma pracownikow" << endl;
			cin >> ilu_prac;
			cout << "Podaj ile zarobil dla firmy" << endl;
			cin >> ile_zarobil;

			DYREKTOR_HANDL dyr_handl(prac, ilu_prac, ile_zarobil);
			dyr_handl.wyswietlPensjeDyreHandl();

		}
	}

	else
	{
		cout << "nie mamy takiego biura" << endl;
		system("pause");
	}

	system("pause");
    return 0;
}

