/*
 * Atoi.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: cvora
 */

// A simple C++ program for implementation of atoi

#include <stdio.h>
#include <iostream>

using namespace std;

// A utility function to check whether x is numeric
bool isNumericChar(char x)
{
    return (x >= '0' && x <= '9')? true: false;
}

// A simple atoi() function. If the given string contains
// any invalid character, then this function returns 0
int myAtoi(char *str)
{
    if (*str == NULL)
       return 0;

    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit

    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;
        i++;  // Also update index of first digit
    }

    // Iterate through all digits of input string and update result
    for (; str[i] != '\0'; ++i)
    {
        if (isNumericChar(str[i]) == false)
            return 0; // You may add some lines to write error message
                      // to error stream
        res = res*10 + str[i] - '0';
        cout<<"res = "<<res<<endl;
    }

    // Return result with sign
    return sign*res;
}

// Driver program to test above function
int main()
{
    char str[] = "-134";
    int val = myAtoi(str);
    printf("%d ", val);
    return 0;
}


