#include <iostream>

/* 
  A CONSTANT EXPRESSION is a non-empty sequence of literals, constant variables, operators, and function calls, all of which must be evaluated at compile time.
  An expression that is not evaluated at compile time is called a RUNRIME EXPRESSION

  const means "can't change." constexpr means "can be evaluated at compile time."

*/

int getNumber()
{
  std::cout << "Enter a number: " << '\n';
  int y{};
  std::cin >> y; // can only execute at runtime since the compiler cant handle I/O

  return y; // return expression is runtime expression
}
/* 
  The return value of a non-constexpr function is a runtime expression
  even when the return expression is a constant expression 
*/
int five()
{
  return 5;  // this return expression if a constant expression even though the function is not
}

int main() 
{
  // Literals can be used in constant expressions
  5;                // constant expression
  1.2;              // constant expression
  "Hello world!";   // constant expression

  // Most operators that have constant expression operands can be used in constant expressions
  5 + 6;            // constant expression
  1.2 * 3.4;        // constant expression
  8 - 5.6;          // constant expression
  sizeof(int) + 1;  // constant expression

  // The return valuse of a non-constexpr functions can only be used in runtime expressions
  getNumber();      // runtime expression
  five();           // runtime expression 

  // Operators without constant expression operands can only be used in runtime expressions
  std::cout << 5;   // runtime expression (std::cout isn't a constant expression operand)

  // Const integral variables with a constant expression initializer can be used in constant expressions:
  const int a {5};          // a is usable in constant expressions
  const int b {a};          // b is usable in constant expressions (a is a constant expression per the prior statement)
  const  long c {a + 2};    // c is usable in constant expressions (operator+ has a constant expression operand even though its a non integral type)
  
  // Other variables cannot be used in constant expressions (even when the have a constant expression initializer)
  int d {5};                // d is not usable in constant expressions (d is non constant)
  const int e {d};          // e is not usable in constant expressions (initializer is no a constant expression)
  const double f {1.2};     // f in not usable in constant expressions (not a const integral variable)

  return 0;
}