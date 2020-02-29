// Class: CSE 2122 Lecture 12
// Date: 2/26/2020
// topics include: pointers and linked lists
/*
notes:
   - a linked list is a list of nodes in which all nodes point to another
      subsequent node in the list
   - searching through a linked list for a single value is explained in 'lecture_12.pdf'
   - basically, move through a given node space by checking for values and continuing
      until either:
      - the value is found
      - the search reaches the 'nullptr' located at the end of the node space
   - Psuedocode for moving through a linked list
      1). create a pointer variable to be the beginning of the list ('head')
      2). while the current pointer ('here') does not equal:
         - null, or the target value
         continue searching through the linked list
      3). if the current node contains the target value, return the current node
   - if you try to access the data value of an empty list, you may get a segmentation fault
      - for this reason, it is a good idea to check for an empty list before searching,
         therefore avoiding a possible segmentation fault
   - pointers and nodes can also be used as iterators for for loops
      - the initial value 'iter' is set to the head of the linked list
      - then, the list is moved through in the same way as before
   Example format:
      Node* iter;  // you may also initialize 'iter' as NULL
      for (iter = head; iter != NULL; iter = iter->link) { loop body }
   - when discarding a node from a linked list, be careful not to remove the pointer inside
      the node itself
   - you must also remove the pointer itself, to do this create a function that
      1). has two input pointer nodes ('before' and 'discard')
         - 'before' - node location in front of the node to be removed
         - 'discard' - node to be removed
      2). set the link in 'before' equal to the link in 'discard'
         - this will make sure the rest of the list is not lost in the next step
      3). delete 'discard'
   - inserting a node into a list

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
