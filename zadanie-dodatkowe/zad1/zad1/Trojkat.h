#pragma once
#include "NodCoord.h"
class CTrojkat :
	public CNodCoord
{
	CNodCoord A;
	CNodCoord B;
	CNodCoord C;
public:
	CTrojkat() : A(CNodCoord()), B(CNodCoord()), C(CNodCoord()) {}
	CTrojkat(CNodCoord AA, CNodCoord BB, CNodCoord CC) : A(AA), B(BB), C(CC) {}
	CTrojkat(CNodCoord *tab);
	~CTrojkat();
	void disp();
};

