// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <locale.h>
#include <fstream>
#include <Windows.h>
#include "Voucher.h"
#include "User.h"
#include "Administrator.h"
#include "Excursion.h"
#include "Rest.h"
#include "Functions.h"
#include "Program.h"
#include "Country.h"
using namespace std;

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int main()
{
	SetColor(0, 15);
	setlocale(LC_ALL, "rus");	
	Administrator adm;
	bool cont = true;
	
	while (cont)
	{
		
		int choice;
		cout << "1)Вход пользователя\n2)Вход администратора\n3)Регистрация\n4)Выход\n";
		while (!(cin >> choice))
		{
			cin.clear();
			while (cin.get() != '\n'&& choice<0 && choice>21);
		}
		rewind(stdin);
		switch (choice)
		{
		case 1: {
			User user;
			string name, surname;
			

			system("cls");
			for (int i = 3; i > 0; i--) {

				if (CheckUser(&user) == true) { system("cls"); UserMenu(user); break; }
				cout << endl << "У вас " << i - 1 << " попытки(a)"<<endl;
			}
		} break;
		case 2:
		{
			string name;
			string Password;
			unsigned char p;
			system("cls");
			cout << "введите логин" << endl;

			getline(cin, name);
			cout << "введите пароль" << std::endl;
			do
			{
				p = _getch();

				if (p == 13) break;
				if (p == '\b' && !Password.empty())
				{
					cout << '\b';
					cout << ' ';
					cout << '\b';

					Password.pop_back();
					continue;
				}
				if (isalnum((unsigned char)p))
				{
					cout << '*';
					Password.push_back(p);
				}

			} while (true);
			if (adm.CheckAdmin(name, Password) == true) { system("cls"); AdministratorMenu(adm); }
		}break;
		case 3: {Registration(); }break;
		case 4: {cont = false; }break;
		case 100: {adm.output(); _getch(); }break;
		default: {cout << "Неверный ввод"; _getch(); } break;

		}
		system("cls");
	}

	_getch();
	return 0;
}

