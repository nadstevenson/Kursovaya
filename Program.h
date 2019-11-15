#pragma once
#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <locale.h>
#include <fstream>
#include "Voucher.h"
#include "User.h"
#include "Administrator.h"
#include "Excursion.h"
#include "Rest.h"
#include "Functions.h"

void Output(vector<Voucher*> vlist);
void Output(Voucher* voucher);
void Output(vector<User>uservect);
void Output(User user);
void VoucherSave(vector<Rest>restlist);
void VoucherSave(vector<Excursion>excurslist);
void UserMenu_Output(vector<Voucher*> vlist, User obj);
void SearchMenu(vector<Voucher*> vlist, User obj);
void AddMenu(vector <Excursion>* excurslist, vector<Rest>* restlist, User obj, int last_rest, int last_exc);
void SortingMenu(vector<Voucher*> vlist);
void UserMenu(User obj);
void User_save(vector<User>user_vect);
void AdministratorMenu(Administrator admin);


