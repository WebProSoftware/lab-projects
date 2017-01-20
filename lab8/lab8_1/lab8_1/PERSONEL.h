#pragma once

#include <iostream>
using namespace std;

/*
	Struktrura listy pracowników
*/
struct pracownicy
{
	string nazwisko;
	int biuro;
	long long telefon;
	int stanowisko; // 0 - pracnownik, 1 - sprzedawna, 2 - dyrektor // 3 - dyrekotor handlowy
};

class PERSONEL
{
	string nazwisko;
	int biuro;

public:
	PERSONEL();
	PERSONEL(pracownicy pracownik);
	void setPersonel(pracownicy pracownik);
	void wyswietlPracownika();
	~PERSONEL();
};

