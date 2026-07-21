#include <iostream>

// Write a function called doubleNumber() that takes one integer parameter. The function should return double the value of the parameter.
int doubleNumber(int num) {
  return num * 2;
}

int main() {
  int x {doubleNumber(6)};

  std::cout << x << "\n";

  return 0;
}