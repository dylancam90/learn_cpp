#include <iostream>
#include <string>
#include <string_view>

void printString(std::string str) // str makes a copy of its initializer (slow)
{
  std::cout << str << '\n'; 
}

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
  std::cout << str << '\n'; 
}


int main()
{
  // Consider the following
  int x{5}; // 5 gets copied into memory for variable x but since its a fundamental type its fast
  std::string s{"Hello world"}; // "Hello world" gets copied into memory and its slow

  std::string s2{"Hello wolrd"}; // s makes a copy of its initializer
  printString(s2);                // then it makes another copy in the function. Its super inneficient 

  /* 
    std::string_view (c++17) 

    To address the issue of copying string literals everywhere you use std::string_view which lives in #include <string_view>.

    std::string_view provides READ-ONLY access to an existing string (a C style string, std::string, or other std::string_view) without making a copy.

    READ ONLY is a kind of confusing title considering the implication is that its constant. What it really is is a fancy pointer with a length value tied to it.
    std::string_view can be changed to point to a different value.
  */

  std::string_view s3{"Hello world"}; // now a std::string_view
  printSV(s3);

  /* 
    BEST PRACTICE: Perfer std::string_view over std::string when you only need a read only string, especially for function parameters 

    Also std::string_view will accept many different types of string arguments.
  */

   

  printSV("Hello world"); // string literal

  std::string t{"Hello world"}; // std::string
  printSV(t);

  std::string_view t1{t};
  printSV(t1);


  // Be aware that you cant do an implicit conversion from std::string_view to std::string but you can explicitly if you need to.

  /* 
    changing what std::string_view points to
  */

  std::string name{"Alex"};
  std::string_view sv {name};
  std::cout << sv << '\n'; // Prints Alex

  sv = "John";             // You changed what sv points to from "Alex" to "John"
  std::cout << sv << '\n'; // Prints John
  std::cout << name << '\n'; // Prints Alex

  /* Literals for std::string_view */

  using namespace std::string_literals;
  using namespace std::string_view_literals;

  std::cout << "foo\n"; // no suffix is a C style string literal 
  std::cout << "good\n"s; // s suffix is a std::string literal
  std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

  /* 
    constexpr support for std::string_view 


    unlike std::string, std::string_view fully supports constexpr


    Symbolic constant - a meaningful name or identifier associated with a fixed value that cannot be changed during the programs execution

  */

  constexpr std::string_view h{"Hello world"}; // h is a string symbolic constant
  std::cout << h << '\n'; // h will be replaced with "Hello world" at compile time









  return 0;
}