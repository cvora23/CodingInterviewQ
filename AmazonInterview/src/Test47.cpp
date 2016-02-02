/*
 * Test47.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: chintan
 */

/*
 * given an integer array , find all combinations which sum to a given number.
 * If a number is used once, it must not be used again.
eg if input array is 6444 and sum =10
output must be just 6 4
Give an O(n) solution
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "require.h"

using namespace std;

void printAllCombinations(std::vector<int>arr,int sum){
	std::map<int,int>hashMap;
	std::map<int,int>::iterator hashMapItr;

	std::set<int>hashSet;
	std::set<int>::iterator hashSetItr;

	for(unsigned int i=0;i<arr.size();i++){
		// if not repeated element
		hashSetItr = hashSet.find(arr[i]);
		if(hashSetItr == hashSet.end()){
			hashSet.insert(arr[i]);
			hashMapItr = hashMap.find(arr[i]);
			if(hashMapItr != hashMap.end()){
				cout<<"Combination is "<<arr[i]<<" and "<<arr[hashMapItr->second]<<endl;
			}
			hashMap.insert(std::pair<int,int>(sum-arr[i],i));
		}
	}
}

int main(){

	{
		int myInts[] = {2,4,8,3,7,8,7,3};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		printAllCombinations(arr1,10);
	}

}

