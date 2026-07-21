#include <iostream>
#include "io.h"

int readNumber() {
  int num{};
  std::cout << "Enter a number: ";
  std::cin >> num;
  return num;
}

void writeAnswer(int x, int y) {
  std::cout << "The answer is: " << x + y << "\n";
}