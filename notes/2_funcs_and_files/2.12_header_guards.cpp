/* 
  Header guards (also called a include guard) a way to end up with duplicate non compiling delcarations in your code. Consider this:
*/

// square.h
int getSquareSides() {
  return 4;
}

// wave.h
#include "square.h"

// main.cpp 

#include "square.h"
#include "wave.h"

int main() {
  return 0;
}

// You will import getSquareSides 2 times and it wont compile because there will be 2 identical copies. Once imported from sqaure and once from wave

/* 
  Header guard:
*/

#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif 

/*
  ALL YOUR HADER FILES SHOULD HAVE HEADER GUARDS
  
  Better example of above
*/

// square.h

#ifndef SQUARE_H
#define SQAURE_H

int getSquareSides() {
  return 4;
}

#endif

// wave.h

#ifndef WAVE_H
#define WAVE_H

#include "square.h"

#endif

// main.cpp

#include "square.h"
#include "wave.h"

int main() {
  return 0;
}


// Easiest way to do header guards with a couple cavets but will work 99% of the time

#pragma once 

int add(int a, int b); 
