/*
 * UniqueChars.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: cvora
 */

// Coding Interview questions Solution 1.1

#include <iostream>

using namespace std;


bool hasUniqueCharsSol1(string str){
	bool *char_set = new bool[256];
	for(unsigned int i=0;i<str.length();i++){
		int val = str.at(i);
		if(char_set[val]){ // Already found this char in string
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

bool hasUniqueCharsSol2(string str){
	int checker = 0;
	for(int i= 0;i<str.length();i++){
		int val = str.at(i) - 'a';
		if((checker & (1 << val)) > 0){
			return false;
		}
		checker |= (1<<val);
	}
	return true;
}

int main(){

	cout<<hasUniqueCharsSol1("Hello")<<endl;
	cout<<hasUniqueCharsSol1("World")<<endl;

	cout<<hasUniqueCharsSol2("Hello")<<endl;
	cout<<hasUniqueCharsSol2("World")<<endl;

}
