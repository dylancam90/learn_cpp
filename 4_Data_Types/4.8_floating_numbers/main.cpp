#include <iostream>
#include <limits>
#include <iomanip> // for output manipulator std::setprecision() for extra print precision


int main() 
{
  // Meant to see if types are IEEE 754 compatible
  std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
  std::cout << "Float: " << std::numeric_limits<float>::is_iec559 << '\n';
  std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
  std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';

  // When using floating point literals always include at least one decimal to help the compiler differentiate between int and float
  int a{5};
  double b{5.0}; // no suffix means double type by default
  float c{5.0f}; // 5.0 is a floating point literal, f suffix means float type

  int d{0}; // 0 is an integer
  double e{0.0}; // 0.0 is a double

  // Printing floating point numbers
  std::cout << 5.0 << '\n'; // cout will not print the fractional part of the number if the fractional part is 0
  std::cout << 6.7f << '\n'; // what you expect
  std::cout << 9876543.21 << "\n\n"; // scientific notation

  /* PRECISION - std::cout only has 6 points of precision by default */
  std::cout << 9.87654321f << '\n';     
  std::cout << 987.654321f << '\n';     // all of these will print with 6 digits of precision
  std::cout << 987654.321f << '\n';
  std::cout << 9876543.21f << "\n\n";
 
  // If you need more import #include <iomanip>
  std::cout << std::setprecision(17); // show 17 digits 
  std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
  std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

  // ^^^^^^^^^^^ These wont print correctly because of how floats work in CS. The longer it is the more its likely to be inaccurate

  float f {123456789.0f}; // f has 10 significant digits
  std::cout << std::setprecision(9); // to show 9 digits in f
  std::cout << f << "\n\n"; // The output will be 123456792 which is greater than f because floats typically only have 7 digits of precision, this is called a ROUNDING ERROR

  // To avoid this use double over float unless space is limited.

  /* 
    NAN and inf ------------------------------------------------------------------------

    inf represents infinity and can be positive or negative 
    NaN stand for not a number and there are different kinds of NaN
    Signed Zero which is seperate representations for “positive zero” (+0.0) and “negative zero” (-0.0).
  */

  double zero { 0.0 };

  double posinf { 5.0 / zero }; // positive infinity
  std::cout << posinf << '\n';

  double neginf { -5.0 / zero }; // negative infinity
  std::cout << neginf << '\n';

  double z1 { 0.0 / posinf }; // positive zero
  std::cout << z1 << '\n';

  double z2 { -0.0 / posinf }; // negative zero
  std::cout << z2 << '\n';

  double nan { zero / zero }; // not a number (mathematically invalid)
  std::cout << nan << '\n';

  return 0;
}