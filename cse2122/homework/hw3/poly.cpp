// Homework 3
// File: poly.cpp
// Created by: Michael Napoli
// Created on: 2/4/2020
// Last modified on:

/*
   Purpose:
*/

#include <cmath>
#include <iostream>
using namespace std;

// Default size of our dynamic coefficient array
const int DEFAULTPOLY = 10;

// Do NOT modify the class header.
class Poly
{
private:
   // Data members
   int arraySize;    // size of array
   int *coeff;       // dynamic array

public:
   // Default Class constructor
   // Allocate an array of DEFAULTPOLY elements and initialize it to the constant 0
   // post: Class object is initialized to degree-0 polynomial of 0
   Poly() {
      // set 'arraySize' to default
      arraySize = DEFAULTPOLY;

      // create array of default size
      coeff = new int [arraySize];

      // set all values to 0
      for (int i(0); i < arraySize; ++i) {
         coeff[i] = 0;
      }
   }

   // Non-default (alternate) Class constructor
   // Allocate an array of 'size' elements and initializes it to the constant 0
   // post: Class object is initialized to degree-0 polynomial of 0
   Poly(int size) {
      // set 'arraySize' to given value
      arraySize = size;

      // allocate memory for dynamic array
      coeff = new int [arraySize];

      // set values of array elements to 0
      for (int i(0); i < arraySize; ++i) {
         coeff[i] = 0;
      }
   }

   // Copy constructor
   // Construct a new Poly that is a copy of an existing Poly
   // post: Class object is initialized to be a copy of the argument Poly
   Poly(const Poly& aPoly) {
      this->operator=(aPoly);
   }

   // Destructor
   // Destroy a poly object by freeing the dynamically allocated array
   ~Poly() {
      // deallocate memory for 'coeff' array
      delete [] coeff;

      // set remainding pointer to NULL
      coeff = nullptr;
   }

   // Assignment operator
   // Assign 'aPoly' Poly object to 'this' Poly object
   // Note: This function is provided, please do not modify it
   const Poly& operator=(const Poly& aPoly);

   // MEMBER FUNCTIONS:

   // member function: grow()
   // This method will allow us to increase the size of the dynamically allocated
   // array by allocating a new array of the desired size, copying the data from
   // the old array to the new array, and then releasing the old array.
   // If the newSize is less than or equal to the current size, then no actions
   // are taken.
   // Note: the maximum degree of a polynomial is one less than the size of the
   // array. The parameter newSize represents the size of the array.
   void grow(int newSize) {
      int* temp_arr;  // pointer variable for the temporary coefficient array

      // if the given array size is equal to or less than the current
      if (newSize <= arraySize) {
         return;  // return nothing (no changes)
      }

      // allocate memory to the temporary array (old size)
      temp_arr = new int [arraySize];

      // create copy of old array
      for (int i(0); i < arraySize; ++i) {
         temp_arr[i] = coeff[i];
      }

      // deallocate memory from old array
      delete [] coeff;
      coeff = nullptr;

      // set 'arraySize' to the new given size
      arraySize = newSize;

      // set 'coeff' array to the new size given
      coeff = new int [arraySize];

      //copy data back into the main array
      for (int i(0); i < arraySize; ++i) {
         coeff[i] = temp_arr[i];
      }

      // deallocate memory from the temporary array
      delete [] temp_arr;
      temp_arr = nullptr;

      return;  // return nothing
   }

   // member function: degree()
   // Finds the degree of a polynomial (the highest power with a non-zero
   // coefficient)
   // pre: Class object exists
   // post: Returns the degree of the polynomial object.
   int degree() const {
      int degree(0);  // variable for the largest polynomial degree in the 'coeff' array

      for (int i(0); i < arraySize; ++i) {
         // if the 'coeff' value is greater than 'degree'
         if (coeff[i] > degree) {
            degree = coeff[i];  // replace the current 'degree' value
         }
      }

      return degree;  // return the largest polynomial value
   }


   // member function: setCoeff()
   // Sets a term, value*x^i, in a polynomial, growing the array if necessary.
   // pre: Class object has been initialized. i is a non-negative integer.
   // post: In the polynomial, the term with power i has coefficient
   //       value. The polynomical was grown if required.
   void setCoeff(int value, int i) {
      // if 'i' is negative, output error and exit function
      if (i < 0) {
         cout << "ERROR: array index can not be negative." << endl;
         return;
      }

      // if the index given is outside array bounds
      if (i > (arraySize - 1)) {
         this->grow(arraySize + 1);  // grow the array appropriately
      }

      // set the necessary 'coeff' index to the given value
      coeff[i] = value;

      return;  // return nothing
   }


   // member function: getCoeff()
   // Finds the coefficient of the x^i term in poly
   // pre: Class object has been initialized. i is a non-negative integer.
   // post: Returns the value of the coefficient of the term with power i
   // note: If the object does not contain a term with power i (e.g.,
   //       i >= arraySize), a coefficient value of zero is returned.
   int getCoeff(int i) const {
      if (i < 0) {
         cout << "ERROR: array index can not be negative." << endl;
         return -1;
      }

      // if the desired coefficient is not a part of the current array
      if (i > (arraySize - 1)) {
         return 0;
      }

      // if parameters are correct, return the correct coefficient
      return coeff[i];
   }

