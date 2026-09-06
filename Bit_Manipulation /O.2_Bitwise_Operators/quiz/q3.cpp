/* 
  Question #3

  Extra credit: Redo quiz #2 but don’t use the test and set functions (use bitwise operators).
*/

#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{

  std::bitset<4> lastBit{bits >> 3};
  std::bitset<4> mask{0b0001};

  bits <<= 1; // bits get shifted 1 no matter what 

  /* 
    My hang up here is that I was doing bits << 1 and expecting the shift to change the value of bits permanently. Thats not how it works.
    I did it correctly in the last quiz but for some reason forgot. Make sure you remember this! 
  */
  if (lastBit == 1)
    return (bits |= 0b0001);



  return bits << 1;

  /* 
    SOLUTION 

    return (bits << 1) | (bits >> 3);

    return (0010 | 0001)

      0010
    | 0001
    ----------
      0011

    This is basically what I did but its much more clever
  */
}

int main()
{
	std::bitset<4> bits1{ 0b0001 }; // 0001
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 }; // 1001
	std::cout << rotl(bits2) << '\n';

	return 0;
}
