/* 
  QUIZ 

  For each statement, identify:

    Whether the initializer is a constant expression or non-constant expression.
    Whether the variable is a constant expression or non-constant expression.

*/
#include <iostream>

int main() 
{
  // a
  char a { 'q' }; // the variable 'q' is a constant expression, 'a' is a non-constant expression because its not const

  // b
  const int b { 0 }; // '0' is a constant expression since it is a literal, 'b' is a constant expression since it is a const integral type with a constant expression initializer

  // c
  const double c { 5.0 }; // a double is a non integral type but 5.0 is because its a literal

  // d
  const int d { a * 2 }; // a * 2 isn't because a is not a constant expression making d also not a const expression

  // e
  int e { c + 1.0 }; // c is a non-constant expression, so c + 1.0 is a non-constant expression. e is a non-constant expression because it is not defined as const and because it does not have a constant expression initializer.

  // f
  // Both d and 2 are constant expressions, so d * 2 is a constant expression.
  // f is a constant expression since it is a const integral type with a constant expression initializer.
  const int f { d * 2 }; // d defined as const int d { 0 };

  // g
  // getNumber() returns a non-constant value, so it is a non-constant expression.
  // g is a non-constant expression because the initializer is a non-constant expression.
  const int g { getNumber() }; // getNumber returns a int by value 

  // h (extra credit)
  // {} invokes value-initialization. There is no explicit initializer here.
  // h is a constant expression since it is a const integral type with a constant expression initializer (value initialization initializes h to 0, which is a constant expression).
  const int h{};


  return 0;
}