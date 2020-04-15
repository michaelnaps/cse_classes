// File: cd_account.cpp
// Created by: Michael Napoli
// Created on: 4/15/2020

/*
   Purpose: Implementation file for the 'CDAccount' class type.
*/

#include "cd_account.h"

namespace hw6_napoli {
   // CONSTRUCTORS:
   // default constructor
   CDAccount::CDAccount() : BankAccount(), int_rate(0.02) {}

   // given account owner name
   CDAccount::CDAccount(const std::string& name) : BankAccount(name), int_rate(0.02) {}

   // given account owner name and initial deposit
   CDAccount::CDAccount(const std::string& name, const double& rate) : BankAccount(name) {
      int_rate = rate;
   }

   // function: withdraw() - virtual function
   // Withdraw a given amount from a 'CDAccount' bank account
   //    Includes fee based on current balance within the account and the
   //    set annual interest rate.
   // intput: initialized 'CDAccount' class variable
   //    'amount' - type double
   // output: boolean value - successful/not successful
   bool CDAccount::withdraw(const double& amount) {
      double wd_penalty(balance * int_rate * 0.25);  // withdraw penalty

      // if the account does not have the amount needed plus the withdrawal fee
      if ((amount +  wd_penalty) > balance || amount <= 0) {
         return false;  // unsuccessful withdrawal
      }
      // otherwise
      else {
         // withdrawal given amount plus the fee
         balance -= (amount + wd_penalty);
         return true;  // successful withdrawal
      }
   }
}
