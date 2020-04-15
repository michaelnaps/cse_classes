// File: bank_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose: Base class for the bank account class types.

   This class will have the following operations:
      - withdraw from the account - virtual function
      - transfer money between different accounts - utilize withdraw
         - returns boolean
*/

// check if the 'bank_account.h' has already been included
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

namespace hw6_napoli {
   class BankAccount
   {
   private:
      std::string owner_name;

   protected:
      double balance;

   public:
      // CONSTRUCTORS:
      BankAccount();
      BankAccount(const std::string& name);
      BankAccount(const std::string& name, const double& amount);

      // ACCESSOR FUNCTIONS:
      std::string getName();
      double getBalance();

      // MEMBER FUNCTIONS:

      // function: deposit()
      // Deposit given amount into bank account.
      // input: initialized 'BankAccount' or child class variable
      // output: boolean value - successful/not successful
      bool deposit(const double& amount);

      // function: withdraw() - virtual function
      // Withdraw a given amount from the associated bank account.
      // intput: initialized 'BankAccount' child class variable
      //    'amount' - type double
      // output: boolean value - successful/not successful
      virtual bool withdraw(const double& amount);
   };
}

#endif
