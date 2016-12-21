#pragma once
class CNodCoord
{
	double x;
	double y;
	double z;
	int numb;
public:
	CNodCoord(double xx, double yy, double zz, double n);
	CNodCoord() { x = 0.0; y = 0.0; z = 0.0; numb = 0;}
	~CNodCoord();
	CNodCoord GetCoord();
	void SetCoord(double xx, double yy, double zz, double n);
	void SetCoord(CNodCoord *ob);
	void Disp();
};

