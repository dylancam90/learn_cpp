#include <iostream>

/* 
  This is basically a ternary operator but is called a conditional operator


  Operator	    Symbol	  Form	        Meaning
  -----------------------------------------------------------------------------------------------------------------------------
  Conditional	    ?:	    c ? x : y	    If conditional c is true then evaluate x, otherwise evaluate y


  BEST PRACTICE: Parenthesize the entrie conditional operation (including operands) when used in a compound expression.

  Be aware that if both operands arent of the same type or cant be converted to the same type you will get and error.
  To get around this you can do a explicit conversion with a static_cast or something else.


  WHEN TO USE THE CONDITIONAL OPERATOR:

  • Initializing an object with one of two values
  • Assigning one of the two values to an object
  • Passing one of the two values to a function
  • Returning one of the two values to a function
  • Printing one of the two values

  Complicated expressions should generally avoid use of the conditional operator as they tend to be error prone and hard to read.
*/

int main()
{
  constexpr bool inBigClassroom { false };
  constexpr int classSize { inBigClassroom ? 30 : 20 };
  std::cout << "The class size is: " << classSize << '\n';



  return 0;
}