# Question 1

Split the following program into two files (main.cpp, and input.cpp). main.cpp should have the main function, and input.cpp should have the getInteger function.

```
#include <iostream>

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " is " << x + y << '\n';
	return 0;
}
```

## Answer

Split both functions into different files making sure to include iostream in both and a forward declaration of getInteger() in front of main.

Compile with:

`g++ ./main.cpp ./input.cpp -o main`
