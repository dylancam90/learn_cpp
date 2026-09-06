#include <iostream>
#include <bitset>
#include <string_view>

/* 
  Make a simple permissions system.

  You have:

  Read
  Write
  Execute
  Delete
  Admin

  Represent all five permissions using a std::bitset<8>.

  Your program should:

  Start with no permissions.
  Give the user Read and Write.
  Check whether they have Read.
  Check whether they have Delete.
  Give them Execute.
  Remove Write.
  Print the final permissions.
  Print how many permissions they have.

  You should end up with something conceptually like:

  Read: true
  Write: false
  Execute: true
  Delete: false
  Admin: false

  Permissions: 2
*/

void outputFlag(std::bitset<8> bitset, std::string_view outStr, const int flagIndex)
{

  std::cout << outStr << bitset.test(flagIndex) << '\n';
}


int main()
{
  [[maybe_unused]] constexpr int read     {0};
  [[maybe_unused]] constexpr int write    {1};
  [[maybe_unused]] constexpr int execute  {2};
  [[maybe_unused]] constexpr int del      {3};
  [[maybe_unused]] constexpr int admin    {4};

  std::bitset<8> permissions{};

  // Give user read and write
  permissions.set(read);
  permissions.set(write);

  // Set cout to output true/false
  std::cout << std::boolalpha;

  // Check whether they have read
  outputFlag(permissions, "Read: ", read);
  // Check whether they have write
  outputFlag(permissions, "Write: ", write);
  std::cout << '\n';

  // Give them execute
  permissions.set(execute);
  // Remove write
  permissions.reset(write);


  // Print all permissions
  outputFlag(permissions, "Read: ", read);
  outputFlag(permissions, "Write: ", write);
  outputFlag(permissions, "Execute: ", execute);
  outputFlag(permissions, "Delete: ", del);
  outputFlag(permissions, "Admin: ", admin);
  std::cout << '\n';

  // Output total permissions
  std::cout << "Total permissions: " << permissions.count() << '\n';

  return 0;
}