/*
 * Test8.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: chintan
 */

#include<iostream>
#include<vector>
#include<map>
#include "require.h"

/*
 * Find the first non-repeated element in an unsorted array
 */

int findFirsNonRepeatedElement(std::vector<int>& arr)
{
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
		if(ElementCounter.at(arr[i]) == 1){
			firstElemWithEvenCount = arr[i];
			break;
		}
	}

	return firstElemWithEvenCount;
}

int main(){

	{
		int myInts[] = {2,4,8,2,4,8,8,56};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		std::cout<<"Missing Elements in AP is: "<<findFirsNonRepeatedElement(arr1)<<std::endl;
	}

	return 0;

}


