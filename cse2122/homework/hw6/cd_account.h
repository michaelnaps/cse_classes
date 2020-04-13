// File: cd_account.h
// Created by: Michael Napoli
// Created on: 4/12/2020

/*
   Purpose:
*/

// check if the 'cd_account.h' has already been included
#ifndef CDACCOUNT_H
#define CDACCOUNT_H

#include <iostream>
#include "bank_account.h"
using namespace std;

class CDAccount : BankAccount
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
      return false;
   }
};

#endif
