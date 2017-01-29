#include "stdafx.h"
#include "View_Controller.h"
#include "Config.h"


#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void View_Controller::header()
{
	system("cls");

	cout << setfill('-') << setw(1) << "+" << setw(78) << "-" << setw(1) << "+";
	cout << setfill(' ') << setw(1) << "|" << setw(9) << "Program: " << left << setw(69)<< this->config.getItem("nazwa_projektu") << setw(1) << "|";
	cout << setfill(' ') << setw(1) << "|" << setw(9) << "Wersja: " << left << setw(69)	<< this->config.getItem("version") << setw(1) << "|";
	cout << setfill(' ') << setw(1) << "|" << setw(9) << "Autor: " << left << setw(69)	<< this->config.getItem("autor") << setw(1) << "|";
	cout << setfill(' ') << setw(1) << "|" << setw(9) << "Email: " << left << setw(69)	<< this->config.getItem("email") << setw(1) << "|";
	cout << setfill('-') << setw(1) << "+" << setw(78) << "-" << setw(1) << "+";
}

bool View_Controller::zaloguj()
{
	const int ilebledow		= this->config.getItem("ilebledow");
	const string login		= this->config.getItem("login");
	const string pass		= this->config.getItem("pass");
	string cin_log, cin_pass;

	for (int i = 0; i < ilebledow; i++)
	{
		View_Controller::header();
		if (i != 0)
		{
			cout << "Blad logowania" << endl;
			cout << "Liczba prob logowania: " << i+1 << "/" << ilebledow << endl;
		}

		cout << "Podaj login: ";
		cin >> cin_log;
		cout << "Podaj haslo: ";
		cin >> cin_pass;

		if ((cin_log == login) && (cin_pass == pass))
		{
			return true;
		}
	}
	return false;
}


void View_Controller::zalogowany()
{
	this->header();
}

void View_Controller::blednawartoscmenu()
{
	system("cls");
	cout << this->message.getItem("200") << endl;
	system("pause");
}

void View_Controller::menu()
{
	cout << "Menu" << endl;
	cout << "1. Wyswietl uzytkownikow" << endl;
	cout << "2. Wyszukaj uzytkownika po ID" << endl;
	cout << "3. Wczytaj zaklady" << endl;
	cout << "4. Wyswietl wszystkie zaklady " << endl;
	cout << "5. Wyczysc liste zakladow " << endl;
	cout << "6. Dodaj nowy zaklad" << endl;
	cout << "7. Usun zaklad" << endl;
	cout << "8. Wprowadz wynik dla zakladu" << endl;
	cout << "9. Zapisz zaklady do pliku " << endl;
	cout << "0. Zakoncz" << endl;
}

//Metoda wyswietlajaca wszystki uzytkownikow	
void View_Controller::getAllUsers(vector<User*> baza)
{
	int size_db = baza.size();
	string id = "Id";
		
	//naglowek
	cout << setfill('-') << setw(1) << "+" << setw(6) << "-" << setw(1) << "+" << setw(10) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;
	cout << setfill(' ') << setw(1) << "|" << setw(6) << id <<  setw(1) << "|" << setw(10) << baza[0]->getImie() << setw(1) << "|" << setw(15) << baza[0]->getNazwisko() << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "-" << setw(6) << "-" << setw(1) << "-" << setw(10) << "-" << setw(1) << "-" << setw(15) << "-" << setw(1) << "-" << endl;
	//end naglowek
	//body
	//poniewaz i = to naglowek;
	for (int i = 1; i < size_db; i++)
	{
		cout << setfill(' ') << setw(1) << "|" << setw(6) << baza[i]->getId() << setw(1) << " " << setw(10) << baza[i]->getImie() << setw(1) << " " << setw(15) << baza[i]->getNazwisko() << setw(1) << "|" << endl;
	}
	//end body
	cout << setfill('-') << setw(1) << "-" << setw(6) << "-" << setw(1) << "-" << setw(10) << "-" << setw(1) << "-" << setw(15) << "-" << setw(1) << "-" << endl;
	system("pause");
}

//Metoda wyswietlajaca uzytkownika o podanym id
void View_Controller::getUserById(std::vector<User*> baza)
{
	int size_db = baza.size();
	int sw; //cin

	this->header();
	cout << this->message.getItem("101") << endl;
	cin >> sw;

	//validacja wprowadzonego id
	if (sw >= 1 && sw < size_db)
	{
		string id = "Id";

		//naglowek
		cout << setfill('-') << setw(1) << "+" << setw(6) << "-" << setw(1) << "+" << setw(10) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;
		cout << setfill(' ') << setw(1) << "|" << setw(6) << id << setw(1) << "|" << setw(10) << baza[0]->getImie() << setw(1) << "|" << setw(15) << baza[0]->getNazwisko() << setw(1) << "|" << endl;
		cout << setfill('-') << setw(1) << "-" << setw(6) << "-" << setw(1) << "-" << setw(10) << "-" << setw(1) << "-" << setw(15) << "-" << setw(1) << "-" << endl;
		//end naglowek
		cout << setfill(' ') << setw(1) << "|" << setw(6) << baza[sw]->getId() << setw(1) << " " << setw(10) << baza[sw]->getImie() << setw(1) << " " << setw(15) << baza[sw]->getNazwisko() << setw(1) << "|" << endl;
		cout << setfill('-') << setw(1) << "-" << setw(6) << "-" << setw(1) << "-" << setw(10) << "-" << setw(1) << "-" << setw(15) << "-" << setw(1) << "-" << endl;
		system("pause");
	}
	else
	{
		cout << this->message.getItem("201") << endl;
		system("pause");
	}

}

