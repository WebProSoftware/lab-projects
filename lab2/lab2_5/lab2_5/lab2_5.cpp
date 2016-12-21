/*
Laboratorum 2
Zadanie laboratoryjne nr 5
@Patryk Przybek
*/

#include "stdafx.h"
#include "windows.h"
#include <iostream>
using namespace std;

class time_day
{
public:
	DWORD start;
	DWORD stop;
	time_day(DWORD ss);
	~time_day();
};

time_day::time_day(DWORD ss)
{
	this->start = ss;
	printf("Zaczynamy\n");
}

time_day::~time_day()
{
	this->stop = GetTickCount();
	cout << "Czas w ms: ";
	cout << (this->stop - this->start)  << endl;
}

//inicjacja globalna 
time_day s1(GetTickCount());

int main()
{
	// inicjacja lokalna w main()
	time_day s2(GetTickCount());
	
	// inicjacja statyczna
	static time_day s3(GetTickCount());
	
	Sleep(2000);
	cout << "GLOBAL: " << endl;
	s1.~time_day();

	cout << "LOCAL: " << endl;
	s2.~time_day();

	cout << "STATIC: " << endl;
	s3.~time_day();

	system("pause");
    return 0;
}

