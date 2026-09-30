#include <iostream>
/*
  Question #1

  Write a short program where the user is asked to enter a single character. Print the value of the character and its ASCII code, using static_cast.
*/

/*
  Question #2

  Modify the program you wrote for quiz #1 to use implicit type conversion instead of static_cast. How many different ways can you think of to do this?
*/

int charAsInt(char c)
{
  // you should be using static_cast<int>(c) this is just an example of implicit vs explicit 
  return c;
}

int main() 
{
  std::cout << "Enter a char: " << '\n';

  char c{};
  std::cin >> c;
  std::cout << "You entered: " << "\"" << c << "\"" << ", which has ASCII code: " << charAsInt(c) << "." << '\n';


  return 0;
}
