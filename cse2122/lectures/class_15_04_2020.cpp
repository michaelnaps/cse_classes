// Class: CSE 2122 Lecture 21
// Date: 4/15/2020
// topics include: polymorphism
/*
notes:
   - virtual functions are not defined during the compilation of the
      program
   - instead, they are defined during runtime and are based on the child
      classes of the ancestor being called
   - they can be defined in the following format:
   Example: format of virtual member functions
      INSIDE PARENT CLASS HEADER FILE:
         virtual returnType functionName(input);
      INSIDE PARENT CLASS IMPLEMENTATION FILE:
         returnType functionName(input) {
            function body...
         }
      INSIDE DERIVED CLASS HEADER FILE:
         virtual returnType functionName(input);
      INSIDE DERIVED CLASS IMPLEMENTATION FILE:
         returnType functionName(input) {
            function body...
         }
   - this just means that the program utilizing these classes will make
      the decision of which version of the function to use at run time

*/

#include <iostream>
using namespace std;

int main()
{
   return 0;
}
