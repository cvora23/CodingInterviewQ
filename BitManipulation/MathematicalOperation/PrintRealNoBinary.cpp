/*
 * PrintBinary.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: cvora
 */

#include <iostream>

// Cracking the Code Interview 5.2 Solution

/**
 * 	Given a real number between 0 and 1 (e.g.,0.72) that is passed in as a double, print
	the binary representation. If the number cannot be represented accurately in binary
	with at most 32 characters, print"ERROR.
 */

using namespace std;

string printBinarySol1(double num){
	if(num >=1 || num<=0){
		return "ERROR";
	}
	string binary;
	binary.append(".");
	while(num>0){
		// Setting a limit on length: 32 characters
		if(binary.length() >= 32){
			return "ERROR";
		}
		double r = num*2;
		if(r>=1){
			binary.append("1");
			num = r-1;
		}else{
			binary.append("0");
			num = r;
		}
	}
	return binary;
}

string printBinarySol2(double num){
	if(num >=1 || num<=0){
		return "ERROR";
	}
	string binary;
	double frac = 0.5;
	binary.append(".");
	while(num>0){
		// Setting a limit on length: 32 characters
		if(binary.length() >= 32){
			return "ERROR";
		}
		if(num>=frac){
			binary.append("1");
			num -= frac;
		}else{
			binary.append("0");
		}
		frac /= 2;
	}
	return binary;
}


int main(){

	cout<<printBinarySol1(0.101)<<endl;
	cout<<printBinarySol1(0.625)<<endl;
	cout<<printBinarySol1(0.25)<<endl;

	cout<<printBinarySol2(0.101)<<endl;
	cout<<printBinarySol2(0.625)<<endl;
	cout<<printBinarySol2(0.25)<<endl;

	return 0;
}



