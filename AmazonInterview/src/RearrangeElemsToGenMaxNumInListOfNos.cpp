/*
 * Test15.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: chintan
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "require.h"

using namespace std;

#define MOD_STATE 0

int getFirstDigit(int num){

	while(num >=10){
		num = num/10;
	}
	return num;
}


struct myGreater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

/*
 * Inserting elements into the map in descending order based on the
 * first digit as keys. Also the values would be actual values.
 * If the first digits are same. Will sort all the elements based on
 * descending order again.
 */

void maxNumFromGroupOfNumber(std::vector<int>vec){

	std::map<int,std::vector<int>, std::greater<int> >table;
	std::map<int,std::vector<int> >::iterator tableItr;

	for(unsigned int i=0;i<vec.size();i++){
		int firstDigit = getFirstDigit(vec[i]);
		tableItr = table.find(firstDigit);
		// first time the key is being inserted
		if(tableItr == table.end()){
			table[firstDigit].push_back(vec[i]);
			//table.insert(std::make_pair(firstDigit,vec[i]));
		}else{
			tableItr->second.push_back(vec[i]);
		}

	}

	for(tableItr = table.begin(); tableItr != table.end(); tableItr++){
		//cout<<tableItr->first<<endl;
		std::sort(tableItr->second.begin(), tableItr->second.end(),myGreater());
		printArray2(tableItr->second,tableItr->second.size());
	}
	cout<<endl;
}

int main(){

	{
		int myInts[] = {54, 546, 548, 60};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		maxNumFromGroupOfNumber(arr1);
	}

	{
		int myInts[] = {2,4,8,2,4,8,8,56};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		maxNumFromGroupOfNumber(arr1);
	}
	return 0;

}

/*
 * Another Soln
 *
 * Just sort the numbers in reverse lexicographic order.
 * (Think of them as strings and sort them descending).

 *
 */


