#include <iostream>
#include <bitset> // for std::bitset

int main()
{
  /* Bit Flags */
  int foo{5};       // assign foo the value 5 (probably uses 32 bits of storage)
  std::cout << foo; // print the value of 5
  /* 
    Instead of viewing objects as holding a single value we can instead treat each bit in the object as an independent Boolean value. When individual bits
    of an object as used as boolean values the bits are called BIT FLAGS

    To define a set of bit flags we will tyically use an unsigned integer of the appropiate size (8 bits, 16 bits, 32 bits, etc... depending on how many flags you want),
    or have std::bitset
  */

  std::bitset<8> mybitset{}; // 8 bits in size means room for 8 flags

  /* 
    Given a sequence of bits, we typically number the bits from right to left starting with 0 (not 1). Each number is a bit position 

    7 6 5 4 9 2 1 0       Bit position
    0 0 0 0 0 1 0 1       Bit sequence

    Given the bit sequence 0000 0101, the bits that are in position 0 and 2 have value 1, and the other bits have value 0
  */

  /* 
    Manipulating bits via std::bitset

    std::bitset includes 4 key member functions:

    test()  allows you to query whether a bit is a 1 or 0.
    set()   allows you to turn a bit on (will do nothing if the bit is already on)
    reset() allows you to run a bit off (will do nothing if the bit is already off)
    flip()  allows you to flip a bit from 0 to 1 or vice versa

    Each of these functions takes the postiion of the bit you want to operate on as their only argument
  */

  std::bitset<8> bits{0b0000'0101}; // you need 8 bits, start with bit pattern 0000 0101
  bits.set(3);    // set bit position 3 to 1 (now its 0000 1101)
  bits.flip(4);   // flip bit 4 (now you have 0001 1101)
  bits.reset(4);  // set bit 4 back to 0 (now you have 0000 1101)

  std::cout << "All the bits: " << bits << '\n';
  std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
  std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

  /* 
    OUTPUT:

      All the bits: 00001101
      Bit 3 has value: 1
      Bit 4 has value: 0
  */

  /* Giving the bits names can help make the code more readable */
  [[maybe_unused]] constexpr int isHungry   {0};
  [[maybe_unused]] constexpr int isSad      {1};
  [[maybe_unused]] constexpr int isMad      {2};
  [[maybe_unused]] constexpr int isHappy    {3};
  [[maybe_unused]] constexpr int isLaughing {4};
  [[maybe_unused]] constexpr int isAsleep   {5};
  [[maybe_unused]] constexpr int isDead     {6};
  [[maybe_unused]] constexpr int isCrying   {7};

  std::bitset<8> me{ 0b0000'0101 }; // you need 8 bits, start with pattern 0000 0101
  me.set(isHappy);      // set bit postion 3 to 1 (now you have 0000 1101)
  me.flip(isLaughing);  // flip bit 4 (now you have 0001 1101)
  me.reset(isLaughing); // set bit 4 back to 0 (now you have 0000 1101)

  std::cout << "All the bits: " << me << '\n';
  std::cout << "I am happy: " << me.test(isHappy) << '\n';
  std::cout << "I am laughing: " << me.test(isLaughing) << '\n';


  /* 
    Size of std::bitset 
    
    Its optimized for speed not memory savings. The size of std::bitset is typically the number of bytes needed to hold the bits, rounded up to the nearest sizeof(size_t)
    which is 4 bytes on 32 bit machines and 8 bytes on 64 bit machines. Thus a std::bitset will typically use either 4 or 8 bytes even though technically it only needs 1 byte
    or 8 bits. 
  */

  /*
    Querying std::bitset
    
    There are a few other memeber functions that are often useful:

    size()  - returns the number of bits in the bitset
    count() - returns the number of bits in the bitset that are set to true
    all()   - returns a boolean indicating whether all bits are set to true
    any()   - returns a boolean indicating whether any bits are set to true
    none()  - returns a boolean indicating whether no bits are set to true 
   */

   std::bitset<8> bits{ 0b0000'1101 };
   std::cout << bits.size() << " bits are in the bitset\n";
   std::cout << bits.count() << " bits are set to true\n";

   std::cout << std::boolalpha;
   std::cout << "All bits are true: " << bits.all() << '\n';
   std::cout << "Some bits are true: " << bits.any() << '\n';
   std::cout << "No bits are true: " << bits.none() << '\n';

   /* 
    OUTPUT:
      8 bits are in the bitset
      3 bits are set to true
      All bits are true: false
      Some bits are true: true
      No bits are true: false
   */

  return 0;
}