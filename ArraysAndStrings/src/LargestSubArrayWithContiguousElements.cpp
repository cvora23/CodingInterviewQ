/*
 * LargestSubArrayWithContiguousElements.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: cvora
 */

/*
 * Given an array of distinct integers, find length of the longest subarray which
 * contains numbers that can be arranged in a continuous sequence.
 *
 * Examples:
 * Input:  arr[] = {10, 12, 11};
 * Output: Length of the longest contiguous subarray is 3
 * Input:  arr[] = {14, 12, 11, 20};
 * Output: Length of the longest contiguous subarray is 2
 * Input:  arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
 * Output: Length of the longest contiguous subarray is 5
 */


#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <require.h>
#include <iostream>

using namespace std;

/*
 * ALGO:
 * The important thing to note in question is, it is given that all elements are distinct.
 * If all elements are distinct, then a subarray has contiguous elements if and only if
 * the difference between maximum and minimum elements in subarray is equal to the difference
 * between last and first indexes of subarray. So the idea is to keep track of minimum and
 * maximum element in every subarray.
 */

#include<iostream>
using namespace std;

// Utility functions to find minimum and maximum of
// two elements
int min(int x, int y) { return (x < y)? x : y; }
int max(int x, int y) { return (x > y)? x : y; }

// Returns length of the longest contiguous subarray
int findLength(int arr[], int n)
{
    int max_len = 1;  // Initialize result
    for (int i=0; i<n-1; i++)
    {
        // Initialize min and max for all subarrays starting with i
        int mn = arr[i], mx = arr[i];

        // Consider all subarrays starting with i and ending with j
        for (int j=i+1; j<n; j++)
        {
            // Update min and max in this subarray if needed
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);

            // If current subarray has all contiguous elements
            if ((mx - mn) == j-i)
                max_len = max(max_len, mx-mn+1);
        }

    }
    return max_len;  // Return result
}

// Driver program to test above function
int main()
{
    int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of the longest contiguous subarray is "
         << findLength(arr, n)<<endl;

    int arr1[] = {14, 12, 11, 20};
     n = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Length of the longest contiguous subarray is "
         << findLength(arr1, n)<<endl;

    int arr2[] = {9, 12, 11};
    n = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Length of the longest contiguous subarray is "
         << findLength(arr2, n)<<endl;

    return 0;
}
