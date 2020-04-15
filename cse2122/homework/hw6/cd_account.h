// File: cd_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose:
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
      // class constructors
      CDAccount();
      CDAccount(const std::string& name);
      CDAccount(const std::string& name, const double& rate);

      virtual bool withdraw(const double& amount);
   };
}

#endif
