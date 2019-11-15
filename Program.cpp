#include "stdafx.h"
#include "Program.h"
#include "Search.h"
#include "Country.h"

void Output(vector<Voucher*> vlist)
{
	cout << " � |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
	cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;

	for (int i = 0; i < vlist.size(); i++)
	{
		cout << setw(3) << i + 1;
		vlist[i]->output();
	}
}

void Output(Voucher* voucher)
{
	cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
	cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
	cout << "   ";
	voucher->output();

}



void Output(vector<User>uservect)
{
	cout << "�__|       �����        |        ������      |         ���        |      �������       |" << endl;
	cout << "___|____________________|____________________|____________________|____________________|" << endl;
	for (int i = 0; i < uservect.size(); i++)
	{
		cout << setw(3) << i + 1;
		uservect[i].Output();
	}
}

void Output(User user)
{
	cout << "�__|       �����        |        ������      |         ���        |      �������       |" << endl;
	cout << "___|____________________|____________________|____________________|____________________|" << endl;
	cout << "   ";
	user.Output();
}

void VoucherSave(vector<Rest>restlist)
{
	Func::ClearFile("rest.txt");
	for (int i = 0; i<restlist.size(); i++)
	{
		restlist[i].Rest_add();
	}
}

void VoucherSave(vector<Excursion>excurslist)
{
	Func::ClearFile("excursion.txt");
	for (int i = 0; i<excurslist.size(); i++)
	{
		excurslist[i].Excursion_add();
	}
}


void UserMenu_Output(vector<Voucher*> vlist, User obj)
{
	if (vlist.empty())cout << "������ ����";
	else
	{
		Output(vlist);

		cout << "\n" << vlist.size() + 1 << ") �����";
		int del = Func::NumCheck();
		if (del <= vlist.size())
		{
			if (vlist[del - 1]->Name == obj.name && vlist[del - 1]->Surname == obj.surname)
			{
				bool menu = true;
				while (menu)
				{

					system("cls");
					cout << "��������� �������: " << endl;
					Output(vlist[del - 1]);
					cout << "\n��� �� ������ � ��� �������?" << endl;
					cout << "1)��������\n2)�������\n������)�����";
					int choice = Func::NumCheck();
					switch (choice)
					{
					case 1: {vlist[del - 1]->Userchange(obj); cout << "\n������ �� ��������� ���������"; _getch(); }break;

					case 2:
					{
						ofstream file;
						file.open("deletereq.txt", ios::app);
						if (file.is_open())
							file << endl << "������� ����� �" << vlist[del - 1]->voucher_number;
						file.close();
						cout << "\n������ �� ��������� ���������";
						_getch();
						menu = false;
					}break;
					default: {menu = false; }break;
					}
				}
			}
			else cout << "�� �� ������ ��������/������� ���� �������" << endl;

		}
		else cout << "�����" << endl;
		_getch();

	}
}


