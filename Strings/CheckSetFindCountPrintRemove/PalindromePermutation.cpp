/*
 * PalindromePermutation.cpp
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
 * Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin- drome.
 * A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters.The palindrome does not need to be limited to just dictionary words.
EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat". "atco cta". etc.)
 */

string delSpaces(string &str)
{
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

bool isPalindromePermutation(string ipString){
	string str = delSpaces(ipString);
	int str_length = str.length();
	map<char,int>charFreq;
	int required_pairs = str_length/2;
	int found_pairs = 0;
	for(unsigned int i=0;i<str.length();i++){
		charFreq[str[i]]++;
	}
	for(unsigned int i=0;i<str.length();i++){
		if(charFreq[str[i]]%2 == 0){
			found_pairs += 1;
		}
	}
	found_pairs = found_pairs/2;
	if(found_pairs != required_pairs){
		return false;
	}
	return true;
}

int main(){
	cout<<isPalindromePermutation("taco cat")<<endl;
	return 0;

}


