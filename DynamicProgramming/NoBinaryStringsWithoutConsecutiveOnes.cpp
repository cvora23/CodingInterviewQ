/*
 * NoBinaryStringsWithoutConsecutiveOnes.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 * Count number of binary strings without consecutive 1’s
2.8
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Examples:

Input:  N = 2
Output: 3
// The 3 strings are 00, 01, 10

Input: N = 3
Output: 5
// The 5 strings are 000, 001, 010, 100, 101
 *
 * This problem can be solved using Dynamic Programming. Let a[i] be the number of binary strings of length i
 * which do not contain any two consecutive 1’s and which end in 0. Similarly, let b[i] be the number of such
 * strings which end in 1. We can append either 0 or 1 to a string ending in 0, but we can only append 0 to a string ending in 1.
 * This yields the recurrence relation:

a[i] = a[i - 1] + b[i - 1]
b[i] = a[i - 1]
The base cases of above recurrence are a[1] = b[1] = 1. The total number of strings of length i is just a[i] + b[i].

Following is the implementation of above solution. In the following implementation, indexes start from 0.
So a[i] represents the number of binary strings for input length i+1. Similarly, b[i] represents binary strings for input length i+1.
 */
int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}


// Driver program to test above functions
int main()
{
    cout << countStrings(3) << endl;
    return 0;
}

/*
 * If we take a closer look at the pattern, we can observe that the count is actually (n+2)’th Fibonacci number for n >= 1.
 * The Fibonacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ….

n = 1, count = 2  = fib(3)
n = 2, count = 3  = fib(4)
n = 3, count = 5  = fib(5)
n = 4, count = 8  = fib(6)
n = 5, count = 13 = fib(7)
................
 */