void SearchMenu(vector<Voucher*> vlist, User obj)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (vlist.empty())cout << "������ ����";
	else {
		int choice;
		char cont = '1';
		while (cont == '1')
		{
			system("cls	");
			cout << "�������� �� ������ �������� �������������\n1)���������\n2)����� ����������\n3)������� �� ������� �����\n4)������ �����������\n5)������ ���� �������\n6)�����";
			choice = Func::NumCheck();
			switch (choice)
			{
			case 1:
			{
				system("cls");
				cout << "������� ���������" << endl;
				int serched_cost = Func::NumCheck();
				cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
				cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
				for (int i = 0; i < vlist.size(); i++)
				{
					if (vlist[i]->cost == serched_cost)
					{
						cout << "   ";
						vlist[i]->output();
					}
				}
				_getch();

			}break;

			case 2:
			{
				system("cls");
				cout << "������� ����� ����������" << endl;
				int serched_time_of_stay = Func::NumCheck();
				cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
				cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
				for (int i = 0; i < vlist.size(); i++)
				{
					if (vlist[i]->time_of_stay == serched_time_of_stay)
					{
						cout << "   ";
						vlist[i]->output();
					}
				}
				_getch();

			}break;

			case 3:
			{
				system("cls");
				cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
				cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
				for (int i = 0; i < vlist.size(); i++)
				{
					if (vlist[i]->voucher_date.year == 2018 && vlist[i]->voucher_date.month == 12)
					{
						cout << "   ";
						vlist[i]->output();
					}
				}
				_getch();

			}break;

			case 4:
			{
				string searched_first_country;
				cout << "������� ������ �����������" << endl;
				cin >> searched_first_country;
				cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
				cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
				for (int i = 0; i < vlist.size(); i++)
				{
					if (vlist[i]->first_country == searched_first_country)
					{
						cout << "   ";
						vlist[i]->output();
					}
				}
				_getch();
			}break;

			case 5:
			{
				cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
				cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
				for (int i = 0; i < vlist.size(); i++)
				{
					if (vlist[i]->Name == obj.name && vlist[i]->Surname == obj.surname)
					{
						cout << "   ";
						vlist[i]->output();
					}
				}
				_getch();

			}break;

			case 6: {cont = '2'; } break;

			default:cout << "�������� ����";
				break;
			}
		}
	}
}


void AddMenu(vector <Excursion>* excurslist, vector<Rest>* restlist, User obj, int last_rest, int last_exc)
{
	cout << "�������� ����� ��� ������� �� ������ ��������\n1)�����\n2)���������\n";
	int choice = Func::NumCheck();
	switch (choice)
	{
	case 1:
	{
		Rest add;
		add.Name = obj.name.substr(0, obj.name.length());
		add.Surname = obj.surname.substr(0, obj.surname.length());
		int number = last_rest + 1;
		add.set(number);
		add.Rest_add();
		restlist->push_back(add);
		cout << restlist->size() - 1;
		_getch();
	}break;
	case 2:
	{
		Excursion add;
		add.Name = obj.name.substr(0, obj.name.length());
		add.Surname = obj.surname.substr(0, obj.surname.length());
		int number = last_exc + 1;
		add.set(number);
		add.Excursion_add();
		excurslist->push_back(add);
		cout << excurslist->size() - 1;
		_getch();
	}break;

	default: {cout << "�������� ����"; _getch(); } break;
	}

}

void DeleteCountriesMenu()
{
	vector<Country>country_vect;
	vector<Country>countries_vect;
	vector<Country>first_countries;
	open(&country_vect, "country.txt");
	open(&countries_vect, "countries.txt");
	open(&first_countries, "firstcountry.txt");
	bool cont = true;
	while(cont)
	{
		system("cls");
		cout << "������� �� ������ �����\n1)������(�����)\n2)������(���������)\n3)������ �����������\n4)�����\n";
		int choice = Func::NumCheck();
		switch(choice)
		{
		case 1: 
		{
			Output(country_vect);
			int del = Func::NumCheck();
			if (del <= country_vect.size() && del>0)
			{
				
				if (country_vect.size() > 1) {
					country_vect.erase(country_vect.begin() + (del-1));
				}
				else { country_vect.clear(); }
				for(int i=0;i<country_vect.size();i++)
				{
					country_vect[i].save("country.txt");
				}
			}
		}break;
		case 2:
		{
			Output(countries_vect);
			int del = Func::NumCheck();
			if (del <= countries_vect.size() && del>0)
			{

				if (countries_vect.size() > 1) {
					countries_vect.erase(countries_vect.begin() + (del-1));
				}
				else { countries_vect.clear(); }
				for (int i = 0; i<countries_vect.size(); i++)
				{
					countries_vect[i].save("countries.txt");
				}
			}
		}break;
		case 3:
		{
			Output(first_countries);
			int del = Func::NumCheck();
			if (del <= first_countries.size() && del>0)
			{

				if (first_countries.size() > 1) {
					first_countries.erase(first_countries.begin() + (del-1));
				}
				else { first_countries.clear(); }
				for (int i = 0; i<first_countries.size(); i++)
				{
					first_countries[i].save("firstcountry.txt");
				}
			}
		}break;
		case 4: {cont = false; }break;
		default: {cout << "�������� ����"; _getch(); }break;

		}

	}
}


