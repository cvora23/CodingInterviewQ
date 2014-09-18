/*
 * MultiplyNumberBy3.5.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */



#include <stdio.h>

int multiplyWith3Point5_1(int x)
{
  return (x<<1) + x + (x>>1);
}

int multiplyWith3Point5_2(int x)
{
  return ((x<<3) - x)>>1;
}

int multiplyWith3Point5_3(int x)
{
  return ((x<<2) - (x>>1));
}

/* Driver program to test above functions*/
int main()
{
  int x = 4;
  printf("%d\n", multiplyWith3Point5_1(x));
  printf("%d\n", multiplyWith3Point5_2(x));
  printf("%d\n", multiplyWith3Point5_3(x));
  getchar();
  return 0;
}
