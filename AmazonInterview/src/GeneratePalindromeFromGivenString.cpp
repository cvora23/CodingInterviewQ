/*
 * Test28.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: chintan
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string generatePalindromeIfPossible(string ipStr){
	string retVal;
	ostringstream convert;   // stream used for the conversion
	char charSet[256] = {0};
	vector<char>oddCharSet;
	//count occurences of each character in the string
	for(unsigned int i=0;i<ipStr.size();i++){
		//std::cout<<ipStr[i]<<endl;
		charSet[ipStr[i]]++;
	}
	// iterate from the 'a' to the 'z' counts and add half of the count of each character to the string.
	// if the character has an odd count, remember it. If there were other characters with an odd count,
	// then there isn't a palindrome so return null;
	for(unsigned int i=0;i<256;i++){
		if(charSet[i]%2 == 1)
			oddCharSet.push_back(i);
		if(oddCharSet.size()>1){
			return "Palindrome Not Possible";
		}
		for(int j=0;j<charSet[i]/2;j++){
			convert << (char)i;
			retVal += convert.str();
			// clearing up old buffer, setting up new buffer
			convert.str("");
		}
	}
	convert.str("");
	// If any odd characters, add it now
	retVal += oddCharSet[0];

	// Iterate from the 'z' to the 'a' counts and add half the count of each character to the string
	for(int i=255;i>=0;i--){
		for(int j=0;j<charSet[i]/2;j++){
			convert << (char)i;
			retVal += convert.str();
			convert.str("");
		}
	}

	//cout<<retVal.size();

	return retVal;
}

int main(){


	cout<<generatePalindromeIfPossible("Hello")<<endl;
	cout<<generatePalindromeIfPossible("ddd")<<endl;
	cout<<generatePalindromeIfPossible("wjee")<<endl;
	cout<<generatePalindromeIfPossible("fjff")<<endl;
	cout<<generatePalindromeIfPossible("rrrraaffttt")<<endl;

	return 0;
}


