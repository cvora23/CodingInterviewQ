/*
 * PositionRightMostSetBit.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */

#include<stdio.h>
#include<math.h>

/*
	Algorithm: (Example 18(010010))
	1. 	Take two's complement of the given no as all bits are reverted
		except the first '1' from right to left (10111)
	2  	Do an bit-wise & with original no, this will return no with the
		required one only (00010)
	3  	Take the log2 of the no, you will get position -1 (1)
	4  	Add 1 (2)
 */

unsigned int getFirstSetBitPos(int n)
{
   return log2(n&-n)+1;
}

int main()
{
    int n = 12;
    printf("%u \n", getFirstSetBitPos(n));
    n = 18;
    printf("%u \n", getFirstSetBitPos(n));

    getchar();
    return 0;
}


