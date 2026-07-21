#include <iostream>

int main() {
  std::cout << "Enter an integer: ";

  int a{};

  std::cin >> a;

  std::cout << "Double " << a << " is: " << a * 2 
            << "\nTriple " << a << " is: " << a * 3 
            << "\n";

  return 0;
}