/*
 * SmallestSubarrayWithSumGreaterThanGivenValue.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: cvora
 */

/*
 * Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.

Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}
 */

/*
 * A simple solution is to use two nested loops. The outer loop picks a starting element,
 * the inner loop considers all elements (on right side of current start) as ending element.
 * Whenever sum of elements between current start and end becomes more than the given number,
 * update the result if current length is smaller than the smallest length so far.
 * Following is C++ implementation of simple approach.
 * Time Complexity: Time complexity of the above approach is clearly O(n2).
 */

# include <iostream>
using namespace std;

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int smallestSubWithSumSol1(int arr[], int n, int x)
{
    //  Initilize length of smallest subarray as n+1
     int min_len = n + 1;

     // Pick every element as starting point
     for (int start=0; start<n; start++)
     {
          // Initialize sum starting with current start
          int curr_sum = arr[start];

          // If first element itself is greater
          if (curr_sum > x) return 1;

          // Try different ending points for current start
          for (int end=start+1; end<n; end++)
          {
              // add last element to current sum
              curr_sum += arr[end];

              // If sum becomes more than x and length of
              // this subarray is smaller than current smallest
              // length, update the smallest length (or result)
              if (curr_sum > x && (end - start + 1) < min_len)
                 min_len = (end - start + 1);
          }
     }
     return min_len;
}

/*
 * Efficient Solution: This problem can be solved in O(n) time
 */

// O(n) solution for finding smallest subarray with sum
// greater than x
#include <iostream>
using namespace std;

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int smallestSubWithSumSol2(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n+1;

    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n)
    {
        // Keep adding array elements while current sum
        // is smaller than x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];

        // If current sum becomes greater than x.
        while (curr_sum > x && start < n)
        {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;

            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}


/* Driver program to test above function */
int main()
{
	{
		int arr1[] = {1, 4, 45, 6, 10, 19};
		int x = 51;
		int n1 = sizeof(arr1)/sizeof(arr1[0]);
		cout << smallestSubWithSumSol1(arr1, n1, x) << endl;

		int arr2[] = {1, 10, 5, 2, 7};
		int n2 = sizeof(arr2)/sizeof(arr2[0]);
		x  = 9;
		cout << smallestSubWithSumSol1(arr2, n2, x) << endl;

		int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
		int n3 = sizeof(arr3)/sizeof(arr3[0]);
		x  = 280;
		cout << smallestSubWithSumSol1(arr3, n3, x)<< endl;
	}
	{
		int arr1[] = {1, 4, 45, 6, 10, 19};
		int x = 51;
		int n1 = sizeof(arr1)/sizeof(arr1[0]);
		cout << smallestSubWithSumSol2(arr1, n1, x) << endl;

		int arr2[] = {1, 10, 5, 2, 7};
		int n2 = sizeof(arr2)/sizeof(arr2[0]);
		x  = 9;
		cout << smallestSubWithSumSol2(arr2, n2, x) << endl;

		int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
		int n3 = sizeof(arr3)/sizeof(arr3[0]);
		x  = 280;
		cout << smallestSubWithSumSol2(arr3, n3, x)<< endl;
	}

    return 0;
}
