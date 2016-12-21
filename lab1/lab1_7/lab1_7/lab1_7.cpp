/*
Laboratorum 1
Zadanie laboratoryjne nr 7
@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int tab[3];

int main()
{
	cout << "Program do wprowadzania danych do tablicy" << endl << endl;
	for (int i = 0; i < size(tab); i++)
	{
		cout << "Wproawdz wartosc nr: " << i + 1 << endl;
		cin >> tab[i];
		cout << endl;
	}

	cout << "Wyprowadzam dane z kolejnoscia dodania" << endl;
	printf("Pozycja\t\t\tWartosc\n");
	for (int i = 0; i < size(tab); i++)
	{
		printf("%d\t\t\t%d\n",i+1,tab[i]);
	}

	cout << "Wyprowadzam dane z kolejnoscia odwrotna do dodania" << endl;
	printf("Pozycja\t\t\tWartosc\n");
	for (int i = size(tab); i > 0; i--)
	{
		printf("%d\t\t\t%d\n", i , tab[i - 1]);
	}

	system("pause");
    return 0;
}

