/*
 * Anagrams.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: cvora
 */

// Coding Interview questions Solution 1.3

#include <iostream>
#include <algorithm>

using namespace std;

bool isAnagramSol1(string s1,string s2){
	if(s1.length() != s2.length()){
		return false;
	}
	std::sort(s1.begin(),s1.end());
	std::sort(s2.begin(),s2.end());

	return s1 == s2;
}

bool isAnagramSol2(string s1,string s2){
	if(s1.length() != s2.length()){
		return false;
	}
	int *letters = new int[256];
	for(unsigned int i=0;i<s1.length();i++){
		letters[s1.at(i)]++;
	}
	for(unsigned int i=0;i<s2.length();i++){
		if(--letters[s2.at(i)]){
			return false;
		}
	}
	return true;
}

int main(){

	cout<<isAnagramSol1("God","dog")<<endl;
	cout<<isAnagramSol1("God","doG")<<endl;

	cout<<isAnagramSol2("God","dog")<<endl;
	cout<<isAnagramSol2("God","doG")<<endl;

	return 0;
}


