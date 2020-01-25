// Class: CSE 2122 Lecture 5
// Date: 1/22/2020
// topics include: arrays, multidimensional arrays, pointers
/*
notes:
   Arrays:
   -to declare an array us the syntax
      variable_type variable_name[number_of_values];
   -a common error is accessing indexes that do not exist, for example:
      int array[5] = ... ;
      cout << array[5] << endl;
   -the outcome of this action is not always known because the memory space after array[4] 
      may or may not have an outputtable value
   -array indexes count by 0, i.e. they go from 0 - (n-1)

   NEW FOR LOOP NOTATION:
   -when iterating over all elements of an array
      for (int start_num : array_name) {}
   
   Multidimensional Arrays:
   -Declaration sytnax
      variable_type variable_name[size1][size2]...[sizeN];
   -Example:
      int arr_2x3[2][3];
      -this array will be a 2x3 (2 rows and 3 collumns)
   -functions that require matrices do not need all dimensions, just all the dimensions
      after the first value
   -Example:
      void function_name(int matrice[][3], const int ROW_NUM);

   Pointers:
   -used to more specficially control memory location useage
   -memory addresses can be used to identify variables
   -pointer declaration has the following syntax
      variable_type* variable_name;  // the asterisks is what makes it a pointer
   -if multiple pointers are declared at once, use the following syntax
      variable_type *var1, *var2, ..., *varN;  // place asterisks before each variable name
   -the address operator '&' can be used to recieve the memory address for a pointer
      address = &pointer;
   -Example pointer assignments:
      p1 = p2;  // assigns the memory location of p2 to p1
      *p1 = *p2;  // assigns the value within p2 to p1
      
*/

#include <iostream>
using namespace std;  // apparently this can be within the main function

int main()
{
   // new for loop example
   int ARR_SIZE(5);
   int count_arr[ARR_SIZE] = {1, 2, 3, 4, 5};

   for (int x : count_arr) {
      cout << x << endl;
   }

   // multidimensional array example
   int matrice_2x3[2][3];

   // variable 'i' will loop through all rows
   for (int i(0); i < 2; ++i) {
      // variable 'k' will loop through all collumns
      for (int k(0); k < 3; ++k) {
         // each element will get a single value
         matrice_2x3[i][k] = (i + 1) * (k + 1);
         // output element value
         cout << matrice_2x3[i][k] << " ";
      }
      // next line when operating between array rows
      cout << endl;
   }

   return 0;
}