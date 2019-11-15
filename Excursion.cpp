#include "stdafx.h"
#include "Excursion.h"


Excursion::Excursion(int voucher_number,char Name[30], char Surname[30], int cost, int time_of_stay, int day, int month, int year,string first_country,string countries):Voucher(voucher_number,Name, Surname, cost, time_of_stay, day, month, year)
{
	this->first_country = first_country.substr(0, first_country.length());
	this->countries = countries.substr(0, countries.length());
}

Excursion::Excursion() :Voucher()
{
}

void Excursion::output()
{
	cout << "|" << setw(10) << type << "|" << setw(5) << voucher_number
		<< "|" << setw(15) << Name << "|" << setw(15) << Surname << "|";
	date_output();
	cout << "|" << setw(10) << cost << "|" << setw(18) << time_of_stay
		<< "|" << setw(14) << "-" << "|" << setw(20) << first_country
		<< "|" << setw(15) << countries;
	cout << endl << "___|__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
}

void Excursion::add_country(string country)
{
	countries.insert(countries.size(), ", ");
	countries.insert(countries.size(), country);
}

void Excursion::change() 
{
	vector<Country>countries_vect;
	vector<Country>first_countries;
	open(&first_countries, "firstcountry.txt");
	open(&countries_vect, "countries.txt");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	char cont = '1';
	while (cont == '1')
	{
		system("cls	");
		Func::OutputRequestsExcursion();
		cout << "�������� ��� ��������\n1)���������\n2)����� ����������\n3)����\n4)�������� ������ ����������� � ���������\n5)�������� �������\n6)�����\n";
		choice = Func::NumCheck();
		switch (choice)
		{
		case 1:
		{
			cout << "������� ���������: " << this->cost << endl;
			cout << "�������� �� ";
			this->cost = Func::NumCheck();
		}break;

		case 2:
		{
			cout << "������� ����� ����������: " << this->time_of_stay << endl;
			cout << "�������� �� ";
			this->time_of_stay = Func::NumCheck();
		}break;

		case 3:
		{
			cout << "������� ����: ";
			this->date_output();
			cout << "\n�������� �� ";
			voucher_date = Func::CheckDate();
		}break;

		case 4:
		{
			bool contin = true;
			cout << "�������� ���������" << endl;
			Output(countries_vect);
			while (contin) {
				int choice = Func::NumCheck();
				if (choice <= countries_vect.size() && choice>0)
				{
					this->cost = countries_vect[choice - 1].cost;
					this->countries = countries_vect[choice - 1].country.substr(0, countries_vect[choice - 1].country.length());
					contin = false;
				}
			}

			cout << "�������� ������ �����������" << endl;
			contin = true;
			Output(first_countries);
			while (contin) {
				int choice = Func::NumCheck();
				if (choice <= first_countries.size() && choice>0)
				{
					this->cost += first_countries[choice - 1].cost;
					this->first_country = first_countries[choice - 1].country.substr(0, first_countries[choice - 1].country.length());
					contin = false;
				}
			}

			this->cost = this->cost*this->time_of_stay;


		}break;

		case 5:
		{
			cout << "�������� ������: ";

			string country;
			cin >> country;
			add_country(country);
		}break;

		

		case 7: {cont = '2'; } break;

		default:cout << "�������� ����";
			break;
		}
	}
}

void Excursion::set(int number)
{
	vector<Country>countries_vect;
	vector<Country>first_countries;
	open(&first_countries, "firstcountry.txt");
	open(&countries_vect, "countries.txt");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool check = false;
	this->voucher_number = number ;
	cout << "������� ����� ���������� ";
	Voucher::time_of_stay = Func::NumCheck();
	cout << "������� ���� ";

	voucher_date = Func::CheckDate();


	bool cont = true;
	cout << "�������� ���������" << endl;
	Output(countries_vect);
	while (cont) {
		int choice = Func::NumCheck();
		if (choice <= countries_vect.size() && choice>0)
		{
			this->cost = countries_vect[choice - 1].cost;
			this->countries = countries_vect[choice - 1].country.substr(0, countries_vect[choice - 1].country.length());
			cont = false;
		}
	}

	cout << "�������� ������ �����������" << endl;
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


}

Excursion::~Excursion()
{
}

