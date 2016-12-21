/*
Laboratorum 1
Zadanie laboratoryjne nr 4

To samo co lab1_2

Program moze roznic sie z PDF
Przeanalizowaæ pod debugerem przestrzenie nazw
@Patryk Przybek
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

namespace MY_NAMESPACE_1
{
	int i;
	void fun(int j, char *str);
}

namespace MY_NAMESPACE_2
{
	int i;
	void fun(int j, char *str);
}

void MY_NAMESPACE_1::fun(int j, char *str)
{
	cout << "j = " << j << " str: " << str << endl;
}

void MY_NAMESPACE_2::fun(int j, char *str)
{
	cout << "j*j = " << j << " str: " << str << "!!!!" << endl;
}

int i; // nalezy do globalnej przestrzeni nazw
void fun(int j, char *str)
{
	cout << "j*j*j = " << j << " str: " << " [" << str << "]" << endl;
}

int main()
{
	MY_NAMESPACE_1::i = 1; //nalezy do przestrzeni nazw MY_NAMESPACE_1
	MY_NAMESPACE_1::i = 2; //nalezy do przestrzeni nazw MY_NAMESPACE_2
						   //To s¹ ró¿ne zmienne - s¹ umieszczone w ró¿nych adresach pamiêci
						   //Dla tego nie powstaje konflikt nazw; ::  - oparator zakresu.
	MY_NAMESPACE_1::fun(10, "abcd");
	MY_NAMESPACE_2::fun(15, "efgk");
	fun(15, "booom");

	system("pause");
	return 0;
}
