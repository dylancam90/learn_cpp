#include <iostream>

/* 
  The PREPROCESSOR is the first step before the file is compiled and consists of removing comments and handles #include directives.

  when the PREPROCESSOR has finished proccessing the code file the result is called a TRANSLATION UNIT, this is what's then compiled.

  Preprocessor directives - often called directives are instructions that start with a # symbol and end with a newline (NOT A SEMICOLON). The Preprocessor replaces the 
  the #include directive with the contents of that file


  MACRO - a rule that defines how input text is converted into replacement output text. There are 2 types, object-like-macros and function-like-macros.

  function-like-macros act like functions but are unsafe and anything they can do can be done by a normal function.

  object-like-macros can be defined in 2 ways:

    #define IDENTIFIER
    #define IDENTIFIER substitution-text

  Macro names should be written in all uppercase letters, with words separated by underscores.

*/

/* WARNING - OBJECT-LIKE-MACROS WITH SUBSTITUTION TEXT ARE MORE OF A LEGACY THING AND SHOULD BE AVOIDED */

#define MY_NAME "Bob" // example of object-like-macro with substitution text

int main() {
  std::cout << "My name is: " << MY_NAME << "\n";

  return 0;
}

/* 
  The preprocessor converts the above into the following: 
  
  // The contents of iostream are inserted here

  int main() {
      std::cout << "My name is: " << "Alex" << '\n';

      return 0;
  }
*/

/* object-like-macros without substitution text */

#include <iostream>

#define PRINT_JOE

int main2() {
  #ifdef PRINT_JOE        // if defined directive
    std::cout << "Joe\n";
  #endif                  // end if directive

  #ifdef PRINT_BOB
    std::cout << "Bob\n";
  #endif 

  return 0;
}

#include <iostream>

int main3() {
  #ifndef PRINT_BOB       // if not defined directive (this will print)
    std::cout << "Bob\n";
  #endif
  return 0;
}

/* These are also the same directives but they use a slightly more C++ style */

int main4() {
  std::cout << "Joe\n";

  // 0 Excludes the block of code to not be compiled, 1 includes it
  #if 0
    std::cout << "Jill\n";
    std::cout << "Bill\n";
  #endif
}

/* 
  Important to note, preproccesor directives in one file do not have any impact on other files unless they are included into another file.

  example: the bottom code will print "Not printing!" because even though PRINT was defined in main.cpp it doesnt have any impact on any code in function.cpp 
  (PRINT doesnt go any deeper than the file it was defined in)
*/

// function.cpp
void doSomething() {
  #ifndef PRINT
    std::cout << "Printing\n";
  #endif
  #ifndef PRINT 
    std::cout << "Not printing!\n";
  #endif
}

// main.cpp

void doSomething(); // forward declaration

#define PRINT

int main5() {
  doSomething();
  return 0;
}