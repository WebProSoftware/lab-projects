// lab11_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<math.h>
#include<iomanip>


using namespace std;

class LZesp {
protected:
	double re;
	double im;

public:
	LZesp(double are = 0, double aim = 0)
	{
		re = are; im = aim;
	}
	LZesp(const LZesp &z)
	{
		re = z.getRe();
		im = z.getIm();
	}
	double getRe() const
	{
		return re;
	}
	double getIm() const
	{
		return im;
	}
	void set(double are, double aim)
	{
		re = are; im = aim;
	}

	LZesp operator+(const LZesp &l) const
	{
		return LZesp(re + l.getRe(), im + l.getIm());
	}

	LZesp& operator=(const LZesp &l)
	{
		if (&l != this) {
			re = l.getRe();
			im = l.getIm();
		}
		return *this;
	}
	LZesp operator-(const LZesp &z) {
		double re = this->getRe() - z.getRe();
		double im = this->getIm() - z.getIm();

		return LZesp(re, im);
	}
	LZesp operator*(const LZesp &z) {
		//(a1 + b1i)(a2 + b2i) = (a1a2 - b1b2) + (a1b2 + a2b1)i -> mnozenie
		double re = (this->getRe() * z.getRe()) - (this->getIm()*z.getIm());
		double im = this->getRe() * z.getIm() + z.getRe() * this->getIm();

		return LZesp(re, im);
	}
	bool operator==(const LZesp &z) {
		return this->getRe() == z.getRe() && this->getIm() == z.getIm() ? true : false;
	}
	bool operator!=(const LZesp &z) {
		return this->getRe() != z.getRe() || this->getIm() != z.getIm() ? true : false;
	}
	double operator[](int idx) {
		if (idx != 0 || idx != 1) {
			std::invalid_argument("Niepoprawny index, index musi byc z zakresu 0,1");
		}
		else if (idx == 0) {
			return this->getRe();
		}
		return this->getIm();

	}

	friend istream& operator >> (istream &i, LZesp &l);

};


istream& operator >> (istream &i, LZesp &l) {
	i >> l.re;
	i >> l.im;
	return i;
}

ostream& operator<< (ostream& os, const LZesp& l) {
	os << "(" << l.getRe() << ", " << l.getIm() << ")i \n";
	return os;
}



int main()
{

	// zadanie 1
	cout << "*" << setfill('*') << setw(37) << "*" << endl;
	cout << "*" << setfill(' ') << setw(24) << "Patryk Przybek" << setfill(' ') << setw(13) << "*" << endl;
	cout << "*" << setfill(' ') << setw(30) << "darknesslightmusic@gmail.com" << setfill(' ') << setw(7) << "*" << endl;
	cout << "*" << setfill('*') << setw(37) << "*" << endl << endl;

	// zadanie 2
	float USD = 4.09315;
	float EUR = 4.36924;
	float CHF = 4.07075;
	float GBP = 5.04742;
	float CAD = 3.07461;
	float DKK = 0.58721;
	float JPY = 0.03563;
	float kwota;
	cout << "Podaj kwote w PLN: ";
	cin >> kwota;

	cout << "\nPodana kwota w PLN to: " << kwota << endl;


	cout << "|" << setfill('-') << setw(15) << "|" << setfill('-') << setw(15) << "|" << setfill('-') << setw(15) << "|" << endl;
	cout << "|" << setfill(' ') << setw(9) << "Kraj" << setfill(' ') << setw(6) << "|" << setfill(' ') << setw(10) << "Waluta" << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(10) << "Kwota" << setfill(' ') << setw(5) << "|" << endl;
	cout << "|" << setfill('-') << setw(15) << "|" << setfill('-') << setw(15) << "|" << setfill('-') << setw(15) << "|" << endl;

	cout << "|" << setfill(' ') << setw(6) << "EUGiW" << setfill(' ') << setw(9) << "|" << setfill(' ') << setw(8) << "EUR" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(13) << setprecision(7) << kwota*EUR << setfill(' ') << setw(2) << "|" << endl;
	cout << "|" << setfill(' ') << setw(4) << "USA" << setfill(' ') << setw(11) << "|" << setfill(' ') << setw(8) << "USD" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(13) << setprecision(7) << kwota*USD << setfill(' ') << setw(2) << "|" << endl;
	cout << "|" << setfill(' ') << setw(12) << "W. Brytania" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(8) << "GBP" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(13) << setprecision(7) << kwota*GBP << setfill(' ') << setw(2) << "|" << endl;
	cout << "|" << setfill(' ') << setw(11) << "Szwajcaria" << setfill(' ') << setw(4) << "|" << setfill(' ') << setw(8) << "CHF" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(13) << setprecision(7) << kwota*CHF << setfill(' ') << setw(2) << "|" << endl;
	cout << "|" << setfill(' ') << setw(7) << "Kanada" << setfill(' ') << setw(8) << "|" << setfill(' ') << setw(8) << "CAD" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(13) << setprecision(7) << kwota*CAD << setfill(' ') << setw(2) << "|" << endl;
	cout << "|" << setfill(' ') << setw(6) << "Dania" << setfill(' ') << setw(9) << "|" << setfill(' ') << setw(8) << "DKK" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(13) << setprecision(7) << kwota*DKK << setfill(' ') << setw(2) << "|" << endl;
	cout << "|" << setfill(' ') << setw(8) << "Japonia" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(8) << "JPY" << setfill(' ') << setw(7) << "|" << setfill(' ') << setw(13) << setprecision(7) << setprecision(7) << kwota*JPY << setfill(' ') << setw(2) << "|" << endl;
	cout << "|" << setfill('-') << setw(15) << "|" << setfill('-') << setw(15) << "|" << setfill('-') << setw(15) << "|" << endl;


	// zadanie 3

	LZesp l1(2, 3), l2(3, 4), l3;
	l3 = l1 + l2;
	// tak naprawdê:
	l3.operator=(l1.operator+(l2));

	// kod poni¿ej mo¿na odkomentowaæ dopiero po implementacji
	// odpowiednich operatorów
	cout << l1 << " + " << l2 << " = " << l3 << endl;
	LZesp l4, l5;
	cin >> l4;
	cin >> l5;
	cout << l4 << " * " << l5 << " = " << l4*l5 << endl;
	cout << l4 << " - " << l5 << " = " << l4 - l5 << endl;
	if (l4 == l5) cout << l4 << " jest rowna " << l5 << endl;
	else cout << l4 << " nie jest rowna " << l5 << endl;
	if (l4 != l5) cout << l4 << " rozni sie od " << l5 << endl;
	else cout << l4 << " nie rozni sie od " << l5 << endl;



	system("PAUSE");
	return 0;
}