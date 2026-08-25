#include <iostream>
#include <string>
#include <string_view>


/* 
  QUESTION 4

  Write a program that asks for the name and age of two people, then prints which person is older.

  Here is the sample output from one run of the program:

    Enter the name of person #1: John Bacon
    Enter the age of John Bacon: 37
    Enter the name of person #2: David Jenkins
    Enter the age of David Jenkins: 44
    David Jenkins (age 44) is older than John Bacon (age 37).

*/
int getAge(std::string_view name) // using std::string_view here because its not modifying anything, its read only
{
  std::cout << "Enter the age of " << name << ": ";

  int age{};  
  std::cin >> age;

  return age;
}

std::string getName()
{
  static int num{1};

  std::cout << "Enter the name of the #" << num << ": "; 
  std::string name{};
  std::getline(std::cin >> std::ws, name);

  ++num;

  return name;
}

/* My solution is actually very close to the solution although I didnt put the if condition logic in its own function (no need) */

int main()
{
  const std::string person1{getName()};
  const int age1{getAge(person1)};

  const std::string person2{getName()};
  const int age2{getAge(person2)};

  if (age1 > age2) 
  {
    std::cout << person1 << " (age " << age1 << ')' 
              << " is older than " << person2 
              << "(age " << age2 << ").\n";
  } 
  else 
  {
    std::cout << person2 << " (age " << age2 << ')' 
              << " is older than " << person1 
              << "(age " << age1 << ").\n";
  }

  return 0;
}

/* 
  Question #5

  In the solution to the above quiz, why can’t variable age1 in main be constexpr?

    It cant be consexpr because it relies on user input that isnt known at runtime (its not a constant expression intitializer)
*/