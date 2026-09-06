#include <iostream>
#include <bitset>

/* 
  Problem 5 — Counting flags

  Given:

  std::bitset<8> flags{ 0b1011'0110 };

  Print:

  Number of flags: 8
  Flags enabled: ?
  Any flags enabled: ?
  All flags enabled: ?
  No flags enabled: ?

  Use:

  size()
  count()
  any()
  all()
  none()

  Don't manually count the bits.

*/

int main()
{

  std::bitset<8> flags{ 0b1011'0110 };

  std::cout << std::boolalpha;

  std::cout << "Number of flags: " << flags.size() << '\n'
            << "Flags enabled: " << flags.count() << '\n'
            << "Any flags enabled: " << flags.any() << '\n'
            << "All flags enabled: " << flags.all() << '\n'
            << "No flags enabled: " << flags.none() << '\n';


  return 0;
}