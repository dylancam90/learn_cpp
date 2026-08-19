#include <iostream>

/* 
  Question #3

  What does the call stack look like in the following program when the point of execution is on line 12? Only the function names are needed for this exercise, not the line numbers indicating the point of return.

  We talk about the call stack in lesson 3.9 -- Using an integrated debugger: The call stack.
*/

void d()
{ // here
}

void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}