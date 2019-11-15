#include "stdafx.h"
#include "Program.h"
#include "Search.h"
#include "Country.h"

void Output(vector<Voucher*> vlist)
{
	cout << " № |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
	cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;

	for (int i = 0; i < vlist.size(); i++)
	{
		cout << setw(3) << i + 1;
		vlist[i]->output();
	}
}

void Output(Voucher* voucher)
{
	cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
	cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
	cout << "   ";
	voucher->output();

}



void Output(vector<User>uservect)
{
	cout << "№__|       Логин        |        Пароль      |         Имя        |      Фамилия       |" << endl;
	cout << "___|____________________|____________________|____________________|____________________|" << endl;
	for (int i = 0; i < uservect.size(); i++)
	{
		cout << setw(3) << i + 1;
		uservect[i].Output();
	}
}

void Output(User user)
{
	cout << "№__|       Логин        |        Пароль      |         Имя        |      Фамилия       |" << endl;
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
	if (vlist.empty())cout << "Вектор пуст";
	else
	{
		Output(vlist);

		cout << "\n" << vlist.size() + 1 << ") Выход";
		int del = Func::NumCheck();
		if (del <= vlist.size())
		{
			if (vlist[del - 1]->Name == obj.name && vlist[del - 1]->Surname == obj.surname)
			{
				bool menu = true;
				while (menu)
				{

					system("cls");
					cout << "Выбранный элемент: " << endl;
					Output(vlist[del - 1]);
					cout << "\nЧто вы хотите с ним сделать?" << endl;
					cout << "1)Изменить\n2)Удалить\nДругое)Выход";
					int choice = Func::NumCheck();
					switch (choice)
					{
					case 1: {vlist[del - 1]->Userchange(obj); cout << "\nЗапрос на изменение отправлен"; _getch(); }break;

					case 2:
					{
						ofstream file;
						file.open("deletereq.txt", ios::app);
						if (file.is_open())
							file << endl << "Удалить заказ №" << vlist[del - 1]->voucher_number;
						file.close();
						cout << "\nЗапрос на изменение отправлен";
						_getch();
						menu = false;
					}break;
					default: {menu = false; }break;
					}
				}
			}
			else cout << "Вы не можете изменить/удалить этот элемент" << endl;

		}
		else cout << "Выход" << endl;
		_getch();

	}
}


void SearchMenu(vector<Voucher*> vlist, User obj)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (vlist.empty())cout << "Вектор пуст";
	else {
		int choice;
		char cont = '1';
		while (cont == '1')
		{
			system("cls	");
			cout << "Выберите по какому критерию отфильтровать\n1)Стоимость\n2)Время пербывания\n3)Путевки на текущий месяц\n4)Страну отправления\n5)Только свои путевки\n6)Выход";
			choice = Func::NumCheck();
			switch (choice)
			{
			case 1:
			{
				system("cls");
				cout << "Введите стоимость" << endl;
				int serched_cost = Func::NumCheck();
				cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
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
				cout << "Введите время пребывания" << endl;
				int serched_time_of_stay = Func::NumCheck();
				cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
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
				cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
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
				cout << "Введите страну отправления" << endl;
				cin >> searched_first_country;
				cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
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
				cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
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

			default:cout << "Неверный ввод";
				break;
			}
		}
	}
}


void AddMenu(vector <Excursion>* excurslist, vector<Rest>* restlist, User obj, int last_rest, int last_exc)
{
	cout << "Выберите какой тип путевки вы хотите добавить\n1)Отдых\n2)Экскурсия\n";
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

	default: {cout << "Неверный ввод"; _getch(); } break;
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
		cout << "Удалить из списка стран\n1)Страну(отдых)\n2)Страны(Экскурсия)\n3)Страну отправления\n4)Выход\n";
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
		default: {cout << "Неверный ввод"; _getch(); }break;

		}

	}
}


void AddCountryMenu()
{
	bool cont = true;
	while (cont)
	{
		system("cls");
		cout << "Добавить\n1)Страну(отдых)\n2)Страны(Экскурсия)\n3)Страну отправления\n4)Выход\n";
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
		default: {cout << "Неверный ввод"; _getch(); }break;

		}

	}
}


