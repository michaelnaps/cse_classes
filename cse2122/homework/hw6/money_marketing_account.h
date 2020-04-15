// File: money_marketing_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose:
*/

// check if the 'money_marketing_account.h' has already been included
#ifndef MONEYMARKETINGACCOUNT_H
#define MONEYMARKETINGACCOUNT_H

#include "bank_account.h"

namespace hw6_napoli {
   class MoneyMarketingAccount : public BankAccount
   {
   private:
      int wd_count;  // number of withdraws, always initialized to 0

   public:
      // class constructors
      MoneyMarketingAccount();
      MoneyMarketingAccount(const std::string& name);
      MoneyMarketingAccount(const std::string& name, const double& amount);

      virtual bool withdraw(const double& amount);
   };
}

#endif
