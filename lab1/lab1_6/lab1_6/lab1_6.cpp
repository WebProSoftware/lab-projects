/*
Laboratorum 1
Zadanie laboratoryjne nr 6

@Patryk Przybek
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
const int MAX = 10;

double tab[MAX];

int main()
{
	//Wypelnianie tablicy przykladowymi danymi
	for (int i = 0; i < size(tab); i++)
	{
		tab[i] = 10.0 * (i+1);
	}

	//Wyswietl tablice
	printf("NAGLOWEK\n\n");
	printf("Pozycja\t\t\tWartosc\n");

	for (int i = 0; i < size(tab); i++)
	{
		printf("%d\t\t\t%4.1f\n", i+1, tab[i]);
	}

	system("pause");
    return 0;
}

