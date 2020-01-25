// Class: CSE 2122 Lecture 2
// Date: 1/10/2020
// topics include: basic review
/*
notes:
   - ascii digit loactions can be found by applying the character to an integer
      type variable
   - Example in code (1)

   - short circuit evaluation can be used to avoid run-time errors
   - Example in code (2)

   - operators within a program will be executed via the precendence strength

*/

#include <iostream>
using namespace std;

int main()
{
   // (1)
   const int ASCII_ZERO_LOC('0');

   cout << ASCII_ZERO_LOC << endl;

   // (2) short circuit statement, run-time error avoidance
   int kids;
   int candy(6);

   cout << "Enter number of kids: ";
   cin >> kids;

   // if kids is inputted as zero, the expression in the output will cause a runtime error
   //                                   expression here vvvvvv
   if (!(kids == 0)) { cout << "Each kid gets " << (candy / kids) << " pieces!" << endl; }
   // avoid the error
   else { cout << "Where the hell are the kids?" << endl; }

   return 0;
}