#include <iostream>
/* 
  Question #2

  Write the following program: The user is asked to enter 2 floating point numbers (use doubles). 
  The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
  The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.

*/

double getInput()
{
  std::cout << "Enter a double value: ";

  double temp{};
  std::cin >> temp;
  
  return temp;
}

char getOperator() 
{
  std::cout << "Enter +, -, *, or /: ";

  char symbol{};
  std::cin >> symbol;

  return symbol;
}

void printOutput(double a, double b, char symbol, double operation) 
{
  std::cout << a << ' ' << symbol << ' ' << b << " is " << operation << '\n';
}

// This function can be fixed with a char array and a loop but I havent got that far. I used a switch because it was hard to look at.
void getAnswer(double a, double b, char symbol) 
{
  double operation = {};

  switch (symbol) {
    case '+':
      operation = a + b;
      break;
    case '-':
      operation = a - b;
      break;
    case '*':
      operation = a * b;
      break;
    case '/':
      operation = a / b;
      break;
    default:
      std::cerr << "Invalid symbol" << '\n';
      return;
      break;
  }


  printOutput(a, b, symbol, operation);
}

int main() 
{
  double a{getInput()};
  double b{getInput()};

  char symbol{getOperator()};
  getAnswer(a, b, symbol);

  return 0;
}