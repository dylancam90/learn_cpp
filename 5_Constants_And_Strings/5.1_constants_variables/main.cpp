#include <iostream>

/* 
  C++ supports 2 kinds of constants 

  Named constants - constant values that are associated with an identifier. These are sometimes called symbolic constants 
  Literal constants - constant values that are not associated with an identifier

  This covers named constants with 5.2 covering literal constants

  Types of named constants 
  There are three ways to define a named constant in C++:

    Constant variables 
    Object-like macros with substitution text (introduced in 2.1 intro to the preprocessor)
    Enumerated constants (13.2 unscoped enumerations)

  Constant variables are the most common 

  refer to learn_cpp/5_constants_and_strings/5.1_constants_variables.cpp to see how to define constants 

*/


#define MY_NAME "Alex" // this is a constant technically bt dont use these as constants 

int main() 
{
  const double gravity{9.8}; // perferred use of const before type
  int const sidesInSquare{4}; // DONT USE THIS: "east const" style, okay but not preferred

/* 
  // Const variables must be initialized
  const double gravity; // error: const variables must be initialized 
  gravity = 9.9;        // error: const cant be changed
*/

  // Note that const variables can be initialized from other variables (including non-const ones):
  std::cout << "Enter your age: ";
  int age{};
  std::cin >> age;

  const int constAge{age}; // initialize const variable using non-const value

  // There are no special naming conventions for const variables. Just use camelCase 

  return 0;
}