   // member function: negate()
   // Negate a polynomial
   // pre: The class object has been initialized.
   // post: The polynomial has been changed to represent its
   //       multiplication by -1.
   void negate() {
      // set all coefficients to itself multiplied by -1
      for(int i(0); i < arraySize; ++i) {
         coeff[i] *= -1;
      }

      return;  // return nothing
   }

   // FRIEND FUNCTIONS:

   // addition operator
   // Add two polynomials together and return a new polynomial that is the result
   // pre: Both class objects have been initialized
   // post: The sum of two polynomials is stored in a new polynomial which is returned.
   //       The parameter polynomials are not changed.
   friend Poly operator+(const Poly& aPoly, const Poly& bPoly);

   // subtraction operator
   // Subtracts one polynomial from another and return a new polynomial that is the result
   // pre: Both class objects have been initialized
   // post: The difference of two polynomials is stored in a new polynomial which is returned.
   //       The parameter polynomials are not changed.
   friend Poly operator-(const Poly& aPoly, const Poly& bPoly);

   // equality operator
   // Compare two polynomials and return true if they are the same, false otherwise
   // pre: Both class objects have been initialized
   // post: A boolean value indicating whether two polynomials are the same is returned.
   //       The parameter polynomials are not changed.
   friend bool operator==(const Poly& aPoly, const Poly& bPoly);

   // insertion operator for output
   // Print polynomials
   // pre: The class object has been initialized
   // post: several values representing the polynomial are inserted into the output stream
   friend ostream& operator<<(ostream& out, const Poly &aPoly);
};


int main(){

   Poly poly1, poly2;
   int numCoeff, coeffValue, coeffDegree, x;

   // prompt user for the number of coefficients
   cout << "How many coefficients for polynomial 1?" << endl;
   cin >> numCoeff;
   for (int i=0; i<numCoeff; ++i){
      cout << "Coefficient " << i+1 << " for polynomial 1:";
      cin >> coeffValue >> coeffDegree;
      poly1.setCoeff(coeffValue, coeffDegree);
   }

   cout << endl << "How many coefficients for polynomial 2?" << endl;
   cin >> numCoeff;
   for (int i=0; i<numCoeff; ++i){
      cout << "Coefficient " << i+1 << " for polynomial 2:";
      cin >> coeffValue >> coeffDegree;
      poly2.setCoeff(coeffValue, coeffDegree);
   }

   // Sample test cases for degree() and operator<<
   cout << endl << "Polynomial 1 = " << poly1 << endl;
   cout << "Polynomial 1 has degree " << poly1.degree() << endl;
   cout << "Polynomial 2 = " << poly2 << endl;
   cout << "Polynomial 2 has degree " << poly2.degree() << endl;

   // Sample test cases for operator+ and operator-
   cout << endl << "Polynomial 1 + Polynomial 2 = " << poly1 + poly2 << endl;
   cout << "Polynomial 1 - Polynomial 2 = " << poly1 - poly2 << endl << endl;

   // Sample test cases for operator==
   if (poly1==poly2)
      cout << "Two polynomials are the same." << endl;
   else
      cout << "Two polynomials are different." << endl;

   // Try more test cases to test your class thoroughly



   return 0;
}

// Do not modify this function
const Poly& Poly::operator=(const Poly& aPoly){
   if (this==&aPoly)
      return *this;

   if (coeff)
      delete [] coeff;
      arraySize = aPoly.arraySize;
      coeff = new int[arraySize];
      for (int i=0; i<arraySize; ++i){
      coeff[i] = aPoly.getCoeff(i);
   }
   return *this;
}

/* your code here */

Poly operator+(const Poly& aPoly, const Poly& bPoly) {
   return aPoly;
}

Poly operator-(const Poly& aPoly, const Poly& bPoly) {
   int temp_arraySize;  // variable for the maximum array size
   Poly poly_return;  // intialize the return polynomial

   // see which of the two arrays is largest
   // apply largest value to size variable and grow the smaller polynomial to proper size
   if (aPoly.arraySize >= bPoly.arraySize) {
      temp_arraySize = aPoly.arraySize;
      bPoly.grow(temp_arraySize);
   }
   else {
      temp_arraySize = bPoly.arraySize;
      aPoly.grow(temp_arraySize);
   }

   // grow 'poly_return' to the proper arrays size
   poly_return.grow(temp_arraySize);

   // subtract elements of appropriate arrays
   for (int i(0); i < temp_arraySize; ++i) {
      poly_return = aPoly.getCoeff(i) - bPoly.getCoeff(i);
   }

   // return the new polynomial
   return poly_return;
}

bool operator==(const Poly& aPoly, const Poly& bPoly) {
   return false;
}

ostream& operator<<(ostream& out, const Poly &aPoly) {
   for (int i(0); i < aPoly.arraySize; ++i) {

   }

   // return?
}
