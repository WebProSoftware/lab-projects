/*
Laboratorum 5
Zadanie laboratoryjne nr 1
@Patryk Przybek
*/

#include "stdafx.h"
#include "node_coord.h"
#include "triangle.h"
#include <iostream>
using namespace std;

void my_fun(triangle trr)
{
	trr.disp();
}

void my_fun(triangle *trr)
{
	trr->disp();
}

int main()
{
	node_coord A(2, 3);
	node_coord B = A;

	node_coord C;
	node_coord D = C;

	node_coord AA(2, 3), BB(3, 4), CC(0, 0);
	
	triangle tr(AA, BB, CC, "trojkat 1");
	tr.disp();

	cout << "distance between first and secound nodes:  " << tr.distance(1,0) << endl;

	my_fun(tr);
	my_fun(&tr);

	system("pause");
    return 0;
}

