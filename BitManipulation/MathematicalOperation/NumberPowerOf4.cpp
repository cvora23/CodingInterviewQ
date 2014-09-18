/*
 * NumberPowerOf4.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */
#include<iostream>
#include<stdio.h>
#define bool int


/**
 * 1. A simple method is to take log of the given number on base 4,
 * and if we get an integer then number is power of 4.
 */

using namespace std;

/*
 * 2. Another solution is to keep dividing the number by 4, i.e,
 * do n = n/4 iteratively. In any iteration, if n%4
 * becomes non-zero and n is not 1 then n is not a power of 4,
 * otherwise n is a power of 4.
 */

/* Function to check if x is power of 4*/
bool isPowerOfFour1(int n)
{
  if(n == 0)
    return 0;
  while(n != 1)
  {
   if(n%4 != 0)
      return 0;
    n = n/4;
  }
  return 1;
}

/*
 * 3. A number n is a power of 4 if following conditions are met.
a) There is only one bit set in the binary representation of n (or n is a power of 2)
b) The count of zero bits before the (only) set bit is even.

For example: 16 (10000) is power of 4 because there is
only one bit set and count of 0s before the set bit is 4 which is even.
 */
bool isPowerOfFour2(unsigned int n)
{
  int count = 0;

  /*Check if there is only one bit set in n*/
  if ( n && !(n&(n-1)) )
  {
     /* count 0 bits before set bit */
     while(n > 1)
     {
       n  >>= 1;
       count += 1;
     }

    /*If count is even then return true else false*/
    return (count%2 == 0)? 1 :0;
  }

  /* If there are more than 1 bit set
    then n is not a power of 4*/
  return 0;
}

/*Driver program to test above function*/
int main()
{
   int test_no;
   cout<<"Enter the input number to test"<<endl;
   cin>>test_no;
   if(isPowerOfFour1(test_no))
     printf("%d is a power of 4 \n", test_no);
   else
     printf("%d is not a power of 4 \n", test_no);
   if(isPowerOfFour2(test_no))
     printf("%d is a power of 4 \n", test_no);
   else
     printf("%d is not a power of 4 \n", test_no);

   getchar();
}
