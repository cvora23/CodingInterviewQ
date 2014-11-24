/*
 * FindFixedPointInGivenArray.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: cvora
 */

/*
 * Find a Fixed Point in a given array
Given an array of n distinct integers sorted in ascending order, write a function that returns a
Fixed Point in the array, if there is any Fixed Point present in array, else returns -1.
Fixed Point in an array is an index i such that arr[i] is equal to i.
Note that integers in array can be negative.

Examples:

  Input: arr[] = {-10, -5, 0, 3, 7}
  Output: 3  // arr[3] == 3

  Input: arr[] = {0, 2, 5, 8, 17}
  Output: 0  // arr[0] == 0


  Input: arr[] = {-10, -5, 3, 4, 7, 9}
  Output: -1  // No Fixed Point
 */

#include <stdio.h>
/*
 * Method 1 (Linear Search)
Linearly search for an index i such that arr[i] == i. Return the first such index found.
 */

int linearSearch(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == i)
            return i;
    }

    /* If no fixed point present then return -1 */
    return -1;
}

/*
 * Method 2 (Binary Search)
First check whether middle element is Fixed Point or not. If it is, then return it; otherwise check
whether index of middle element is greater than value at the index. If index is greater, then Fixed
Point(s) lies on the right side of the middle point (obviously only if there is a Fixed Point).
Else the Fixed Point(s) lies on left side.
 */

int binarySearch(int arr[], int low, int high)
{
    if(high >= low)
    {
        int mid = (low + high)/2;  /*low + (high - low)/2;*/
        if(mid == arr[mid])
            return mid;
        if(mid > arr[mid])
            return binarySearch(arr, (mid + 1), high);
        else
            return binarySearch(arr, low, (mid -1));
    }

    /* Return -1 if there is no Fixed Point */
    return -1;
}

/* Driver program to check above functions */
int main()
{
    int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Fixed Point is %d \n", linearSearch(arr,n));
    printf("Fixed Point is %d \n", binarySearch(arr, 0, n-1));
    getchar();
    return 0;
}
