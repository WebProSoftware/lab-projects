#pragma once
class Figura
{
public:
	static size_t alloc;
protected:
	double s;
public:
	Figura(){ s = 0; }
	virtual ~Figura();

	virtual void area() = 0;
	virtual void disp() = 0;
};


