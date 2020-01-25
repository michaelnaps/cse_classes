// Class: CSE 2122 Lecture 4
// Date: 1/17/2020
// topics include: local variables and blocks, debugging techniques
/*
notes:
   - a block is a section of code enclosed by braces
   - any variable created with two braces is limited to the end of that block
      - these are called local variables
   - if it is called from another block, there will be an error and the program will be ended
   - global variables are created when a variable is declared outside of the main program
      - these variables exist as long as the program is running and can be called from anywhere
      - these are to be avoided
   - using call-by-reference within the function parameters sends a pointer to the function
      being called instead of a pure value
      - good for saving memory space but risky, because
      - once a variable is sent by reference it can be modified, unlike when it is passed not 
         by reference
   
   Debugging Techniques:
   - each function should be tested as a seperate unit from the program
   - driver programs allow testing of individual, simple functions
      - then, once a function is complete, it can be used to test others
   - a driver program is one thats only purpose is to call the function being tested
   - these can be used to loop through all possible values for a given function
   - Stubs can be used when a function must be tested that doesn't have all of its components yet
      - these functions should be so simple, they are guranteed to perform correctly
      - For example, a function that does nothing but return 1
   - Use a debugger
      - a debugger works along the program line-by-line, stopping as it compiles when an error occurs
   - The 'cassert' include library   
(1)   #include <cassert>
   - this library can be used to evaluate programming outputs
   - use the command
(2)   assert(boolean);
   - if the boolean is ever false, the program will be ended immediately

*/

#include <iostream>
using namespace std;

// this variable would be considered a global variable
// const int EXAMPLE = 0;

int main()
{

}