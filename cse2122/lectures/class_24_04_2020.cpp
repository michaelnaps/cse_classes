// Class: CSE 2122 Lecture 24
// Date: 4/24/2020
// topics include: standard template libraries
/*
notes:
   - STL libraries have containers, algorithms and iterators
      - containers hold objects
      - generic algorithms act on objects in containers
      - iterators provide access to containers without showing the
         internal structure of the container

   Iterators:
   - iterators are generalizations of pointers
      - they are often times implemented using pointers
   - treating iterators as pointers in typically acceptable
   - Basic operations shared by all iterators:
      '++' (pre and postfix) to advance to the next data item
      '==' and '!=' to test two iterator points
      '*' dereferencing operator provides data item access
      'c.begin()' returns iterator pointing to the first element in
         the container
      'c.end()' returns the iterator pointing to the element AFTER the
         last element in the container
      '--' (pre and postfix) moves to previous data item. NOT available
         to all types of iterators
   - the '*' operator may be read-only or read-write depending on the
      container being used
   - STL containers define iterator types appropriate to the container
      internals
   - forward iterators provide basic operations
   - bidirectional iterators provide the basic operations and the '--'
      operators (pre and postfix) to move between container elements
   - random access iteratos provide:
      - basic operators
      - indexing
         - 'p[n]' works like calling array elements (zero count) from the
            current element being pointed to by the iterator
      - iterator arithmetic
         - '(p + 2)' returns the second element after the current element
         - 'c.end() - 1' returns the last element in a given container 'c'
      - constant iterators do not allow changing elements at the current
         location using the dereferencing operator
      Example: constant iterator call with vector container
         vector<variableType>::const_iterator variableName;
      - mutable iterators allows the changing of elements at the current
         location using the dereferencing operator
      Example: mutable iterator
         vector<variableType>::iterator variableName;

   Containers:
   - three types of containers:
      - sequestial containers - the ultimate position of the element depends
         on where it is inserted, not on value
      - container adapters - use the sequential containers for storage but
         modifies the user interface to stack, queue, etc.
      - associative containers - maintain the data in sorted order to implement
         the containers purpose i.e. position depends on the value of element
         automatically
   - list, vector and deque are sequential containers
      - 'list' is a doubly linked list
      - 'vector' is essentially an array whose allocated space can grow dynamically
      - 'deque' is a double ended queue

*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
   vector<int> container;
   for (int i(1); i <= 4; ++i)
      container.push_back(i);

   cout << "Container: ";

   // mutable iterator
   vector<int>::iterator p;  // iterator object of vector type container of integers

   for (p = container.begin(); p != container.end(); ++p)
      // dereference operator:
      cout << *p << " ";  // show the item located in the current iterator location
   cout << endl;

   cout << "Change container value: ";
   for (p = container.begin(); p != container.end(); ++p) {
      *p = 0;  // change iterator value
      cout << *p << " ";
   }
   cout << endl;

   return 0;
}
