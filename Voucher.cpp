#include "stdafx.h"
#include "Voucher.h"


Voucher::Voucher()
{

	this->cost = 0;
	this->time_of_stay = 0;
	voucher_date.day = 0;
	voucher_date.month = 0;
	voucher_date.year = 0;
}


Voucher::Voucher(int voucher_number,string in_Name, string  in_Surname, int cost, int time_of_stay, int day, int month, int year)
{
	this->voucher_number = voucher_number;
	Name = in_Name.substr(0, in_Name.length());
	Surname = in_Surname.substr(0, in_Surname.length());
	this->cost = cost;
	this->time_of_stay = time_of_stay;
	voucher_date.day = day;
	voucher_date.month = month;
	voucher_date.year = year;
}

void Voucher::date_output()
{
	cout <<setw(2)<< voucher_date.day << "." <<setw(2)<< voucher_date.month << "." << setw(4) << voucher_date.year;
}



Voucher::~Voucher()
{
}