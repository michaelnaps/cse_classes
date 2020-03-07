// Class: CSE 2122 Lecture 14
// Date: 3/4/2020
// topics include: recursion
/*
notes:
   (1) Example of recursive function: 'power()'
   - when designing a recursive function:
      - check that the function cannot be inifite
      - check that the stopping case returns the correct value
      - check that the final answer is correct
   (2) binary search algorithm: 'search()'
      - with a given SORTED array, do the following
      - if the middle index is what is wanted, return
      - if it is greater than value wanted, search first half of array
      - if it is less than the value wanted, search second half of array
      - continue until value is found
      - if the value is not in the array:
         - the beginning and ending indexes will be seperated by 1
         - important stopping case
      - if value cannot be found, return -1 for the index
      - note: indexes are integers so half location will be approximate if array has
         even number of elements

*/

#include <iostream>
using namespace std;

// (2)
int power(int x, int pow) {
   // the base/stopping case
   if (pow == 0) {
      return 1;
   }

   return (power(x, pow - 1) * x);
}

// (3)
// 'k' - desired value
int search(int find, const int *arr, int begin, int end) {
   int n = (end + begin) / 2;  // value to be checked against 'find'

   // stopping case 1
   // if the given parameters have no values between them
   if (begin == (end - 1)) {
      return -1;  // value is not in array, return -1
   }
   else {
      // stopping case 2
      if (arr[n] == find) {
         return n;
      }
      else if (arr[n] > find) {
         n = search(find, arr, 0, n);
      }
      else if (arr[n] < find) {
         n = search(find, arr, n, end);
      }
   }

   return n;
}

int main()
{
   int x(0), n(0);

   cout << "Enter number and power respectively: ";
   cin >> x >> n;

   cout << endl << x << '^' << n << " = " << power(x, n) << endl;

   int arr[5];
   int index(-1);

   cout << endl << "Enter 5 values for the array: ";
   for (int i(0); i < 5; ++i) {
      cin >> arr[i];
   }

   index = search(3, arr, 0, 5);

   if (index == -1) {
      cout << "3 was not in the given array." << endl;
   }
   else {
      cout << "Index for 3 = " << index << endl;
   }

   return 0;
}
