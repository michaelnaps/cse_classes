// Homework #1
// File: oven_timer.cpp
// Created by: Michael Napoli
// Created on: 1/8/2020
// Last modified on: 1/10/2020

/*
   Synopsis: Program that will read the user input of a desired cooking time and 
   output the time able to be completed by the broken timer.

   The input options include:
      1). Time that is able to be done by the keypad.
      2). Time that include 1, 4, or 7 which is not able to be done by the broken keypad.
      3). Time that does not fall within an acceptable range of the time: 00:01 - 09:59

   The outputs from these options include:
      - If input falls under parameter 1, the program will output the desired time.
      - If input falls under parameter 2, the program will substitute and output the next highest available time.
      - If input falls under parameter 3, the program will output an error message.

*/

#include <iostream>
#include <iomanip>
using namespace std;

// check whether a given time is between 00:01 and 09:59
bool isValid(const int hours, const int minutes);

// check whether a given time contains digits 1, 4, or 7
// if the values 1, 4, or 7 are present, the time is adjusted appropriately
void containsDigits(int& hours, int& minutes);

// print a given time in the format of hh:mm
void printTime(const int hours, const int minutes);

int main()
{
    // variables for desired cook time from user, initially set to 0
    int hours(0), minutes(0);
    char c; // to skip the ':'

    // ask user for desired time input
    cout<<"Enter the desired time: ";
    cin >> hours >> c >> minutes;

    // if the isValid() command returns false, the error message is returned and the program is ended
    if (!isValid(hours, minutes)) {
        cout << "The desired time is invalid." << endl;
    }

    // if the isValid() command returns true, program continues
    else {
        // evaluate and adjust hours and minutes to account for digits 1, 4, and 7 
        containsDigits(hours, minutes);

        // print the valid cooking time
        printTime(hours, minutes);
    }

    // end program
    return 0;
}

// function that checks the given values of time to see if they are within an acceptable range
bool isValid(const int hours, const int minutes){
    // if hours exceeds 9 or is negative, value is not valid
    if (hours > 9 || hours < 0) { 
        return false; 
    }

    // if minutes exceeds 59 or is negative, value is not valid
    else if (minutes > 59 || minutes < 0) { 
        return false; 
    }

    // if 0 is entered for both hours and minutes, value is not valid
    else if (hours == 0 && minutes == 0) {
        return false;
    }

    // desired time is within an acceptable range
    return true;
}

// function that evaluates whether the given values of time contain 1, 4, or 7
void containsDigits(int& hours, int& minutes){
    // CHECK HOURS VALUE
    // if the minutes contain an invalid number, increments hours integer by 1 and set seconds to 0
    if (hours == 1 || hours == 4 || hours == 7) {
        ++hours;
        minutes = 0;
    }

    // CHECK MINUTES
    // if minutes value is truncated to 1 when divided by 10, increase to 20
    if (minutes / 10 == 1) { 
        minutes = 20; 
    }
    // if minutes is truncated to 4 when divided by 10, increase to 50
    else if (minutes / 10 == 4) { 
        minutes = 50; 
    }
    // if remainder value of minutes is equal to 1, 4, or 7, increment minutes value by 1
    else if (minutes % 10 == 1 || minutes % 10 == 4 || minutes % 10 == 7) { 
        ++minutes; 
    }
}

// function that takes inputted hours and minutes and outputs them in digital clock format
// 'hours':'minutes'
void printTime(const int hours, const int minutes){
    cout << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes << endl;
}