void AddCountryMenu()
{
	bool cont = true;
	while (cont)
	{
		system("cls");
		cout << "��������\n1)������(�����)\n2)������(���������)\n3)������ �����������\n4)�����\n";
		int choice = Func::NumCheck();
		switch (choice)
		{
		case 1:
		{
			Country country;
			country.set_country();
			country.save("country.txt");	
		}break;
		case 2:
		{
			Country country;
			country.set_countries();
			country.save("countries.txt");
		}break;
		case 3:
		{
			Country country;
			country.set_country();
			country.save("firstcountry.txt");
		}break;
		case 4: {cont = false; }break;
		default: {cout << "�������� ����"; _getch(); }break;

		}

	}
}


void SortingMenu(vector<Voucher*> vlist)
{
	if (vlist.empty())cout << "������ ����";
	else {
		int choice;
		char cont = '1';
		while (cont == '1')
		{
			system("cls	");
			cout << "�������� �� ������ �������� �����������\n1)���������\n2)����� ����������\n3)������ �����������\n4)�����\n";
			choice = Func::NumCheck();
			switch (choice)
			{
			case 1:
			{
				for (int j = 0; j < vlist.size(); j++) {
					for (int i = 0; i < vlist.size() - 1; i++) {
						if (vlist[i]->cost>vlist[i + 1]->cost) {
							swap(vlist[i], vlist[i + 1]);
						}
					}
				}
				Output(vlist);
				_getch();
			}break;

			case 2:
			{
				for (int j = 0; j < vlist.size(); j++) {
					for (int i = 0; i < vlist.size() - 1; i++) {
						if (vlist[i]->time_of_stay>vlist[i + 1]->time_of_stay) {
							swap(vlist[i], vlist[i + 1]);
						}
					}
				}
				Output(vlist);
				_getch();
			}break;

			case 3:
			{
				for (int j = 0; j < vlist.size(); j++) {
					for (int i = 0; i < vlist.size() - 1; i++) {
						if (vlist[i]->first_country[0]>vlist[i + 1]->first_country[0]) {
							swap(vlist[i], vlist[i + 1]);
						}
					}
				}
				Output(vlist);
				_getch();
			}break;


			case 4: {cont = '2'; } break;

			default:cout << "�������� ����";
				break;
			}
		}
	}
}


