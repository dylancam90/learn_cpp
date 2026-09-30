#include <iostream>
#include <cmath> // for std::abs()
#include <algorithm> // for std::max

  /* 
    So how can we reasoanbly compare two floating point operands to see if they are equal?

    The most common method of doing floating point equality involves using a function that looks to see if 2 numbers are almost the same. If they are close enough
    then we call them equal. The value used to represent "close enough" is called EPSILON. Epsilon is generally defined as a small positive number 
    e.g. 0.00000001, sometimes written 1e-8
  */

  // Return true if the difference between a and b is within the epsilon percent of the larger of a and b
  constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
  {
    // Now instead of the epsilon being an absolute number, epsilon is now relative to the magnitude of a or b
    return (std::abs(a - b) <= 
           (std::max(std::abs(a), std::abs(b)) * relEpsilon));
  }

  // This one uses both relative and absolute for numbers really close to zero (see further down)
  constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);


  /* 
    std::abs() - returns the absolute value of a number, basically its distance from zero. If 5 then 5, if -5 then also 5.
    std::max() - Takes 2 values and returns the largest one. You can also give it a initializer list: { 5, 10, 3, 8, 2 } 

    On the left side of the <= operator, std::abs(a - b) tells us the distance between a and b as a postitive number

    On the right side of the <= operator we need to calculate the largest value of "close enough" we're willing to accept. To do this the algorithm chooses the larger
    of a and b and then multiplies it by the epsilon. In this function relEpsilon represents a percentage. For example, if we want to say "close enough" means a and b
    are within 1% of the larger of a and b, we pass in a reEpsilon of 0.01 (1% = 1/100 = 0.01). The value for Epsilon can be adjusted to whatever is most appropriate
    for the circumstances. e.g. an epsilon of 0.002 means within 0.2%
  */

  // Return true if the difference between a and b is within epsilon percent of the larger of a and b
  int main()
  {
    // a is really close to 1.0, but has rounding errors
    constexpr double a { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    constexpr double relEps {1e-8};   // relative epsilon (%)
    constexpr double absEps {1e-12};  // absolute epsilon (const)

    std::cout << std::boolalpha; // print true or false instead of 1 or 0

    // First lets compare a (almost 1.0) to 1.0
    std::cout << approximatelyEqualRel(a, 1.0, relEps) << '\n';
    // Second, lets compare a - 1.0 (almost 0.0) to 0.0
    std::cout << approximatelyEqualRel(a - 1.0, 0.0, relEps) << '\n';

    /* 
      Output:
        true
        false

      The reason for the second output is because the math breaks down close to zero.

      One way to avoid this is to use both an absolute epsilon and a relative epsilon:
    */

    // Now with the updated functon
    std::cout << approximatelyEqualAbsRel(a, 1.0, absEps, relEps) << '\n';     // compare "almost 1.0" to 1.0
    std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, absEps, relEps) << '\n'; // compare "almost 0.0" to 0.0

    // Now the output for these is true

    return 0;
  }

  // Can make this constexpr in C++23+ because std::abs wasnt made constexpr until C++23. 
  constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) 
  {
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon) 
      return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
  }

  /* 
    If using something older than C++23 use this template:

    template <typename T>
    constexpr T constAbs(T x)
    {
        return (x < 0 ? -x : x);
    }
  
  */