void Excursion::Userchange(User user)
{
	vector<Country>countries_vect;
	vector<Country>first_countries;
	open(&first_countries, "firstcountry.txt");
	open(&countries_vect, "countries.txt");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	char cont = '1';
	while (cont == '1')
	{
		system("cls	");
		cout << "�������� ��� ��������\n1)������ ����������� � ���������\n2)����� ����������\n3)����\n4)�������� ������\n5)�����\n";
		choice = Func::NumCheck();
		char request[200];
		switch (choice)
		{
		case 1:
		{
			bool contin = true;
			cout << "�������� ���������" << endl;
			Output(countries_vect);
			while (contin) {
				int choice = Func::NumCheck();
				if (choice <= countries_vect.size() && choice>0)
				{
					this->cost = countries_vect[choice - 1].cost;
					this->countries = countries_vect[choice - 1].country.substr(0, countries_vect[choice - 1].country.length());
					contin = false;
				}
			}

			cout << "�������� ������ �����������" << endl;
			contin = true;
			Output(first_countries);
			while (contin) {
				int choice = Func::NumCheck();
				if (choice <= first_countries.size() && choice>0)
				{
					this->cost += first_countries[choice - 1].cost;
					this->first_country = first_countries[choice - 1].country.substr(0, first_countries[choice - 1].country.length());
					contin = false;
				}
			}

			this->cost = this->cost*this->time_of_stay;


			ofstream file;
			file.open("changereqexcursion.txt", ios::app);
			if (file.is_open())
				file << endl << "� ������ �" << Voucher::voucher_number << " �������� ������ ����������� �� " << this->first_country<<" �������� ��������� �� "<<this->countries;
			file.close();
			cout << "\n������ �� ��������� ���������";

		}break;

		case 2:
		{
			char number[10];
			_itoa(this->voucher_number, number, 10);
			cout << "������� ����� ����������: " << this->time_of_stay << endl;
			cout << "�������� �� ";
			this->time_of_stay = Func::NumCheck();
			ofstream file;
			file.open("changereqexcursion.txt", ios::app);
			if (file.is_open())
				file << endl << "� ������ �" << Voucher::voucher_number << " �������� �������� ������� ���������� �� " << this->time_of_stay;
			file.close();
			cout << "\n������ �� ��������� ���������";

		}break;

		case 3:
		{
			char number[10];
			_itoa(this->voucher_number, number, 10);
			cout << "������� ����: ";
			this->date_output();
			cout << "\n�������� �� ";
			this->voucher_date = Func::CheckDate();

			ofstream file;
			file.open("changereqexcursion.txt", ios::app);
			if (file.is_open())
				file << endl << "� ������ �" << Voucher::voucher_number << " �������� �������� ���� �� "
				<< voucher_date.day << "." <<voucher_date.month << "." <<
				voucher_date.year;
			file.close();
			cout << "\n������ �� ��������� ���������";

		}break;



		case 4:
		{
			cout << "�������� ������: ";

			string country;
			cin >> country;
			add_country(country);
			ofstream file;
			file.open("changereqexcursion.txt", ios::app);
			if (file.is_open())
				file << endl << "� ������ �" << Voucher::voucher_number << " �������� ������ "
				<< country;
			file.close();
			cout << "\n������ �� ��������� ���������";
		}break;

	

		case 5: {cont = '2'; } break;

		default:cout << "�������� ����";
			break;
		}
	}
}

void Excursion::Excursion_add()
{
	ofstream file;
	file.open("excursion.txt", ios::app);
	if (file.is_open())
		file << endl << voucher_number
		<< endl << Voucher::Name
		<< endl << Voucher::Surname
		<< endl << Voucher::cost
		<< endl << Voucher::time_of_stay
		<< endl << Voucher::voucher_date.day
		<< endl << Voucher::voucher_date.month
		<< endl << Voucher::voucher_date.year
		<< endl << this->first_country 
		<<endl<<this->countries;
	file.close();
	return;
}

void ExcursionOpen(vector<Excursion>* excurslist)
{
	ifstream file;
	file.open("excursion.txt");
	if ((file.is_open())) {
		Excursion file_excursion;
		file.ignore(1);
		while (!file.eof())
		{
			file >> file_excursion.voucher_number;
			file.ignore(1);
			getline(file, file_excursion.Name);
			getline(file, file_excursion.Surname);

			file >> file_excursion.cost;
			file >> file_excursion.time_of_stay;
			file >> file_excursion.voucher_date.day;
			file >> file_excursion.voucher_date.month;
			file >> file_excursion.voucher_date.year;

			file.ignore(1);
			getline(file, file_excursion.first_country);
			getline(file, file_excursion.countries);
			excurslist->push_back(file_excursion);
		}
	}
	file.close();
}
