// File: bank_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose: Base class for the bank account class types.

   This class will have the following operations:
      - deposit into the account - return boolean
      - withdraw from the account - return boolean
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
      bool deposit(const double& amount);
      virtual bool withdraw(const double& amount);
   };
}

#endif