void UserMenu(User obj)
{

	vector <Excursion> excurslist;
	ExcursionOpen(&excurslist);
	vector<Rest>restlist;
	RestOpen(&restlist);
	vector<Voucher*> vlist;
	int iterator = 1;

	bool cont = true;
	while (cont)
	{
		vlist.clear();
		for (int i = 0; i < restlist.size(); i++)
		{
			vlist.push_back(&restlist[i]);
		}
		for (int i = 0; i < excurslist.size(); i++)
		{
			vlist.push_back(&excurslist[i]);
		}

		cout << "�� � ���� ������������: " << obj.login << endl;
		cout << "���: " << obj.name << " �������: " << obj.surname;
		cout << "\n1)������ �������*\n2)�������� �������\n3)���������� �� ����\n4)������� ������������� ������ �������\n5)�����*\n6)�����\n(� ������� ���������� * ����������� �������/��������)" << endl;
		int choice;
		while (!(cin >> choice))
		{
			cin.clear();
			while (cin.get() != '\n'&& choice<0 && choice>21);
		}
		rewind(stdin);
		
		switch (choice)
		{
		case 1:
		{
			UserMenu_Output(vlist, obj);

		}break;
		case 2:
		{
			int int_rest;
			if (restlist.empty())int_rest = 100;
			else int_rest = restlist[restlist.size() - 1].voucher_number;

			int int_esc;
			if (excurslist.empty())int_esc = 1000;
			else int_esc = excurslist[excurslist.size() - 1].voucher_number;

			_getch();
			AddMenu(&excurslist, &restlist, obj, int_rest, int_esc);

		}break;
		case 3:
		{
			SearchMenu(vlist, obj);

		}break;
		case 4:
		{
			SortingMenu(vlist);

		}break;
		case 5:
		{
			Search<Voucher*>searcher(vlist);
			int index = searcher.Searching();
			if (index >= 0)
			{
				bool menu = true;
				while (menu)
				{

					system("cls");
					cout << "��������� �������: " << endl;
					Output(vlist[index]);
					if (vlist[index]->Name == obj.name && vlist[index]->Surname == obj.surname)
					{
						cout << "\n��� �� ������ � ��� �������?" << endl;
						cout << "1)��������\n2)�������\n������)�����";
						int choice = Func::NumCheck();
						switch (choice)
						{
						case 1: {vlist[index]->Userchange(obj); }break;

						case 2:
						{
							ofstream file;
							file.open("deletereq.txt", ios::app);
							if (file.is_open())
								file << endl << "������� ����� �" << vlist[index]->voucher_number;
							file.close();
							cout << "\n������ �� �������� ���������";
							_getch();
							menu = false;
						}break;
						default: {menu = false; }break;
						}
					}
					else
					{
						menu = false;
						_getch();
					}
				}
			}
		}break;
		case 6: {cont = false; }break;

		default: {cout << "�������� ����"; _getch(); } break;

		}
		system("cls");
	}
	Func::DeleteEqualRequest("changereqrest.txt");
	Func::DeleteEqualRequest("deletereqrest.txt");


}

void User_save(vector<User>user_vect)
{
	Func::ClearFile("user.txt");
	for (int i = 0; i < user_vect.size(); i++)
	{
		user_vect[i].SaveUser();
	}
}


