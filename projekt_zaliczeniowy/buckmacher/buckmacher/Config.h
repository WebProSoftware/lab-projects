#pragma once
#include "Dane.h"

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>


using namespace std;

class Config
{
private:
	string trim(string str);
	map <string, Dane> ElementKonfiguracji;

public:
	Config(const char* cfgfile, const char Separator = ':');
	Dane getItem(const string &key);
};

