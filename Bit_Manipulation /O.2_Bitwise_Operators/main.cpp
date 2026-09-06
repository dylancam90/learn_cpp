#include <iostream>
#include <bitset>

/* 
  BITWISE OPERATORS

  Operator	    Symbol	  Form	      The operation returns a value where:
  ---------------------------------------------------------------------------------------------------------------------------------------------
  left shift	    <<	    x << n	    the bits from x are shifted left by n positions, new bits are 0.
  right shift	    >>	    x >> n	    the bits from x are shifted right by n positions, new bits are 0.
  bitwise NOT	    ~	      ~x	        each bit from x is flipped.
  bitwise AND	    &	      x & y	      each bit is set when both corresponding bits in x and y are 1.
  bitwise OR	    |	      x | y	      each bit is set when either corresponding bit in x and y is 1.
  bitwise XOR	    ^	      x ^ y	      each bit is set when the corresponding bits in x and y are different.

  BEST PRACTICE 
  ---------------------------------------------------------------------------------------------------------------------------------------------
  To avoid surprises, use the bitwise operators with unsigned integral operands or std::bitset.


  Bitwise left shift << and bitwise right shift >> operators
  ---------------------------------------------------------------------------------------------------------------------------------------------

  The bitwise left shift (<<) operator shifts bits to the left. The left operand is an expression that provides the initial bit sequence, and the right operand is an integer
  number that specifies the number of bit positions to move the bits over by. For example, when you write x << 2, you are saying: 
    
    "produce a value where the bits from x have been moved 2 positions left"

  The left operand is not modified and its new bits shifted in from the right side are 0.

  Here are some examples of left shifting the bit sequence 0011:

  0011 << 1 is 0110
  0011 << 2 is 1100
  0011 << 3 is 1000

  Right shift works the same way just to the opposite side

*/

