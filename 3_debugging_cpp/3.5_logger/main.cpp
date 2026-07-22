#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput() {
  PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;
  return x;
}

int main() {
  plog::init(plog::debug, "Logfile.txt"); // STEP 2: initialize the logger

  PLOGD << "main() called";

  int x{getUserInput()};
  std::cout << "You entered " << x << "\n";

  return 0;
}