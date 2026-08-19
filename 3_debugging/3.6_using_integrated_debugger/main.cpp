#include <iostream>

/* 
  RUN TO LINE - Right clicking on a line and selecting "run to line" will do a "run to cursor" where the program executes to the line you selected 
  CONTINUE - Run from the line you selected onwards to the end of the program or to a breakpoint (this is the play button in the menu)
  START - The start command is similar to continue but it starts at the beggining of the program (press F5)
  BREAKPOINTS - special marker that tells the debugger to stop execution of the program at the breakpoint. (click on line number)
*/

void printValue(int value) 
{
  std::cout << value << "\n";
}

int main() 
{
  printValue(5);
  printValue(6);
  printValue(7);
  return 0;
}