#include <iostream>
#include <bitset>

/* 
  Using set(), reset(), and flip()

  Start with: 0000 1111

  Perform these operations in order:

  Turn off bit 0
  Turn on bit 7
  Flip bit 2
  Turn on bit 4
  Turn off bit 1

  What should the final bitset be?
*/

int main()
{
  std::bitset<8> bits{0b0000'1111};

  bits.reset(0);
  bits.set(7);
  bits.flip(2);
  bits.set(4);
  bits.reset(1);

  std::cout << bits << '\n'; // output: 10011000


  return 0;
}