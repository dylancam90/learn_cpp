#include <iostream>
#include <bitset>

/* 
  Write code that prints whether each of these bits is on:

  Bit 0:
  Bit 2:
  Bit 5:
  Bit 7:

  Example:
    Bit 0: 1
    Bit 2: 1
    ...

  Use test().

  Bonus: Turn on std::boolalpha so that it prints true/false instead.
*/

int main()
{
  [[maybe_unused]] constexpr int bit0{0};
  [[maybe_unused]] constexpr int bit2{2};
  [[maybe_unused]] constexpr int bit5{5};
  [[maybe_unused]] constexpr int bit7{7};

  std::bitset<8> bits{0b1010'0101};

  // Print true or false
  std::cout << std::boolalpha;

  std::cout << "Bit 0: " << bits.test(bit0) << '\n'
            << "Bit 2: " << bits.test(bit2) << '\n'
            << "Bit 5: " << bits.test(bit5) << '\n'
            << "Bit 7: " << bits.test(bit7) << '\n';

  return 0;
}