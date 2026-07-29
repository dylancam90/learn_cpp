#include <iostream>

/* 
  Question #1

  The following program is supposed to add two numbers, but doesn’t work correctly.

  Use the integrated debugger to step through this program and watch the value of x. Based on the information you learn, fix the following program:
*/

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x {};
	// readNumber(x);   
	// x = x + readNumber(x);
  x = readNumber(x) + readNumber(x); // The first read number statement wasnt being saved to a variable, I did it this way instead of changing the function signature
	writeAnswer(x);

	return 0;
}