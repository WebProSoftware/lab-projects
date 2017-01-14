// lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class klasa
{
private:
	int min;

public:
	klasa(int A){ min = A;  }
	
	int zwroc()
	{
		return min;
	}

	void wypisz()
	{
		cout << min / 60 << "h " << min % 60 << endl;
	}

	void  operator + (klasa k)
	{
		min += k.zwroc();
	}

	void operator + (int x)
	{
		min += x;
	}

};


class suma
{

public:
	int operator [] (int indeks)
	{
		int s = 0;
		while (indeks != 0)
		{
			s += indeks % 10;
			indeks /= 10;
		}

		return s;
	}


};


int _tmain(int argc, _TCHAR* argv[])
{
	klasa A(12), B(100);
	A + B;
	A.wypisz();
	A + 5;
	A.wypisz();

	suma s1;
	cout << "Suma cyfr liczby 123 wynosi " << s1[123] << endl;

	system("pause");
	return 0;
}

