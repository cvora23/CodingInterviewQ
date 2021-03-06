/*
 * CountNoOfBitsToFlipToConvertA2B.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */

/* Function to get no of set bits in binary
   representation of passed binary no. */
#include <iostream>
#include <stdint.h>
// Cracking the Code Interview 5.5 Solution
/*
Solution:

  1. Calculate XOR of A and B.
        a_xor_b = A ^ B
  2. Count the set bits in the above calculated XOR result.
        countSetBits(a_xor_b)
XOR of two number will have set bits only at those places where A differs from B.*/
using namespace std;

int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}


int noOfBitsToFlipToConvertA2B(unsigned int no1,unsigned int no2)
{
	unsigned int XOR = no1 ^ no2;
	return countSetBits(XOR);
}

int main(){

	cout<<noOfBitsToFlipToConvertA2B(199,200)<<endl;
	// 199 = 11000111
	// 200 = 11001000

	return 0;
}

