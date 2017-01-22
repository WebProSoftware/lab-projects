// lab9_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Figura.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include <iostream>
#include <time.h>
using namespace std;

size_t Figura::alloc = 0;

int main()
{

	Figura *prt = NULL, *prt_rect = NULL;
	prt_rect = new Rectangle(2, 3);

	Circle c1(2), cl1(3); 
	Triangle tr(2, 4);

	srand(time(NULL));

	for (int it = 0; it < 10; it++)
	{
		int ind = rand() % 4;

		switch (ind)
		{
		case 0:
			prt = &c1;
			break;
		case 1:
			prt = &cl1;
			break;
		case 2:
			prt = &tr;
			break;
		case 3:
			prt = prt_rect;
			break;
		default:
			break;
		}

		prt->area();
		prt->disp();
	}

	delete prt_rect;
	prt_rect = NULL;

	if (Figura::alloc)
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n error: leak of memory\n";

	system("pause");
     return 0;
}

