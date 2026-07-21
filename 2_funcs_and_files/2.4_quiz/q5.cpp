#include <iostream>

/* 
    Write a complete program that reads an integer from the user, doubles it using the doubleNumber() function you wrote in the previous quiz question, 
    and then prints the doubled value out to the console.
*/

int doubleNumber(int num) {
  return num * 2;
}

int main() {
  int x{};

  std::cout << "Enter a number: ";
  std::cin >> x;

  int result {doubleNumber(x)};

  std::cout << result << "\n";

  return 0;
}