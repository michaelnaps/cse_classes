// Class: CSE 2122 Lecture 16
// Date: 3/25/2020
// topics include: seperate compilation (ADT)
/*
notes:
   Abstract Data Types (ADT) are classes defined in order to sepearate the implementation
      and the interface programming files.
      - all member variables are privat
   - this form of programming can include:
      - public member functions
      - ordinary functions
      - overloaded operators
      - friend functions
   - this programming also includes the new file type - header files
   Example: ClassName.h  <--.h stands for header
   - these are connected to the implemetation file through the include operator
   Example: #include "ClassName.h"
   - NOTE: the file must be located in the same folder as the implementation program unless
      otherwise specified by the include line
   - in many cases, the implementation file will by given the same name as the header
   Example: if the header is example.h
      the implementation file will be example.cpp
*/

#include <iostream>
using namespace std;

class A {
public:
   void func();

private:
   int test;
}

int main()
{

   return 0;
}
