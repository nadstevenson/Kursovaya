#pragma once
#include "Voucher.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <conio.h>
#include <string>
#include "Country.h"

using namespace std;


class Excursion:public Voucher
{
protected:
	string countries;
public:
	char type[10] = "Ёкскурси€";
	Excursion();
	Excursion(int voucher_number,char Name[30], char Surname[30], int cost, int time_of_stay, int day, int month, int year, string first_country, string countries);
	virtual void output();
	virtual void change();
	virtual void set(int number);
	virtual void Userchange(User user) ;
	void Excursion_add();
	void add_country(string country);
	friend void SearchMenu(vector<Voucher*> vlist);
	friend void ExcursionOpen(vector<Excursion>* excurslist);

	friend void SortingMenu(vector<Voucher*> vlist);
	//bool operator==(Excursion obj);
	~Excursion();
};

