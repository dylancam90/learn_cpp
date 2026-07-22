#include <iostream>

/* 

  If using print statements to debug use std::cerr but that leaves a lot lines that will need to be commented out or removed manually. 

  OR USE A LOGGER, see an example of this in learn_cpp/3_debugging_cpp/3.5_logger/main.cpp

*/



// Instead use preproccessor directives 
#define ENABLE_DEBUG // Comment this out if you dont want the debug output

int getUserInput() {
  
  #ifdef ENABLE_DEBUG // Now its conditional based on whether its commented out or not
    std::cerr << "getUserInput() called\n";
  #endif

  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;
  return x;
}

int main() {

  #ifdef ENABLE_DEBUG
    std::cerr << "main() called\n";
  #endif

  int x{getUserInput()};
  std::cout << "You entered: " << x << "\n";

  return 0;
}
