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
#include <iostream>
using namespace std;

class CDAccount : public BankAccount
{
private:
   double int_rate;

public:
   // class constructors
   CDAccount() : BankAccount(), int_rate(0.02) {}
   CDAccount(const string& name) : BankAccount(name), int_rate(0.02) {}
   CDAccount(const string& name, const double& rate) : BankAccount(name) {
      int_rate = rate;
   }

   virtual bool withdraw(const double& amount) {
      double wd_penalty(balance * int_rate * 0.25);  // withdraw penalty

      if ((amount +  wd_penalty) > balance || amount <= 0) {
         return false;
      }
      else {
         balance -= (amount + wd_penalty);
      }
   }
};

#endif
