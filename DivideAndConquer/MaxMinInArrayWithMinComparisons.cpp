/*
 * MaxMinInArrayWithMinComparisons.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: cvora
 */

/*
 * Maximum and minimum of an array using minimum number of comparisons
Write a C function to return minimum and maximum in an array. You program should make minimum number of comparisons.

First of all, how do we return multiple values from a C function? We can do it either using structures or pointers.

We have created a structure named pair (which contains min and max) to return multiple values.

struct pair
{
  int min;
  int max;
};
And the function declaration becomes: struct pair getMinMax(int arr[], int n) where arr[] is
the array of size n whose minimum and maximum are needed.
 */



/*
 * METHOD 1 (Simple Linear Search)
Initialize values of min and max as minimum and maximum of the first two
elements respectively. Starting from 3rd, compare each element with max and min,
and change max and min accordingly (i.e., if the element is smaller than min then
change min, else if the element is greater than max then change max, else ignore the element)
 */

/* structure is used to return two values from minMax() */
#include<stdio.h>
struct pair
{
  int min;
  int max;
};

struct pair getMinMaxSol1(int arr[], int n)
{
  struct pair minmax;
  int i;

  /*If there is only one element then return it as min and max both*/
  if (n == 1)
  {
     minmax.max = arr[0];
     minmax.min = arr[0];
     return minmax;
  }

  /* If there are more than one elements, then initialize min
      and max*/
  if (arr[0] > arr[1])
  {
      minmax.max = arr[0];
      minmax.min = arr[1];
  }
  else
  {
      minmax.max = arr[1];
      minmax.min = arr[0];
  }

  for (i = 2; i<n; i++)
  {
    if (arr[i] >  minmax.max)
      minmax.max = arr[i];

    else if (arr[i] <  minmax.min)
      minmax.min = arr[i];
  }

  return minmax;
}

/*
 * METHOD 2 (Tournament Method)
Divide the array into two parts and compare the maximums and minimums of the the two parts to get
the maximum and the minimum of the the whole array.

Pair MaxMin(array, array_size)
   if array_size = 1
      return element as both max and min
   else if arry_size = 2
      one comparison to determine max and min
      return that pair
   else    // array_size  > 2
      recur for max and min of left half
      recur for max and min of right half
      one comparison determines true max of the two candidates
      one comparison determines true min of the two candidates
      return the pair of max and min
 */

struct pair getMinMaxSol2(int arr[], int low, int high)
{
  struct pair minmax, mml, mmr;
  int mid;

  /* If there is only on element */
  if (low == high)
  {
     minmax.max = arr[low];
     minmax.min = arr[low];
     return minmax;
  }

  /* If there are two elements */
  if (high == low + 1)
  {
     if (arr[low] > arr[high])
     {
        minmax.max = arr[low];
        minmax.min = arr[high];
     }
     else
     {
        minmax.max = arr[high];
        minmax.min = arr[low];
     }
     return minmax;
  }

  /* If there are more than 2 elements */
  mid = (low + high)/2;
  mml = getMinMaxSol2(arr, low, mid);
  mmr = getMinMaxSol2(arr, mid+1, high);

  /* compare minimums of two parts*/
  if (mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;

  /* compare maximums of two parts*/
  if (mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;

  return minmax;
}

/* Driver program to test above function */
int main()
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arr_size = 6;
  struct pair minmax = getMinMaxSol1 (arr, arr_size);
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
  minmax = getMinMaxSol2 (arr, 0,arr_size-1);
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);

  getchar();
}