void AdministratorMenu(Administrator admin)
{
	vector <Excursion> excurslist;
	ExcursionOpen(&excurslist);
	vector<Rest>restlist;
	RestOpen(&restlist);
	vector<User>user_vect;
	ifstream file;
	User_vector_add(&user_vect);

	bool cont = true;
	while (cont)
	{
		cout << "1)������ �������\n2)������ �������������\n3)�������/�������� �������\n4)��������/������� ������������\n5)�������� ������������\n6)�������� �������\n7)������� �� ������ �����\n8)�������� ������(�)\n9)�����" << endl;
		int choice;
		while (!(cin >> choice))
		{
			cin.clear();
			while (cin.get() != '\n'&& choice<0 && choice>21);
		}
		rewind(stdin);
		switch (choice)
		{
		case 1: {
			cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
			cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
			if (restlist.empty())cout << "������ ����";
			else
			{
				for (int i = 0; i < restlist.size(); i++)
				{
					cout << "\n";
					cout << "   ";
					cout << restlist[i];
				}
			}

			if (excurslist.empty())cout << "������ ����";
			else
			{

				for (int i = 0; i < excurslist.size(); i++)
				{
					cout << "\n";
					cout << "   ";
					excurslist[i].output();
				}
			}
			_getch();
		}break;

		case 2:
		{
			if (user_vect.empty()) { cout << "������ ����"; _getch(); }
			else {
				Output(user_vect);
			}
			_getch();
		}break;
		case 3:
		{
			system("cls");
			cout << "��� �������:\n1)�����\n2)���������\n";
			int choice = Func::NumCheck();
			switch (choice)
			{
			case 1: {
				Func::OutputRequestsRest();
				Search<Rest>searcher(restlist);
				cout << "����� �� ������ ";
				int del = searcher.Searching();
				if (del >= 0) {
					bool menu = true;
					while (menu)
					{
						cout << endl;
						system("cls");
						Func::OutputRequestsRest();
						cout << "��������� �������: ";
						cout << endl;
						cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
						cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
						cout << "   ";
						restlist[del].output();
						cout << "\n��� �� ������ � ��� �������?" << endl;
						cout << "1)��������\n2)�������\n������)�����";
						int choice = Func::NumCheck();
						switch (choice)
						{
						case 1: {restlist[del].change(); }break;
						case 2:
						{
							if (restlist.size() > 1) {
								restlist.erase(restlist.begin() + (del));
							}
							else { restlist.clear(); }
							VoucherSave(restlist);
							menu = false;
						}break;

						default: {menu = false; }break;
						}
					}
					VoucherSave(restlist);
				}
				else cout << "�� �������";
				_getch();
			}break;
			case 2:
			{
				Func::OutputRequestsExcursion();
				Search<Excursion>searcher(excurslist);
				cout << "����� �� ������ ";
				int del = searcher.Searching();
				if (del >= 0) {
					bool menu = true;
					while (menu)
					{
						cout << endl;
						system("cls");
						Func::OutputRequestsExcursion();
						cout << "��������� �������: ";
						cout << endl;
						cout << "   |    ���   |�����|      ���      |    �������    |    ���a  |   ����   | ����� ���������� |    *�����    | ������ ����������� | ������ ��������/��������� �� �������" << endl;
						cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
						cout << "   ";
						excurslist[del].output();
						cout << endl<<"��� �� ������ � ��� �������?" << endl;
						cout << "1)��������\n2)�������\n������)�����"<<endl;
						int choice = Func::NumCheck();
						switch (choice)
						{
						case 1: {excurslist[del].change(); }break;
						case 2:
						{
							if (excurslist.size() > 1) {
								excurslist.erase(excurslist.begin() + (del));
							}
							else { excurslist.clear(); }
							VoucherSave(excurslist);
							menu = false;
						}break;

						default: {menu = false; }break;
						}
					}
					VoucherSave(excurslist);
				}
				else cout << "�� �������";
				_getch();
			}break;
			}


		}break;
		case 4:
		{
			if (user_vect.empty()) { cout << "������ ����"; _getch(); }
			else {
				Output(user_vect);
				int del = Func::NumCheck();
				if (del <= user_vect.size())
				{
					bool menu = true;
					while (menu)
					{
						system("cls");
						cout << user_vect.size();
						cout << "��������� �������: " << endl;
						Output(user_vect[del - 1]);
						cout << "\n��� �� ������ � ��� �������?" << endl;
						cout << "1)��������\n2)�������\n������)�����\n";
						int choice = Func::NumCheck();
						switch (choice)
						{
						case 1: {user_vect[del - 1].Change(); }break;
						case 2:
						{
							if (user_vect.size() > 1) {
								user_vect.erase(user_vect.begin() + (del-1));
							}
							else
							{
								user_vect.clear();
							}
							menu = false;
						}break;

						default: {menu = false; }break;
						}
						User_save(user_vect);
					}
				}
				else cout << "�������� ����" << endl;
				_getch();
			}
		}break;
		case 5: {Registration(); }break;
		case 6: 
		{

			if (user_vect.empty()) { cout << "������ ����"; _getch(); }
			else {
				int int_rest;
				if (restlist.empty())int_rest = 100;
				else int_rest = restlist[restlist.size() - 1].voucher_number;

				int int_esc;
				if (excurslist.empty())int_esc = 1000;
				else int_esc = excurslist[excurslist.size() - 1].voucher_number;

				Output(user_vect);
				int del = Func::NumCheck();
				if (del <= user_vect.size())
				{
					AddMenu(&excurslist, &restlist, user_vect[del - 1], int_rest, int_esc);
				}
				else cout << "�������� ����" << endl;

			}
		}break;
		case 7: {DeleteCountriesMenu(); }break;
		case 8: {AddCountryMenu(); }break;
		case 9: {cont = false; }break;
		default: {cout << "�������� ����"; _getch(); } break;

		}
		system("cls");
	}
	Func::ClearFile("changereqrest.txt");
	Func::ClearFile("changereqexcursion.txt");
	Func::ClearFile("deletereq.txt");
}
