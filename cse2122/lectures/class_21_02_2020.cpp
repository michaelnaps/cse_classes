// Class: CSE 2122 Lecture 11
// Date: 2/21/2020
// topics include: structures, nodes, building linked lists
/*
notes:
   Nodes and Pointers:
   - when calling nodes (structure data points) as a pointer, special format is needed
   Example format: changing value
      (*variable_name).node_var_name = newValue;  // parentheses are NEEDED
      or
      variable->.node_var_name = newValue;  // considered shortcut
   - for changing values the second node, the memory address can be found in the following form
   Example format: accessing second node value
      first_var_name->second_var_name->var_in_second;
   - when the end of the list is needed, set the final pointer to the 'NULL' constant
      - this is considered the 'end marker'
      - also equal to 0 integer
   - could also utilize the 'nullptr' constant (better)
      - this value is not attached to a integer value, it is its own value
      - implemented in C++11

   Building a Linked List:
   - to create the first node, the operator 'new' creates dynamic memory
   Example:
      variable_name = new Node_name;
   - for the last node, the pointer must be set to 'NULL' or 'nullptr'
   Example:
      in the 'main' program body:
      variable_name->link_name = nullptr;
   - it is not reasonable to create all the nodes using the main program command lines
   - the function 'head_insert' below will create a given number of node memory locations
      when called by the program
   - using temporary node pointers, structures can be searched for all values up to the
      ending NULL pointer

*/

#include <iostream>
using namespace std;

// linked list node inside of a structure
struct Node
{
   int data;
   Node *link;
}

// 'head' - the beginning variable of the linked list
//        - passed by reference (IMPORTANT)
// 'nlinks' - the number of links needed
void head_insert(Node& head, int nlinks) {
}

int main()
{
   return 0;
}
