// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream plik;
	plik.open("./studenci.txt");
	string line;

	double srednia[3];
	srednia[0] = 0;
	srednia[1] = 0;
	srednia[2] = 0;
	
	if (!getline(plik, line))
	{
		return 0;
	}

	for (int i = 0; i < 3; i++)
	{
		istringstream stream(line);
		string name, secoundName, heh;
		char temp;
		stream >> name;

		stream >> secoundName;
		cout << name;
		cout << " " << secoundName;
		
		double points;
		double sum = 0;

		vector <double>sums;

		while (stream >> points)
		{
			sum += points;
			sums.push_back(points);
		}
		cout << " " << sum;
		getline(plik, line);
		cout << endl;

		int  f = 0;
		{
			while (!sums.empty())
			{
				double a = sums.back();
				srednia[f++] += a;
				sums.pop_back();
			}
		}
	}

	for (int j = 0; j < 3; j++)
	{
		cout << j << ". " << srednia[j] / 3 << endl;
	}


	system("PAUSE");
	return 0;
}

