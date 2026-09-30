#include <iostream>
#include <string>
#include <string_view>

// used near bottom to illustrate ownership and how this string will be destroyed after the function is returned
std::string getName() 
{
  std::string alex{"Alex"};
  return alex;
}

// This is also bad because it returns a view but the thing its poiting to gets destroyed after the function returns
std::string_view getName2() 
{
  std::string name{"Alex"};
  return name;
}

// This is okay
std::string_view getNameGood()
{
  return "Alex"; 
}

int main()
{
  /* 
    Since std::string_view is essentially a pointer you need to be careful not to hang it by destroying what its viewing:

    So what happens in this example is that in getName() a std::string is initialized and copied to memory but after the functions closure its destroyed meaning 
    that name2 is now pointing at a memory address that doesnt contain what you think it does. This is UB (undefined behavior)
  */

  std::string_view name2 {getName()};
  std::cout << name2;

  /* 
    remove_prefix() - member function that removes chars from the left side of the view
    removes_suffix() - member function that removes chars from the right side of the view


    Think of std::string_view as a pointer that points from the first character to the last character and include a length field.

    Take this for example:
  */

  std::string_view str {"Peach"};

  /* 
    You have:

                P e a c h
                ↑       ↑
                └───────┘
                  view
  
    Then:
  */

  str.remove_prefix(1);

  /* 
    You simply move the start of the view 1 index to the right of the first char

                P e a c h
                  ↑     ↑
                  └─────┘
                   view
  */

  std::cout << str << '\n'; // Output: "each"

  // Now using remove_suffix()
  str.remove_suffix(2); // Output: "Pea"

  /* 
    You now move the view 2 places to the left of the last char

                P e a
                ↑   ↑
                └───┘
                view

    You aren't actually modifying the string you're just adjusting the window. This lets you manipulate strings.

  */

  /* 
    NOTE:
      std::str_view may NOT be null terminated "\0"

    QUIDE ON WHEN TO USE STD::STRING VS STD::VIEW_STRING --------------------------------------------------------------------------------------------------------------------------------

    Variables: 

      Use a std::string when:
        • You need a string that you can modify
        • You need to store user-inputted text
        • You need to store the return value of a function that returns a std::string

      Use a std::string_view varaible when:
        • You need read-only access to part or all of a string that already exists elsewhere and will not be modified or destroyed before use of the std::string_view is complete
        • You need a symbolic constant for a C style string
        • You need to continue viewing the return value of a function that returns C style string or non dangling std::string_view

    Function parameters:

      Use a std::string function parameter when:
        • The function needs to modify the string passed in as an argument without affecting the caller. (This is rare)
        • You are using language standard C++14 or older and arent comfortable using references yet

      Use a std::string_view function parameter when:
        • The function needs a read only string
        • The function needs to work with non-null-terminated strings

    Return types:

      Use a std::string return type when:
        • The return value is a std::string local variable or function parameter
        • The return value is a function call or operator that returns a std::string by value

      Use a std::string_view return type when:
        • The function returns a C style string literal or local std::string_view that has been initialized with a C style string literal
        • The function returns a std::string_view parameter




        
  */

  return 0;
}