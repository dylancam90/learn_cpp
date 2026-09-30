#include <iostream>

/* 
  Narrowing: when the type is too small for a specific primitive. ex: int x = 4.5 will be narrowed to 4 (the compiller will warn you)
  Vexing Parse: when the compiler mistakes a var declaration for a function prototype
*/

int main() {
  // Default initialization (in most cases the value will be garbage)
  int x;

  // Copy initialization (issues: Narrowing and function vexing)
  int y = 5;

  // Direct initialization /  Parenthesis initialization (issues: Narrowing and function vexing)
  int c(5);

  // Direct list initialization / uniform initialization (best: prevents narrowing)
  int k{5};

  // Copy list initialization (not as safe as direct list initialization / value  initialization)
  int l = {5};

  // Value initialization
  int m{};

  /* 
    Q - What is the difference between initialization and assignment? 

    A - Initialization provides a variable with an initial value (at the point of creation) while assignment gives a varaible a new value
  */

  return 0;
}