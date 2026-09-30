#include <iostream>
#include <cstdlib>
/* 

Question #3

Extra credit: This one is a little more challenging.

Write a short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the height of the tower in meters. 
Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start). 
Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should not go underneath the ground (height 0).

Use a function to calculate the height of the ball after x seconds. 
The function can calculate how far the ball has fallen after x seconds using the following formula: distance fallen = gravity_constant * x_seconds2 / 2

*/

// They tell you not to use loops but I already know how to do loops in C so I used one since it was more intuitive. This may not be the correct way to do it in CPP
void calculateFall(float fallRate, unsigned int height)  
{

  for (int seconds{0}; seconds <= 5; seconds++) 
  {
    float calculation = height - ((fallRate * (seconds * seconds)) / 2);

    if (calculation <= 0) 
    {
      std::cout << "At " << seconds << " seconds, " << "the ball hits the ground." << '\n';
      return;  
    }

    std::cout << "At " << seconds << " seconds, " << "the ball is at the height: " << calculation << '\n'; 
  }
}

unsigned int getTowerHeight()
{
  std::cout << "Enter the height of the tower in meters: ";

  unsigned int height{};
  std::cin >> height;

  if (height <= 0) 
  {
    std::cerr << "Height must be above 0 meters, nice try. " << '\n';
    std::exit(EXIT_FAILURE);
  }

  return height;
}

int main()
{
  float fallRate{9.8f};
  unsigned int height{getTowerHeight()};
  calculateFall(fallRate, height);
  return 0;
}