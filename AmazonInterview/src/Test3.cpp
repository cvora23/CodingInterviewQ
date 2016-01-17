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



