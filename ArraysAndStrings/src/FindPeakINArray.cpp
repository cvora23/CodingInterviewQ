/*
 * FindPeakINArray.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: cvora
 */

/*
 * Find a peak element
Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors.
For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element.
For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. Note that we need to return any one peak element.

Following corner cases give better idea about the problem.
1) If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
2) If input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
3) If all elements of input array are same, every element is a peak element.

It is clear from above examples that there is always a peak element in input array in any input array.

A simple solution is to do a linear scan of array and as soon as we find a peak element, we return it.
The worst case time complexity of this method would be O(n).
 */



/*
 * Can we find a peak element in worst time complexity better than O(n)?
 * We can use Divide and Conquer to find a peak in O(Logn) time.
 * The idea is Binary Search based, we compare middle element with its neighbors.
 * If middle element is greater than both of its neighbors, then we return it.
 * If the middle element is smaller than the its left neighbor, then there is always a peak in left half (Why? take few examples).
 * If the middle element is smaller than the its right neighbor, then there is always a peak in right half
 * (due to same reason as left half). Following is C implementation of this approach.
 */

// A divide and conquer solution to find a peak element element
#include <stdio.h>

// A binary search based function that returns index of a peak element
int findPeakUtil(int arr[], int low, int high, int n)
{
    // Fin index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */

    // Compare middle element with its neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;

    // If middle element is not peak and its left neighbor is greater than it
    // then left half must have a peak element
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), n);

    // If middle element is not peak and its right neighbor is greater than it
    // then right half must have a peak element
    else return findPeakUtil(arr, (mid + 1), high, n);
}

// A wrapper over recursive function findPeakUtil()
int findPeak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n-1, n);
}

/* Driver program to check above functions */
int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Index of a peak point is %d", findPeak(arr, n));
    return 0;
}
