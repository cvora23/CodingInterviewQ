/*
 * UniqueChars.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: cvora
 */

// Coding Interview questions Solution 1.1
/**
 * Find if a string has all unique characters
 */

#include <iostream>

using namespace std;

/**
 * simple solution is to create an array of boolean values, where the flag at index i indicates
 * whether char i in alphabet is contained in string. If you run across this character a second
 * time, you can immediately return false.
 */
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

/**
 * we can reduce the space usage by factor of 8 by using a bit vector. We will assume
 * in the below code, that the string only uses the lower case letters a through z.
 * This will allow us to use just a single int.
 */
bool hasUniqueCharsSol2(string str){
	int checker = 0;
	for(unsigned int i= 0;i<str.length();i++){
		int val = str.at(i) - 'a';
		if((checker & (1 << val)) > 0){
			return false;
		}
		checker |= (1<<val);
	}
	return true;
}

/**
 * Alternate solution:
 * 1: Compare every char in string with every other char of string. this will take O(n2) time and O(1) space.
 * 2: If we are allowed to modify input string, we could sort the string in O(n log(n)) time and then linearly
 * check the string for neighboring chars that are identical. Many sorting algo might take up extra space though.
 */

int main(){

	cout<<"Initial Logging call"<<endl;

	cout<<hasUniqueCharsSol1("Hello")<<endl;
	cout<<hasUniqueCharsSol1("World")<<endl;

	cout<<hasUniqueCharsSol2("Hello")<<endl;
	cout<<hasUniqueCharsSol2("World")<<endl;

}
