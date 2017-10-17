/*
 * OneAway.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: chivora
 */

#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

/*
 * One Away: There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit (or zero edits) away.
EXAMPLE
pale, pIe -> true pales, pale -> true pale, bale -> true pale. bake -> false
 */

bool isOneAway(string str1,string str2){
	unsigned int str1_len,str2_len;
	str1_len = str1.length();
	str2_len = str2.length();
	if(std::abs(int(str1_len-str2_len)) > 1){
		return false;
	}
	// swap str1_len,str2_len if str1_len < str2_len and swap str1 and str2 also
	if(str1_len < str2_len){
		int temp = str1_len;
		str1_len = str2_len;
		str2_len = temp;
		swap(str1,str2);
	}

	int oneAway = 0;
	for(unsigned int i=0,j=0;(i<str1_len || j<str2_len);i++,j++){
		if(str1[i] != str2[j] && str1_len > str2_len){
			oneAway++;
			j--;
		}else if(str1[i] != str2[j]){
			oneAway++;
		}
	}
	if(oneAway > 1){
		return false;
	}
	return true;
}


int main(){

	cout<<isOneAway("pale","ple")<<endl;
	cout<<isOneAway("pales","pale")<<endl;
	cout<<isOneAway("pale","bale")<<endl;
	cout<<isOneAway("pale","bake")<<endl;
	cout<<isOneAway("aple","ple")<<endl;
	cout<<isOneAway("ple","pale")<<endl;
	return 0;

}


