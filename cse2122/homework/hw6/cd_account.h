// File: cd_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose: Child class to 'BankAccount' object
      Bank account class that pays constant interest rate and has
      large fees for early withdrawals.
*/

// check if the 'cd_account.h' has already been included
#ifndef CDACCOUNT_H
#define CDACCOUNT_H

#include "bank_account.h"

namespace hw6_napoli {
   class CDAccount : public BankAccount
   {
   private:
      double int_rate;

   public:
      // CONSTRUCTORS:
      CDAccount();
      CDAccount(const std::string& name);
      CDAccount(const std::string& name, const double& rate);

      // MEMBER FUNCTIONS:
      virtual bool withdraw(const double& amount);
   };
}

#endif
