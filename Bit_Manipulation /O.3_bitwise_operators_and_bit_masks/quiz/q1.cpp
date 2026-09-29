#include <bitset>
#include <cstdint>
#include <iostream>

/* 
  Do not use std::bitset in this quiz. We’re only using std::bitset for printing.

  Given the following program: 

  a) Add a line of code to set the article as viewed.
    Expected output:
      00000101

  b) Add a line of code to check if the article was deleted.

  c) Add a line of code to clear the article as a favorite.
    Expected output (Assuming you did quiz (a)):
      00000001
*/

int main() 
{
  [[maybe_unused]] constexpr std::uint8_t option_viewed     { 0x01 };
  [[maybe_unused]] constexpr std::uint8_t option_edited     { 0x02 };
  [[maybe_unused]] constexpr std::uint8_t option_favorited  { 0x04 };
  [[maybe_unused]] constexpr std::uint8_t option_shared     { 0x08 };
  [[maybe_unused]] constexpr std::uint8_t option_deleted    { 0x10 };

  std::uint8_t myArticleFlags { option_favorited };

  // Place all line of code for the following quiz here


  myArticleFlags |= option_viewed; // a
  std::cout << "Deleted article bit is " << (static_cast<bool>(myArticleFlags & option_deleted) ? "on\n" : "off\n"); // b
  // You do this becuase it works if you dont know if the bit is on or not
  // Also static_cast is used because the inverse ~ causes integral promotion
  myArticleFlags &= static_cast<std::uint8_t>(~option_favorited); // c

  std::cout << std::bitset<8>{ myArticleFlags } << '\n';

  return 0;
}