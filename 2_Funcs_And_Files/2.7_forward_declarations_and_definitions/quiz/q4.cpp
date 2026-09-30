#include <iostream>

int doMath(int first, int second, int third, int fourth);

int main() {
  std::cout << doMath(1, 2, 3, 4); // the function here called in this maaner is called a temporary object
  return 0;
}

// Write the function declaration for this function (use the preferred form with names)
int doMath(int first, int second, int third, int fourth)
{
     return first + second * third / fourth;
}