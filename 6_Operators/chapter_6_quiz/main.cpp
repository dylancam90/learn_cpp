#include <iostream>
#include <string>
#include <string_view>

/* 
  Complete the following program 
*/

// Write the function for getQuantityPhrase() here
constexpr std::string_view getQuantityPhrase(const int amount) 
{
  if (amount < 0)
    return "negative";
  else if (amount == 0)
    return "no";
  else if (amount == 1)
    return "a single";
  else if (amount == 2)
    return "a couple of";
  else if (amount == 3)
    return "a few";
  
  return "many";
}

// Wrtie the function for getApplesPluralized here
constexpr std::string_view getApplesPluralized(const int amount)
{
  if (amount == 1)
    return "apple";

  return "apples";
}

int main()
{
  constexpr int maryApples{3};
  std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

  std::cout << "How many apples do you have? ";
  int numApples{};
  std::cin >> numApples;

  std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

  return 0;
}