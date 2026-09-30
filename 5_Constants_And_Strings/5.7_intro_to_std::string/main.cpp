#include <iostream>
#include <string> // to use std::string and std::getline

/* 
  C-Style string lliterals are fine to use but behave oddly, can result in undefined behavior, are hard to work with, and can be dangerous
  e.g. If you copy a larger C style string into the space allocated for a shorter C stle string will cause undefined behavior.

  In C++ there are two additional string types that are much easier and safer to work with: 
    std::string 
    std::string_view (C++17)

  These arent fundamental types, theyre class types (something to keep in mind)
*/

int main()
{
  std::cout << "Hello, world!" << '\n'; // C-style string literal (best avoided in C++)

  /* 
    The easiest way to work with strings and string objects in C++ is via the std::string type, which lives in the <string> header.
  */
  std::string name{};           // empty string
  std::string name2{"Alex"};    // initialize name with string literal "Alex"
  name2 = "John";               // change name to John

  std::string myID{"45"};        // A number as a string

  /* String output with std::cout */
  std::string name3{"Alex"};
  std::cout << "My name is: " << name3 << '\n';

  std::string empty{};
  std::cout << '[' << empty << ']' << '\n'; // an empty string prints nothing. output: "[]"

  /* std::string can handle strings of different length */
  std::string name4{"Alex"};      // initialize name with string literal "Alex"
  std::cout << name4 << '\n';     // "Alex"

  name4 = "Jason";                // 1 more character longer than Alex
  std::cout << name4 << '\n';     // prints "Jason" with no problem

  name4 = "Jay";                  // Shorter than Jason  
  std::cout << name4 << '\n';     // prints "Jay"

  /* 
    NOTE - If string doesnt have enough memory for a string it will request the memory at runtime, this is called dynamic memory allocation

    String input with std::cin ----------------------------------------------------------------
  */
  
  std::cout << "Enter your name: ";
  std::string urName{};
  std::cin >> urName;

  std::cout << "Enter your favorite color: ";
  std::string color{};
  std::cin >> color;

  std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

  /* 

  NOTE - When entering "John Doe" as an input std::cin will extract "John" and leave " Doe", std::cin will only collect chars up to the whitespace and leave the rest buffered

  Use std::getline() to input text ----------------------------------------------------------------

  To read a full line of input into a string, you're better off using the std::getline() function instead of std::cin.

  std::getline() requires 2 arguments: 
    the first is std::cin 
    the second is the string variable

  std::getline() reads until it hits a newline character

  */

  std::cout << "Enter full name: ";
  std::string fullName{};
  std::getline(std::cin >> std::ws, name); // pay attention to the std::ws

  std::cout << "Your name is: " << '\n';

  /* 
    What is std::ws ? ---------------------------------------------------------

    Its called a input manipulator the same way std::setprecission() is a output manipulator for floats. 
    The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction.
    NOTE: it needs to be included in every call 
    
    Here is an example:
  */  
  
  std::cout << "Enter 1 or 2: ";
  int choice{};
  std::cin >> choice;

  std::cout << "Now enter your name: ";
  std::string name5{};
  std::getline(std::cin, name); // notice no std::ws here

  std::cout << "Hello, " << name << ", you picked " << choice << '\n';

  /* 
    output:

    Pick 1 or 2: 2
    Now enter your name: Hello, , you picked 2

    When you enter the 2 and hit enter it will not wait to get your name, this is because the first std::cin call grabbed the "2" and left the '\n' char in the buffer.
    When the std::getline(std::cin, name) gets called it sees the '\n' in the buffer and uses that to store in name5. 

    Remember to use std::cin >> std::ws when calling std::getline() if you want to ignore leading whitespace
  */

  /* Getting the length of a std::string */
  std::string name6{"Alex"};
  std::cout << name << " has " << name.length() << " characters\n"; // output: "Alex has 4 characters" 

  /* 
    name.length() does not include the null terminator 

    the full path is std::string::length()

    NOTE: std::string::length() returns an unsigned integral value (most likely of type size_t). If you want to assign the length to an int use static_cast
  */

  int length {static_cast<int>(name.length())}; // static cast from size_t (likely) to int

  /* 
    WARNINGS:

    Initializing a std::string is expensive: Whenever a std::string is initialized a copy of the string is made. Making copies of string is expensive so try to be careful  
    
    Do not pass std::string by value: This also results in an expensive copy. The solution is std::string_view (next section)

    Returning a std::string: When a function returns by value to the caller, the return value is normally copied from the function back to the caller. So you might expect
    that you should not return std::string by value. However, it is normally okay to return a std::string by value when the expression of the return statement resolves to any
    of the following:

      A local variable of type std::string (Like a variable decalred in the function and returned)
      A std::string that has been returned by value from another function call or operator 
      A std::string temporary that is created as part of the return statement

    TIP: If returning a C-style string literal use a std::string_view return type instead

  */

  /* 
    Literals for std::string

    Double quoted string literals like "Hello world" are C style string by default (and thus have a strange type)

    You can create string literals with type std::string by using s suffix after the double-quoted string literal. The s must be lowercase
  */
  using namespace std::string_literals; 

  std::cout << "foo\n"; // no suffix is a C style string literal
  std::cout << "goo\n"s; // s suffix is a std::string literal

  /* 
    using namespace std::string_literals is the way to import the s literal, without it you couldnt use it

    You wont need to use this often but there are some use cases that make this easier 
  */

  /* 
    Constexpr strings

    If you try to generate a constexpr std::string your compiler will probably gernerate an error.
  */

  using namespace std::string_literals;

  constexpr std::string name6{"Alex"}; // compiler error
  std::cout << "My name is: " << '\n';

  /* 
    This happens because constexpr std::string isnt supported in c++17 or earlier and only works in limited cases in c++20/23.
    If you need a constexpr string use std::string_view instead.
  */
  

  





  return 0;
}