/*
 * TotalSetBitsOneTon.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: cvora
 */

// A simple program to count set bits in all numbers from 1 to n.
#include <stdio.h>

// A utility function to count set bits in a number x
unsigned int countSetBitsUtil(unsigned int x);

// Returns count of set bits present in all numbers from 1 to n
unsigned int countSetBits1(unsigned int n)
{
    int bitCount = 0; // initialize the result

    for(unsigned int i = 1; i <= n; i++)
       bitCount += countSetBitsUtil(i);

    return bitCount;
}

// A utility function to count set bits in a number x
unsigned int countSetBitsUtil(unsigned int x)
{
    if (x <= 0)
        return 0;
    return (x %2 == 0? 0: 1) + countSetBitsUtil (x/2);
}

// A O(Logn) complexity program to count set bits in all numbers from 1 to n
#include <stdio.h>

/* Returns position of leftmost set bit. The rightmost
   position is considered as 0 */
unsigned int getLeftmostBit (int n)
{
   int m = 0;
   while (n  > 1)
   {
      n = n >> 1;
      m++;
   }
   return m;
}

/* Given the position of previous leftmost set bit in n (or an upper
   bound on leftmost position) returns the new position of leftmost
   set bit in n  */
unsigned int getNextLeftmostBit (int n, int m)
{
   unsigned int temp = 1 << m;
   while (n  < temp)
   {
      temp = temp >> 1;
      m--;
   }
   return m;
}

// The main recursive function used by countSetBits()
unsigned int _countSetBits(unsigned int n, int m);

// Returns count of set bits present in all numbers from 1 to n
unsigned int countSetBits2(unsigned int n)
{
   // Get the position of leftmost set bit in n. This will be
   // used as an upper bound for next set bit function
   int m = getLeftmostBit (n);

   // Use the position
   return _countSetBits (n, m);
}

unsigned int _countSetBits(unsigned int n, int m)
{
    // Base Case: if n is 0, then set bit count is 0
    if (n == 0)
       return 0;

    /* get position of next leftmost set bit */
    m = getNextLeftmostBit(n, m);

    // If n is of the form 2^x-1, i.e., if n is like 1, 3, 7, 15, 31,.. etc,
    // then we are done.
    // Since positions are considered starting from 0, 1 is added to m
    if (n == ((unsigned int)1<<(m+1))-1)
        return (unsigned int)(m+1)*(1<<m);

    // update n for next recursive call
    n = n - (1<<m);
    return (n+1) + countSetBits2(n) + m*(1<<(m-1));
}

/* Function to get no of set bits in binary
   representation of passed binary no. */
/**
 * 1. Simple Method Loop through all bits in an integer,
 * check if a bit is set and if it is then increment the set bit count. See below program.
 */
int countSetBits3(unsigned int n)
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
int countSetBits4(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}


// Driver program to test above functions
int main()
{
   int n = 4;
   printf ("Total set bit count is %d", countSetBits1(n));
   printf ("Total set bit count is %d", countSetBits2(n));
   return 0;
}



