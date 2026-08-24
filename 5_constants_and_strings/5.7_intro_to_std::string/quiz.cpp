#include <iostream>
#include <string>
#include <typeinfo> // To print out the type of a variable or returned value

/* 
  Question #1

  Write a program that asks the user to enter their full name and their age.  
  As output, tell the user the sum of their age and the number of characters in their name (use the std::string::length() member function to get the length of the string). 
  For simplicity, count any spaces in the name as a character.
*/

int main()
{
  std::cout << "Enter full name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);

  std::cout << "Enter your age: ";
  unsigned int age{};
  std::cin >> age;

  // ChatGPT recommends not statically casting since its not needed, and I agree. No conversion needs to take place and memory isn't an issue
  const std::size_t nameLen{name.length()};
  const int total{nameLen + age};

  std::cout << "Your age + length of name is: " << total << '\n';

  // unrelated to the question, this prints out "m" which is a unsigned integral type used to represent size_t thats returned from name.length() without a static cast
  std::cout << typeid(name.length()).name() << '\n';

  return 0;
}