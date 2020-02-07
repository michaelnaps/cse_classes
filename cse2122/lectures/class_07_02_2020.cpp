// Class: CSE 2122 Lecture 8
// Date: 1/31/2020
// topics include: overloading operators for IO, destructors
/*
notes:
   - overloading operators is not a necessity for any function
   - the '<<' operator is a binary operator and thus can be treated like other algebra symbols
   - this operator declaration must include an output variable and the class variable
   - Example:
      // for output
      ostream& operator<<(ostream& output_variable_name, Class_name variable_name);
      // for input
      istream& operator>>(istream& input_variable_name, Class_name variable_name);
   - also, this function must contain a 'return output_variable_name;'
   - very imporant that the return variable is the output stream used in the function
   - also very important that the ouput/input parameter is by reference, because of its complexity
   - overloading the input operator is declared and returned in the same format

   Destructors:
   - member functions that are called automatically upon the end of a variable's use
   - declaration is similar to that of a constructor
   - Example:
      ~Class_name() { function body }
   - these functions are most important for class types that contain pointer variables
   - 

*/

#include <iostream>
using namespace std;

int main()
{

}
