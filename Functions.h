#pragma once
#include <conio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <locale.h>
#include <algorithm>
#include <string>

#include <fstream>
#include "User.h"
#include"Date.h"
using namespace std;

namespace Func 
{
	int NumCheck();
	void Addrequest(char request[200]);
	void DeleteEqualRequest(char name[50]);
	void OutputRequestsRest();
	void OutputRequestsExcursion();
	Date CheckDate();
	void ClearFile(char name[40]);
}

