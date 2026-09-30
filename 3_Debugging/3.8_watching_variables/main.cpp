#include <iostream>

/* 
  You have to add a breakpoint or else it will run all the way through (this happens because "stopAtEntry": false in launch.json). 
  You can see the variables change in the window which you already know.
*/

int main() 
{
  int x{1};
  std::cout << x << ' ';

  x = x + 2;
  std::cout << x << ' ';

  x = x + 3;
  std::cout << x << ' '; 

  return 0;
}