#include <iostream>
#include <bitset> // std::bitset for outputting binary 
// The print library to print binary (ADVANCED)
#include <print> // C++23 
#include <format> // C++20

/* 

  Octal and hexadecimal literals

  Octal is base 8. Obviosuly that means that there are 8 numbers and they are 0, 1, 2, 3, 4, 5, 6, and 7
  You skip 8 and add do "10" this means 8


  Hexadecimal is base 16. 

  Decimal         0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15
  Binary          0     1    10    11   100   101   110   111  1000  1001  1010  1011  1100  1101  1110  1111
  Octal           0     1     2     3     4     5     6     7    10    11    12    13    14    15    16    17
  Hexadecimal     0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F

*/


/* 
  #include <print> is a modern library and g++ doesnt automatically assume you want to use the latest version so you have to specify

  TO COMPILE THIS PROGRAM WITHOUT A IMPORT ERROR: 

     g++-14 -std=c++23 ./5.3_hexadecimal_octal_binary.cpp -o <output_file>

  This specifically tells GCC to use 14+ with the std library from C++ 23

*/

int main() 
{
  // OCTAL LITERALS
  int x{ 012 }; // 0 before the numbers means octal 
  std::cout << "Octal:" << '\n';
  std::cout << x << '\n'; // outputs: 10


  // HEXADECIMAL LITERALS
  int y{ 0xF }; // 0x before the numbers means this is hexadecimal
  std::cout << "Hex:" << '\n';
  std::cout << y << "\n\n"; // outputs: 15

  // BINARY LITERALS - C++14+
  int bin{}; // assume 16 bit ints
  bin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
  bin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
  bin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
  bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable

  // Can also use hexidecimal units as well
  bin = 0x00FF; // assign binary 0000 0000 1111 1111 to the variable
  bin = 0x00B3; // assign binary 0000 0000 1011 0011 to the variable
  bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable

  // DIGIT SEPERATORS - for readability to break up long literals use " ' " 

  int binx { 0b1011'0010 };
  long value { 2'132'673'462 };

  // can not ocuur before the first digit of value
  // int bin { 0b'1011'0010 } <--- error

  // OUTPUTTING VALUES IN DECIMAL, OCTAL, HEXADECIMAL

  int a { 12 };
  std::cout << "Outputting values in Decimal, Octal, and Hex: " << '\n';
  std::cout << a << '\n'; // decimal (default)
  std::cout << std::hex << a << '\n'; // std::hex basically sets it to output only hex until you change it
  std::cout << a << '\n'; // still hex
  std::cout << std::oct << a << '\n'; // std::octal does the same thing to std::cout as std::hex
  std::cout << a << '\n'; // still octal
  std::cout << std::dec << a << '\n'; // return to decimal (default setting)
  std::cout << a << "\n\n"; // still decimal
  
  
  // OUTPUTTING VALUE IN BINARY
  
  // std::bitset<8> means we want to store 8 bits
  std::bitset<8> bin1 { 0b1100'0101 }; // binary literal for binary 1100 0101
  std::bitset<8> bin2 { 0xC5 }; // using hexadecimal literal for binary 1100 0101

  std::cout << "Outputting values in Binary:" << '\n'; 
  std::cout << bin1 << '\n' << bin2 << '\n'; 
  std::cout << std::bitset<4>{ 0b1010 } << "\n\n"; // create a temporary std::bitset and print it

  // Outputting values in binary using the Format / Print Library (READ TOP COMMENT TO COMPILE)
  std::cout << "Using the modern libraries:" << '\n';
  std::cout << std::format("{:b}\n", 0b1010);   // C++20, {:b} formats the argumnt as binary digits 
  std::cout << std::format("{:#b}\n", 0b1010);  // C++20 {:b#} formats the argument as 0b prefixed binary digits

  std::println("{:b} {:#b}", 0b1010, 0b1010);

  
  return 0;
}