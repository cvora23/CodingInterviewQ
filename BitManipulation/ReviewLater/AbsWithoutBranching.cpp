/*
 * AbsWithoutBranching.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */

#include <stdio.h>

#define CHAR_BIT 8

/* This function will return absoulte value of n*/
unsigned int getAbs1(int n)
{
  int const mask = n >> (sizeof(int) * CHAR_BIT - 1);
  return ((n + mask) ^ mask);
}

/* This function will return absoulte value of n*/
unsigned int getAbs2(int n)
{
  int const mask = n >> (sizeof(int) * CHAR_BIT - 1);
  return ((n ^ mask) - mask);
}

/* This function will return absoulte value of n*/
unsigned int getAbs3(int n)
{
	return (n<0)?-(unsigned)n:n;
}

/* Driver program to test above function */
int main()
{
  int n = -6;
  printf("Absolute value of %d is %u \n", n, getAbs1(n));
  printf("Absolute value of %d is %u \n", n, getAbs2(n));
  printf("Absolute value of %d is %u \n", n, getAbs3(n));
  printf("Absolute value of %d is %u \n", n, getAbs4(n));

  getchar();
  return 0;
}
