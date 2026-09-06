#include <bitset>
#include <iostream>

/* 
  Make the final bitset: 0001 0110

  Use set()
  Don't directly assign another bitset
  Think carefully about bit positions.
*/

int main()
{
    std::bitset<8> bits{ 0b0000'0000 };

    // Your code here
    bits.set(1);
    bits.set(2);
    bits.set(4);

    std::cout << bits << '\n';
}