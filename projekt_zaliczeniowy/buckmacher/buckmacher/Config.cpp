#include "stdafx.h"
#include "Config.h"


Config::Config(const char * cfgfile, const char Separator)
{
	fstream file(cfgfile, ios::in);
	if (file)
	{
		string line;
		while (getline(file,line))
		{
			size_t sep = line.find_first_of(Separator);
			size_t comment = line.find_first_of("#");
			if (sep != string::npos)
			{
				string key = trim(line.substr(0, sep));
				string value = trim(line.substr(sep + 1));
				if (!key.empty() && !value.empty())
				{
					ElementKonfiguracji[key] = Dane(value);
				}
				else
				{
					throw runtime_error("blad w konfiguracji brakuje klucza albo warosci");
				}
			}
			else if(comment == string::npos)
			{
				throw runtime_error("blad w konfiguracji brakuje klucza albo warosci");
			}		
		}
	}
	else
	{
		throw runtime_error("blad otwarcia pliku");
	}
}

Dane Config::getItem(const string & key)
{
	map <string, Dane>::const_iterator it = ElementKonfiguracji.find(key);

	if (it != ElementKonfiguracji.end())
	{
		return it->second;
	}
	else
	{
		throw runtime_error("Nie moze znalezc odpowiedniego konfiga");
	}
}


string Config::trim(string str)
{
	size_t pozycja = str.find_first_not_of(" \t\n");

	if (pozycja != string::npos)
	{
		str.erase(0, pozycja);
	}

	pozycja = str.find_last_not_of(" \t\n");

	if (pozycja)
	{
		str.erase(pozycja + 1);
	}

	return str;
}
