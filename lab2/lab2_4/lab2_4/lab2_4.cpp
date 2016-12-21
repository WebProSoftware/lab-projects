/*
Laboratorum 2
Zadanie laboratoryjne nr 4
@Patryk Przybek
*/

// W1_1.cpp : Defines the entry point for the console application.
// Konstruktory i destruktory
#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 100
//declaration of class CStack
class CStack
{
	//private members
	double *arr_stack; //tablica elementow
	int dim; //rozmiar tablicy arr_stack
	int noitems; //aktualjna ilosc elementow w steku
public:
	CStack(int max); //Konstruktor
	~CStack(); //Destruktor
	void push(double mem);
	double pop();
	int getnumb();
};
//definicje funkcji-metod klasy CStack
CStack::CStack(int max)
{
	//konstruktor alokuje pamiec
	noitems = 0;
	dim = max;
	arr_stack = new double[max];
	if (!arr_stack)
	{
		//to jest nie najlepsze rozwiazanie !
		cout << "blad alokacji pamieci" << endl;
		system("pause");
		exit(1);
	}
}
CStack ::~CStack()
{
	//destruktor: zwalnia pamiec
	if (arr_stack)
	{
		delete [] arr_stack;
		arr_stack = NULL;
	}
}
void CStack::push(double mem)
{
	//umieszcza nowy element do steku
	if (noitems >= MAX_SIZE)
	{
		cout << "stack jest wypelniony\n";
		return;
	}
	arr_stack[noitems] = mem;
	noitems++;
}
double CStack::pop()
{
	//dostaje z steku ostatnij element
	if (noitems <= 0)
	{
		cout << "stack jest pusty\n";
		return 0;
	}
	noitems--;
  return arr_stack[noitems];
}
int CStack::getnumb()
{
	return noitems;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int op = 0;
	int max = 0;
	double var;
	
	cout << "Podaj wielkosc stacku \n";
	cin >> max;

	CStack st(max);
	while (op != 3)
	{
		cout << "kod dzialania? (0 - push, 1 - pop, 2 - ilosc elementow, 3 - skoncz)\n"
			;
		cin >> op;
		switch (op)
		{
		case 0: //push
			cout << "wprowadz wartosc\n";
			cin >> var;
			st.push(var);
			break;
		case 1: //pop
			var = st.pop();
			cout << " wartosc var = " << var << "\n";
			break;
		case 2:
			cout << " pozostalo " << st.getnumb() << " elementow\n";
			break;
		case 3:
			break;
		default:
			cout << "bledne dzialanie\n";
		};
	}
	return 0;
}
#undef MAX_SIZE