/*
 * CountNoSetBitsFloatPointNo.cpp
 *
 *  Created on: Oct 16, 2013
 *      Author: cvora
 */

#include <stdio.h>

// A utility function to count set bits in a char.
// Refer http://goo.gl/eHF6Y8 for details of this function.
unsigned int countSetBitsChar(char n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1);
      count++;
    }
    return count;
}

// Returns set bits in binary representation of x
unsigned int countSetBitsFloat(float x)
{
    // Count number of chars (or bytes) in binary representation of float
    unsigned int n = sizeof(float)/sizeof(char);

    // typcast address of x to a char pointer
    char *ptr = (char *)&x;

    int count = 0;   // To store the result
    for (int i = 0; i < n; i++)
    {
         count += countSetBitsChar(*ptr);
         ptr++;
    }
    return count;
}

// Driver program to test above function
int main()
{
    float x = 0.15625;
    printf("Binary representation of %f has %u set bits ", x,countSetBitsFloat(x));
    return 0;
}


