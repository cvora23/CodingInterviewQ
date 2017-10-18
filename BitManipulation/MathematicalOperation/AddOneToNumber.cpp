/*
 * AddOneToNumber.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */

#include<stdio.h>

/**
 * To add 1 to a number x (say 0011000111), we need to flip all
 * the bits after the rightmost 0 bit (we get 0011000000).
 * Finally, flip the rightmost 0 bit also (we get 0011001000) and we are done.
 */

int addOne1(int x)
{
  int m = 1;

  /* Flip all the set bits until we find a 0 */
  while( x & m )
  {
    x = x^m;
    m <<= 1;
  }

  /* flip the rightmost 0 bit */
  x = x^m;
  return x;
}

/**
 * We know that the negative number is represented in 2′s complement form on most of the architectures.
 * We have the following lemma hold for 2′s complement representation of signed numbers.
 * Say, x is numerical value of a number, then
 * ~x = -(x+1) [ ~ is for bitwise complement ]
 * (x + 1) is due to addition of 1 in 2′s complement conversion
 * To get (x + 1) apply negation once again. So, the final expression becomes (-(~x)).
 */

int addOne2(int x)
{
   return (-(~x));
}

/* Driver program to test above functions*/
int main()
{
  printf("%d \n", addOne1(13));
  printf("%d \n", addOne2(13));
  getchar();
  return 0;
}
