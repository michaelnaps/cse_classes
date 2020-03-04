// Class: CSE 2122 Lecture 14
// Date: 3/4/2020
// topics include: recursion
/*
notes:
   Recursion - solving a problem using repetitive programming language
   - recursion functions call on themselves in order to complete a larger task in increments
   (1) Example Function: write_vertical();
   - writing a given number in vertical orientation
      step 1: create the write_vertical() function
      step 2: if the value is less than 10, output the single digit
      step 3: otherwise, put value through the function again divided by 10
      step 4: output the front number using the '%' operator
   - recursive functions require that the function only calls itself to complete the goal given
      - when called by itself, argument MUST BE DIFFERENT than the initial one given
   - recursive calls
      - pause at the point of the recursive call
      - save information for later execution
      - resumes execution after the recursive call finishes
   - one or more recursive calls must accomplish task without the main recursive call
      - called the 'base cases' or 'stopping cases'
   - basically, the final recursive call must be independent of the recursive function
   - 'Stacks' are used to keep track of recusion because of the LIFO (last in first out) trend

*/

#include <iostream>
using namespace std;

// (1)
// this function is considered 'recursive' because it calls itself upon execution but with a different argument
void write_vertical(int n) {
   // if the input is less than 10
   if (n < 10) {
      cout << n << endl;  // output the single digit
   }
   // otherwise
   else {
      write_vertical(n / 10);  // cut off the last digit of the input and put back through function
      cout << n % 10 << endl;  // output intput's last digit
   }
}

int main()
{
   int n;

   cout << "Enter number to be written vertically: ";
   cin >> n;

   write_vertical(n);

   return 0;
}
