// File: test_main.cpp
// Created by: Michael Napoli
// Created on: 4/12/2020
// Last modified on:

/*
   Purpose:
*/

#include <iostream>
#include <string>
#include "bank_account.h"
#include "cd_account.h"
#include "money_marketing_account.h"
using namespace std;
using namespace hw6_napoli;

void userDeposit(BankAccount &acc);
void userWithdraw(BankAccount &acc);
void userTransfer(BankAccount &from, BankAccount &to);
void printAccountInfo(BankAccount &acc);
bool transfer(BankAccount &fromAccount, BankAccount &toAccount, double transAmount);

int main()
{
   string name;
   double rate;

   cout << "Enter Money Marketing Account owner's name: ";
   cin >> name;

   MoneyMarketingAccount mmacc(name);

   cout << "Enter CD Account owner's name: ";
   cin >> name;
   cout << "Enter CD Account's interest rate (0 to 1): ";
   cin >> rate;

   CDAccount cdacc(name, rate);

   cout.setf(ios::fixed);
   cout.precision(2);

   userDeposit(mmacc);
   userDeposit(cdacc);

   userWithdraw(mmacc);
   userWithdraw(mmacc);

   userWithdraw(cdacc);
   userWithdraw(cdacc);

   userTransfer(cdacc, mmacc);
   userTransfer(mmacc, cdacc);

   userWithdraw(mmacc);

   return 0;
}

void userDeposit(BankAccount &acc)
{
   double amount;
   cout << "\nEnter amount to deposit to " << acc.getName() << "'s account: ";
   cin >> amount;

   if(acc.deposit(amount))
      cout << "\nSuccessful deposit.";
   else
      cout << "\nUnsuccessful deposit. Invalid amount: " << amount;

   printAccountInfo(acc);
}

   void userWithdraw(BankAccount &acc)
   {
   double amount;
   cout << "\nEnter amount to withdraw from " << acc.getName() << "'s account: ";
   cin >> amount;

   if(acc.withdraw(amount))
      cout << "\nSuccessful withdraw.";
   else
      cout << "\nUnsuccessful withdraw. Insufficient funds (" << acc.getBalance() << ") or invalid amount (" << amount << ")";
   printAccountInfo(acc);
   }

void userTransfer(BankAccount &from, BankAccount &to)
{
   double amount;
   cout << "\nEnter amount to transfer from " << from.getName() << "'s account";
   cout << " to " << to.getName() << "'s account: ";
   cin >> amount;

   if(transfer(from, to, amount))
      cout << "\nSuccessful transfer.";
   else
      cout << "\nUnsuccessful transfer. Insufficient funds (" << from.getBalance() << ") or invalid amount (" << amount << ")";

   printAccountInfo(from);
   printAccountInfo(to);
}

void printAccountInfo(BankAccount &acc)
{
   cout << endl << acc.getName() << "'s account balance: " << acc.getBalance() << endl;
}

// function: transfer()
// Take two variables of class 'BankAccount' or one of its child classes
//    and transfer the amount given to the appropriate account.
// input: two initialized 'BankAccount' variables
//    amount two be transferred
// output: boolean - successful/not successful
bool transfer(BankAccount &fromAccount, BankAccount &toAccount, double transAmount){
   // if withdraw is successful
   if (fromAccount.withdraw(transAmount)) {
      // return whether deposit was successful
      return toAccount.deposit(transAmount);
   }

   // if withdraw not successful, return false
   return false;
}
