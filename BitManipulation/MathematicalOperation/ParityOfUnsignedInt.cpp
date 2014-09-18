/*
 * ParityOfUnsignedInt.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */

# include <stdio.h>
# define  bool int

/*
 * Parity: Parity of a number refers to whether it contains an
 * odd or even number of 1-bits. The number has “odd parity”,
 * if it contains odd number of 1-bits and is “even parity”
 * if it contains even number of 1-bits.
	Main idea of the below solution is – Loop while n
	is not 0 and in loop unset one of the set bits and invert parity.
 */

/*
 * Algorithm: getParity(n)
	1. Initialize parity = 0
	2. Loop while n != 0
      a. Invert parity
             parity = !parity
      b. Unset rightmost set bit
             n = n & (n-1)
	3. return parity
 *
 */

/* Function to get parity of number n. It returns 1
   if n has odd parity, and returns 0 if n has even
   parity */
bool getParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n      = n & (n - 1);
    }
    return parity;
}

/* Driver program to test getParity() */
int main()
{
    unsigned int n = 7;
    printf("Parity of no %d = %s",  n,
             (getParity(n)? "odd": "even"));

    getchar();
    return 0;
}



