#include <iostream>

/* 
  Put breakpoints at line 9 and 14 and take a look at the call stack window. Now hit the continue button and see how it changes
*/

void a() 
{
  std::cout << "a() called\n";
}

void b() 
{
  std::cout << "b() called\n";
}

int main() 
{
  a();
  b();

  return 0;
}