void View_Controller::getDatabaseFromFile(Database_Controller<Zaklad> *database, const char *file)
{
	database->getDb().clear();
	ifstream dbFile;
	dbFile.open(file);
	while (true)
	{
		int id;
		int typ;
		string nazwa;
		int win;
		dbFile >> id >> typ >> nazwa;
		if (typ == 1)
		{
			double k1;
			double kx;
			double k2;
			dbFile >> k1 >> kx >> k2 >> win;
			database->getDb().push_back(new Pilkarski(nazwa, k1, kx, k2, win,id));
			if (!dbFile.good())
			{
				break;
			}
	
		}
		else if (typ == 2)
		{
			double k1;
			double k2;
			dbFile >> k1 >> k2 >> win;
			database->getDb().push_back(new Koszykarski(nazwa, k1, k2, win,id));
			if (!dbFile.good())
			{
				break;
			}
		}
		else if (typ == 3)
		{
			double kV;
			dbFile >> kV >> win;
			database->getDb().push_back(new Skoki(nazwa, kV, win, id));
			
			if (!dbFile.good())
			{
				break;
			}	
		}
	}
	cout << message.getItem("102") << endl;
	system("pause");

}

void View_Controller::getAllZaklady(Database_Controller<Zaklad> *db)
{
	cout << setfill('-') << setw(1) << "+" << setw(78) << "-" << setw(1) << "+";
	for (int i = 0; i < db->getDb().size(); i++)
	{
		db->getDb()[i]->disp();
	}
	system("pause");
}

void View_Controller::deleteAllZaklady(Database_Controller<Zaklad>* db)
{
	db->getDb().clear();
	cout << message.getItem("103") << endl;
	system("pause");
}

void View_Controller::addZaklad(Database_Controller<Zaklad>* db)
{
	int typ;
	string nazwa;
	cout << message.getItem("104") << endl;
	cout << message.getItem("106") << endl;
	cin >> nazwa;
	cout << message.getItem("105") << endl;
	cin >> typ;

	if (typ == 1)
	{
		double *kursy = new double[3];
		cout << message.getItem("107") << endl;
		cin >> kursy[0];
		cout << message.getItem("108") << endl;
		cin >> kursy[1];
		cout << message.getItem("108") << endl;
		cin >> kursy[2];

		db->getDb().push_back(new Pilkarski(nazwa, kursy[0], kursy[1], kursy[2], -1, rand()));
		delete[] kursy;
		kursy = NULL;
	}
	else if (typ == 2)
	{
		double *kursy = new double[2];
		cout << message.getItem("107") << endl;
		cin >> kursy[0];
		cout << message.getItem("108") << endl;
		cin >> kursy[1];

		db->getDb().push_back(new Koszykarski(nazwa, kursy[0],  kursy[1], -1, rand()));
		delete[] kursy;
		kursy = NULL;
	}
	else if (typ == 3)
	{
		double kursy;
		cout << message.getItem("110") << endl;
		cin >> kursy;

		db->getDb().push_back(new Skoki(nazwa, kursy, -1, rand()));
	}
	else
	{
		this->zalogowany();
		cout << message.getItem("203") << endl;
		system("pause");
	}
	//clear
	this->zalogowany();
	cout << message.getItem("111") << endl;
	system("pause");
}

void View_Controller::eraseZaklad(Database_Controller<Zaklad>* db)
{
	cout << message.getItem("112") << endl;
	int id;
	cin >> id;

	bool check = false;

	for (int i = 0; i < db->getDb().size(); i++)
	{
		if (id == db->getDb()[i]->getId())
		{
			db->getDb().erase(db->getDb().begin() + (i), db->getDb().begin() + (i+1));
			check = true;
			break;
		}
	}
	if (check)
	{
		cout << message.getItem("113") << endl;
	}
	else
	{
		cout << message.getItem("114") << endl;
	}
	system("pause");
}

void View_Controller::addResultMatch(Database_Controller<Zaklad>* db)
{
	int id, wynik;
	cout << message.getItem("115") << endl;
	cin >> id;
	cout << message.getItem("116") << endl;
	cin >> wynik;

	bool check = false;

	for (int i = 0; i < db->getDb().size(); i++)
	{
		if (id == db->getDb()[i]->getId())
		{
			db->getDb()[i]->setWygrana(wynik);
			check = true;
			break;
		}
	}
	if (check)
	{
		cout << message.getItem("120") << endl;
	}
	else
	{
		cout << message.getItem("114") << endl;
	}
	system("pause");

}

void View_Controller::saveAll(Database_Controller<Zaklad>* db, const char *file)
{
	ofstream f;
	f.open(file);

	for (int i = 0; i < db->getDb().size(); i++)
	{
		int id = db->getDb()[i]->getId();
		int typ = db->getDb()[i]->getTyp();
		string nazwa = db->getDb()[i]->getNazwa();
		string kursy = db->getDb()[i]->getKursy();
		int win = db->getDb()[i]->getWin();

		f << id << " " << typ << " " << nazwa << " " << kursy  << " "<< win << endl;
	}
	db->getDb().clear();
	f.close();
	
}

void View_Controller::end()
{
	cout << this->message.getItem("301") << endl << this->message.getItem("302") << endl;
	system("pause");
	exit(1);
}
