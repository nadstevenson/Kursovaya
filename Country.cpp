#include "stdafx.h"
#include "Country.h"


Country::Country()
{
}

void Country::set_country()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.ignore(1);
	cout << "Введите страну ";
	getline(std::cin, country);
	cout << "Введите цену ";
	cost = Func::NumCheck();
}

void Country::set_countries()
{
	bool cont = true;
	while (cont) {
		cout << "Количество стран(минимум 3) ";
		int countries_quantity = Func::NumCheck();
		if (countries_quantity>2)
		{
			cin >> this->country;
			for (int i = 1; i<countries_quantity; i++)
			{
				string country;
				cin >> country;
				this->country.insert(this->country.size(), ", ");
				this->country.insert(this->country.size(), country);;
			}
			cont = false;
		}
		else { cout << "Повторите ввод"; _getch(); }

	}
	cout << "Введите цену ";
	cost = Func::NumCheck();

}

void Country::save(char name[50])
{
	ofstream file;
	file.open(name, ios::app);
	if (file.is_open())
		file << endl << cost<<endl<<country;
	file.close();
}

void open(vector<Country>*contries, char name[50])
{
	ifstream file;
	file.open(name);
	if ((file.is_open())) {
		Country file_country;
		file.ignore(1);
		while (!file.eof())
		{
			file >> file_country.cost;
			file.ignore(1);
			getline(file, file_country.country);
			contries->push_back(file_country);
		}
	}
	file.close();
}

Country::~Country()
{
}

ostream& operator<<(ostream& os, const Country& dt)
{
	os << "|" << setw(10) << dt.cost << "|" << setw(30) << dt.country;
		
	cout << endl << "___|__________|_______________________________" << endl;

	return os;
}

void Output(vector<Country> countries)
{
	cout << " № |   Цена   |          Страна(ы)            ";
	cout << endl << "___|__________|_______________________________" << endl;
	for (int i = 0; i < countries.size(); i++)
	{
		cout << setw(3) << i + 1 << countries[i];

	}
}