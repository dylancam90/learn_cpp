#include <bitset>
#include <iostream>

/* 
  Create these constants:

  isHungry   = 0
  isSad      = 1
  isMad      = 2
  isHappy    = 3
  isLaughing = 4
  isAsleep   = 5
  isDead     = 6
  isCrying   = 7

  then create: std::bitset<8> person{};

  Write code so that the person is:
    hungry
    happy
    laughing
    not sad
    not asleep

  Then print:
    Hungry: true
    Sad: false
    Happy: true
    Laughing: true
    Asleep: false
*/

int main()
{
    [[maybe_unused]] constexpr int isHungry{0};
    [[maybe_unused]] constexpr int isSad{1};
    [[maybe_unused]] constexpr int isMad{2};
    [[maybe_unused]] constexpr int isHappy{3};
    [[maybe_unused]] constexpr int isLaughing{4};
    [[maybe_unused]] constexpr int isAsleep{5};
    [[maybe_unused]] constexpr int isDead{6};
    [[maybe_unused]] constexpr int isCrying{7};



    std::bitset<8> person{};

    person.set(isHungry);
    person.set(isHappy);
    person.set(isLaughing);

    // Set output to true or false
    std::cout << std::boolalpha;

    std::cout << "Hungry: " << person.test(isHungry) << '\n'
              << "Sad: " << person.test(isSad) << '\n'
              << "Happy: " << person.test(isHappy) << '\n'
              << "Laughing: " << person.test(isLaughing) << '\n'
              << "Asleep: " << person.test(isAsleep) << '\n';
}