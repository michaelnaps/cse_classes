// File: money_marketing_account.cpp
// Created by: Michael Napoli
// Created on: 4/15/2020

/*
   Purpose: Implementation file for the 'MoneyMarketingAccount' class type.
*/

#include "money_marketing_account.h"
#include <string>
using namespace hw6_napoli;

// class constructors
MoneyMarketingAccount::MoneyMarketingAccount() : BankAccount(), wd_count(0) {}
MoneyMarketingAccount::MoneyMarketingAccount(const std::string& name) : BankAccount(name), wd_count(0) {}
MoneyMarketingAccount::MoneyMarketingAccount(const std::string& name, const double& amount) : BankAccount(name, amount), wd_count(0) {}

bool MoneyMarketingAccount::withdraw(const double& amount) {
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
