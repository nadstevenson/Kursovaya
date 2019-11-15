#include "stdafx.h"
#include "Rest.h"


Rest::Rest() :Voucher()
{

}

Rest::Rest(int voucher_number,string Name, string Surname, int cost, int time_of_stay, int day, int month, int year, string first_country, string second_country, string hotel) :Voucher(voucher_number,Name, Surname, cost, time_of_stay, day, month, year)
{
	this->first_country = first_country.substr(0, first_country.length());
	this->second_country = second_country.substr(0, second_country.length());
	this->hotel = hotel.substr(0, hotel.length());
}

Rest::Rest(const Rest& obj) :Voucher(obj.voucher_number, obj.Name, obj.Surname, obj.cost, obj.time_of_stay, obj.voucher_date.day, obj.voucher_date.month, obj.voucher_date.year)
{
	this->first_country = obj.first_country.substr(0, obj.first_country.length());
	this->second_country = obj.second_country.substr(0, obj.second_country.length());
	this->hotel = obj.hotel.substr(0, obj.hotel.length());
}


void Rest::output()
{
	cout <<"|"<< setw(10) << type << "|" <<setw(5)<< voucher_number 
		<< "|" <<setw(15)<< Name << "|" << setw(15) << Surname<<"|";
	date_output();
	cout<<"|"<<setw(10)<<cost <<"|" << setw(18) << time_of_stay 
		<< "|" << setw(14) << hotel << "|" << setw(20) << first_country
		<< "|" << setw(15) << second_country;
	cout <<endl<< "___|__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;

}

void Rest::set(int number)
{
	vector<Country>country_vect;
	vector<Country>first_countries;
	open(&country_vect, "country.txt");
	open(&first_countries, "firstcountry.txt");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool check = false;
	this->voucher_number = number;

	cout << "Введите время пребывания ";
	Voucher::time_of_stay =Func::NumCheck();
	cout << "Введите дату ";

	voucher_date = Func::CheckDate();
	bool cont = true;
	cout << "Выберите странy прибытия "<<endl;
	Output(country_vect);
	while (cont) {
		int choice = Func::NumCheck();
		if(choice <= country_vect.size()&&choice>0)
		{
			this->cost = country_vect[choice - 1].cost;
			this->second_country = country_vect[choice - 1].country.substr(0, country_vect[choice - 1].country.length());
			cont = false;
		}
	}

	cout << "Выберите страну отправления" << endl;
	cont = true;
	Output(first_countries);
	while (cont) {
		int choice = Func::NumCheck();
		if (choice <= first_countries.size() && choice>0)
		{
			this->cost += first_countries[choice - 1].cost;
			this->first_country = first_countries[choice - 1].country.substr(0, first_countries[choice - 1].country.length());
			cont = false;
		}
	}
	
	this->cost = this->cost*this->time_of_stay;

	cout << "Введите отель ";
	cin >> hotel;

}

void Rest::change()
{
	vector<Country>country_vect;
	vector<Country>first_countries;
	open(&country_vect, "country.txt");
	open(&first_countries, "firstcountry.txt");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	char cont = '1';
	while (cont == '1')
	{
		system("cls	");
		Func::OutputRequestsRest();
		cout << "Выберите что изменить\n1)Страны отправления и прибытия\n2)Время пербывания\n3)Дату\n4)Отель\n5)Выход\n";
		choice = Func::NumCheck();
		switch (choice)
		{
		case 1:
		{
			bool cont = true;
			cout << "Выберите странy прибытия " << endl;
			Output(country_vect);
			while (cont) {
				int choice = Func::NumCheck();
				if (choice <= country_vect.size() && choice>0)
				{
					this->cost = country_vect[choice - 1].cost;
					this->second_country = country_vect[choice - 1].country.substr(0, country_vect[choice - 1].country.length());
					cont = false;
				}
			}

			cout << "Выберите страну отправления" << endl;
			cont = true;
			Output(first_countries);
			while (cont) {
				int choice = Func::NumCheck();
				if (choice <= first_countries.size() && choice>0)
				{
					this->cost += first_countries[choice - 1].cost;
					this->first_country = first_countries[choice - 1].country.substr(0, first_countries[choice - 1].country.length());
					cont = false;
				}
			}
			this->cost = this->cost*this->time_of_stay;

		}break;

		case 2:
		{
			cout << "Текущее время пребывания: " << this->time_of_stay << endl;
			cout << "Изменить на ";
			this->time_of_stay = Func::NumCheck();
		}break;

		case 3:
		{
			cout << "Текущая дата: ";
			this->date_output();
			cout << "\nИзменить на ";
			Voucher::voucher_date = Func::CheckDate();

		}break;

		case 4:
		{
			cout << "Текущий отель: " << this->hotel << endl;
			cout << "Изменить на ";
			cin >> this->hotel;
		}break;

		case 5: {cont = '2'; } break;

		default:cout << "Неверный ввод";
			break;
		}
	}

}



