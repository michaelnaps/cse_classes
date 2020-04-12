// File: cd_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose:
*/

// check if the 'cd_account.h' has already been included
#ifndef CDACCOUNT_H
#define CDACCOUNT_H

#include <iostream>
#include "bank_account.h"
using namespace std;

class CDAccount : BankAccount
{
public:
   // class constructors
   CDAccount(const string& name) : BankAccount(name) {}
   CDAccount(const string& name, const double& amount) : BankAccount(name, amount) {}
};

#endif
