/*
Laboratorum 1
Zadanie laboratoryjne nr 2

@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>

#pragma warning(disable : 4996)  
using namespace std;

int main()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int year_now = timeinfo->tm_year + 1900;
	int input_year;

	int iint;
	double ddouble;
	string text;

	cout << "Program powitalny" << endl;
	cout << "Mamy rok: " << year_now << endl;
	cout << "Witam mam na imie: Patryk Przybek" << endl;
	cout << "Grupa 2" << endl;
	cout << "Podaj swoj rok urodzenia: ";
	cin >> input_year;
	cout << "\n\n";
	cout << "Masz " << year_now - input_year << " lat" << endl;
	cout << "Teraz powprowadzamy troszke liczb" << endl;
	cout << "Wprowadz int:";
	cin >> iint;
	cout << "\n";
	cout << "Wprowadz double";
	cin >> ddouble;
	cout << "\n";
	cout << "Wprowadz wiesz: ";
	cin.get();
	getline(cin, text);
	cout << "INT = " << iint << " DOUBLE = " << ddouble << " TEXT = " << text << endl;

	system("pause");
    return 0;
}

