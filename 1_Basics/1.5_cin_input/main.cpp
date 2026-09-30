#include <iostream>

// Take 3 ints as inputs and outputs them
int main() {
  int a{}, b{}, c{};

  std::cout << "Please enter 3 numbers sperated by a space\n";

  std::cin >> a >> b >> c;

  std::cout << "You entered " 
            << a << ", " 
            << b << ", and " 
            << c << ".\n" ;

  return 0;
}