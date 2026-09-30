#include <iostream>

/* 
  Question #2

  The following program is supposed to divide two numbers, but doesn’t work correctly.

  Use the integrated debugger to step through this program. For inputs, enter 8 and 4. Based on the information you learn, fix the following program:
*/

int readNumber()
{
	std::cout << "Please enter a number: ";
	int x {};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The quotient is: " << x << '\n';
}

int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	// x = readNumber();
	// x = readNumber();  // These are both x
	writeAnswer(x/y);

	return 0;
}