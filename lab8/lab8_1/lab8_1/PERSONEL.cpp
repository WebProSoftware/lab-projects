#include "stdafx.h"
#include "PERSONEL.h"

#include <string>
#include <iostream>
using namespace std;

PERSONEL::PERSONEL()
{
	this->nazwisko = "";
	this->biuro = 0; 
}

PERSONEL::PERSONEL(pracownicy pracownik)
{
	this->nazwisko = pracownik.nazwisko;
	this->biuro = pracownik.biuro;
}

void PERSONEL::setPersonel(pracownicy pracownik)
{
	this->nazwisko = pracownik.nazwisko;
	this->biuro = pracownik.biuro;
}

void PERSONEL::wyswietlPracownika()
{
	cout << "nazwisko: " << nazwisko << endl;
	cout << "nr biura: " << biuro << endl;
}


PERSONEL::~PERSONEL()
{
}
