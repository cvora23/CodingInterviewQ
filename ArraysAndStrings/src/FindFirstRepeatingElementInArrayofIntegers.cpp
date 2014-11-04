/*
 * FindFirstRepeatingElementInArrayofIntegers.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: cvora
 */

/*
 * Find the first repeating element in an array of integers
 * Given an array of integers, find the first repeating element in it.
 * We need to find the element that occurs more than once and whose index of first occurrence is smallest.

Examples:

Input:  arr[] = {10, 5, 3, 4, 3, 5, 6}
Output: 5 [5 is the first element that repeats]

Input:  arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
Output: 6 [6 is the first element that repeats]

A Simple Solution is to use two nested loops. The outer loop picks an element one by one,
the inner loop checks whether the element is repeated or not. Once we find an element
that repeats, we break the loops and print the element. Time Complexity of this solution is O(n2)

We can Use Sorting to solve the problem in O(nLogn) time. Following are detailed steps.
1) Copy the given array to an auxiliary array temp[].
2) Sort the temp array using a O(nLogn) time sorting algorithm.
3) Scan the input array from left to right. For every element, count its occurrences in temp[]
   using binary search. As soon as we find an element that occurs more than once, we return the element.
This step can be done in O(nLogn) time.
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include "require.h"

using namespace std;

/* if x is present in arr[] then returns the index of FIRST occurrence
   of x in arr[0..n-1], otherwise returns -1 */
int first(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
      return mid;
    else if(x > arr[mid])
      return first(arr, (mid + 1), high, x, n);
    else
      return first(arr, low, (mid -1), x, n);
  }
  return -1;
}


/* if x is present in arr[] then returns the index of LAST occurrence
   of x in arr[0..n-1], otherwise returns -1 */
int last(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
      return mid;
    else if(x < arr[mid])
      return last(arr, low, (mid -1), x, n);
    else
      return last(arr, (mid + 1), high, x, n);
  }
  return -1;
}



/* if x is present in arr[] then returns the count of occurrences of x,
   otherwise returns -1. */
int count(int arr[], int x, int n)
{
  int i; // index of first occurrence of x in arr[0..n-1]
  int j; // index of last occurrence of x in arr[0..n-1]

  /* get the index of first occurrence of x */
  i = first(arr, 0, n-1, x, n);

  /* If x doesn't exist in arr[] then return -1 */
  if(i == -1)
    return i;

  /* Else get the index of last occurrence of x. Note that we
      are only looking in the subarray after first occurrence */
  j = last(arr, i, n-1, x, n);

  /* return count */
  return j-i+1;
}

void printFirstRepeating(int arr[],int size){
	std::vector<int> myVector(arr,arr+size);
	std::sort(myVector.begin(),myVector.end());
	printArray2(myVector,size);

	int temp[size] ;

	for(int i=0;i<size;i++){
		temp[i] = myVector[i];
	}

	int index = -1;
	int counter = 0;

	for(int i=0;i<size;i++){
		counter = count(temp,arr[i],size);
		if(counter > 1){
			index = i;
			break;
		}
	}
	if(index != -1)
		cout<<"First repeating element is "<<arr[index]<<endl;
}


int main(){
	int arr[] = {10, 5, 3, 4, 3, 5, 6};
	        printFirstRepeating(arr,sizeof(arr)/sizeof(arr[0]));
}
