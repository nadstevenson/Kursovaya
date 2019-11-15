#pragma once
#include <conio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <locale.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>;
#include <windows.h>;
#include "Administrator.h"
#include "Functions.h"
using namespace std;


class User
{
private:
	string password;
public:
	string login, name, surname;
	User();
	User(string user_login, string user_password, string user_name, string user_surname);
	User(const User &obj);
	void Change();
	void Output();
	void SaveUser();
	~User();
	friend bool CheckUser(User *obj);
	friend void Registration();
	friend void UserOutput();
	friend void User_vector_add(vector<User> *user_vect);
	friend void AdministratorMenu(Administrator admin);
	friend void User_save(vector<User>user_vect);
	friend bool CheckEqual(string login);
	int Check();
};

