/*
 * MinJumps.cpp
 *
 *  Created on: Feb 7, 2018
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
 * Minimum number of jumps to reach end
Given an array of integers where each element represents the max number of steps that can be made forward from that element.
Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
If an element is 0, then cannot move through that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)
First element is 1, so can only go to 3. Second element is 3, so can make at most 3 steps eg to 5 or 8 or 9.

Method 1 (Naive Recursive Approach)
A naive approach is to start from the first element and recursively call for all the elements reachable from first element.
The minimum number of jumps to reach end from first can be calculated using minimum number of jumps needed to reach end from
the elements reachable from first.

minJumps(start, end) = Min ( minJumps(k, end) ) for all k reachable from start
 */

namespace Recursion{

	// Returns minimum number of jumps to reach arr[h] from arr[l]
	int minJumps(int arr[], int l, int h)
	{
	   // Base case: when source and destination are same
	   if (h == l)
		 return 0;

	   // When nothing is reachable from the given source
	   if (arr[l] == 0)
		 return INT_MAX;

	   // Traverse through all the points reachable from arr[l]. Recursively
	   // get the minimum number of jumps needed to reach arr[h] from these
	   // reachable points.
	   int min = INT_MAX;
	   for (int i = l+1; i <= h && i <= l + arr[l]; i++)
	   {
		   int jumps = minJumps(arr, i, h);
		   if(jumps != INT_MAX && jumps + 1 < min)
			   min = jumps + 1;
	   }

	   return min;
	}

}

/*
 *If we trace the execution of this method, we can see that there will be overlapping subproblems.
 *If For example, minJumps(3, 9) will be called two times as arr[3] is reachable from arr[1] and arr[2].
 *If So this problem has both properties (optimal substructure and overlapping subproblems) of Dynamic Programming.
 */

/*
 * Method 2 (Dynamic Programming)
In this method, we build a jumps[] array from left to right such that jumps[i] indicates the minimum number
of jumps needed to reach arr[i] from arr[0]. Finally, we return jumps[n-1].

Time Complexity: O(n^2)

 */

namespace DP{

	int min(int x, int y) { return (x < y)? x: y; }

	// Returns minimum number of jumps to reach arr[n-1] from arr[0]
	int minJumps(int arr[], int n)
	{
		int *jumps = new int[n];  // jumps[n-1] will hold the result
		int i, j;

		if (n == 0 || arr[0] == 0)
			return INT_MAX;

		jumps[0] = 0;

		// Find the minimum number of jumps to reach arr[i]
		// from arr[0], and assign this value to jumps[i]
		for (i = 1; i < n; i++)
		{
			jumps[i] = INT_MAX;
			for (j = 0; j < i; j++)
			{
				if (i <= j + arr[j] && jumps[j] != INT_MAX)
				{
					 jumps[i] = min(jumps[i], jumps[j] + 1);
					 break;
				}
			}
		}
		return jumps[n-1];
	}
}

int main(){

	{
	  int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	  int n = sizeof(arr)/sizeof(arr[0]);
	  printf("Minimum number of jumps to reach end is %d \n", Recursion::minJumps(arr, 0, n-1));
	}

	return 0;

}
