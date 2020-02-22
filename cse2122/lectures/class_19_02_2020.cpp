// Class: CSE 2122 Lecture 10
// Date: 2/19/2020
// topics include: vector class, Structures, nodes in linked lists
/*
notes:
   - vector is an array class that allows the changing of array size during program runs
   - because the vector class is a class type, its member functions are accessed using dot notation
   - using the '.push_back(value)' function, elements can be added to the vector variable without
      allocating the memory first
      Example Notation: variable_name.push_back(newValue);
   - the '.size()' function returns the size of the vecotr, similar to the size of an array
      Example Notation: variable_name.size();
   - note: the '.size()' function returns an unsigned integer so when calling the function for loop
      iteration, good practice is to initialize the loop variable to an unsigned integer as well.
   - when a vector variable is initialized using a single integer, the variable will be initialized to
      that number of elements, all equaling 0
   - '.resize()' can be used to  shrink or expand an array more specifically
      Example Notation: variable_name.resize(newSize);
   - '.reserve()' creates new memory locations for a given number of elements

   Structures:
   - example structure shown below in program body
   - originally designed for 'C' language (because of the lack of class types)
   - a structure will contain multiple values (possibly) of differing types
   - can also contain member functions
   - the only difference between structures and classes is that classes can have private members
   - the structure class begins with the keyword 'struct'
   Example: (1)
      struct structure_name { structure body };   <-- ending semicolon is important
   - member names are identified in the structure body
   - because data members are public by default, the variables are accessed via dot notation
   - once a structure variable is called, its members are treated as seperate variables
   - initializing a structure can be shortcut in the following way
   Example: for the CDAccount structure
      CDAccount variable_name = {val1, val2, val3};
      for this notation, the followng will occur
      balance = val1;
      interest_rate = val2;
      term = val3;
   - structures can also have initial values within the structure definition

   Nodes and Linked Lists:
   - a linked list can grow and shrink while the program is running
   - a linked list is consistent of pointer variables that point to the next node in the list, etc.
   - the structure for these are made up of the struct members and a single pointer variable that points
      to another structure of the same type
      - this way, each time the variable is made, the next node (pointer) is found in the previous node

*/

#include <iostream>
#include <vector>
using namespace std;

// (1)
struct CDAccount
{
   double balance;
   double interest_rate = 0.02;  // cannot use the '()' notation
   int term = 3;
};

int main()
{
   // declare two variables of the new structure type
   CDAccount mine, yours;

   mine.balance = 1000;

   cout << mine.balance << endl;
   cout << mine.interest_rate << endl;
   cout << mine.term << endl;

   return 0;
}
