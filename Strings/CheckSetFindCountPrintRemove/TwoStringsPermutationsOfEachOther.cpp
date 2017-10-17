/*
 * TwoStringsPermutationsOfEachOther.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: chivora
 */

#include <iostream>
#include <map>
#include <bitset>
#include <string>         // std::string
#include <bits/stdc++.h>
#include <algorithm>

/*
 * Hint:
 * 1: Hash Table
 * 2:
 */

using namespace std;
#define NUM_CHARS 255

bool checkIfPermutationsOfEachOther(string str1,string str2){
	std::map<char,int> mymap;
    std::map<char,int>::iterator it;

    if(str1.length() != str2.length()){
    	return false;
    }
	for(unsigned int i=0;i<str1.length();i++){
		mymap[str1[i]]++;
		mymap[str2[i]]--;
	}
	for(it=mymap.begin();it!=mymap.end();it++){
		if(it->second != 0){
			return false;
		}
	}
	return true;
}

bool checkIfPermutationsOfEachOther2(string str1,string str2){
	std::sort(str1.begin(),str1.end());
	std::sort(str2.begin(),str2.end());
	return str1.compare(str2) == 0;
}

int main(){
	cout<<checkIfPermutationsOfEachOther("Hello","Hello")<<endl;
	cout<<checkIfPermutationsOfEachOther("Hello","HelloWorld")<<endl;
	cout<<checkIfPermutationsOfEachOther2("Hello","Hello")<<endl;
	cout<<checkIfPermutationsOfEachOther2("Hello","HelloWorld")<<endl;
}

