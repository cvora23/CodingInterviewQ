/*
 * TwoIntegersOppSign.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: cvora
 */

#include<stdbool.h>
#include<stdio.h>

/**
 * Given two signed integers, write a function that returns true
 * if the signs of given integers are different, otherwise false.
 * For example, the function should return true -1 and +100,
 * and should return false for -100 and -200. The function should
 * not use any of the arithmetic operators.
 */


/**
 * Let the given integers be x and y. The sign bit is 1 in negative numbers,
 * and 0 in positive numbers. The XOR of x and y will have the sign bit as
 * 1 if they have opposite sign. In other words, XOR of x and y will be
 * negative number number iff x and y have opposite signs.
 * The following code use this logic.
 */
bool oppositeSigns1(int x, int y)
{
    return ((x ^ y) < 0);
}

bool oppositeSigns2(int x, int y)
{
    return (x < 0)? (y >= 0): (y < 0);
}

/*
 * The function is written only for compilers where size of an integer is 32 bit.
 *  The expression basically checks sign of (x^y) using bitwise operator ‘>>’.
 *  As mentioned above, the sign bit for negative numbers is always 1.
 *  The sign bit is the leftmost bit in binary representation.
 *  So we need to checks whether the 32th bit (or leftmost bit) of x^y is 1 or not.
 *  We do it by right shifting the value of x^y by 31, so that the sign bit
 *  becomes the least significant bit. If sign bit is 1, then the value of (x^y)>>31
 *  will be 1, otherwise 0.
 */
bool oppositeSigns3(int x, int y)
{
    return ((x ^ y) >> 31);
}

int main()
{
    int x = 100, y = -100;
    if (oppositeSigns1(x, y) == true)
       printf ("Signs are opposite\n");
    else
      printf ("Signs are not opposite\n");
    if (oppositeSigns2(x, y) == true)
       printf ("Signs are opposite\n");
    else
      printf ("Signs are not opposite\n");
    if (oppositeSigns3(x, y) == true)
       printf ("Signs are opposite\n");
    else
      printf ("Signs are not opposite\n");

    return 0;
}
