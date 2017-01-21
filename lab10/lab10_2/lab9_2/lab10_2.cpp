// lab9_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const int szesc = 6;
	const int *wsk_c = &szesc;
	int *wsk_norm;
	cout << "Wartosc wsk_c = " << *wsk_c << " adres = " << wsk_c << endl;
	wsk_norm = const_cast<int*>(wsk_c);
	cout << "Wartosc wsk_c = " << *wsk_norm << " adres = " << wsk_norm << endl;

	system("pause");
    return 0;
}

