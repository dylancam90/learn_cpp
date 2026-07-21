#include <iostream>

using namespace std; // this is called a USING DIRECTIVE, apparently its discouraged so naming collisions dont occur

int main() {
  /* 
    The "::" is called the SCOPE RESOLUTION OPERATOR. The indentifier to the left indicates the namespace that the identifier to the right belongs to.
    If no identifier to the left is provided the global namespace is assumed.

    When a identifier includes a namespace prefix, the identifier is called a qualified name
  */
  std::cout << "Hello, world!"; // qualified name that uses a scope resolution operator

  return 0;
}