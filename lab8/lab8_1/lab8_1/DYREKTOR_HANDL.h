#pragma once
#include "DYREKTOR.h"
#include "SPRZEDAWCA.h"


class DYREKTOR_HANDL :
	public DYREKTOR, public SPRZEDAWCA
{
	double pensja;

public:
	DYREKTOR_HANDL();
	DYREKTOR_HANDL(pracownicy dyrehandl, int licz_prac, int zarobki,int za_pracownika = 150, int procent_premi = 20);
	void wyswietlPensjeDyreHandl();
	~DYREKTOR_HANDL();
};

