// File: bank_account.cpp
// Created by: Michael Napoli
// Created on: 4/15/2020

/*
   Purpose: Program file for 'BankAccount' class function
      definitions.
*/

#include "bank_account.h"
#include <string>

namespace hw6_napoli {
   // CONSTRUCTORS:
   BankAccount::BankAccount() : owner_name("Joe Doe"), balance(0) {}
   BankAccount::BankAccount(const std::string& owner) : balance(0)
   {
      owner_name = owner;
   }

   // ACCESSOR FUNCTIONS:
   std::string BankAccount::getName()
   {
      return owner_name;
   }

   double BankAccount::getBalance()
   {
      return balance;
   }

   // MEMBER FUNCTIONS:

   // function: deposit()
   // Deposit given amount into bank account.
   // input: initialized 'BankAccount' or child class variable
   // output: boolean value - successful/not successful
   bool BankAccount::deposit(const double& amount)
   {
      if (amount <= 0) {
         return false;
      }
      else {
         balance += amount;
         return true;
      }
   }

   // function: withdraw() - virtual function
   // Withdraw a given amount from the associated bank account.
   // intput: initialized 'BankAccount' child class variable
   //    'amount' - type double
   // output: boolean value - successful/not successful
   bool BankAccount::withdraw(const double& amount)
   {
      return false;  // the base class does not contain its own withdraw function
   }
}
