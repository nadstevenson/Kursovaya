#pragma once
#include <windows.h>;
#include <conio.h>
#include <vector>
#include <iterator>
#include <string>
#include "Rest.h"
#include "Excursion.h"

template <typename Type>
class Search
{
	vector<Type> vect;
public:
	Search(vector<Type> vect);
	int Searching();

	~Search() {};
};


template <typename Type>
Search<Type>::Search(vector<Type> vect)
{
	this->vect.swap(vect);
}


template<>
int Search<Rest>::Searching()
{
	int search = Func::NumCheck();
	int i;
	for (i = 0; i < vect.size(); i++)
	{
		if (vect[i].voucher_number== search)
			break;

	}
	if (i != vect.size() ) return i;
	else return -1;
}

template<>
int Search<Excursion> ::Searching()
{
	int search = Func::NumCheck();
	int i;
	for (i = 0; i < vect.size(); i++)
	{
		if (vect[i].voucher_number == search)
			break;

	}
	if (i != vect.size() ) return i;
	else return -1;
}

template<>
int Search<Voucher*>::Searching()
{
	int search = Func::NumCheck();
	int i;
	for (i = 0; i < vect.size(); i++)
	{
		if (vect[i]->voucher_number == search)
			break;

	}
	if (i != vect.size()) return i;
	else return -1;
}

template<>
int Search<User>::Searching()
{
	string search;
	cin >> search;
	int i;
	for (i = 0; i < vect.size(); i++)
	{
		if (vect[i].login == search)
			break;

	}
	if (i != vect.size()) return i;
	else return -1;
}


