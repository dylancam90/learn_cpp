/* 
  Header files are really just to keep your main file from filling up with too many forward declarations.

  A header file contains 2 things, a header guard, and the actual content which should be forward declarations.


  FOR AN EXAMPLE GO TO C++/learn_cpp/2_funcs_and_files/2.11_header_files

  1. You want to put your forward declaration in your header file (along with a header guard which will be covered later)
  2. In your add.cpp file you need to import the header file and define the functionality of the function
  3. In main.cpp you also want to import the header file

  What happens during the preproccesor process is it will start in the main.cpp file and see "#include add.h", it will then go to the add.h file and know that add exists 
  so when it passes the transpile untit to the compiler the linker can find the definition

  The difference between #include <> and #include "":
  
  When using <> we are telling the preproccessor that we didnt write it ourselves and the preproccessor will search for the header only in the directories specified by
  the INCLUDE DIRECTORIES. INCLUDE DIRECTORIES is a configuration.
  
  When using "" we are telling the preproccessor we wrote it and it will look in the current dierctory

  Why <iostream> inst iostream.h. It was at first but changes after the namespace was introduced 

  Headers that may include other headers:
  
  Its common that the content of a header file will make use of something that is delared in another header file. This is called a TRANSITIVE INCLUDE

  Lets say we have a header file called #include <Engine.h> that contains #include <string>, its not good to import Engine.h to main and use string.h. Its better to inlude
  <string> in main.cpp

*/




// add.h:

// We really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)

// This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!

/* 
  In order to use this header file in main.cpp, we have to #include it (using quotes, not angle brackets).

  main.cpp: 
*/

#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}

// add.cpp:

#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.

int add(int x, int y)
{
    return x + y;
}