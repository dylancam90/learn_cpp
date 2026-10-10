#include <iostream>
#include <cstdint>
#include <bitset>

int main()
{
  // 1. Create masks using shifts. Fill in the missing masks. Don't write binary literals directly; use 1 << n.
  constexpr std::uint8_t bit0 { 1 << 0 };
  constexpr std::uint8_t bit2 { 1 << 2 };
  constexpr std::uint8_t bit5 { 1 << 5 };
  constexpr std::uint8_t bit7 { 1 << 7 };

  // 2. Query individual bits. Given:
  constexpr std::uint8_t bit1 { 1 << 1 };
  constexpr std::uint8_t bit3 { 1 << 3 };   // added for #5
  constexpr std::uint8_t bit4 { 1 << 4 };
  constexpr std::uint8_t bit6 { 1 << 6 };

  std::uint8_t flags2{ 0b0101'0010 };

  std::cout << std::boolalpha;  // Set std::cout to print true + false 
  std::cout << "2: \n";
  std::cout << static_cast<bool>(flags2 & bit1) << '\n';
  std::cout << static_cast<bool>(flags2 & bit4) << '\n';
  std::cout << static_cast<bool>(flags2 & bit6) << '\n';


  // 3. Set bits. Start with 0010 0001 and turn on only bit 2 and 4, do it with 1 statement and predict the final bit pattern before printing it
  std::uint8_t flags3{ 0b0010'0001 };
  // prediction: 0011 0101
  flags3 |= (bit2 | bit4);
  std::cout << "3: " << std::bitset<8>(flags3) << '\n';

  /* 
    4. Clear bits. Clear bits 2 and 5 simultaneously. Do not change any other bits. Then explain why this works: 
      
      flags &= ~(bit2 | bit5);
  */

  std::uint8_t flags4{ 0b1110'1101 };
  flags4 &= ~(bit2 | bit5);

  /*
    why this works:

    Given these bits:
    1110 1101

    Combine both masks into 1 mask using OR

    0000 0100
    0001 0000   OR
    -----------
    0001 0100

    Now you have: 0001 0100

    Now do NOR ^

    1110 1101
    0001 0100     NOR
    --------------
    1111 1001


    why this works: flags &= ~(bit2 | bit5)

    start off with: 1110 1101

    combine bit masks:          0001 0100
    inverse bit masks product:  1110 1011
    AND with original:

      1110 1101
      1110 1011   AND
      -----------
      1110 1001

    Result: 1110 1001
  */

  // 5. Toggle multiple bits. Toggle bits 0, 3, and 7 in one statement. Before compiling, calculate the resulting byte by hand.
  std::uint8_t flags5{ 0b1010'1001 };

  flags5 ^= ( bit0 | bit3 | bit7 );
  /* 
    Before compiling given bits 1010 1001

    0000 0001
    0000 1000     OR
    1000 0000
    ------------
    1000 1001

    NOT: 0111 0110

    0111 0110
    1010 1001   AND
    ------------
    0010 0000

    Final: 0010 0000
  */

  std::cout << "5: " << std::bitset<8>(flags5) << '\n';

  /* 
    Im skipping to 8 to avoid being repetitive 

    8. Spot the bug. Someone wants to turn off isRunning:

    In this one & will keep the bit set. They can use use state &= ~isRunning to turn it off
    
    9. OR is wrong because the condition would still return true if the bit was off or on

    10. Require multiple flags at once. Given:
  */
  // Write an if condition that is true only if both hasKey and hasMap are set.
  [[maybe_unused]] constexpr std::uint8_t hasKey      { 1 << 0 };
  [[maybe_unused]] constexpr std::uint8_t hasMap      { 1 << 1 };
  [[maybe_unused]] constexpr std::uint8_t hasCompass  { 1 << 2 };
  std::uint8_t inventory{ 0b1010'0011 }; // This is supposed to be unknown, if you change the last 2 bits to not match the condition will fail
  
  /* 
    I'm an idiot, all this practice with bit manipulation made me forget that '&' is a bit operator and you need a "&&" for and in the condition. This
    took me way longer than it should have 

    The reason if (inventory & (hasKey | hasMap)) doesnt work is because one or the other could be set meaning it will always evaluate to > 0 and return true
  */

  if ((inventory & hasKey) && (inventory & hasMap)) 
  {
    std::cout << "10: Both flags are set!\n";
  }

  /* 
    11. Extract a group of bits. Here's a 16-bit value:

      std::uint16_t data{ 0b1011'0110'1101'0011 };

    You only care about bits 4–7:

      1011 0110 1101 0011
            ^^^^
            bits 4-7

    Create a mask for those four bits, use & to isolate them, then shift them down so the result occupies bits 0–3.
      0000 0000 0000 ????

    Don't convert it to decimal until you've figured out the bit operations.

    This is the same basic technique the LearnCpp lesson uses to extract the individual R, G, B, and A fields from a packed 32-bit color value.
  */
  constexpr uint16_t mask { 0b0000'0000'1111'0000 };

  std::uint16_t data{ 0b1011'0110'1101'0011 };
  data &= mask;
  std::uint8_t result{ static_cast<uint8_t>(data >> 4) };
  std::bitset<8> toBinary = std::bitset<8>(result);
  
  std::cout << "11: " << toBinary << '\n';
  std::cout << "To binary: " << toBinary.to_ulong() << '\n';

  /* 
    12.  Mini-project: packed game status. Store all of these in one std::uint8_t: 

      bit 0 = engine on
      bit 1 = landing gear down
      bit 2 = master arm on
      bit 3 = autopilot on
      bit 4 = radar on
      bit 5 = jammer on
      bit 6 = warning light
      bit 7 = damaged

    Starting with everything off, perform this sequence:

      Turn the engine on.
      Turn the radar on.
      Lower the landing gear.
      Turn master arm on.
      Toggle the radar.
      Turn the jammer and autopilot on simultaneously.
      Raise the landing gear.
      Set the damaged and warning-light flags simultaneously.
      Check whether master arm is currently on.

    At the end, print the byte with:

      std::cout << std::bitset<8>{ status } << '\n';


  */

  [[maybe_unused]] constexpr uint8_t engine         { 0x01 };   // 1
  [[maybe_unused]] constexpr uint8_t landingGear    { 0x02 };   // 2
  [[maybe_unused]] constexpr uint8_t masterArm      { 0x04 };   // 3
  [[maybe_unused]] constexpr uint8_t autoPilot      { 0x08 };   // 4
  [[maybe_unused]] constexpr uint8_t radar          { 0x10 };   // 5
  [[maybe_unused]] constexpr uint8_t jammer         { 0x20 };   // 6
  [[maybe_unused]] constexpr uint8_t warningLight   { 0x40 };   // 7
  [[maybe_unused]] constexpr uint8_t damaged        { 0x80 };   // 8

  uint8_t aircraft{};

  std::cout << "\n12: \n"; 

  // Turn all these on
  aircraft |= (engine | radar | landingGear | masterArm);
  std::cout << std::bitset<8>{ aircraft } << '\n';

  aircraft ^= radar;
  std::cout << std::bitset<8>{ aircraft } << '\n';

  aircraft |= (jammer | autoPilot);
  std::cout << std::bitset<8>{ aircraft } << '\n';

  aircraft &= ~landingGear;
  std::cout << std::bitset<8>{ aircraft } << '\n';

  aircraft |= (damaged | warningLight); // I did this because I wasn't sure if they were already on or not
  std::cout << std::bitset<8>{ aircraft } << '\n';

  if ((aircraft & masterArm)) {
    std::cout << "Master arm is on\n";
  }


  return 0;
}