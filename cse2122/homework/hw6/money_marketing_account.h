// File: money_marketing_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose:
*/

// check if the 'money_marketing_account.h' has already been included
#ifndef MONEYMARKETINGACCOUNT_H
#define MONEYMARKETINGACCOUNT_H

#include "bank_account.h"
#include <iostream>
using namespace std;

class MoneyMarketingAccount : public BankAccount
{
private:
   int wd_count;  // number of withdraws, always initialized to 0

public:
   // class constructors
   MoneyMarketingAccount() : BankAccount(), wd_count(0) {}
   MoneyMarketingAccount(const string& name) : BankAccount(name), wd_count(0) {}
   MoneyMarketingAccount(const string& name, const double& amount) : BankAccount(name, amount), wd_count(0) {}

   virtual bool withdraw(const double& amount) {
      if (amount > 0) {
         if (wd_count < 2 && amount < balance) {
            ++wd_count;  // iterate withdraw count variable
            balance -= amount;  // withdraw amount
            return true;  // successful withdraw
         }
         else if (amount < (balance - 1.50)) {
            balance -= (amount + 1.50);  // withdraw amount and fee
            return true;  // successful withdraw
         }
      }

      return false;  // unsuccessful withdraw
   }
};

#endif
