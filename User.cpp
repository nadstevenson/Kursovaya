#include "stdafx.h"
#include "User.h"
#include <conio.h>
#include <iostream>
using namespace std;


User::User()
{
}

User::User(string user_login, string user_password, string user_name, string user_surname)
{
	login = user_login.substr(0, user_login.length());
	password = user_password.substr(0, user_password.length());
	name = user_name.substr(0, user_name.length());
	surname = user_surname.substr(0, user_surname.length());
}

void UserOutput()
{
	ifstream file;
	file.open("user.txt");
	if ((file.is_open())) {
		User admin;
		file.ignore(1);
		while (!file.eof())
		{
			getline(file, admin.login);
			getline(file, admin.password);
			getline(file, admin.name);
			getline(file, admin.surname);
			cout << setw(10) << admin.login << "|";
			cout << setw(10) << admin.name << "|";
			cout << setw(10) << admin.surname << setw(10) << endl;

		}
	}
	file.close();
	_getch();
}

User::User(const User &obj)
{
	login = obj.login.substr(0, obj.login.length());
	password = obj.password.substr(0, obj.password.length());
	name = obj.name.substr(0, obj.name.length());
	surname = obj.surname.substr(0, obj.surname.length());
}



User::~User()
{
}



bool CheckUser(User *obj)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string Login, Password;
	unsigned char p;
	cout << "введите логин" << endl;
	getline(std::cin, Login);
	for (int i = 0; i < Login.size(); i++) {
		Login[i] = Login[i];
	}
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
	for (int i = 0; i <Password.size(); i++) {
		Password[i] = Password[i] + 8;
	}
	//getline(std::cin, Password);
	for (int i = 0; i < Password.size(); i++) {
		Password[i] = Password[i];
	}
	ifstream file;
	file.open("user.txt");
	if ((file.is_open())) {
		User user;
		file.ignore(1);
		while (!file.eof()) {
			getline(file, user.login);
			getline(file, user.password);
			getline(file, user.name);
			getline(file, user.surname);
			if ((user.password == Password) && (user.login == Login))
			{
			
				obj->login= user.login.substr(0, user.login.length());
				obj->password = user.password.substr(0, user.password.length());
				obj->name = user.name.substr(0, user.name.length());
				obj->surname = user.surname.substr(0, user.surname.length());

			
				for (int i = 0; i <user.password.size(); i++) {
				user.password[i] = user.password[i]-8;
				}
				file.close();
				return true;
			}
		}
		file.close();

	}

}

bool CheckEqual(string login)
{
	ifstream file;
	file.open("user.txt");
	if ((file.is_open())) {
		User admin;
		file.ignore(1);
		while (!file.eof()) {
			getline(file, admin.login);
			getline(file, admin.password);
			getline(file, admin.name);
			getline(file, admin.surname);
			if (admin.login==login)
			{
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}
}

void Registration()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool cont = true;
	while (cont) {
		User user;
		cout << "введите логин" << endl;

		getline(cin, user.login);
		if (CheckEqual(user.login) == false)
		{
			for (int i = 0; i < user.login.size(); i++) {
				user.login[i] = user.login[i];
			}
			cout << "введите пароль" << endl;
			cin >> user.password;
			for (int i = 0; i < user.password.size(); i++) {
				user.password[i] = user.password[i]+8;
			}
			cout << "введите имя" << endl;
			cin>> user.name;
			cout << "введите фамилию" << endl;
			cin>>user.surname;
			ofstream file;
			file.open("user.txt", ios::app);
			if (file.is_open())
				file << endl << user.login
				<< endl << user.password
				<< endl << user.name
				<< endl << user.surname;
			file.close();
			cont = false;
		}
		else
		{
			cout << "Придумайте уникальный логин"<<endl;
			_getch();
		}
	}

	return;
}

void User_vector_add(vector<User>* user_vect)
{
	ifstream file;
	file.open("user.txt");
	if ((file.is_open())) {
		User file_user;
		file.ignore(1);
		while (!file.eof())
		{
			getline(file, file_user.login);
			getline(file, file_user.password);
			getline(file, file_user.name);
			getline(file, file_user.surname);
			for (int i = 0; i <file_user.password.size(); i++) {
				file_user.password[i] = file_user.password[i] - 8;
			}
			user_vect->push_back(file_user);
		}
	}
	file.close();
}

void User::Change() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	char cont = '1';
	while (cont == '1')
	{
		system("cls	");
		cout << "Выберите что изменить\n1)Имя пользователя\n2)Пароль\n3)Имя\n4)Фамилию\n5)Выход\n";
		choice = Func::NumCheck();
		switch (choice)
		{
		case 1:
		{
			cout << "Текущее Имя пользователя: " << this->login << endl;
			cout << "Изменить на ";
			cin >> this->login;
		}break;

		case 2:
		{
			cout << "Текущий пароль: " << this->password << endl;
			cout << "Изменить на ";
			cin >> this->password;
		}break;

		case 3:
		{
			cout << "Текущее Имя: " << this->name << endl;
			cout << "Изменить на ";
			cin >> this->name;
		}break;

		case 4:
		{
			cout << "Текущая Фамилия: " << this->surname << endl;
			cout << "Изменить на ";
			cin >> this->surname;
		}break;

		case 5:{cont = '2'; } break;

	
		default:cout << "Неверный ввод";
			break;
		}
	}
}

void User::Output() 
{
	cout << "|" << setw(20) << login << "|" << setw(20) << password
		<< "|" << setw(20) << name << "|" << setw(20) << surname << "|";
	cout << endl << "___|____________________|____________________|____________________|____________________|" << endl;

}

void User::SaveUser()
{
	for (int i = 0; i < password.size(); i++) {
		password[i] = password[i] + 8;
	}
	ofstream file;
	file.open("user.txt", ios::app);
	if (file.is_open())
		file << endl << login
		<< endl << password
		<< endl << name
		<< endl << surname;
	file.close();
	for (int i = 0; i < password.size(); i++) {
		password[i] = password[i] - 8;
	}
}
