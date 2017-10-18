/*
 * ReverseBitsOfNumber.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */

#include <stdio.h>
#include <stdint.h>
#include <iostream>

using namespace std;

/**
 * 	Method1 – Simple
	Loop through all the bits of an integer.
	If a bit at ith position is set in the i/p no. then set the bit at	(NO_OF_BITS – 1) – i in o/p.
	Where NO_OF_BITS is	number of bits present in the given number
 */
uint8_t reverseBits1(uint8_t num)
{
	uint8_t  NO_OF_BITS = sizeof(num) * 8;
	uint8_t reverse_num = 0;
	uint8_t i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
   }
    return reverse_num;
}

/*
 * Method 2 – Standard
The idea is to keep putting set bits of the num in reverse_num until num becomes zero.
After num becomes zero, shift the remaining bits of reverse_num.
Let num is stored using 8 bits and num be 00000110. After the loop you will get
reverse_num as 00011011. Now you need to left shift reverse_num 5 more
times and you get the exact reverse 01100000.
 */
uint8_t reverseBits2(uint8_t num)
{
	uint8_t count = sizeof(num) * 8 - 1;
	uint8_t reverse_num = num;

    num >>= 1;
    while(num)
    {
       reverse_num <<= 1;
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

int main()
{
	uint8_t x = 1;
    printf("%u \n", reverseBits1(x));
    printf("%u \n", reverseBits2(x));
    x = 6;
    printf("%u \n", reverseBits2(x));

    getchar();
}


