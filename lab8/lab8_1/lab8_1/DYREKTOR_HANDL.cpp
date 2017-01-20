#include "stdafx.h"
#include "DYREKTOR_HANDL.h"


DYREKTOR_HANDL::DYREKTOR_HANDL()
{
	this->pensja = 0.0;

}

DYREKTOR_HANDL::DYREKTOR_HANDL(pracownicy dyrehandl, int licz_prac, int zarobki, int za_pracownika , int procent_premi)
{
	//perosnel ustalenie dozsamosci
	PERSONEL::setPersonel(dyrehandl);

	//Pracownik czyli wyliczenie pensji 8h * 5h * 4 ~ 180h
	//Stawka 60
	PRACOWNIK::setGodziny(180); // okolo jednego miesiaca 8h /5dni
	PRACOWNIK::setStawka(60);
	PRACOWNIK::setPensja();

	DYREKTOR::setLiczaPracownikow(licz_prac);
	DYREKTOR::setPremia(za_pracownika);

	SPRZEDAWCA::setSprzedaz(zarobki);
	SPRZEDAWCA::setProcent(procent_premi);
	
	this->pensja = (PRACOWNIK::getPensja()) + (DYREKTOR::getLiczbaPracownikow() * DYREKTOR::getPremia()) + ((SPRZEDAWCA::getSprzedaz() * SPRZEDAWCA::getProcent()) / 100);
}

void DYREKTOR_HANDL::wyswietlPensjeDyreHandl()
{
	system("cls");
	PERSONEL::wyswietlPracownika();
	cout << "W tym miesiacu zarobil : " << this->pensja << endl;
}

DYREKTOR_HANDL::~DYREKTOR_HANDL()
{
}
