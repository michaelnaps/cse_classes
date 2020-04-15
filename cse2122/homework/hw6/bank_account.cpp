// File: bank_account.cpp
// Created by: Michael Napoli
// Created on: 4/15/2020

/*
   Purpose: Program file for 'BankAccount' class function
      definitions.
*/

#include "bank_account.h"  // include header file
#include <string>

namespace hw6_napoli {
   // CONSTRUCTORS:
   // default constructor
   BankAccount::BankAccount() : owner_name("Joe Doe"), balance(0) {}

   // given name of account owner
   BankAccount::BankAccount(const std::string& name) : balance(0)
   {
      owner_name = name;
   }

   // given name of account owner and initial deposit
   BankAccount::BankAccount(const std::string& name, const double& amount) {
      owner_name = name;
      balance = amount;
   }

   // ACCESSOR FUNCTIONS:
   // function: getName()
   // returns the name of the current account owner
   std::string BankAccount::getName()
   {
      return owner_name;
   }

   // function: getBalance()
   // returns the balance of the current bank account
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
