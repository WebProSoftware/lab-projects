#include "Zaklad.h"
class Skoki :
	public Zaklad
{
private:
	double kursV;
public:
	Skoki() { this->typ = 3; };
	Skoki(string nazwa, double kV, int wygra, int idd);
	virtual ~Skoki();

	virtual string getKursy();
	virtual double getKursWygranej();
	virtual void disp();

	double getKursv() { return this->kursV; }
	
};
