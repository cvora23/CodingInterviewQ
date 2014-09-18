/*
 * SwapBits.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: cvora
 */


#include<stdio.h>

int swapBits1(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* xor contains xor of two sets */
    unsigned int XOR = ((x >> p1) ^ (x >> p2)) & ((1U << n) - 1);

    /* To swap two sets, we need to again XOR the xor with original sets */
    return x ^ ((XOR << p1) | (XOR << p2));
}

int swapBits2(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 =  (x >> p1) & ((1U << n) - 1);

    /* Moce all bits of second set to rightmost side */
    unsigned int set2 =  (x >> p2) & ((1U << n) - 1);

    /* XOR the two sets */
    unsigned int XOR = (set1^set2);

    /* Put the xor bits back to their original positions */
    XOR = (XOR << p1) | (XOR << p2);

    /* XOR the 'xor' with the original number so that the
       two sets are swapped */
    unsigned int result = x ^ XOR;

    return result;
}

/* Drier program to test above function*/
int main()
{
    int res =  swapBits1(28, 0, 3, 2);
    printf("\nResult = %d ", res);
    int res =  swapBits2(28, 0, 3, 2);
    printf("\nResult = %d ", res);

    return 0;
}

