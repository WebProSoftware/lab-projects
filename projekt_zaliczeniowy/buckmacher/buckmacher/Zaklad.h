#pragma once

#include <string>
#include <iostream>

using namespace std;

/*
zmienna win
1-zwycieztwo pierwsze,
0-remis
2-zwycieztwo drugiej
-1-brak wyniku
*/

class Zaklad
{
protected:
	string nazwa;
	int typ;
	int win;
	int id;
	
public:
	Zaklad() { this->typ = 0; }
	Zaklad(string naz, int typp, int wygrana, int idd);
	Zaklad(const Zaklad &zak);
	virtual ~Zaklad();
	bool operator == (string str);

	string nazwa_typ(int typp);
	string nazwa_wygranej(int win);

	void setWygrana(int wygrana);
	virtual double getKursWygranej() = 0;
	virtual void disp() = 0;
	virtual string getKursy() = 0;

	int getTyp();
	int getId();
	string getNazwa();
	int getWin();
};

