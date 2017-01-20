#pragma once
#include "PERSONEL.h"

class DYREKTOR : 
	public virtual PERSONEL
{
	double pensja = 6000;
	int premia; // stala premia moze ona uledz zmianie
	int liczba_pracownikow;

public:
	DYREKTOR() { this->liczba_pracownikow = 0; this->premia = 0; }
	DYREKTOR(pracownicy dyre, int licz_prac, int premia_za_pracownika = 100);

	double oblicz_pensje(int ile_prac);

	void wyswietlPensje();
	void setPremia(int premiaa) { this->premia = premiaa; }
	void setLiczaPracownikow(int licz_prac) { this->liczba_pracownikow = licz_prac; }

	int getPremia() { return this->premia;  }
	int getLiczbaPracownikow() { return this->liczba_pracownikow; }
	double getPensjaDyrektor() { return this->pensja; }
};


