#pragma once
#include "View_Controller.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class User
{
private:
	int id;
	string imie;
	string nazwisko;

public:
	User();
	User(int idd, string im, string naz);
	int getId();
	string getImie();
	string getNazwisko();

	void set(string im);
};

