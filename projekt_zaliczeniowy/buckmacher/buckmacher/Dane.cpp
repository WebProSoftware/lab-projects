#include "stdafx.h"
#include "Dane.h"


Dane::Dane(const string & data)
{
	ElementKonfiguracji = data;
}

Dane::operator int() const
{
	stringstream strstream(ElementKonfiguracji);
	int val = 0;
	strstream >> val;

	if (strstream.fail())
	{
		throw runtime_error("Nie da sie zmienic int");
	}
	return val;
}

Dane::operator string() const
{
	return ElementKonfiguracji;
}


Dane::operator bool() const
{
	return ElementKonfiguracji == "true" || ElementKonfiguracji == "True";
}

ostream & operator<<(ostream &wyjscie, Dane const & d1)
{
	wyjscie << d1.ElementKonfiguracji;
	return wyjscie;
}
