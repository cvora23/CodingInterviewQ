/*
 * CheckIfStringRotationOfOther.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: cvora
 */


// Coding Interview questions Solution 1.8

#include <iostream>

using namespace std;

bool isRotationSol1(string str1,string str2){
	unsigned int len = str1.length();
	if(len == str2.length() && len>0){
		string str1str1 = str1.append(str1);
		if(str1str1.find(str2) != string::npos){
			return true;
		}
	}
	return false;
}

int main(){

	cout<<(isRotationSol1("waterbottle","erbottlewat"))<<endl;
	cout<<(isRotationSol1("waterbottle","erbottwat"))<<endl;

}
