#include "stdafx.h"
#include "SPRZEDAWCA.h"

SPRZEDAWCA::SPRZEDAWCA(pracownicy list, int sprze, int proc)
{
	PERSONEL::setPersonel(list);
	PRACOWNIK::setGodziny(180); // okolo jednego miesiaca 8h /5dni
	PRACOWNIK::setStawka(40);
	PRACOWNIK::setPensja();

	this->procent = proc;
	this->sprzedaz = sprze;
	this->pensja_sprzedawca = this->getPensjaSzprzedawna();
}

double SPRZEDAWCA::getPensjaSzprzedawna()
{
	return PRACOWNIK::getPensja() + ((this->sprzedaz * this->procent) / 100);
}

void SPRZEDAWCA::wyswietlPensje()
{
	system("cls");
	PERSONEL::wyswietlPracownika();
	cout << "W tym miesiacu zarobil : " << this->pensja_sprzedawca << endl;
}
