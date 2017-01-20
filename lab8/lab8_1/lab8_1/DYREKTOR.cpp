#include "stdafx.h"
#include "DYREKTOR.h"


DYREKTOR::DYREKTOR(pracownicy dyre, int licz_prac, int premia_za_pracownika)
{
	PERSONEL::setPersonel(dyre);
	this->liczba_pracownikow = licz_prac;
	this->premia = premia_za_pracownika;
	this->pensja += oblicz_pensje(this->liczba_pracownikow);
}

double DYREKTOR::oblicz_pensje(int ile_prac)
{
	return ile_prac * this->premia;
}

void DYREKTOR::wyswietlPensje()
{
	system("cls");
	PERSONEL::wyswietlPracownika();
	cout << "W tym miesiacu zarobil : " << this->pensja << endl;
}

