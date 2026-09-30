#include <iostream>

/* 
  Operator	Symbol	  Form	  Operation
  -----------------------------------------------------------------
  Comma	      ,	      x, y	  Evaluate x then y, returns value of y


  The comma operator ',' allows you to evaluate multiple expressions wherever a single expression is allowed. The comma operator evaluates to the left operand,
  then the right operand, and then returns the result of the right operand

  NOTE: the comma operator has the lowest precedence of all the operators, even lower than assignment

  z = (a, b);   // evaluate (a, b) first to get result of b, then assign that value to variable z
  z = a, b;     // evaluates as "(z=a) ,b" so z gets assigned the value of a, and b is evaluated and discarded


  BEST PRACTICE: Avoid using the comma operator as all with a single excpetion of inside for loops
*/

int main()
{
  int x{1};
  int y{2};

  std::cout << (++x, ++y) << '\n'; // increment x and y, return y


  

  return 0;
}