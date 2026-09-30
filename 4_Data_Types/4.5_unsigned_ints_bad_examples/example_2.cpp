#include <iostream>

/* 
  This example explains what happens when an expression uses both unsigned and signed ints

  BE AWARE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  when a signed and unsigned int are operated on the result converts to a UNSIGNED INT
*/

// assuming an int is 4 bytes
int main() 
{
  unsigned int u{ 2 };
  // "signed" is redundant in this case because "int" is signed by default 
  signed int s{ 3 }; //  

  std::cout << u - s << '\n'; // 2 - 3 = -1 but since a singed + unsigned operation results in a UNSIGNED int there becomes a unsigned int underflow

  return 0;
}