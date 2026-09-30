#include <iostream>

/* 
  This is an example of why its recommended not to use unsigned ints and why they could be dangerous because of underflow
*/

// assuming int is 4 bytes and the min for that is 0 and max is 4,294,967,295

int main() 
{
  unsigned int x{ 2 };
  unsigned int y{ 3 };

  std::cout << x - y << '\n'; // this -1 which unsigned does not handle so the result is really 4,294,967,295 because of the underflow

  return 0; 
}