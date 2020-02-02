// Class: CSE 2122 Lecture 8
// Date: 1/31/2020
// topics include: user class, constructors, friend functions
/*
notes:
   - in most cases objects of class types are passed to functions by reference, not by value
      - this is more efficient for memory useage

   Constructors:
   - normal '=' operands do not work for class member variables because of the
      possibility for more than one object within the variable
   - these are special member functions that are used to initialize class variables
      when they are declared in the main program
   - format:
      - they are declared like a member function of a class but do not have a return data type
         as well as have the same function name as the class name
      - Example:
         class class_name
         {
         public:
            Class_Name::Class_Name(variable_type variable_name, variable_type variable_name)
            or
            Class_Name::Class_Name(): variable_name(1)  // used to initialize with constants if the user does themselves
            ...
         }
   - a constructor is not called using the dot notation, but instead is called whenever an object
      is declared
   - Example: during declaration
      class_name variable_name(inputs);
      or
      class_name variable_name;
   - we can also overload the constructors so that the user does not always have to declare variables
      in the same manner, also makes it so the user does not need to initialize variable at all

   Friend Functions:
   - friend functions are not member functions of a class, but can access private member functions within a class
   - they are regular, nonmember functions given access to the class
   - Example:
      (within class 'public' definition)
      friend function_name;
      (outside of class)
      return_type function_name(input parameters);
   - the '::' operand is NOT used in the declaration of a friend function
   - friend functions are called like a normal function, not using the dot notation of member functions

*/

#include <iostream>
using namespace std;

int main()
{


   return 0;
}
