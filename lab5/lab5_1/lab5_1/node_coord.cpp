#include "stdafx.h"
#include "node_coord.h"
#include <iostream>
#include <cmath>
using namespace std;

node_coord::node_coord(double x, double y)
{
	try
	{
		pcoord = new double[2];
		pcoord[0] = x;
		pcoord[1] = y;
	}
	catch (bad_alloc)
	{
		crash();
	}
}

node_coord::node_coord(const node_coord &nc)
{
	if (nc.pcoord)
	{
		try
		{
			pcoord = new double[2];
			pcoord[0] = nc.pcoord[0];
			pcoord[1] = nc.pcoord[1];
		}
		catch (bad_alloc)
		{
			crash();
		}
	}
	else
	{
		pcoord = NULL;
	}
}

void node_coord::crash()
{
	cout << "memory allocation error\n";
	system("pause");
	exit(1);
}

void node_coord::disp()
{
	if (pcoord)
	{
		cout << "x = " << this->pcoord[0] << endl;
		cout << "y = " << this->pcoord[1] << endl;
	}
	else
	{
		cout << "pcoord in null" << endl;
	}
	cout << endl;
}

node_coord::~node_coord()
{
	if (pcoord)
	{
		delete[] pcoord;
		pcoord = NULL;
	}
}

double distance(node_coord & a, node_coord & b)
{
	double ax, ay, bx, by;
	if (a.pcoord && b.pcoord)
	{
		ax = a.pcoord[0]; //node_coord a - x
		ay = a.pcoord[1]; //node_coord a - y
		bx = b.pcoord[0]; //node_coord b - x
		by = b.pcoord[1]; //node_coord b - y

		return sqrt((bx - ax)*(bx - ax) + (by - ay)*(by - ay));
	}
	else
	{
		return 0.0;
	}
}
