/*
 * PreIncrementOperator.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: cvora
 */

/*
 * In C++, pre-increment (or pre-decrement) can be used as l-value, but post-increment
 * (or post-decrement) can not be used as l-value.

For example, following program prints a = 20 (++a is used as l-value)

#include<stdio.h>

int main()
{
  int a = 10;
  ++a = 20; // works
  printf("a = %d", a);
  getchar();
  return 0;
}
And following program fails in compilation with error “non-lvalue in assignment” (a++ is used as l-value)

#include<stdio.h>

int main()
{
  int a = 10;
  a++ = 20; // error
  printf("a = %d", a);
  getchar();
  return 0;
}
 */


