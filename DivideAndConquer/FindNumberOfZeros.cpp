/*
 * FindNumberOfZeros.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: cvora
 */

/*
 * Find the number of zeroes
Given an array of 1s and 0s which has all 1s first followed by all 0s. Find the number of 0s.
Count the number of zeroes in the given array.

Examples:

Input: arr[] = {1, 1, 1, 1, 0, 0}
Output: 2

Input: arr[] = {1, 0, 0, 0, 0}
Output: 4

Input: arr[] = {0, 0, 0}
Output: 3

Input: arr[] = {1, 1, 1, 1}
Output: 0
We strongly recommend to minimize the browser and try this yourself in time complexity better than O(n).

A simple solution is to traverse the input array. As soon as we find a 0, we return n – index of first 0.
Here n is number of elements in input array. Time complexity of this solution would be O(n).

Since the input array is sorted, we can use Binary Search to find the first occurrence of 0.
Once we have index of first element, we can return count as n – index of first zero.
 */

// A divide and conquer solution to find count of zeroes in an array
// where all 1s are present before all 0s
#include <stdio.h>

/* if 0 is present in arr[] then returns the index of FIRST occurrence
   of 0 in arr[low..high], otherwise returns -1 */
int firstZero(int arr[], int low, int high)
{
    if (high >= low)
    {
        // Check if mid element is first 0
        int mid = low + (high - low)/2;
        if (( mid == 0 || arr[mid-1] == 1) && arr[mid] == 0)
            return mid;

        if (arr[mid] == 1)  // If mid element is not 0 but 1 then element must be on right hand side
            return firstZero(arr, (mid + 1), high);
        else  // If mid element is 0, but not first 0 then element must be on left hand side
            return firstZero(arr, low, (mid -1));
    }
    return -1;
}

// A wrapper over recursive function firstZero()
int countZeros(int arr[], int n)
{
    // Find index of first zero in given array
    int first = firstZero(arr, 0, n-1);

    // If 0 is not present at all, return 0
    if (first == -1)
        return 0;

    return (n - first);
}

/* Driver program to check above functions */
int main()
{
	{
		int arr[] =   {1, 1, 1, 0, 0, 0, 0, 0};
		int n = sizeof(arr)/sizeof(arr[0]);
		printf("Count of zeroes is %d \n", countZeros(arr, n));
	}
	{
		int arr[] =   {1, 0, 0, 0, 0};
		int n = sizeof(arr)/sizeof(arr[0]);
		printf("Count of zeroes is %d \n", countZeros(arr, n));
	}
	{
		int arr[] =   {0, 0, 0};
		int n = sizeof(arr)/sizeof(arr[0]);
		printf("Count of zeroes is %d \n", countZeros(arr, n));
	}
	{
		int arr[] =  {1, 1, 1, 1};
		int n = sizeof(arr)/sizeof(arr[0]);
		printf("Count of zeroes is %d \n", countZeros(arr, n));
	}
    return 0;
}

