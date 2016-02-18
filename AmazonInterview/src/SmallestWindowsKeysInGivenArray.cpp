/*
 * Test10.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: chintan
 */
#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include "require.h"
using namespace std;

bool validate(map<int, int> & map){

	for(std::map<int, int>::iterator it = map.begin(); it != map.end(); it++){
		if(it->second < 1){
			return false;
		}
	}

	return true;
}

vector<int> smallestWindow(vector<int> input, vector<int> keys){

	map<int, int> map;
	vector<int> result;

	for(unsigned int i = 0; i < keys.size(); i++){
		map.insert(std::make_pair(keys[i], 0));
	}

	unsigned int left =0, right = 0;

	unsigned int len = INT_MAX;
	int l=0, r=0;

	while(right < input.size()){

		// push a number to the window
		if(map.find(input[right]) != map.end()){
			map[input[right]]++;

			// remove a number from the window until the window is invalid
			while(validate(map)){
				if(right - left < len){
					len = right - left;
					r = right;
					l = left;
				}

				if(map.find(input[left]) != map.end()){
					map[input[left]]--;
				}
				left++;
			}
		}

		right++;
	}

	for(int i = l; i <= r;i++){
	    result.push_back(input[i]);
    }

	return result;
}

int main(){

	int myInts[] = { 6, 7, 1, 3, 2, 4, 5, 2, 3, 1, 2, 5 };
	std::vector<int>input(myInts, myInts + sizeof(myInts) / sizeof(int) );
	printArray2(input,input.size());

	int myKeyInts [] = { 2, 5, 1 };
	std::vector<int>keys(myKeyInts, myKeyInts + sizeof(myKeyInts) / sizeof(int) );
	printArray2(keys,keys.size());
	vector<int> result = smallestWindow(input, keys);
	printArray2(result,result.size());
	return 0;
}



