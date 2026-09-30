#include <iostream>

int getInteger() {
  std::cout << "Enter a integer: ";
  int x{};
  std::cin >> x;
  return x;
}