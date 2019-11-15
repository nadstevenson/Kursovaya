#include "stdafx.h"
#include "Functions.h"

int Func::NumCheck()
{
int n;
while (!(cin >> n))
{
	cout << "Неверный ввод" << endl;
	cin.clear();
	while (cin.get() != '\n'&& n < 0 && n>21);
}
return n;
}

void Func::Addrequest(char request[200])
{
	ofstream file;
	file.open("changereq.txt", ios::app);
	if (file.is_open())
		file << endl << request;
	file.close();
}


void Func::DeleteEqualRequest(char name[50])
{
	string line;
	vector<string> lines;
	ifstream file;
	file.open(name);
	if ((file.is_open())) {
		User admin;
		file.ignore(1);
		while (!file.eof())
		{
			getline(file, line);
			lines.push_back(line);
		}
	}file.close();

	ofstream outFile(name);
	sort(lines.begin(), lines.end());
	unique_copy(lines.begin(), lines.end(), std::ostream_iterator<string>(outFile, "\n"));
	outFile.close();
}

void Func::OutputRequestsRest()
{
	system("cls");
	string line;
	ifstream file;
	file.open("changereqrest.txt");
	if ((file.is_open())) {
		User admin;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
		}
	}file.close();


	ifstream file1;
	file1.open("deletereq.txt");
	if ((file1.is_open())) {
		User admin;
		while (!file1.eof())
		{
			getline(file1, line);
			cout << line << endl;
		}
	}file1.close();
}

void Func::OutputRequestsExcursion()
{
	system("cls");
	string line;
	ifstream file;
	file.open("changereqexcursion.txt");
	if ((file.is_open())) {
		User admin;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
		}
	}file.close();


	ifstream file1;
	file1.open("deletereq.txt");
	if ((file1.is_open())) {
		User admin;
		while (!file1.eof())
		{
			getline(file1, line);
			cout << line << endl;
		}
	}file1.close();
}


Date Func::CheckDate() 
{
	Date tmp;
	bool test = true;
	while (test)
	{
		cout << endl;
		printf("Введите год отправления: ");
		while (!(cin >> tmp.year))
		{
			cin.clear();
			while (cin.get() != '\n'&& tmp.year < 0 && tmp.year>21);
		}
		if (tmp.year > 2017 && tmp.year <= 2050) test = false;
		else printf("Повторите ввод(от 2018 до 2050) ");
		rewind(stdin);
	}
	test = true;
	while (test)
	{
		printf("Введите месяц отправления: ");
		while (!(cin >> tmp.month))
		{
			cin.clear();
			while (cin.get() != '\n'&& tmp.month < 0 && tmp.month>21);
		}
		if (tmp.month <= 12 && tmp.month > 0)test = false;
		else printf("Повторите ввод(в году 12 месяцев) ");
		rewind(stdin);
	}
	test = true;
	while (test)
	{
		printf("Введите день отправления: ");
		while (!(cin >> tmp.day))
		{
			cin.clear();
			while (cin.get() != '\n'&& tmp.day < 0 && tmp.day>21);
		}
		if (tmp.month == 1 || tmp.month == 3 || tmp.month == 5 || tmp.month == 7 || tmp.month == 8 || tmp.month == 10 || tmp.month == 12)
		{
			if (tmp.day > 0 && tmp.day <= 31)test = false;
			else printf("Повторите ввод(в январе, марте, мае, июле, августе, октябре, декабре 31 день)\n");
		}
		if (tmp.month == 4 || tmp.month == 6 || tmp.month == 9 || tmp.month == 11)
		{
			if (tmp.day > 0 && tmp.day <= 30)test = false;
			else printf("Повторите ввод(в апреле, июне, сентябре, ноябре 30 дней)\n");
		}
		if (tmp.month == 2)
		{
			if (tmp.day > 0 && tmp.day <= 28)test = false;
			else printf("Повторите ввод(в феврале 28 дней)\n");
		}
		rewind(stdin);
	}
		return tmp;
}

void Func::ClearFile(char name[40])
{
	ofstream ok(name, ios::trunc);
	ok.close();
}


