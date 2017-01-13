// zd_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double pi = 3.14;

//klasa bazowa
class shape_geom
{
private:
	double area;

public:
	shape_geom() { area = NULL; };
	void setArea(double wynik) { area = wynik; };
	double getArea() { return area; };
	void wyswietl() { cout << "wynosi: " << shape_geom::getArea() << endl << endl; };
};


//klasa pochodna prostok¹ta
class rect : private shape_geom
{
private:
	double a, b;

public:
	rect() { a = 2.0; b = 3.0; };
	rect(double aa, double bb);
	~rect();
	void oblicz();
	void wyswietl();
};

rect::rect(double aa,double bb)
{
	a = aa;
	b = bb;
}

rect::~rect() {}

void rect::oblicz()
{
	shape_geom::setArea(this->a * this->b);
}

void rect::wyswietl()
{
	cout << "Pole kwadratu ";
	shape_geom::wyswietl();
}



class circle : public shape_geom
{
private:
	double r;
public:
	circle() { r = 1.0; };
	circle(double rr);
	~circle();
	void oblicz();
	void wyswietl();
};

circle::circle(double rr)
{
	r = rr;
}

void circle::oblicz()
{
	shape_geom::setArea((double)(this->r*this->r*pi));
}

void circle::wyswietl()
{
	cout << "Pole kola ";
	shape_geom::wyswietl();
}


circle::~circle(){}


int main()
{
	//obiekt prostokata
	rect r1(2.0, 4.0);
	r1.oblicz();
	r1.wyswietl();

	//obiekt kola
	circle c1(2.0);
	c1.oblicz();
	c1.wyswietl();

	system("pause");
    return 0;
}

