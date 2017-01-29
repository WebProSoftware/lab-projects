// buckmacher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dane.h"
#include "Config.h"
#include "View_Controller.h"
#include "User.h"
#include "Pilkarski.h"
#include "Database_Controller.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const char* configFile = "config/config.cfg";
const char* messageList = "config/msg.list";
const char* usersdb = "database/users.txt";
const char* zakladyDB = "database/zaklady.txt";

Config cfg(configFile);
Config msg(messageList);

//szablon funcji
template <class T>
vector<T> bazaDB(const string &userlist)
{
	ifstream dbusr;
	vector<T> baza;
	dbusr.open(userlist.c_str());
	while (true)
	{
		int id; // id - naglowek tabeli
		string imie;
		string nazwisko;
		dbusr >> id >> imie >> nazwisko;
		if (dbusr.good())
			baza.push_back(new User(id, imie, nazwisko));
		else
			break;
	}
	return baza;
}


int main()
{
	bool loop = true; //jak zmieni sie na false to znaczy ze prgoram sie zakonczy;
	int sw;
	//komunitary - widoki - controller (obrobka danych)
	View_Controller *response = new View_Controller(msg, cfg);
	//szablon funckji sprawdzajacy czy cos sie nie zmienilo w bazie uzytykownikow
	vector<User*> bazaUzytkownikow = bazaDB<User*>(usersdb);

	try
	{
		Database_Controller<Zaklad> *db = new Database_Controller<Zaklad>();
		if (response->zaloguj())
		{
			while (loop)
			{
				response->zalogowany();
				response->menu();

				//zmienna sterujaca menu 
				cin.clear();
				cin >> sw;
				switch (sw)
				{
				case 1:
					//Wyswietla wszystki uzytkownikow
					response->zalogowany();
					response->getAllUsers(bazaUzytkownikow);
					break;
				case 2:
					//Wyswietla info o uzytkowniku po podaniu numeru id kliena
					response->zalogowany();
					response->getUserById(bazaUzytkownikow);
					break;
				case 3:
					//Wczytaj baze zakladow do pamieci 
					response->zalogowany();
					response->getDatabaseFromFile(db, zakladyDB);
					break;
				case 4:
					//Wyswietla wszystkie 
					response->zalogowany();
					response->getAllZaklady(db);
					break;
				case 5:
					//Czyscie obiekt 
					response->zalogowany();
					response->deleteAllZaklady(db);
					break;
				case 6:
					//Dodaje pojedynczy zaklad
					response->zalogowany();
					response->addZaklad(db);
					break;
				case 7:
					//Kasuje jeden
					response->zalogowany();
					response->eraseZaklad(db);
					break;
				case 8:
					//Zmienia / modyfikuje obiekt
					response->zalogowany();
					response->addResultMatch(db);
					break;
				case 9:
					//Zapisuje zmiany w bazie
					response->zalogowany();
					response->saveAll(db,zakladyDB);

				case 0:
					loop = false;
					break;
				default:
					response->blednawartoscmenu();
					break;
				}

			
				//sprzatamy baze uzytkownikow
			}
			system("cls");
			response->end();
		}
		else
		{
			system("cls");
			cout << msg.getItem("300") << endl; //przekroczona liczba logowan
			response->end();
		}
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}


	//czyscimy wszystkie dynamiczne alokatory pamieci
	bazaUzytkownikow.clear();
	delete response;
	response = NULL;

	system("pause");
	return 0;
}

