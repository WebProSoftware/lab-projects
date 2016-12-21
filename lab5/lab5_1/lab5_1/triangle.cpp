#include "stdafx.h"
#include "node_coord.h"
#include "triangle.h"
#include <iostream>
using namespace std;

void triangle::disp()
{
	cout << str << endl;
	vert_a.disp();
	vert_b.disp();
	vert_c.disp();
}

double triangle::distance(int First, int Second)
{
	if ((First >= 0 && First <= 2) && (Second >= 0 && Second <= 2) && (First != Second))
	{
		node_coord *triangle_verts;
		try
		{
			triangle_verts = new node_coord[3];
			triangle_verts[0] = vert_a;
			triangle_verts[1] = vert_b;
			triangle_verts[2] = vert_c;
		}
		catch (bad_alloc)
		{
			cout << "bad alloc memoory \n";
			system("pause");
			exit(1);
		}
		
		double distance(node_coord & a, node_coord & b); // funcja zaprzyjazniona z clasa node_coord
		double result = distance(triangle_verts[First], triangle_verts[Second]);

		// Wynik
		return result;
	}
	else
	{
		cout << "bad arg value" << endl;
		return 0;
	}
}

triangle::~triangle()
{

}
