#pragma once
#include "Date.h"
#include <conio.h>
#include <iostream>
#include "User.h"
using namespace std;


class Voucher
{
protected:
public:
	int cost, time_of_stay;
	Date voucher_date;
	string Name;
	string Surname;
	string first_country;
	int voucher_number;
	Voucher();
	Voucher(int voucher_number,string in_Name, string  in_Surname, int cost, int time_of_stay, int day, int month, int year);
	virtual void change() = 0;
	virtual void output() = 0;
	virtual void set(int number) = 0;
	virtual void Userchange(User user)=0;
	void date_output();
	~Voucher();
};

