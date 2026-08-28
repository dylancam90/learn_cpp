#include <iostream>

/* 
  Pre-increment/decrement is more performant because post creates a copy of the value while pre returns a reference to the modified value 

  BEST PRACTICE: Always use prefix considering its more performate and less likely to surprise you
*/

int add(int x, int y) // used to show side effects
{
  return x + y;
}

int main()
{

  int x{5};
  int y{5};
  std::cout << x << ' ' << y << '\n';       // output: 5 5
  std::cout << ++x << ' ' << --y << '\n';   // output: 6 4 
  std::cout << x << ' ' << y << '\n';       // output: 6 4
  std::cout << x++ << ' ' << y-- << '\n';   // output: 6 4 (numbers get incremented/decremented after they are used)
  std::cout << x << ' ' << y << '\n';       // output: 7 3


  /* Potential side effects */
  int i{5};
  int value{add(x, ++x)}; // undefined behavior, is this 5 + 6 or 6 + 6? It depends on what your compiler does (thankfully the linter will catch it)

  std::cout << value << '\n';


  return 0;
}