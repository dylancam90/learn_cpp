#include <iostream>

/* 
Question #1

Pick the appropriate data type for a variable in each of the following situations. Be as specific as possible. 
If the answer is an integer, pick int (if size isn’t important), or a specific fixed-width integer type (e.g. std::int16_t) based on range. 

*/

int main() 
{
  // a) The age of the user (in years) (assume the size of the type isn’t important)
  int age{};
  // b) Whether the user wants the application to check for updates
  bool checkForUpdates{true};
  // c) pi (3.14159265)
  double pi{3.14159265};
  // d) The number of pages in a textbook (assume size is not important)
  int pages{};
  // e) The length of a couch in feet, to 2 decimal places (assume size is important)
  float length{};
  // f) How many times you’ve blinked since you were born (note: answer is in the millions)
  std::int32_t blinks{};
  // g) A user selecting an option from a menu by letter
  char letter{};
  // h) The year someone was born (assuming size is important)
  std::int16_t birthYear{};

  return 0;
}