#include <cstdint>
#include <iostream>

/* 
  This program is supposed to ask for a RGBA pixel as input

  8 bits for the red channel
  8 bits for the green channel
  8 bits for the blue channel
  8 bits for the alpha channel

  Then extracts the different values from the input
*/

int main()
{
  constexpr std::uint32_t redBits     { 0xFF000000 };
  constexpr std::uint32_t greenBits   { 0x00FF0000 };
  constexpr std::uint32_t blueBits    { 0x0000FF00 };
  constexpr std::uint32_t alphaBits   { 0x000000FF };

  // FF7F3300
	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
	std::uint32_t pixel{};
	std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value


  // 0000 0000
  const std::uint8_t red    {static_cast<std::uint8_t>((pixel & redBits) >> 24)};
  const std::uint8_t green  {static_cast<std::uint8_t>((pixel & greenBits) >> 16)};
  const std::uint8_t blue   {static_cast<std::uint8_t>((pixel & blueBits)  >> 8)};
  const std::uint8_t alpha  {static_cast<std::uint8_t>((pixel & alphaBits))};

  std::cout << "Your color contains:\n";
  std::cout << std::hex;  // print the following values in hex

  // reminder that std::uint8_t will likely print as a char
  // we use static_cast to int to ensure it prints as a int
  std::cout << static_cast<int>(red)    << " red\n";
  std::cout << static_cast<int>(green)  << " green\n";
  std::cout << static_cast<int>(blue)   << " blue\n";
  std::cout << static_cast<int>(alpha)  << " alpha\n";
  
  return 0;
}