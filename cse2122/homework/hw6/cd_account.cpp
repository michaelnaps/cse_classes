// File: cd_account.cpp
// Created by: Michael Napoli
// Created on: 4/15/2020

/*
   Purpose: Implementation file for the 'CDAccount' class type.
*/

#include "cd_account.h"
#include <string>

namespace hw6_napoli {
   // class constructors
   CDAccount::CDAccount() : BankAccount(), int_rate(0.02) {}
   CDAccount::CDAccount(const std::string& name) : BankAccount(name), int_rate(0.02) {}
   CDAccount::CDAccount(const std::string& name, const double& rate) : BankAccount(name) {
      int_rate = rate;
   }

   bool CDAccount::withdraw(const double& amount) {
      double wd_penalty(balance * int_rate * 0.25);  // withdraw penalty

      if ((amount +  wd_penalty) > balance || amount <= 0) {
         return false;
      }
      else {
         balance -= (amount + wd_penalty);
         return true;
      }
   }
}
