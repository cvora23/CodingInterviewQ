/*
 * PositionOfOnlySetBit.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: cvora
 */

#include <stdio.h>

// A utility function to check whether n is power of 2 or not. See http://goo.gl/17Arj
/*
 *  If we subtract a power of 2 numbers by 1 then all
 *  unset bits after the only set bit become set; and the set bit become unset.
 *  For example for 4 ( 100) and 16(10000), we get following after subtracting 1
 *  3 –> 011
 *  15 –> 01111
 *  So, if a number n is a power of 2 then bitwise & of n and n-1 will be zero.
 *  We can say n is a power of 2 or not based on value of n&(n-1).
 *  The expression n&(n-1) will not work when n is 0.
 *  To handle this case also, our expression will become n& (!n&(n-1))
 *
 */
int isPowerOfTwo(unsigned n)
{
	return n && (! (n & (n-1)) );
}

// Returns position of the only set bit in 'n'
int findPosition1(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;

    unsigned i = 1, pos = 1;

    // Iterate through bits of n till we find a set bit
    // i&n will be non-zero only when 'i' and 'n' have a set bit
    // at same position
    while (!(i & n))
    {
        // Unset current bit and set the next bit in 'i'
        i = i << 1;

        // increment position
        ++pos;
    }

    return pos;
}

// Returns position of the only set bit in 'n'
int findPosition2(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;

    unsigned count = 0;

    // One by one move the only set bit to right till it reaches end
    while (n)
    {
        n = n >> 1;

        // increment count of shifts
        ++count;
    }

    return count;
}


unsigned int Log2n(unsigned int n)
{
   return (n > 1)? 1 + Log2n(n/2): 0;
}

int findPosition3(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;
    return Log2n(n) + 1;
}

// Driver program to test above function
int main(void)
{
    int n = 0;
    int pos;
    pos = findPosition1(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);
    pos = findPosition2(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);
    pos = findPosition3(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);

    n = 12;
    pos = findPosition1(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);
    n = 12;
    pos = findPosition2(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);
    n = 12;
    pos = findPosition3(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);

    n = 128;
    pos = findPosition1(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);
    n = 128;
    pos = findPosition2(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);
    n = 128;
    pos = findPosition3(n);
    (pos == -1)? printf("n = %d, Invalid number\n", n):
                 printf("n = %d, Position %d \n", n, pos);

    return 0;
}





