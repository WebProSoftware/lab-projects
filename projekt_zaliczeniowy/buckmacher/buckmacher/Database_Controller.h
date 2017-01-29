#pragma once

#include <ostream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

template<typename T> class Database_Controller
{
protected:
	vector<T *> db;

public:
	Database_Controller();
	~Database_Controller();
	void setDb(vector <T*> &database) { this->db = database; }
	vector<T *> &getDb() { return this->db; }
};

