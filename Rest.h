#pragma once
#include "Voucher.h"
#include "Functions.h"
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
#include "User.h"
#include "Country.h"

using namespace std;


class Rest :public Voucher
{
	string  second_country, hotel;
public:
	char type[6]  = "־עהûץ";
	Rest();
	virtual void set(int number);
	Rest(int voucher_number,string Name, string Surname, int cost, int time_of_stay, int day, int month, int year, string first_country, string second_country, string hotel);
	Rest(const Rest& obj);
	virtual void change();
	virtual void Userchange(User user);
	virtual void output();
	void Rest_add();
	friend void SortingMenu(vector<Voucher*> vlist);
	friend ostream& operator<<(ostream& os, const Rest& dt);
	Rest& operator=(const Rest& other);
	friend void RestOpen(vector<Rest>* restlist);

	~Rest();
};

