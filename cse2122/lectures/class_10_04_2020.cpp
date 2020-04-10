// Class: CSE 2122 Lecture 20
// Date: 4/10/2020
// topics include: Inheritance, polymorphism
/*
notes:
   - if the implementation program would like to use the base class
      version of a redefined function, do the following
   Example: base class function call format
      childClass variableName;
      variableName.parentClass::functionName();
   - derived classes do NOT inherit base class constructors
   - if the constructor is needed:
   Example: format for calling base class constructor
      childClass::childClass : baseClass(), other variables constructors...
      {  // body of constructor  }
   THIS ORDER IS IMPORTANT
   - if a child class is used as the base class for another class type...
      - the first ancestor class' constructor is called
      - this format is followed until the closest parent constructor
      - the constructor of the child class is completed
   - the derived class does NOT inherit the destructors of the ancestor class
   - variables non-dynamically allocated will be freed
   - dynamically allocated variables will NOT be freed
   - destructors should be made for the child class when dynamic memory is used
   - if the derived class does not contain its own destructor, it will call
      the destuctor of its parent class but this may not free all the memory
   THIS ORDER IS IMPORTANT
   - if a child is the child of a parent
      - the destructor of the bottom child is called first
      - the destructors work up the chain to the highest parent class
      - the "oldest" ancestor's destructor is called last

   Polymorphism:
   - the ability to associate multiple meanings with one function name using
      a mechanism called late binding
   - key component to object oriented programming
   - IMPORTANT - utilizes concepts of inheritance
   - virtual funtions tell the compiler to wait until the function is used in
      a program to implement the function
      - this is called late binding
   Example: format virtual function
      virtual functionName();  // inside the base function

*/

#include <iostream>
using namespace std;

namespace ex1_napoli
{
   class A
   {
   private:
      int priv_exampleA;
   protected:
      int prot_exampleA;
   public:
      int publ_exampleA;

      A() {
         priv_exampleA = 1;
         prot_exampleA = 2;
         publ_exampleA = 3;
      }
   };

   class B : public A
   {
   public:
      void return_A() {
         // cout << ex1::priv_exampleA << endl;   // error
         cout << publ_exampleA << endl;      // no error
         cout << prot_exampleA << endl;      // no error
      }
   };
}

using namespace ex1_napoli;

int main()
{
   B ex_var;
   ex_var.return_A();
   return 0;
}
