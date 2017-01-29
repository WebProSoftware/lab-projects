#include "stdafx.h"
#include "Zaklad.h"


Zaklad::Zaklad(string naz, int typp,  int wygrana, int idd)
{
	this->nazwa = naz;
	this->typ = typp;
	this->win = wygrana;
	this->id = idd;
}

Zaklad::Zaklad(const Zaklad & zak)
{
	string nowa_nazwa;
	cout << "Zmien nazwe : ";
	cin >> nowa_nazwa;

	this->typ = zak.typ;
	this->win = zak.win;
	this->id = zak.id;
}

Zaklad::~Zaklad()
{
}

bool Zaklad::operator==(string str)
{
	if (this->nazwa.find(str) != string::npos)
	{
		return true;
	}
	return false;
}

void Zaklad::setWygrana(int wygrana)
{
	this->win = wygrana;
}

string Zaklad::nazwa_typ(int typp)
{
	if (typp == 1)
	{
		return "Pilka nozna";
	}
	else if (typp == 2)
	{
		return "Koszykowka";
	}
	else if(typp == 3)
	{
		return "Skoki narciarskie";
	}
}

string Zaklad::nazwa_wygranej(int win)
{
	if (win == -1)
	{
		return "brak wyniku";
	}
	else
	{
		return to_string(win);
	}
}

int Zaklad::getTyp()
{
	return this->typ;
}

int Zaklad::getId()
{
	return this->id;
}

string Zaklad::getNazwa()
{
	return this->nazwa;
}

int Zaklad::getWin()
{
	return this->win;
}
