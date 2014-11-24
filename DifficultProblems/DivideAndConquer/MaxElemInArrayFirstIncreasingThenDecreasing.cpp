/*
 * MaxElemInArrayFirstIncreasingThenDecreasing.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: cvora
 */

/*
 * Find the maximum element in an array which is first increasing and then decreasing
Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array.

Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
Output: 500

Input: arr[] = {1, 3, 50, 10, 9, 7, 6}
Output: 50

Corner case (No decreasing part)
Input: arr[] = {10, 20, 30, 40, 50}
Output: 50

Corner case (No increasing part)
Input: arr[] = {120, 100, 80, 20, 0}
Output: 120

*/


/*
Method 1 (Linear Search)
We can traverse the array and keep track of maximum and element. And finally return the maximum element.
*/

#include <stdio.h>

int findMaximumSol1(int arr[], int low, int high)
{
   int max = arr[low];
   int i;
   for (i = low; i <= high; i++)
   {
       if (arr[i] > max)
          max = arr[i];
   }
   return max;
}

/*
 *  Method 2 (Binary Search)
 *  We can modify the standard Binary Search algorithm for the given type of arrays.
 *  i) 	If the mid element is greater than both of its adjacent elements, then mid is the maximum.
 *  ii) If mid element is greater than its next element and smaller than the previous element then maximum lies
 *   	on left side of mid. Example array: {3, 50, 10, 9, 7, 6}
 *  iii)If mid element is smaller than its next element and greater than the previous element then maximum lies
 *  	on right side of mid. Example array: {2, 4, 6, 8, 10, 3, 1}
 */

int findMaximumSol2(int arr[], int low, int high)
{

   /* Base Case: Only one element is present in arr[low..high]*/
   if (low == high)
     return arr[low];

   /* If there are two elements and first is greater then
      the first element is maximum */
   if ((high == low + 1) && arr[low] >= arr[high])
      return arr[low];

   /* If there are two elements and second is greater then
      the second element is maximum */
   if ((high == low + 1) && arr[low] < arr[high])
      return arr[high];

   int mid = (low + high)/2;   /*low + (high - low)/2;*/

   /* If we reach a point where arr[mid] is greater than both of
     its adjacent elements arr[mid-1] and arr[mid+1], then arr[mid]
     is the maximum element*/
   if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
      return arr[mid];

   /* If arr[mid] is greater than the next element and smaller than the previous
    element then maximum lies on left side of mid */
   if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
     return findMaximumSol2(arr, low, mid-1);
   else // when arr[mid] is greater than arr[mid-1] and smaller than arr[mid+1]
     return findMaximumSol2(arr, mid + 1, high);
}


/* Driver program to check above functions */
int main()
{
   int arr[] = {1, 30, 40, 50, 60, 70, 23, 20};
   int n = sizeof(arr)/sizeof(arr[0]);
   printf("The maximum element is %d \n", findMaximumSol1(arr, 0, n-1));
   printf("The maximum element is %d \n", findMaximumSol2(arr, 0, n-1));
   getchar();
   return 0;
}
/*
Time Complexity: O(n)
 */


