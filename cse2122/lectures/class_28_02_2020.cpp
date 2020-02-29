// Class: CSE 2122 Lecture 13
// Date: 2/28/2020
// topics include: stacks, functions of linked lists and stacks
/*
notes:
   Inserting a Pointer into a Linked List
   pseudocode:
      - use a function to change the pointer of a designated node to the new value
      - assign to that new value the pointer that was in the node before its addition
   Example function initiation:
      void insert(Node* after_me, int the_number);
   - a strength of the linked list method is that inserting values into the list is
      much more efficient than the array or vector method

   Stacks: a application of linked lists
   - lecture_13.pdf has a good figure for this concept
   - instead of adding values to the end of an array, the stack method will deal with
      the top of the stack only
      - this is very difficult to do with array based structures
   - hw4 (creating a postfix class) is a good example of the application of this
   The 'push' function adds a value to the top of a stack
   Example initialization:
      void push(variable_type variable_name);
   - the new value will be designated as the 'head' of the linked list
   - the location of the old 'head' value will be given to the new 'head'
   The 'pop' function will remove the top value from a stack
   Example initialization:
      void pop();
   - if the stack is empty do nothing
   - create temporary variable to hold the node of the current 'head' node
   - give the designation of 'head' to the second value in the stack
   - delete the old 'head' using the temporary variable
   The 'empty' function will simply check if the current stack is empty
   Example initialization:
      bool empty();
   - if the first value in the stack is the null space pointer, return 'true'
   - otherwise, return 'false'



   TO DEALLOCATE MEMORY FROM A STACK
   - use the '~Class_name' destructor
   - the only function that needs to be called is 'pop()' because it deletes the top
      value from the stack
   - loop the 'pop()' function until the stack is empty

*/

#include <iostream>
using namespace std;

int main()
{


   return 0;
}
