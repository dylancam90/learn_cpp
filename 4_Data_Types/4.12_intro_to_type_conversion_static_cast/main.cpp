#include <cstdint>
#include <iostream>

void printDouble(double value)
{
  std::cout << value << '\n';
}

void printInt(int value)
{
  std::cout << value << '\n';
}

int main()
{
  /*
    TYPE CONVERSION

    Type conversion is the process of converting a value from one type to another.

    C++ can perform some conversions automatically (implicit conversion), or we can
    explicitly request a conversion ourselves using static_cast.

    IMPORTANT:
    Converting a value does NOT change the type of the original variable.
    The conversion produces a new value of the destination type.
  */

  int number{5};

  printDouble(number); // int 5 is implicitly converted to double 5.0

  // number is still an int and still contains 5.
  std::cout << number << '\n';


  /*
    IMPLICIT TYPE CONVERSION

    An implicit conversion happens when the compiler converts a value for us.

    In the example below, printDouble() requires a double, but we give it an int.
    C++ converts the int value into a double value automatically.

    Some implicit conversions preserve the value safely.
    Others may lose information.
  */

  int wholeNumber{10};
  printDouble(wholeNumber); // int -> double


  /*
    CONVERSIONS CAN LOSE INFORMATION

    Converting from double to int discards the fractional portion.

      5.5 -> 5
      9.9 -> 9

    The compiler may warn about conversions where information could be lost.
  */

  double decimal{5.5};

  // printInt(decimal);
  // The conversion is possible, but may generate a warning because .5 is lost.


  /*
    BRACE INITIALIZATION HELPS PREVENT NARROWING

    Brace initialization generally rejects implicit conversions that could lose data.

      int value{5.5}; // error: narrowing conversion

    This is one reason brace initialization is preferred.
  */

  double safeValue{5}; // okay: int 5 can be represented as double 5.0

  [[maybe_unused]] double unusedSafeValue{safeValue};


  /*
    EXPLICIT TYPE CONVERSION WITH static_cast

    static_cast allows us to explicitly request a conversion.

    Syntax:

      static_cast<new_type>(expression)

    This tells the compiler:
      "I intentionally want this value converted to this type."

    Because we explicitly requested the conversion, the compiler knows that we are
    taking responsibility for possible information loss.
  */

  double price{9.75};

  int wholePrice{static_cast<int>(price)};

  std::cout << "Original double: " << price << '\n';       // 9.75
  std::cout << "Converted int: " << wholePrice << '\n';    // 9

  // price itself was NOT changed.
  // static_cast<int>(price) produced a new int value.


  /*
    static_cast WITH EXPRESSIONS

    The thing inside static_cast(...) can be any expression.

    The expression is evaluated first, then the resulting value is converted.
  */

  int x{5};
  int y{2};

  double result{static_cast<double>(x) / y};

  // Without the cast:
  //   5 / 2 = 2        (integer division)
  //
  // With the cast:
  //   5.0 / 2 = 2.5    (floating-point division)

  std::cout << "5 / 2 as floating-point division: " << result << '\n';


  /*
    USING static_cast TO PRINT A char AS AN INTEGER

    A char stores an integer value internally, but std::cout normally prints it
    as a character.

    static_cast<int>(character) lets us view its numeric value instead.
  */

  char letter{'A'};

  std::cout << "Character: " << letter << '\n';
  std::cout << "Numeric value: " << static_cast<int>(letter) << '\n';


  /*
    std::int8_t AND std::uint8_t

    On many systems:

      std::int8_t  behaves like signed char
      std::uint8_t behaves like unsigned char

    Because of this, std::cout may treat these types as characters instead of
    ordinary integers.

    Converting them to int before printing ensures that their NUMERIC value is
    printed.
  */

  std::uint8_t byteValue{65};

  // This may print the character 'A' instead of the number 65:
  std::cout << "uint8_t printed directly: " << byteValue << '\n';

  // This reliably prints the numeric value:
  std::cout << "uint8_t as int: "
            << static_cast<int>(byteValue)
            << '\n';


  /*
    BE CAREFUL READING INPUT DIRECTLY INTO std::uint8_t

    Because std::uint8_t is often an alias for unsigned char, std::cin may treat
    the input as character input.

    For example, if the user types:

      35

    std::cin may read only the character '3', whose character code is 51.

    A common solution is to read into a normal integer type first, validate the
    range, then explicitly convert it.
  */

  unsigned int input{};

  std::cout << "Enter a number from 0 to 255: ";
  std::cin >> input;

  if (input <= 255)
  {
    std::uint8_t smallValue{static_cast<std::uint8_t>(input)};

    std::cout << "Stored uint8_t value: "
              << static_cast<int>(smallValue)
              << '\n';
  }
  else
  {
    std::cout << "Value is outside the range of uint8_t.\n";
  }


  /*
    SIGNED / UNSIGNED CONVERSIONS

    static_cast can also explicitly convert between signed and unsigned integers.

    If the value exists in both types, the numeric value stays the same.
  */

  unsigned int unsignedFive{5};
  int signedFive{static_cast<int>(unsignedFive)};

  int anotherFive{5};
  unsigned int anotherUnsignedFive{
    static_cast<unsigned int>(anotherFive)
  };

  std::cout << signedFive << '\n';          // 5
  std::cout << anotherUnsignedFive << '\n'; // 5


  /*
    OUT-OF-RANGE SIGNED / UNSIGNED CONVERSIONS

    Be careful when the value cannot be represented by the destination type.

    Example on a system with 32-bit unsigned int:

      int negative{-1};

      static_cast<unsigned int>(negative)

    produces a very large unsigned value (typically 4294967295).

    Just because static_cast allows a conversion does NOT mean the conversion is
    necessarily a good idea.

    static_cast makes the conversion explicit -- it does not make an unsafe or
    lossy conversion magically safe.
  */


  /*
    QUICK SUMMARY

    Implicit conversion:
      The compiler converts the value automatically.

        int x{5};
        double y{x}; // int -> double

    Explicit conversion:
      We request the conversion ourselves.

        double x{5.5};
        int y{static_cast<int>(x)}; // 5

    static_cast syntax:

      static_cast<destination_type>(expression)

    Remember:

      - A conversion creates a new value of the destination type.
      - The original variable does not change type.
      - Some conversions can lose information.
      - Brace initialization helps prevent accidental narrowing.
      - static_cast is useful when a conversion is intentional.
      - static_cast<int>(charValue) prints a char's numeric value.
      - std::int8_t / std::uint8_t often behave like character types.
      - Explicit does not automatically mean safe -- always consider whether the
        destination type can represent the value.
  */

  return 0;
}
