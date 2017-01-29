#include "stdafx.h"
#include "User.h"

User::User()
{
}

User::User(int idd, string im, string naz)
{
	this->id = idd;
	this->imie = im;
	this->nazwisko = naz;
}

int User::getId()
{
	return this->id;
}

string User::getImie()
{
	return this->imie;
}

string User::getNazwisko()
{
	return this->nazwisko;
}

void User::set(string im)
{
	this->imie = im;
}
