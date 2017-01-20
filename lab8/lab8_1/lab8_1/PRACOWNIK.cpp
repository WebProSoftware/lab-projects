#include "stdafx.h"
#include "PRACOWNIK.h"


PRACOWNIK::PRACOWNIK()	
{	
	godziny = 0;	
	stawka_nagodzine = 12.0; // minimalna stawka domyslna	
	pensja = 0.0;	
}

void PRACOWNIK::setPracownik(pracownicy p1, int liczba_godzin, double stawka)
{
	this->setPersonel(p1);
	this->setGodziny(liczba_godzin);
	this->setStawka(stawka);
	this->setPensja();
}

void PRACOWNIK::setGodziny(int liczba_godzin)
{
	this->godziny = liczba_godzin;
}

void PRACOWNIK::setStawka(int stawka)
{
	this->stawka_nagodzine = stawka;
}

void PRACOWNIK::setPensja()
{
	this->pensja = this->oblicz_pensje(this->godziny, this->stawka_nagodzine);
}

double PRACOWNIK::getPensja()
{
	return this->pensja;
}

double PRACOWNIK::oblicz_pensje(int godz, double sstawka)
{
	return godz * sstawka;
}

void PRACOWNIK::wyswietlPensje()
{
	system("cls");
	PERSONEL::wyswietlPracownika();
	cout << "W tym miesiacu zarobil : " << this->pensja << endl;
}

PRACOWNIK::~PRACOWNIK()
{
}
