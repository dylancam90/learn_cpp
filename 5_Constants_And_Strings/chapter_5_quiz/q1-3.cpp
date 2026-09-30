#include <cstdint> // for std::uint8_t
#include <iostream>

/* 
  QUESTION 1 
  
  Why are named constants often a better choice than literal constants? 

    Named constants are not magic expressions. Its more readable and more modular just in case you need to change what the literal constant is.
    That way you can change one variable instead of multiple literal constants 

  
  Why are const/constexpr variables usually a better choice than #defined symbolic constants?

    Defined symbolic constants are preprocessor oriented which means they dont make it to the compiller meaning they can be hard to debug and can have naming conflicts. 
    Const/constexpr are handled by the compiler and thus can be evaluated.

  Question #2

  Find 3 issues in the following code:

  Sample desired output:

    How old are you? 
    6
    Allowed to drive a car in Texas: No  

    How old are you?
    19
    Allowed to drive a car in Texas: Yes

  Question 3 - 5 below
  
*/

int main()
{
  std::cout << "How old are you?\n";

  // #1
  // std::uint8_t age{}; // the second issue is this. (see below comment for explanation)
  std::uint16_t age{};
  /* 
    std::uint8_t is treated like a char because of how uint8_t works so its seeing "6" insead of 6 which is 54 in ASCII
    it should be either be std::uint16_t or you can cast it after the input to a uint8_t after it returns from std::cin
  */
  std::cin >> age;   

  std::cout << "Allowed to drive a car in Texas: ";

  // #2 Magic number used as 16, should be a variable
  if (age >= 16)
      std::cout << "Yes";
  else
      std::cout << "No";

  std::cout << '\n'; // #1 first issue here is '.\n' this is a multi char literal and needs a ""

  return 0;
}

/* 
  Question #3

  What are the primary differences between std::string and std::string_view?
    The primary differences are that std::string is an expensive allocation of memory and std::string_view is more of a pointer meaning you dont have to copy 
    it everywhere you use it

  What can go wrong when using a std::string_view?
    If you arent careful you can point std::string_view to a dead string called a "dangling view". It causes UB
*/