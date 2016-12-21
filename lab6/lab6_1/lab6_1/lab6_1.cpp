/*
Laboratorum 1
Zadanie laboratoryjne nr 2

Program moze roznic sie z PDF'em
@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

//Prototyp funkcji
int liczbaSekund(int godziny=1, int minuty=10, int sekundy=25);

//Funkcja g³owna
int main()
{
	cout << liczbaSekund(1) << endl;
	system("pause");
    return 0;
}

//Definicja funkcji
int liczbaSekund(int godziny, int minuty, int sekundy)
{
	int suma = 0;
	suma = godziny * 60 * 60;
	suma += minuty * 60;
	suma += sekundy;

	return suma;
}

//Odp: W tej konfiguracji nie mozemy musielibysmy zmienic kolejnosc przekazywana parametro
//z H:M:S -> H:S:M. Ewentualnie przeciazyc funkcje 




