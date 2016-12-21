#include "stdafx.h"
#include "Trojkat.h"
#include <iostream>
using namespace std;


CTrojkat::CTrojkat(CNodCoord *tabb)
{
	A = tabb[0];
	B = tabb[1];
	C = tabb[2];
}


CTrojkat::~CTrojkat()
{
}

void CTrojkat::disp()
{
	cout << "Trojkat" << endl;
	A.Disp();
	B.Disp();
	C.Disp();
	cout << "END" << endl;
}
