/*
 * Test5.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: chintan
 */
/*
 * Given an array, find the first element that appears an even number of times.
 */

#include<iostream>
#include<vector>
#include<map>
#include "require.h"

using namespace std;

int findFirstElementWithEvenCounts(vector<int>arr){
	int firstElemWithEvenCount = -1;
	std::map<int,int>ElementCounter;
	std::map<int,int>::iterator ElementCounterItr;
	int initCount = 1;
	for(unsigned int i=0;i<arr.size();i++){
		//element is present in map
		if(ElementCounter.find(arr[i]) != ElementCounter.end()){
			ElementCounter.at(arr[i]) += 1;
		}else{// first entry of element in map
			ElementCounter.insert ( std::pair<int,int>(arr[i],initCount) );
		}
	}
	for(unsigned int i=0;i<arr.size();i++){
		if((ElementCounter.at(arr[i]) % 2 ) == 0){
			firstElemWithEvenCount = arr[i];
			break;
		}
	}

	return firstElemWithEvenCount;
}


int main(){

	/*
	 * TEST 1
	 * Mid-Pt is missing
	 */
	{
		int myInts[] = {2,4,8,2,10,12,10,14};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		std::cout<<"FirstElementWithEvenCounts is: "<<findFirstElementWithEvenCounts(arr1)<<std::endl;
	}


	return 0;
}

