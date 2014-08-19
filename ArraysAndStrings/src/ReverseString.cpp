/*
 * reverseString.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: cvora
 */

// Coding Interview questions Solution 1.2

#include <iostream>

using namespace std;

void reverseSol1(char* str){
	char* end = str;
	char temp;
	if(str){
		while(*end)// find end of string
			end++;
		--end; // set one char back, since last char is null

		// swap chars from start of string with end of the string, until pointers meet in the middle.
		while(str<end){
			temp = *str;
			*str++ = *end;
			*end-- = temp;
		}
	}
}

int main(){

	string str = "hello world";
	reverseSol1((char*)str.c_str());
	cout<<str<<endl;

	return 0;
}
