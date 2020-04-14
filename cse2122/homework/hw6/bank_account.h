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

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
   string owner_name;

protected:
   double balance;

public:
   // CONSTRUCTORS:
   BankAccount() : owner_name("Joe Doe"), balance(0) {}

   BankAccount(const string& owner) : balance(0) {
      owner_name = owner;
   }

   BankAccount(const string& owner, const double& amount) {
      owner_name = owner;
      balance = amount;
   }

   // ACCESSOR FUNCTIONS:
   string getName() {
      return owner_name;
   }

   double getBalance() {
      return balance;
   }

   // MEMBER FUNCTIONS:

   // function: deposit()
   // Deposit given amount into bank account.
   // input: initialized 'BankAccount' or child class variable
   // output: boolean value - successful/not successful
   bool deposit(const double& amount) {
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
   virtual bool withdraw(const double& amount) {
      return false;  // invalid child class variable input
   }
};

#endif
