// Class: CSE 2122 Lecture 17
// Date: 3/27/2020
// topics include: ADT, namespaces
/*
notes:
   Exam 2:
   - will cover from first class to recursion lectures
   - sample exam format on carmen under 'Test quiz'
   - safest option is to take exam with computer/keyboard

   Lecture:
   Seperate Compilation:
   - when compiling multiple header files, it is possible for them to include
      their own headers and therefore multiple compilations of the same class
   - to avoid this syntax error, the following commands are used
      #ifndef fileName.h
         - this checks whether or not the file has already been defined, if so
            it does not define the file
      #define fileName.h
         - if the file has not been included the class is added to a 'list' of
            headers that are already included in the program
      #endif fileName.h
         - end of include decisions
   Example: #indef conditions
      #ifndef CLASSNAME_H
      #define CLASSNAME_H
         ... class definition body
      #endif

   Namespace:
      - a collection of name definitions, i.e
         - class definitions
         - variables
         - etc.
      - if a program is being modified by multiple different programmers, it is
         possible for a single title/name to be utilized multiple times
      - if two functions, etc. are being used in multiple namespaces, the following
         format is needed
      Example: namespace useage
         using namespace ns1;
         functionName();
         or
         using namespace ns2;
         functionName();
      - this will avoid syntax errors
      - unless otherwise noted, programs written are added to the global namespace
      - to create a specific namespace, the following declaration is used
      Example: namespace declaration
         namespace nsName
         {
            body of code
         }
      - this namespace can than be utilized with the appropriate command
      Example:
         using namespace nsName;

      Example of namespace uses can be seen in program below
         - this is just an example, good practice is having a single namespace
            in any given program
*/

#include <iostream>
using namespace std;

namespace test1
{
   void hello() {
      cout << "hello from namespace test1" << endl;
   }
}

namespace test2
{
   void hello() {
      cout << "hello from namespace test2" << endl;
   }
}

int main()
{
   {
      using namespace test1;
      hello();
   }

   {
      using namespace test2;
      hello();
   }

   return 0;
}
