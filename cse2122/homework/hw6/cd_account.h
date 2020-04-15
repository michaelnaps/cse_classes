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
#include <string>

namespace hw6_napoli {
   class CDAccount : public hw6_napoli::BankAccount
   {
   private:
      double int_rate;

   public:
      // class constructors
      inline CDAccount();
      inline CDAccount(const std::string& name);
      inline CDAccount(const std::string& name, const double& rate);

      inline bool withdraw(const double& amount);
   };
}

#endif
