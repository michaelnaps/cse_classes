// Class: CSE 2122 Lecture 22
// Date: 4/17/2020
// topics include: slicing problem, template programming
/*
notes:
   Slicing Problem:
   - slicing problem - when a derived class is copied to a base class
      the member variables of the derived that is not a part of the base
      will be lost
   - this is also apparent in functions because ancestor class cannot be
      used to replace derived classes in implementation
   - this can be avoided by using dynamic memory and pointers
   - a pointer of a ancestor class can ustilize the memory locations of
      a derived class, access by following:
   Example: base class used to access derived members
      baseClass* var1;  // pointer
      derivedClass var2(initialized);
      var1 = &var2;  // assign memory address;
      var1.virtualFunction();  // access the base class' version of the vf
      var1->virtaalFunction();  // access the derived class' version of the vf
   IF THE FUNCTIONS BEING USED ARE VIRTUAL: (late binding)
   - in this instance the base class variable can even call member functions
      that give direct access to derived class variables
   - as long as the '->' operator is used instead of the dot operator, the
      variable will be able to utilize derived class variables
   - if both variables are pointers, the derived class can be directly applied
      to the base class variable but the same function logic needs followed

   Template Programming: making code more flexible
   - functions are often written for specific implementation in ways that
      can be generalized for other purposes
   - the swap function is a good exmaple
   Example: swap function
      void swap(int& v1, int& v2);  // specific impl.
   - a function template will allow function implementation for any variable
      type as long as the function rules are followed
   - a template function can be defined in the following way
   (1) Example: template function format
      temaple <class T>  // 'T' is a type parameter
      void swap(T& var1, T& var2);  // generalized impl.
   - as long as the type parameter is not a keyword it is acceptable
   - also good practice is to start the type parameter name with a capital letter
   - to declare two different type parameters do the following
   (2) Example: template function, two or more type parameters
      template <class T1, class T2>
   - NOTE: for creating these functions, somtimes it will be easier to start with a
      concrete data type and then convert it later

*/

#include <iostream>
using namespace std;

// (1)
template <class T>
void swap(const T& var1, const T& var2) {
   T temp(var1);
   var1 = var2;
   var2 = temp;
}

// (2)
template <class T1, class T2>
void print(const T1& var1, const T2& var2) {
   cout << var1 << ' ' << var2 << endl;
}

int main()
{
   string test = "test testing";
   print((double)4.25, (char)test[3]);
   print((int)4, (string)test);
   return 0;
}