int main()
{
  std::bitset<4> x{0b1100};

  std::cout << x << '\n'; // This is just printing the bits as they are: 1100

  std::cout << (x >> 1) << '\n';  // Shift right by 1, yielding 0110
  std::cout << (x << 1) << '\n';  // Shift left by 1, yielding 1000

  /* Bit shifting in C++ is endian agnostic. Left shift is always towards the most significant bit, and right shift towards the least significant bit */

  /* 
    Bitwise NOT (~) is conceptually striaghtforward: It simply flips each bit from a 0 to a 1 or vice versa
    ---------------------------------------------------------------------------------------------------------------------------------------------
    ~0011 is 1100
    ~0000 0100 is 1111 1011
  */

  std::bitset<4> y{0b0011}; // 0011
  y = ~y; // flip all bits to 1100
  std::cout << y << '\n';


  /* 
    BITWISE OR (|)
    ---------------------------------------------------------------------------------------------------------------------------------------------

    Bitwise OR (|) works much like its logical OR counterpart. Logical OR evaluates to true (1) if either of the operands are true, otherwise it evaluates to false (0).

    However, whereas logical OR is applied to the entire operand (to produce a single true or false result), bitwise OR is applied to each pair of bits in the operands
    (to produce a single true or false result for each bit)

    Consider the expression 0b0101 | 0b0110

    0101
    0110
    -----
    0111

    You can also do this with more than 2 expressions
  */

  std::bitset<4> or1{0b0101}; // 0101
  std::bitset<4> or2{0b0110};  // 0110

  std::bitset<4> orBoth{or1 | or2};
  std::cout << orBoth << '\n';  // 0111


  /* 
    Bitwise AND (&) 
    ---------------------------------------------------------------------------------------------------------------------------------------------
    Biwise AND (&) works similarly to the above except it uses AND logic instead of or logic. 

    Consider the expression 0b0101 & 0b0110

    0101
    0110
    ----
    0100

    Just like above you can use more than 2 expressions
  */

  std::bitset<4> and1{0b0101}; // 0101
  std::bitset<4> and2{0b0110}; // 0110

  std::bitset<4> andBoth{and1 & and2}; 
  std::cout << andBoth << '\n'; // 0100

  /* 
    Bitwise XOR (^)
    ---------------------------------------------------------------------------------------------------------------------------------------------
    Bitwise XOR (^), also know as exclusive or.

    For each pair of bits in the operands, Bitwise XOR sets the resulting bit to true (1) when exactly one of the paired bits is 1, and false (0) otherwise. 
    Put another way, Bitwise XOR sets the resulting bit to true when the paired bits are different (one is a 0 and the other is a 1)

    Consider the expression 0b0110 ^ 0b0011

    0110
    0011
    -----
    0101
  */

  std::bitset<4> xor1{0b0110};  // 0110
  std::bitset<4> xor2{0b0011};  // 0011

  std::bitset<4> xorBoth{xor1 ^ xor2};  
  std::cout << xorBoth << '\n'; // 0101


  /* 
    Bitwise assignment operators
    ---------------------------------------------------------------------------------------------------------------------------------------------

    Similar to the arithmetic assignment operators, C++ provides bitwise assignment operators. These do modify the left operand.


    Operator	      Symbol	    Form	          The operation modifies the left operand where:
    ---------------------------------------------------------------------------------------------------------------------------------------------
    left shift	      <<	      x <<= n	        the bits in x are shifted left by n positions, new bits are 0.
    right shift	      >>	      x >>= n	        the bits in x are shifted right by n positions, new bits are 0.
    bitwise AND	      &     	  x &= y	        each bit is set when both corresponding bits in x and y are 1.
    bitwise OR	      |	        x |= y	        each bit is set when either corresponding bit in x and y is 1.
    bitwise XOR	      ^	        x ^= y	        each bit is set when the corresponding bits in x and y are different.


    For example, instead of writing x = x >> 1, yuo can write x >>= 1

    There is no NOT (~=) operator because you can just do x = ~x
  */

  std::bitset<4> bits {0b0100}; // 0100
  bits >>= 1;   // shifts 1 bit to the right and saves the result to bits
  std::cout << bits << '\n';


  /* 
    WARNING
    ---------------------------------------------------------------------------------------------------------------------------------------------

    Bitwise operators dont operate on uint8_t, char, unsigned short directly. They first convert them to a wider/bigger int or sometimes a unsigned int.

    See below:
  */

  std::uint8_t c {0b00001111}; // c is 0000 1111 (its 8 bits because uint8_t is 1 byte)
  c = ~c; 
  /* 
    You might expect this to become 1111 0000 but what happens is the uint8_t turns into a 32 bit int which becomes:

    00000000 00000000 00000000 00001111

    Now flip all 32 bits

    11111111 11111111 11111111 11110000

    Which is not whats intended. Here is a larger example in code
  */

  std::uint8_t c2 {0b00001111};                 // 0000 1111
  std::cout << std::bitset<32>(~c) << '\n';     // incorrect: prints 11111111111111111111111111110000 because it was expanded to a larger size
  std::cout << std::bitset<32>(c << 6) << '\n'; // incorrect: prints 0000000000000000001111000000 (same thing)
  // std::uint8_t cneg {~c};                    // error: narrowing conversion from unsigned int to std::uint8_t
  // c2 = ~c;                                   // possible warning: narrowing conversion from unsigned int to std::uint8_t
  
  
  /* 
    These issues can be addressed by using static_cast to convert the result of your bitwise operation back the the narrower intergral type. The following program
    produces the correct results:
  */

  std::uint8_t c3 {0b00001111}; // 0000 1111

  std::cout << std::bitset<32>( static_cast<std::uint8_t>(~c) ) << '\n';        // correct: prints 00000000000000000000000011110000
  std::cout << std::bitset<32>( static_cast<std::uint8_t>(c << 6) ) << '\n';    // correct: prints 0000000000000000000011000000
  std::uint8_t cneg { static_cast<std::uint8_t>(~c) };                          // compiles
  c3 = static_cast<std::uint8_t>(~c);                                           // no warning

  return 0;
}