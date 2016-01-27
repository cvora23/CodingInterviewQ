/*
 * Test30.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: chintan
 */

/*
 *
Given two strings, return true if they are one edit away from each other,
else return false. An edit is insert/replace/delete a character.
Ex. {"abc","ab"}->true, {"abc","adc"}->true, {"abc","cab"}->false
 *
 */

#include <string>
#include <iostream>

using namespace std;

bool isOneEditPossible(std::string str1,std::string str2){
	unsigned int len1 = str1.length(),len2 = str2.length();

	int lenDifference = 0;
	if(len1>len2){
		lenDifference = len1-len2;
	}else{
		lenDifference = len2-len1;
	}
	/*
	 * if difference between length of string is more than 2
	 * one edit is not possible. return false.
	 */
	if(lenDifference>2){
		return false;
	}else if(lenDifference == 1){
		/*
		 * Check if insertion/deletion is possible for one edit
		 */
		/*
		 * check if smaller string is substring of bigger string
		 */
		if(len1<len2){
			if(str2.find(str1) != std::string::npos){
				return true;
			}else{
				return false;
			}
		}else{
			if(str1.find(str2) != std::string::npos){
				return true;
			}else{
				return false;
			}
		}
	}else if(lenDifference == 0){
		/*
		 * check if replace is possible.
		 */
		int replaceCount = 0;
		for(unsigned int i=0;i<len1;i++){
			if(str1[i] != str2[i]){
				replaceCount++;
			}
		}
		if(replaceCount>1){
			return false;
		}else{
			return true;
		}
	}
	return false;
}

int main(){

	std::cout<<isOneEditPossible("abc","ab")<<std::endl;
	std::cout<<isOneEditPossible("abc","adc")<<std::endl;
	std::cout<<isOneEditPossible("abc","cab")<<std::endl;

	return 0;

}
