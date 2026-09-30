/* 
  https://www.learncpp.com/cpp-tutorial/converting-integers-between-binary-and-decimal-representation/

  I didnt want to write all of this down, its easier to go read it to refresh. Some of it will be written down here

  It goes over tricks to converting decimal to binary and vice versa with some clever tricks. It also goes over binary addition as well as 
  Twos Compliment


  Converting decimal to binary ----------------------------------------------------------------------------------------------------

  How do you represent -5 in binary 2's compliment?

  Lets say we have the number -5
  First find out the binary representation of its positive form: 0000 0101
  Then invert all the bits (~): 1111 1010
  Then you add 1:   1111 1011 ( < added a single 1 to the end)
  Now its a 2's compliment -5

  Now lets do it for -76
  Get -76 positive representaion in binary:  0100 1100
  Inverse all the bits (~):   1011 0011
  Add 1:  1011 0100

  Ones compliment is just inversing the positive representation in binary


  Converting binary (two's compliment) to decimal ----------------------------------------------------------------------------------------------------

  If the sign is 0 just do a normal conversion since its unsigned 
  If the sign is 1:
    1. invert the bits
    2. add 1
    3. convert to decimal
    4. make the decimal negative

  For example, to convert 1001 1110 from two's compliment to decimal

  Given 1001 1110
  Invert the bits (~): 0110 0001
  Add 1: 0110 0010
  Convert to decimal: (0 * 128) + (1 * 64) + (1 * 32) + (0 * 16) + (0 * 8) + (0 * 4) + (1 * 2) + (0 * 1) = (64 + 32 + 2) = 98
  Its an unsigned number so the final value is -98

  An even easier method is to do it this way, subtract the first bit by its place:

  Given 1001 1110
  (1 * -128) + (0 * 64) + (0 * 32) + (1 * 16) + (1 * 8) + (1 * 4) + (1 * 2) + (0 * 1) = (-128 + 16 + 8 + 4 + 2) = -98








*/


