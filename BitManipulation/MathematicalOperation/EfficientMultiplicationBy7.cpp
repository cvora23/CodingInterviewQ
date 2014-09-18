/*
 * EfficientMultiplicationBy7.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */


# include<stdio.h>


/**
 * We can multiply a number by 7 using bitwise operator.
 * First left shift the number by 3 bits (you will get 8n)
 * then subtract the original numberfrom the shifted number and
 * return the difference (8n – n).
 */
int multiplyBySeven(unsigned int n)
{
    /* Note the inner bracket here. This is needed
       because precedence of '-' operator is higher
       than '<<' */
    return ((n<<3) - n);
}

/* Driver program to test above function */
int main()
{
    unsigned int n = 4;
    printf("%u", multiplyBySeven(n));

    getchar();
    return 0;
}


