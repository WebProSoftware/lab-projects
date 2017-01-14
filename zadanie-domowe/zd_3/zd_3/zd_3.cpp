// zd_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h> 

using namespace std;

class A
{
private:
	char *txt;

public:
	A();
	A(char *txt);
	A(const A &ob);
	~A();
	void wyswietl();
	char *getText();
};

A::A()
{
	txt = NULL;
	cout << "Kontruktor domyslny!" << std::endl;
}

A::A(char *text) {
	int size_tab = strlen(text) + 2;
	txt = new char[size_tab];

	for (int i = 0; i < size_tab; i++) {
		txt[i] = text[i];
	}

	cout << "Kontruktor sparametryzowany!" << endl;
}

A::A(const A &ob) {
	int size_tab = strlen(ob.txt) + 2;  
	txt = new char[size_tab];

	for (int i = 0; i < size_tab; i++) {
		txt[i] = ob.txt[i];
	}

	cout << "Kontruktor kopujacy!" << endl;
}


void A::wyswietl() {
	if (txt != NULL) {
		cout << "Wiersz: " << txt << endl;
	}
	else {
		cout << "Brak wiersza!" << endl;
	}
}


A::~A()
{
	std::cout << "Destruktor!" << std::endl;
	delete[] this->txt;
}

char *A::getText() {
	return this->txt;
}

void fun(A obj)
{
	obj.wyswietl();
}

void fun(A *obj)
{
	obj->wyswietl();
}

A fun()
{
	return A("nanananan");
}

int main()
{
	//A ob("aaaaaaaab");
	//fun(ob);
	//fun(&ob);


	A cc = fun();
	system("pause");
	return 0; 
}