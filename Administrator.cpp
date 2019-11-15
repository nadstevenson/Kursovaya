#include "stdafx.h"
#include "Administrator.h"
#include <conio.h>
#include <iostream>
using namespace std;




void Administrator::output()
{
	cout << endl << "adm,admpass";
}

bool Administrator::CheckAdmin(string name,string password)
{
	static string admname = "adm";
	static string admpassword = "admpass";
	if (name == admname&&password == admpassword) { return true; }
	else return false;


}

Administrator::Administrator()
{
}


Administrator::~Administrator()
{
}