void Rest::Userchange(User user)
{
	vector<Country>country_vect;
	vector<Country>first_countries;
	open(&country_vect, "country.txt");
	open(&first_countries, "firstcountry.txt");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int choice;
	char cont = '1';
	while (cont == '1')
	{
		system("cls	");
		cout << "Выберите что изменить\n1)Страны отправления и прибытия\n2)Время пербывания\n3)Дату\n4)Отель\n5)Выход\n";
		choice = Func::NumCheck();
		char request[200];
		switch (choice)
		{
		case 1:
		{
			bool cont = true;
			cout << "Выберите странy прибытия " << endl;
			Output(country_vect);
			while (cont) {
				int choice = Func::NumCheck();
				if (choice <= country_vect.size() && choice>0)
				{
					this->cost = country_vect[choice - 1].cost;
					this->second_country = country_vect[choice - 1].country.substr(0, country_vect[choice - 1].country.length());
					cont = false;
				}
			}

			cout << "Выберите страну отправления" << endl;
			cont = true;
			Output(first_countries);
			while (cont) {
				int choice = Func::NumCheck();
				if (choice <= first_countries.size() && choice>0)
				{
					this->cost += first_countries[choice - 1].cost;
					this->first_country = first_countries[choice - 1].country.substr(0, first_countries[choice - 1].country.length());
					cont = false;
				}
			}

			this->cost = this->cost*this->time_of_stay;


			ofstream file;
			file.open("changereqrest.txt", ios::app);
			if (file.is_open())
				file << endl << "В заказе №" << Voucher::voucher_number << " изменить значение страны отправления на " << this->first_country<<" изменить значение страны прибытия на "<<this->second_country;
			file.close();
			cout << "\nЗапрос на изменение отправлен";
		}break;

		case 2:
		{
			char number[10];
			_itoa(this->voucher_number, number, 10);
			cout << "Текущее время пребывания: " << this->time_of_stay << endl;
			cout << "Изменить на ";
			this->time_of_stay = Func::NumCheck();
			ofstream file;
			file.open("changereqrest.txt", ios::app);
			if (file.is_open())
				file <<endl<< "В заказе №" << Voucher::voucher_number << " изменить значение времени пребывания на " << this->time_of_stay;
			file.close();
			cout << "\nЗапрос на изменение отправлен";

		}break;

		case 3:
		{
			char number[10];
			_itoa(this->voucher_number, number, 10);
			cout << "Текущая дата: ";
			this->date_output();
			cout << "\nИзменить на ";
			this->voucher_date=Func::CheckDate();
			
			ofstream file;
			file.open("changereqrest.txt", ios::app);
			if (file.is_open())
				file <<endl<< "В заказе №" << Voucher::voucher_number << " изменить значение даты на " 
				<< voucher_date.day<<"."<<voucher_date.month<<"."<<
				voucher_date.year;
			file.close();
			cout << "\nЗапрос на изменение отправлен";

		}break;

		case 4:
		{
			cout << "Текущий отель: " << this->hotel << endl;
			cout << "Изменить на ";
			cin >> this->hotel;
			ofstream file;
			file.open("changereqrest.txt", ios::app);
			if (file.is_open())
				file << endl << "В заказе №" << Voucher::voucher_number << " изменить значение отеля на "
				<< this->hotel;
			file.close();
			cout << "\nЗапрос на изменение отправлен";

		}break;

		case 5: {cont = '2'; } break;

		default:cout << "Неверный ввод";
			break;
		}
	}

}

void Rest::Rest_add()
{
	ofstream file;
	file.open("rest.txt", ios::app);
	if (file.is_open())
		file<<endl<<voucher_number 
		<< endl << Voucher::Name
		<< endl << Voucher::Surname
		<< endl << Voucher::cost
		<< endl << Voucher::time_of_stay
		<< endl << Voucher::voucher_date.day
		<< endl << Voucher::voucher_date.month
		<< endl << Voucher::voucher_date.year
		<< endl << this->first_country << endl << this->second_country
		<< endl << this->hotel;
	file.close();
	return;
}



void RestOpen(vector<Rest>* restlist)
{
	ifstream file;
	file.open("rest.txt");
	if ((file.is_open())) {
		Rest file_rest;
		file.ignore(1);
		while (!file.eof())
		{
			file >> file_rest.voucher_number;
			file.ignore(1);
			getline(file, file_rest.Name);
			getline(file, file_rest.Surname);
			
			file >> file_rest.cost;
			file >> file_rest.time_of_stay;
			file >> file_rest.voucher_date.day;
			file >> file_rest.voucher_date.month;
			file >> file_rest.voucher_date.year;

			file.ignore(1);
			getline(file, file_rest.first_country);
			getline(file, file_rest.second_country);
			getline(file, file_rest.hotel);
			restlist->push_back(file_rest);
		}
	}
	file.close();
}



Rest::~Rest()
{
}

ostream& operator<<(ostream& os, const Rest& dt)
{
	os <<"|"<< setw(10) << dt.type << "|" <<setw(5)<< dt.voucher_number 
		<< "|" <<setw(15)<< dt.Name << "|" << setw(15) << dt.Surname<<"|";
	cout << setw(2) << dt.voucher_date.day << "." << setw(2) << dt.voucher_date.month << "." << setw(4) << dt.voucher_date.year;

	cout<<"|"<<setw(10)<<dt.cost <<"|" << setw(18) << dt.time_of_stay 
		<< "|" << setw(14) << dt.hotel << "|" << setw(20) << dt.first_country
		<< "|" << setw(15) << dt.second_country;
	cout <<endl<< "___|__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;

	return os;
}

Rest& Rest::operator=(const Rest& other)
{
	this->first_country = other.first_country.substr(0, other.first_country.length());
	this->second_country = other.second_country.substr(0, other.second_country.length());
	this->hotel = other.hotel.substr(0, other.hotel.length());
	this->voucher_number = other.voucher_number;
	this->Name = other.Name.substr(0, other.Name.length());
	this->Surname = other.Surname.substr(0, other.Surname.length());
	this->cost = other.cost;
	this->time_of_stay = other.time_of_stay;
	this->voucher_date.day = other.voucher_date.day;
	this->voucher_date.month = other.voucher_date.month;
	this->voucher_date.year = other.voucher_date.year;
	return *this;
}