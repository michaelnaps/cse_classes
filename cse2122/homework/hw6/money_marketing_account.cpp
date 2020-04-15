// File: money_marketing_account.cpp
// Created by: Michael Napoli
// Created on: 4/15/2020

/*
   Purpose: Implementation file for the 'MoneyMarketingAccount' class type.
*/

#include "money_marketing_account.h"
#include <string>

namespace hw6_napoli {
   // CONSTRUCTORS:
   // default constructor
   MoneyMarketingAccount::MoneyMarketingAccount() : BankAccount(), wd_count(0) {}

   // given account owner name
   MoneyMarketingAccount::MoneyMarketingAccount(const std::string& name) : BankAccount(name), wd_count(0) {}

   // given acount owner name and initial deposit amount
   MoneyMarketingAccount::MoneyMarketingAccount(const std::string& name, const double& amount) : BankAccount(name, amount), wd_count(0) {}

   // function: withdraw()
   // Function for withdrawing money from the 'MoneyMarketingAccount' class type
   // input: initialized 'MoneyMarketingAccount' type variable
   //    'amount' - amount to be withdrawn
   // output: boolean - successful/not successful
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
}
