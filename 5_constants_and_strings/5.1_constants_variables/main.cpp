#include <iostream>

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