#pragma once
#include <conio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <locale.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>;
#include <windows.h>;
#include <algorithm>
#include "Functions.h"
using namespace std;

class Country
{
public:
	string country;
	int cost;
	void save(char name[50]);
	friend void open(vector<Country>*contries, char name[50]);
	void set_country();
	void set_countries();
	Country();
	friend ostream& operator<<(ostream& os, const Country& dt);
	friend void Output(vector<Country> countries);
	~Country();
};

