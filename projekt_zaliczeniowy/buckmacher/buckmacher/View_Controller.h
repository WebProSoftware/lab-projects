#pragma once
#include "Config.h"
#include "User.h"
#include "Zaklad.h"
#include "Pilkarski.h"
#include "Koszykarski.h"
#include "Skoki.h"
#include "Database_Controller.h"

#include <iostream>
#include <vector>
//Linijka potrzebna do zadeklarowanie arguemnut vector<user> baza
class User;


using namespace std;

class View_Controller
{
	Config message;
	Config config;

public:
	View_Controller(Config &msg, Config &conf) : message(msg), config(conf) {}

	void header();
	bool zaloguj();
	void zalogowany();
	void end();
	void blednawartoscmenu();
	void menu();

	void getAllUsers(std::vector<User*> baza);
	void getUserById(std::vector<User*> baza);

	void getDatabaseFromFile(Database_Controller<Zaklad> *database, const char *file);
	void getAllZaklady(Database_Controller<Zaklad> *db);
	void deleteAllZaklady(Database_Controller<Zaklad> *db);
	void addZaklad(Database_Controller<Zaklad> *db);
	void eraseZaklad(Database_Controller<Zaklad> *db);
	void addResultMatch(Database_Controller<Zaklad> *db);
	void saveAll(Database_Controller<Zaklad> *db, const char *file);
};


