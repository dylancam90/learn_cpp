#include "add.h"
#include <iostream>

/* 
  To compile this in the command line enter: 
    
          g++ main.cpp add.cpp -o main
  
  The header files get found by the preproccessor


*/

int main() {
  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n";
  return 0;
}