#include <iostream>
#include <cmath> // for std::abs()
#include <algorithm> // for std::max

bool approximatelyEqualAbs(double a, double b, double absEpsilon);

int main()
{
  constexpr double d1 {100.0 - 99.99}; // should equal 0.01 mathematically
  constexpr double d2 {10.0 - 9.99};   // should equal 0.01 mathematically

  if (d1 == d2) 
    std::cout << "d1 == d2" << '\n';
  else if (d1 > d2)
    std::cout << "d1 > d2" << '\n';
  else if (d1 < d2)
    std::cout << "d1 < d2" << '\n';


  /* 
    Variables d1 and d2 should both have the value of 0.01 but the output of this program is: d1 > d2

    If you inspect both values in the debugger youll likely see d1 = 0.010000000000005116 and d2 = 0.0099999999999997868. Both numbers are close to .01 but d1 is greater.

    Comparing floating point numbers using any of the relational operators can be dangerous. This is because floating point values are not precise, and small erors may throw off
    results.

    If the consequence of getting a wrong answer when the operands are similar is acceptable, then using these operators can be acceptable. This is an application-specific decision.
  */

  // Both == and !- can be much more troublesome. Use of these operators with floating point numbers should generally be avoided
  std::cout << std::boolalpha << (0.3 == 0.2 + 0.1) << '\n'; // prints False

  // Okay if its initialized with a literal
  constexpr double gravity { 9.8 };
  if (gravity == 9.8) // okay if gravity was initialized with a literal
      // we're on earth
      std::cout << "Good" << '\n';

  constexpr double absEpsilon{0.5};
  std::cout << approximatelyEqualAbs(d1, d2, absEpsilon) << '\n';

  return 0;
}

/* 
    So how can we reasoanbly compare two floating point operands to see if they are equal?

    The most common method of doing floating point equality involves using a function that looks to see if 2 numbers are almost the same. If they are close enough
    then we call them equal. The value used to represent "close enough" is called EPSILON. Epsilon is generally defined as a small positive number 
    e.g. 0.00000001, sometimes written 1e-8

    The whole point is to give yourself a limit of accuracy and compare it to the limit youve given 

    New developers often try to write their own "close enough" function like this:
*/

// absEpsilon is an absolute value
bool approximatelyEqualAbs(double a, double b, double absEpsilon)  // THIS WORKS BUT IT ISNT GREAT
{ 
  std::cout << std::abs(a-b) << '\n';
  // if the distance between a and b is less than or equal to absEpsilon, then a and b are "close enough"
  return std::abs(a - b) <= absEpsilon;
}
