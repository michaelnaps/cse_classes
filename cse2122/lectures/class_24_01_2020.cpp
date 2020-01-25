// Class: CSE 2122 Lecture 6
// Date: 1/24/2020
// topics include: pointers cont., dynamic variables and arrays
/*
notes:
   - arrays and pointers can be accessed in the same format
   - if a pointer memory location is set equal to a array location, all values of the 
      array can be accessed by the pointer (they are synonymous to one another)
   
   Dynamic Variables and Arrays
      'new' operator
   - the above operand will allocate a memory location of given type for a pointer
   - DANGEROUS - never forget to delete a pointer before ending a program, otherwise
      the memory space allocated to that variable will be lost FOREVER
   - the 'new' operand can also be used to allocated memory for dynamic arrays
   Example:
      variable_type *arr = new int[10];
      - this will declare a pointer with 10 values starting at the first memory space
   
   'typedef'
      - this command will change the given type definition to notation given
      Example:
         typedef normal_var_type new_var_type;

*/

#include <iostream>
using namespace std;

int main()
{
   // no examples needed

   return 0;
}