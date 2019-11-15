#pragma once
#include <string>
using namespace std;
class Administrator
{
private:
	//static string name, password;
public:
	static void output();
	bool CheckAdmin(string name, string password);
	Administrator();
	~Administrator();
	
};