void SortingMenu(vector<Voucher*> vlist)
{
	if (vlist.empty())cout << "Вектор пуст";
	else {
		int choice;
		char cont = '1';
		while (cont == '1')
		{
			system("cls	");
			cout << "Выберите по какому критерию упорядочить\n1)Стоимость\n2)Время пербывания\n3)Страну отправления\n4)Выход\n";
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

			default:cout << "Неверный ввод";
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

		cout << "Вы в меню пользователя: " << obj.login << endl;
		cout << "Имя: " << obj.name << " Фамилия: " << obj.surname;
		cout << "\n1)Список путевок*\n2)Заказать путевку\n3)Фильтрация по полю\n4)Вывести упорядоченный список путевок\n5)Поиск*\n6)Выход\n(В пунктах отмеченных * разрешается удалять/изменять)" << endl;
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
					cout << "Найденный элемент: " << endl;
					Output(vlist[index]);
					if (vlist[index]->Name == obj.name && vlist[index]->Surname == obj.surname)
					{
						cout << "\nЧто вы хотите с ним сделать?" << endl;
						cout << "1)Изменить\n2)Удалить\nДругое)Выход";
						int choice = Func::NumCheck();
						switch (choice)
						{
						case 1: {vlist[index]->Userchange(obj); }break;

						case 2:
						{
							ofstream file;
							file.open("deletereq.txt", ios::app);
							if (file.is_open())
								file << endl << "Удалить заказ №" << vlist[index]->voucher_number;
							file.close();
							cout << "\nЗапрос на удаление отправлен";
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

		default: {cout << "Неверный ввод"; _getch(); } break;

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
		cout << "1)Список путевок\n2)Список пользователей\n3)Удалить/изменить путевку\n4)Изменить/удалить пользователя\n5)Добавить пользователя\n6)Добавить путевку\n7)Удалить из списка стран\n8)Добавить страну(ы)\n9)Выход" << endl;
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
			cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
			cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
			if (restlist.empty())cout << "Вектор пуст";
			else
			{
				for (int i = 0; i < restlist.size(); i++)
				{
					cout << "\n";
					cout << "   ";
					cout << restlist[i];
				}
			}

			if (excurslist.empty())cout << "Вектор пуст";
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
			if (user_vect.empty()) { cout << "Вектор пуст"; _getch(); }
			else {
				Output(user_vect);
			}
			_getch();
		}break;
		case 3:
		{
			system("cls");
			cout << "Тип путевки:\n1)Отдых\n2)Экскурсия\n";
			int choice = Func::NumCheck();
			switch (choice)
			{
			case 1: {
				Func::OutputRequestsRest();
				Search<Rest>searcher(restlist);
				cout << "Поиск по номеру ";
				int del = searcher.Searching();
				if (del >= 0) {
					bool menu = true;
					while (menu)
					{
						cout << endl;
						system("cls");
						Func::OutputRequestsRest();
						cout << "Выбранный элемент: ";
						cout << endl;
						cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
						cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
						cout << "   ";
						restlist[del].output();
						cout << "\nЧто вы хотите с ним сделать?" << endl;
						cout << "1)Изменить\n2)Удалить\nДругое)Выход";
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
				else cout << "Не найдено";
				_getch();
			}break;
			case 2:
			{
				Func::OutputRequestsExcursion();
				Search<Excursion>searcher(excurslist);
				cout << "Поиск по номеру ";
				int del = searcher.Searching();
				if (del >= 0) {
					bool menu = true;
					while (menu)
					{
						cout << endl;
						system("cls");
						Func::OutputRequestsExcursion();
						cout << "Выбранный элемент: ";
						cout << endl;
						cout << "   |    Тип   |Номер|      Имя      |    Фамилия    |    Датa  |   Цена   | Время пребывания |    *Отель    | Страна отправления | Страна прибытия/Экскурсия по странам" << endl;
						cout << "   |__________|_____|_______________|_______________|__________|__________|__________________|______________|____________________|_____________________________________" << endl;
						cout << "   ";
						excurslist[del].output();
						cout << endl<<"Что вы хотите с ним сделать?" << endl;
						cout << "1)Изменить\n2)Удалить\nДругое)Выход"<<endl;
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
				else cout << "Не найдено";
				_getch();
			}break;
			}


		}break;
		case 4:
		{
			if (user_vect.empty()) { cout << "Вектор пуст"; _getch(); }
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
						cout << "Выбранный элемент: " << endl;
						Output(user_vect[del - 1]);
						cout << "\nЧто вы хотите с ним сделать?" << endl;
						cout << "1)Изменить\n2)Удалить\nДругое)Выход\n";
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
				else cout << "Неверный ввод" << endl;
				_getch();
			}
		}break;
		case 5: {Registration(); }break;
		case 6: 
		{

			if (user_vect.empty()) { cout << "Вектор пуст"; _getch(); }
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
				else cout << "Неверный ввод" << endl;

			}
		}break;
		case 7: {DeleteCountriesMenu(); }break;
		case 8: {AddCountryMenu(); }break;
		case 9: {cont = false; }break;
		default: {cout << "Неверный ввод"; _getch(); } break;

		}
		system("cls");
	}
	Func::ClearFile("changereqrest.txt");
	Func::ClearFile("changereqexcursion.txt");
	Func::ClearFile("deletereq.txt");
}
