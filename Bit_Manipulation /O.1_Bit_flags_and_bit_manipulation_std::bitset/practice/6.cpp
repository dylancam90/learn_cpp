#include <bitset>
#include <iostream>

/* 
  Whats wrong with this code?

  The program prints:

    The person is dead!

  even though we never set isDead.

  Fix the program.
*/

int main()
{
    constexpr int isHungry{0};
    constexpr int isHappy{1};
    constexpr int isDead{2};

    std::bitset<8> person{};

    person.set(isHungry);
    person.set(isHappy);
    
    std::cout << person << '\n';

    if (person.test(isDead))
      std::cout << "The person is dead!\n";
    else
      std::cout << "The person is alive!\n";
}