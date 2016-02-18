/*
 * Test3.cpp
 *
 *  Created on: Jan 16, 2016
 *      Author: chintan
 */
/*
 * Find missing element in the A.P.
 */

#include "require.h"
#include <iostream>
#include <vector>

int findMissingElementAP(std::vector<int>elements,int low,int high){

	if(low<=high){
		int mid = (high+low)/2;
		// Only One/Two Elements left
		//Everything is Good
		if(mid == 0){
			return -1;
		}
		// If Mid-pt is the Mis-fit element
		else if(((elements[mid]-elements[mid-1]) != (elements[mid+1]-elements[mid]))){
			if((elements[mid]-elements[mid-1]) > (elements[mid+1]-elements[mid])){
				return elements[mid-1] + (elements[mid+1]-elements[mid]);
			}else{
				return elements[mid] + elements[mid]-elements[mid-1];
			}
		}
		// Go on the left side
		else if(((elements[mid]-elements[low])/(mid-low)) > ((elements[high]-elements[mid])/(high-mid))){
			return findMissingElementAP(elements,low,mid);
		}
		// Go on the right side
		else if(((elements[mid]-elements[low])/(mid-low)) < ((elements[high]-elements[mid])/(high-mid))){
			return findMissingElementAP(elements,mid,high);
		}
		// Everything is good
		else{
			return -1;
		}
	}
	// Everything is good
	else{
		return -1;
	}
}

int findMissingElementAPExt(std::vector<int>elements,int low,int high){
	return findMissingElementAP(elements,low,high-1);
}

// A C program to find the missing number in a given
// arithmetic progression
#include <stdio.h>
#include <limits.h>

// Geeks for Geeks Version of the same problem.

// A binary search based recursive function that returns
// the missing element in arithmetic progression
int findMissingUtil(int arr[], int low, int high, int diff)
{
    // There must be two elements to find the missing
    if (high <= low)
        return INT_MAX;

    // Find index of middle element
    int mid = low + (high - low)/2;

    // The element just after the middle element is missing.
    // The arr[mid+1] must exist, because we return when
    // (low == high) and take floor of (high-low)/2
    if (arr[mid+1] - arr[mid] != diff)
        return (arr[mid] + diff);

    // The element just before mid is missing
    if (mid > 0 && arr[mid] - arr[mid-1] != diff)
        return (arr[mid-1] + diff);

    // If the elements till mid follow AP, then recur
    // for right half
    if (arr[mid] == arr[0] + mid*diff)
        return findMissingUtil(arr, mid+1, high, diff);

    // Else recur for left half
    return findMissingUtil(arr, low, mid-1, diff);
}

// The function uses findMissingUtil() to find the missing
// element in AP.  It assumes that there is exactly one missing
// element and may give incorrect result when there is no missing
// element or more than one missing elements.
// This function also assumes that the difference in AP is an
// integer.
int findMissing(int arr[], int n)
{
    // If exactly one element is missing, then we can find
    // difference of arithmetic progression using following
    // formula.  Example, 2, 4, 6, 10, diff = (10-2)/4 = 2.
    // The assumption in formula is that the difference is
    // an integer.
    int diff = (arr[n-1] - arr[0])/n;

    // Binary search for the missing number using above
    // calculated diff
    return findMissingUtil(arr, 0, n-1, diff);
}

int main(){

	/*
	 * TEST 1
	 * Mid-Pt is missing
	 */
	{
		int myInts[] = {2,4,8,10,12,14};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		std::cout<<"Missing Elements in AP is: "<<findMissingElementAPExt(arr1,0,arr1.size())<<std::endl;
	}
	/*
	 * TEST 2
	 * Missing element is on left
	 */
	{
		int myInts[] = {2,6,8,10,12,14};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		std::cout<<"Missing Elements in AP is: "<<findMissingElementAPExt(arr1,0,arr1.size())<<std::endl;
	}
	/*
	 * TEST 3
	 * Missing element is on right
	 */
	{
		int myInts[] = {1,6,11,16,21,31};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		std::cout<<"Missing Elements in AP is: "<<findMissingElementAPExt(arr1,0,arr1.size())<<std::endl;
	}
	/*
	 * TEST 4
	 * Missing element is on right
	 */
	{
		int myInts[] = {1,6,16};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		std::cout<<"Missing Elements in AP is: "<<findMissingElementAPExt(arr1,0,arr1.size())<<std::endl;
	}
	/*
	 * TEST 5
	 * Everything is good
	 */
	{
		int myInts[] = {1,6,11};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		std::cout<<"Missing Elements in AP is: "<<findMissingElementAPExt(arr1,0,arr1.size())<<std::endl;
	}
	return 0;
}



