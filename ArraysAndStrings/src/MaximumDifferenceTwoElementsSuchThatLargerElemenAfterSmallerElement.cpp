/*
 * MaximumDifferenceTwoElementsSuchThatLargerElemenAfterSmallerElement.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: cvora
 */
/*
 * Maximum difference between two elements such that larger element appears after the smaller number
Given an array arr[] of integers, find out the difference between any two elements such that larger
element appears after the smaller number in arr[].

Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2).
If array is [ 7, 9, 5, 6, 3, 2 ] then returned value should be 2 (Diff between 7 and 9)

Method 1 (Simple)
Use two loops. In the outer loop, pick elements one by one and in the inner loop calculate the
difference of the picked element with every other element in the array and compare the difference
with the maximum difference calculated so far.
 */
#include<stdio.h>
#include <exception>      // std::exception

/* The function assumes that there are at least two
   elements in array.
   The function returns a negative value if the array is
   sorted in decreasing order.
   Returns 0 if elements are equal */
int maxDiffSol1(int arr[], int arr_size)
{
  int max_diff = arr[1] - arr[0];
  int i, j;
  for(i = 0; i < arr_size; i++)
  {
    for(j = i+1; j < arr_size; j++)
    {
      if(arr[j] - arr[i] > max_diff)
         max_diff = arr[j] - arr[i];
    }
  }
  return max_diff;
}

/*
 * Method 2 (Tricky and Efficient)
 * In this method, instead of taking difference of the picked element with every other element,
 * we take the difference with the minimum element found so far. So we need to keep track of 2 things:
 * 1) Maximum difference found so far (max_diff).
 * 2) Minimum number visited so far (min_element).
 */

/* The function assumes that there are at least two
   elements in array.
   The function returns a negative value if the array is
   sorted in decreasing order.
   Returns 0 if elements are equal  */
int maxDiffSol2(int arr[], int arr_size)
{
  int max_diff = arr[1] - arr[0];
  int min_element = arr[0];
  int i;
  for(i = 1; i < arr_size; i++)
  {
    if(arr[i] - min_element > max_diff)
      max_diff = arr[i] - min_element;
    if(arr[i] < min_element)
         min_element = arr[i];
  }
  return max_diff;
}

/* Driver program to test above function */
int main(){

	try {
		int arr[] = {1, 2, 6, 80, 100};
		int size = sizeof(arr)/sizeof(arr[0]);
		printf("Maximum difference is %d \n",  maxDiffSol1(arr, size));
	} catch (std::exception &e) {
	}

	try {
		int arr[] = {1, 2, 6, 80, 100};
		int size = sizeof(arr)/sizeof(arr[0]);
		printf("Maximum difference is %d \n",  maxDiffSol2(arr, size));
	} catch (std::exception &e) {
	}

  return 0;
}
