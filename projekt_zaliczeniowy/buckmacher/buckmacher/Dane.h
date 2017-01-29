#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Dane
{
	string ElementKonfiguracji;
public:
	Dane(const string &data = "");

	operator int() const;
	operator string() const;
	operator bool() const;
	friend ostream &operator<< (ostream &, Dane const&);
};

