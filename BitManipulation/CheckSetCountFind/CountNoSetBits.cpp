/*
 * CountNoSetBits.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */
#include<stdio.h>


/* Function to get no of set bits in binary
   representation of passed binary no. */
/**
 * 1. Simple Method Loop through all bits in an integer,
 * check if a bit is set and if it is then increment the set bit count. See below program.
 */
int countSetBits1(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}


/* Function to get no of set bits in binary
   representation of passed binary no. */
/*
 * 2. Brian Kernighan’s Algorithm:
	Subtraction of 1 from a number toggles all the bits (from right to left)
	till the rightmost set bit(including the righmost set bit).
	So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)),
	we unset the righmost set bit. If we do n & (n-1) in a loop
	and count the no of times loop executes we get the set bit count.
	Beauty of the this solution is number of times it loops is equal
	to the number of set bits in a given integer.
 *
 */
int countSetBits2(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

/* Program to test function countSetBits */
int main()
{
    int i = 9;
    printf("%d", countSetBits1(i));
    printf("%d", countSetBits2(i));
    getchar();
    return 0;
}




