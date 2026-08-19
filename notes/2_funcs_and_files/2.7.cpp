#include <iostream>

// Identifier - a unique name to identify user-defined program elements like variables, functions, classes, objects, and namespaces

/* 
  A DECLARATION tells the compiler an identifier exists. 
  A DEFINITION is a declaration that actually gets set up in memory.
  A PURE DECLARATION only declares the name and type without allocating space in memory
*/

int add(int x, int y); // PURE DECLARATION

int main() {
  int x; // DECLARATION && DEFINITION (typically called a definition though because the space is allocated here)
  return 0;
}

int add(int x, int y) { // DEFINITION
  int z{x + y};
  return z;
}