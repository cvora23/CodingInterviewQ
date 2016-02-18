/*
 * Test17.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: chintan
 */

#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include "require.h"
using namespace std;

bool validate(map<string, int> & map){

	for(std::map<string, int>::iterator it = map.begin(); it != map.end(); it++){
		if(it->second < 1){
			return false;
		}
	}

	return true;
}

vector<string> smallestWindow(vector<string> input, vector<string> keys){

	map<string, int> map;
	vector<string> result;

	for(unsigned int i = 0; i < keys.size(); i++){
		map.insert(std::make_pair(keys[i], 0));
	}

	unsigned int left, right;
	left = right = 0;

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
	std::vector<string>input;
	string myStr[6] = {"the", "brown", "quick", "frog", "hello", "the"};
	for(int i=0;i<6;i++){
		input.push_back(myStr[i]);
	}
	printArray2(input,input.size());

	string myKeyStrs [2] = {"the", "quick" };
	std::vector<string>keys;
	for(int i=0;i<2;i++){
		keys.push_back(myKeyStrs[i]);
	}

	printArray2(keys,keys.size());
	vector<string> result = smallestWindow(input, keys);
	printArray2(result,result.size());
	return 0;
}




