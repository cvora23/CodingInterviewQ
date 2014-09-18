/*
 * BooleanArrayPuzzle.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: cvora
 */

#include <stdio.h>

/*
A Boolean Array Puzzle
Input: A array arr[] of two elements having value 0 and 1

Output: Make both elements 0.

Specifications: Following are the specifications to follow.
1) It is guaranteed that one element is 0 but we do not know its position.
2) We can’t say about another element it can be 0 or 1.
3) We can only complement array elements, no other operation like and, or, multi, division, …. etc.
4) We can’t use if, else and loop constructs.
5) Obviously, we can’t directly assign 0 to array elements.
 */

void changeToZero1(int a[2])
{
   a[ a[1] ] = a[ !a[1] ];
}


void changeToZero2(int a[2])
{
    a[ !a[0] ] = a[ !a[1] ];
}

void changeToZero3(int a[2])
{
    a[ a[1] ] = a[ a[0] ];
}

void changeToZero4(int a[2])
{
  a[0] = a[a[0]];
  a[1] = a[0];
}

int main()
{
   int a[] = {1, 0};
   changeToZero1(a);

   printf(" arr[0] = %d ", a[0]);
   printf(" arr[1] = %d \n", a[1]);


   changeToZero2(a);

   printf(" arr[0] = %d ", a[0]);
   printf(" arr[1] = %d \n", a[1]);


   changeToZero3(a);

   printf(" arr[0] = %d ", a[0]);
   printf(" arr[1] = %d \n", a[1]);


   changeToZero4(a);

   printf(" arr[0] = %d ", a[0]);
   printf(" arr[1] = %d \n", a[1]);


   getchar();
   return 0;
}
