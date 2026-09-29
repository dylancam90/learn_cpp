#include <iostream>
#include <bitset>
#include <cstdint>

/* 
  A bit mask is a predefined set of bits that is used to select which specific bits will be modified by subsequent operations.

  Because C++14 supports binary literals, defining these bit masks is easy:
*/

int main()
{

  constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
  constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
  constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
  constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
  constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
  constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
  constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
  constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7
  /* 
    Now we have a set of symbolic constants that represents each bit position. We can use these to manipulate the bits 

    Because C++11 doesnt support binary literals we have to use other methods to set the symbolic constants. There are two good methods of doing this.

    The first is to use hex literals:
  */

  constexpr std::uint8_t hmask0{ 0x01 }; // hex for 0000 0001
  constexpr std::uint8_t hmask1{ 0x02 }; // hex for 0000 0010
  constexpr std::uint8_t hmask2{ 0x04 }; // hex for 0000 0100
  constexpr std::uint8_t hmask3{ 0x08 }; // hex for 0000 1000
  constexpr std::uint8_t hmask4{ 0x10 }; // hex for 0001 0000
  constexpr std::uint8_t hmask5{ 0x20 }; // hex for 0010 0000
  constexpr std::uint8_t hmask6{ 0x40 }; // hex for 0100 0000
  constexpr std::uint8_t hmask7{ 0x80 }; // hex for 1000 0000

  /* 
    Sometimes leading hex 0s will be omitted (e.g. instead of 0x01 youll just see 0x1).

    An easier method is to use the left shift operator to shift a single bit into the proper location:
  */

  constexpr std::uint8_t omask0 { 1 << 0 }; // 0000 0001
  constexpr std::uint8_t omask1{ 1 << 1 }; // 0000 0010
  constexpr std::uint8_t omask2{ 1 << 2 }; // 0000 0100
  constexpr std::uint8_t omask3{ 1 << 3 }; // 0000 1000
  constexpr std::uint8_t omask4{ 1 << 4 }; // 0001 0000
  constexpr std::uint8_t omask5{ 1 << 5 }; // 0010 0000
  constexpr std::uint8_t omask6{ 1 << 6 }; // 0100 0000
  constexpr std::uint8_t omask7{ 1 << 7 }; // 1000 0000

  /* 
    Testing a bit to see if its on or off --------------------------------------------------------------------------------------------------------

    Now that we have a set of bit masks, we can use these in conjunction with a bit flag variable to manipulate out bit flags. 
    To determine if a bit is on or off, we use bitwise AND in conjunction with the bit mask for the appropriate bit:
    
  */

  [[maybe_unused]] constexpr std::uint8_t emask0{ 0b0000'0001 }; // represents bit 0
  [[maybe_unused]] constexpr std::uint8_t emask1{ 0b0000'0010 }; // represents bit 1
	[[maybe_unused]] constexpr std::uint8_t emask2{ 0b0000'0100 }; // represents bit 2
	[[maybe_unused]] constexpr std::uint8_t emask3{ 0b0000'1000 }; // represents bit 3
	[[maybe_unused]] constexpr std::uint8_t emask4{ 0b0001'0000 }; // represents bit 4
	[[maybe_unused]] constexpr std::uint8_t emask5{ 0b0010'0000 }; // represents bit 5
	[[maybe_unused]] constexpr std::uint8_t emask6{ 0b0100'0000 }; // represents bit 6
	[[maybe_unused]] constexpr std::uint8_t emask7{ 0b1000'0000 }; // represents bit 7


  std::uint8_t flags { 0b0000'0101 }; // 8 bits in size means room for 8 flags

  std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
  std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

  /* 
    How this works 

    In the case of flags & mask0, we have 0000'0101 & 0000'0001. Let's line these up:

    0000'0101 &
    0000'0001
    ------------
    0000'0001

    You are then casting 0000'0001 to a bool. Since any non-zero number converts to true and this vaue has a non zero digit it evaluated to true.
    In the case of flags & mask1m we have 0000'0101 & 0000'0010. Lets line these up:

    0000'0101 &
    0000'0010
    --------------
    0000'0000

    Since a zero value converts to false and this value has only zero digits, this evaluates to false
   */

   /* 
    Setting a bit ------------------------------------------------------------------------------------------------------------------------------------------------------
    To set (turn on) a bit (to value 1) we use bitwise OR (|=) in conjunction with a bitmask for the specific bit:
   */

  std::cout << "bit 1 is " << (static_cast<bool>(flags & emask1) ? "on\n" : "off\n");

  flags |= mask1; // turn on bit 1

  std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

  /* 
    Output:

    bit 1 is off
    bit 1 is on

  */

  flags |= (emask4 | emask5); // You can also turn on multiple bits at the same time

  /* 
    Resetting a bit --------------------------------------------------------------------------------------------------------------------------------------------

    To reset a bit to 0 use AND and NOT together
  */

  flags &= ~emask2; // turn off bit 2
  flags &= ~(emask4 | emask5); // turn off multiple bits at the same time

  /* 
    Flipping a bit from 1 to 0 or 0 to 1 use XOR
  */

  flags ^= emask2; // flip bit 2
  flags ^= emask4; // flip bit 4

  /* 
    The reason to do this over using bitset functions is because bitset functions can only operate on 1 bit at a time while this can do multiple
    
    
    Making it meaningfull -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  */

  [[maybe_unused]] constexpr std::uint8_t isHungry      { 1 << 0 }; // 0000 0001
  [[maybe_unused]] constexpr std::uint8_t isSad         { 1 << 1 }; // 0000 0010
  [[maybe_unused]] constexpr std::uint8_t isMad         { 1 << 2 }; // 0000 0100
  [[maybe_unused]] constexpr std::uint8_t isHappy       { 1 << 3 }; // 0001 0000
  [[maybe_unused]] constexpr std::uint8_t isLaughing    { 1 << 4 }; // 0010 0000
  [[maybe_unused]] constexpr std::uint8_t isAsleep      { 1 << 5 }; // 0100 0000
  [[maybe_unused]] constexpr std::uint8_t isCrying      { 1 << 6 }; // 1000 0000

  std::uint8_t me{};                // all flags turned off to start
  me |= (isHappy | isLaughing);     // set flags for laughing and happy
  me &= ~isLaughing;                // flip the laughing bit (to off)

  // Query a few states
  // use static_cast<bool> to interperet the results as a boolean value
  std::cout << std::boolalpha;      // print values as bools
  std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
  std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';

  /* Adding some std::bitset in addition */

  [[maybe_unused]] constexpr std::bitset<8> bisHungry   { 0b0000'0001 };
	[[maybe_unused]] constexpr std::bitset<8> bisSad      { 0b0000'0010 };
	[[maybe_unused]] constexpr std::bitset<8> bisMad      { 0b0000'0100 };
	[[maybe_unused]] constexpr std::bitset<8> bisHappy    { 0b0000'1000 };
	[[maybe_unused]] constexpr std::bitset<8> bisLaughing { 0b0001'0000 };
	[[maybe_unused]] constexpr std::bitset<8> bisAsleep   { 0b0010'0000 };
	[[maybe_unused]] constexpr std::bitset<8> bisDead     { 0b0100'0000 };
	[[maybe_unused]] constexpr std::bitset<8> bisCrying   { 0b1000'0000 };

  std::bitset<8> meBit{}; // all flags zero'd
  meBit |= (isHappy | isLaughing);
  me &= ~isLaughing;

  // set std::boolalpha earlier
  std::cout << "I am happy? " << (meBit & bisHappy).any() << '\n';
  std::cout << "I am laughing? " << (meBit & bisLaughing).any() << '\n';
  
  /* 
    Two notes here: First, std::bitset doesn’t have a nice function that allows you to query bits using a bit mask. \
    So if you want to use bit masks rather than positional indexes, you’ll have to use Bitwise AND to query bits. 
    Second, we make use of the any() function, which returns true if any bits are set, and false otherwise to see if the bit we queried remains on or off.
  */

  /* 
    SUMMARY ================================================================================================================================ 

    Summarizing how to set, clear, toggle, and query bit flags:

    To query bit states, we use bitwise AND:

    if (flags & option4) ... // if option4 is set, do something

    To set bits (turn on), we use bitwise OR:

    flags |= option4; // turn option 4 on.
    flags |= (option4 | option5); // turn options 4 and 5 on.

    To clear bits (turn off), we use bitwise AND with bitwise NOT:

    flags &= ~option4; // turn option 4 off
    flags &= ~(option4 | option5); // turn options 4 and 5 off

    To flip bit states, we use bitwise XOR:

    flags ^= option4; // flip option4 from on to off, or vice versa
    flags ^= (option4 | option5); // flip options 4 and 5
  */

  return 0;
}