/*
Laboratorum 2
Zadanie laboratoryjne nr 3
@Patryk Przybek
*/


#include "stdafx.h"
#include <iostream>
using namespace std;

//clasa MY_POINT reprezentuje punkt na plaszczyznie
class MY_POINT
{
	double coord[2];  //coord[0] - x; coord[1] - y
public:
	MY_POINT() { memset((void *)coord, 0, sizeof(coord)); }  //konstruktor domyslny
	MY_POINT(double xx, double yy) { coord[0] = xx; coord[1] = yy; }  //konstruktor sparametryzowany
	void disp() { cout << " x = " << coord[0] << " y = " << coord[1] << endl; }
	void set(double xx, double yy) { coord[0] = xx; coord[1] = yy; }
};

//clasa MY_LINE reprezentuje prosta
class MY_LINE
{
	MY_POINT PointStart;  //punkt poczatku prostej
	MY_POINT PointEnd;    //punkt konca prostej
public:
	MY_LINE(MY_POINT start, MY_POINT end) : PointStart(start), PointEnd(end) {} //konstruktor sparametryzowany
	void disp(char *str);
};

//definicja metod klasy MY_LINE
void MY_LINE::disp(char *str)
{
	cout << str << endl;
	cout << "begin : ";
	PointStart.disp();
	cout << "end   : ";
	PointEnd.disp();
}

//stworzyc klase Triangle, ktora reprezentuje trojkat.
class MY_TRIANGLE
{
	MY_POINT A;
	MY_POINT B;
	MY_POINT C;
public:
	MY_TRIANGLE(MY_POINT AA, MY_POINT BB, MY_POINT CC) : A(AA), B(BB), C(CC) {} // konstrukor sparametrozwny
	void disp(char *str);
};

void MY_TRIANGLE::disp(char *str)
{
	cout << str << endl;
	cout << "A   : ";
	A.disp();
	cout << "B   : ";
	B.disp();
	cout << "C   : ";
	C.disp();
}

int _tmain(int argc, _TCHAR* argv[])
{
	MY_POINT pt_begin(0, 0);  //tworzymy punkt poczatku za pomoca konstruktora sparametryzowanego
	MY_POINT pt_end;	      //tworzymy punkt konca za pomoca konstruktora domyslnego
	pt_end.set(1, 2);         //ustawiamy wspolrzedne po tworzeniu
	MY_LINE line_1(pt_begin, pt_end); //tworzymy prosta za pomoca konstruktora sparametryzowanego
	line_1.disp("line 1");

	//stworzyc punkty A, B, C jako wierzcholki trojkata
	MY_POINT A(1, 1);
	MY_POINT B(2, 2);
	MY_POINT C(3, 3);
	//stworzyc trojkat i wyprowadzic wspolrzedne jego wierzcholkow na monitor
	MY_TRIANGLE t1(A, B, C);
	t1.disp("trojkat 1");

	system("pause");
	return 0;
}
