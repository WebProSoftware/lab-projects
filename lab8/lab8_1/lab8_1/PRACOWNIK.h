#pragma once
#include "PERSONEL.h"
class PRACOWNIK :
	public virtual PERSONEL
{
	PERSONEL p1;
	int godziny;
	double stawka_nagodzine;
	double pensja;

	double oblicz_pensje(int godz, double sstawka);

public:
	PRACOWNIK();
	~PRACOWNIK();
	void setPracownik(pracownicy p1, int liczba_godzin, double stawka);
	void setGodziny(int liczba_godzin);
	void setStawka(int stawka);
	void setPensja();
	double getPensja();
	void wyswietlPensje();
};

