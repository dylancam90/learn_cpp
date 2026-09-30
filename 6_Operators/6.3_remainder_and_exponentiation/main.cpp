#include <iostream>

constexpr bool isEven(const int num)
{
  return (num % 2) == 0;
}

void printOutput(const int num, const bool isEven) 
{
  if (isEven)
    std::cout << num << " is even" << '\n';
  else 
    std::cout << num << " is odd" << '\n';
}

const int getInput() 
{
  std::cout << "Enter an integer: ";

  int i{};
  std::cin >> i;

  return i;
}

int main()
{
  const int num{getInput()};
  const bool evenOdd{isEven(num)};
  printOutput(num, evenOdd);

  return 0;
}