// zd_2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>


using namespace std;

//nazwa klasy dla funcji zaprzyjaznionej
class pr2;
//----------------------------------

class pr1
{
	int printing;

public:
	pr1() { printing = 0; };
	void set_printing(int status) { printing = status; }
	int is_used() { return printing; };
	friend bool inuse(pr1 &obb1, pr2 &obb2);
};

class pr2
{
	int printing;

public:
	pr2() { printing = 0; };
	void set_printing(int status) { printing = status; };
	int is_used() { return printing; };
	friend bool inuse(pr1 &obb1, pr2 &obb2);
};



// funkcja zaprzyjazniona 
bool inuse(pr1 &obb1, pr2 &obb2)
{
	if ((obb1.printing == 1) || (obb2.printing == 1))
	{
		return true;
	}
	else
	{
		return false;
	}

}


int main()
{
	pr1 ob1;
	pr2 ob2;

	int it = 0;
	int key, it_used = 0;

	while (it < 100)
	{
		key = rand();
		//jesli drukarka jest zajeta 4 iteracji petli - zwoniic jej
		if ((it - it_used) >= 4)
		{
			if (ob1.is_used())
			{
				ob1.set_printing(0);
				cout << "----------- job 1 is ended -----------" << endl;
			}
			if (ob2.is_used())
			{
				ob2.set_printing(0);
				cout << "----------- job 2 is ended -----------" << endl;
			}
		}
		
		//-------------------------------------------------------------------
		if(key%3 == 0)
		{
			//Jezeli wartosc key dzieli sie przez 3 drukarka jest wolna
			//Zadanie 1 zajmuje drukarke

			if (!inuse(ob1, ob2))
			{
				ob1.set_printing(1);
				it_used = it; 
			}
		}

		else if (key % 3 == 1)
		{
			//Jezeli wartosc key dzieli sie przez 3 z reszta 1 drukarka jest wolna
			//Zadanie 2 zajmuje drukarke
			if (!inuse(ob1, ob2))
			{
				ob2.set_printing(1);
				it_used = it;
			}
		}
		else
		{
		}

		if (ob1.is_used())
		{
			cout << "printer is used by job 1" << endl;
		}
		else if (ob2.is_used())
		{
			cout << "printer is used by job 2" << endl;
		}
		else
		{
			cout << " free " << endl;
		}

		it++;
	}
	system("pause");
    return 0;
}

