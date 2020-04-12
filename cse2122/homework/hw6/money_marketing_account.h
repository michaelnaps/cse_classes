// File: money_marketing_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose:
*/

// check if the 'money_marketing_account.h' has already been included
#ifndef MONEYMARKETINGACCOUNT_H
#define MONEYMARKETINGACCOUNT_H

#include <iostream>
#include "bank_account.h"
using namespace std;

class MoneyMarketingAccount : BankAccount
{
public:
   MoneyMarketingAccount(const string& name) : BankAccount(name) {}
   MoneyMarketingAccount(const string& name, const double& amount) : BankAccount(name, amount) {}
};

#endif
