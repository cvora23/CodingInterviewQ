/*
 * NthFibonnaciNumber.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: cvora
 */

/*
 * Program for Fibonacci numbers
The Fibonacci numbers are the numbers in the following integer sequence.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

  F_n = F_{n-1} + F_{n-2}

with seed values

   F_0 = 0 \quad\text{and}\quad F_1 = 1.

Write a function int fib(int n) that returns F_n. For example, if n = 0,
then fib() should return 0. If n = 1, then it should return 1. For n > 1, it
should return  F_{n-1} + F_{n-2}
 */

/*
Method 1 ( Use recursion )
A simple method that is a direct recusrive implementation mathematical recurance relation given above.
*/

#include<stdio.h>
int fibRec(int n)
{
   if (n <= 1)
      return n;
   return fibRec(n-1) + fibRec(n-2);
}

/*
 * Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential.
We can observe that this implementation does a lot of repeated work (see the following recursion tree).
So this is a bad implementation for nth Fibonacci number.

                         fib(5)
                     /             \
               fib(4)                fib(3)
             /      \                /     \
         fib(3)      fib(2)         fib(2)    fib(1)
        /     \        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /    \
fib(1) fib(0)
Extra Space: O(n) if we consider the fuinction call stack size, otherwise O(1).
 */

/*
 * Method 2 ( Use Dynamic Programming )
We can avoid the repeated work done is the method 1 by storing the Fibonacci numbers calculated so far.
 */

int fibDP1(int n)
{
  /* Declare an array to store fibonacci numbers. */
  int f[n+1];
  int i;

  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
} // Time Complexity: O(n); Extra Space: O(n)

/*
Method 3 ( Space Otimized Method 2 )
We can optimize the space used in method 2 by storing the previous two numbers only because
that is all we need to get the next Fibannaci number in series.
*/

#include<stdio.h>
int fibDP2(int n)
{
  int a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}
/*
 * Time Complexity: O(n)
 * Extra Space: O(1)
 */


/* Driver program to test above function */
int main()
{
  int n = 9;

  printf("%d \n", fibRec(n));
  printf("%d \n", fibDP1(n));
  printf("%d \n", fibDP2(n));

  getchar();
  return 0;
}
