/*
 * AddWithoutArithmeticOperator.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: cvora
 */



#include<stdio.h>


/**
 	Sum of two bits can be obtained by performing XOR (^) of the two bits.
 	Carry bit can be obtained by performing AND (&) of two bits.
   	Above is simple Half Adder logic that can be used to add 2 single bits.
   	We can extend this logic for integers.
   	If x and y don’t have set bits at same position(s),
   	then bitwise XOR (^) of x and y gives the sum of x and y.
   	To incorporate common set bits also, bitwise AND (&) is used.
   	Bitwise AND of x and y gives all carry bits.
   	We calculate (x & y) << 1 and add it to x ^ y to get the required result.
*/

// Iterative approach
int Add1(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry now contains common set bits of x and y
        int carry = x & y;

        // Sum of bits of x and y where at least one of the bits is not set
        x = x ^ y;

        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

// Recursive approach
int Add2(int x, int y)
{
    if (y == 0)
        return x;
    else
        return Add2( x ^ y, (x & y) << 1);
}

unsigned int Add3(unsigned int a,unsigned int b)
{
	return a ?Add3((a&b) << 1,a^b):b;
}



int main()
{
    printf("%d \n", Add1(15, 32));
    printf("%d \n", Add2(15, 32));
    printf("%d \n", Add3(15, 32));

    return 0;
}
