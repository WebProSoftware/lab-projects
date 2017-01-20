#pragma once
#include "PRACOWNIK.h"
class SPRZEDAWCA :
	public virtual PRACOWNIK
{
	int procent;
	int sprzedaz;
	double pensja_sprzedawca;

public:
	SPRZEDAWCA() {};
	SPRZEDAWCA(pracownicy list, int sprze = 0, int proc = 15);
	void setSprzedaz(int sprzz) { this->sprzedaz = sprzz; }
	void setProcent(int proc) { this->procent = proc; }

	int getProcent() { return this->procent; }
	int getSprzedaz() { return this->sprzedaz; }

	double getPensjaSzprzedawna();
	void wyswietlPensje();	
};

