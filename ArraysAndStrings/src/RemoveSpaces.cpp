/*
 * RemoveSpaces.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: cvora
 */

// Coding Interview questions Solution 1.4

#include <iostream>
#include <string.h>

using namespace std;

// Assumes str has enough space to accomodate changes from spaces to %20 in string

void replaceSpacesSol1(char str[],int length){

	int spaceCount = 0,newLength,i;

	for(i=0;i<length;i++){
		if(str[i] == ' '){
			spaceCount++;
		}
	}

	cout<<"Space count = "<<spaceCount<<endl;
	newLength = length + spaceCount*2;
	str[newLength] = '\0';

	cout<<"NEW LENGTH = "<<newLength<<endl;

	for(i=length-1;i>=0;i--){
		if(str[i] == ' '){
			str[newLength - 1] = '0';
			str[newLength - 2] = '2';
			str[newLength - 3] = '%';
			newLength = newLength - 3;
		}else{
			cout<<str[i]<<endl;
			str[newLength - 1] = str[i];
			newLength = newLength - 1;
			cout<<"Position placed at "<<newLength<<endl;
		}
	}
}

int main(){
	char* str1 = new char[50];
	string str;
	str.assign("Hi Hi ");
	strcpy(str1,str.c_str());
	replaceSpacesSol1(str1,str.length());
	cout<<str1<<endl;
}

