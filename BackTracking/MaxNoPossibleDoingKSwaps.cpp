/*
 * MaxNoPossibleDoingKSwaps.cpp
 *
 *  Created on: Nov 8, 2017
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
 * Find Maximum number possible by doing at-most K swaps
3.7
Given a positive integer, find maximum integer possible by doing at-most K swap operations on its digits.

Examples:

Input: M = 254, K = 1
Output: 524

Input: M = 254, K = 2
Output: 542

Input: M = 68543, K = 1
Output: 86543

Input: M = 7599, K = 2
Output: 9975

Input: M = 76543, K = 1
Output: 76543

Input: M = 129814999, K = 4
Output: 999984211

Idea is to consider every digit and swap it with digits following it one at a time and see if it leads to the maximum number.
We repeat the process K times. The code can be further optimized if we swap only if current digit is less than the following digit.
 */

// function to find maximum integer possible by
// doing at-most K swap operations on its digits
void findMaximumNum(string str, int k, string& max)
{
    // return if no swaps left
    if(k == 0)
        return;

    int n = str.length();

    // consider every digit
    for (int i = 0; i < n - 1; i++)
    {
        // and compare it with all digits after it
        for (int j = i + 1; j < n; j++)
        {
            // if digit at position i is less than digit
            // at position j, swap it and check for maximum
            // number so far and recurse for remaining swaps
            if (str[i] < str[j])
            {
                // swap str[i] with str[j]
                swap(str[i], str[j]);

                // If current num is more than maximum so far
                if (str.compare(max) > 0)
                    max = str;

                // recurse of the other k - 1 swaps
                findMaximumNum(str, k - 1, max);

                // backtrack
                swap(str[i], str[j]);
            }
        }
    }
}

// Driver code
int main()
{
    string str = "129814999";

    int k = 4;

    string max = str;
    findMaximumNum(str, k, max);

    cout << max << endl;

    return 0;
}
