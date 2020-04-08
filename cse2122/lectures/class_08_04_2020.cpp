// Class: CSE 2122 Lecture 19
// Date: 4/8/2020
// topics include: inheritance details
/*
notes:
   - inheritance is when a class is created using other "base/parent" classes
      - the new class is considered the "derived/child" class
   - when the derived class is created using the format below, it will "inherit"
      all of the member functions and variables from the base class and therefore
      be able to utilize them
   Example format:
      class derivedClass : public baseClass {
         class body...
      }
   - the parent class may also be referred to as the ancestor of the child class
   - the child class may also be referred to as the descendant of the parent class
      - that being said, ancestor and descendant is most often used when the
         classes are seperated by more than one level
   - an object of a class type can be used wherever an of its ancestors can be used
   - an ancestor cannot be used wherever one of its descendants can be used
   Example: Class A <- already initialized
      class B : public A {}
      - wherever class A can be used, class B can be used
      - class A cannot be used wherever class B is being used
      - this is mostly applied to functions inputs (see below)
      output ex_function1(A variable);
      - this function can take inputs of B
      output ex_function2(B variable);
      - this function cannot take inputs of A
   - private member variables in the parent class are not accessible from the child
   - protected member variables ARE given to the child from the parent
   - protected member variables are only accessible by the parent functions and its descnedants
      - i.e. not accessible only from the implementation program
   - not all members will be inherited by the derived class:
      - constructors (unless default)
      - destructors
      - the assignment operator
      - friend function relationships

*/

#include <iostream>
using namespace std;

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
      // cout << priv_exampleA << endl;   // error
      cout << publ_exampleA << endl;      // no error
      cout << prot_exampleA << endl;      // no error
   }
};

int main()
{
   B output_ex;
   output_ex.return_A();
   // commented out calls will return syntax error
   // cout << output_ex.priv_exampleA << endl;     // error
   cout << output_ex.publ_exampleA << endl;        // no error
   // cout << output_ex.prot_exampleA << endl;     // error
   return 0;
}
