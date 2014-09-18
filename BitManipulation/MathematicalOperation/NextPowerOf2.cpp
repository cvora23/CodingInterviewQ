/*
 * NextPowerOf2.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */
# include <stdio.h>

unsigned int nextPowerOf2_1(unsigned int n)
{
  unsigned count = 0;

  /* First n in the below condition is for the case where n is 0*/
  if (n && !(n&(n-1)))
    return n;

  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }

  return 1<<count;
}

unsigned int nextPowerOf2_2(unsigned int n)
{
    unsigned int p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n) {
        p <<= 1;
    }
    return p;
}

unsigned int nextPowerOf2_3(unsigned int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}


/* Driver program to test above function */
int main()
{
    unsigned int n = 5;
    printf("%d\n", nextPowerOf2_1(n));
    printf("%d\n", nextPowerOf2_2(n));
    printf("%d\n", nextPowerOf2_3(n));

    getchar();
    return 0;

}

