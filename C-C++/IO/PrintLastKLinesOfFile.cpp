/*
 * PrintLastKLinesOfFile.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: cvora
 */

// Cracking the Coding Interview - Sol 13.1

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void print_state (const std::ios& stream) {
  std::cout << " good()=" << stream.good();
  std::cout << " eof()=" << stream.eof();
  std::cout << " fail()=" << stream.fail();
  std::cout << " bad()=" << stream.bad();
}

void printLastKLines(char* fileName,int k){
	ifstream file (fileName);
	string *L = new string[k];
	int size = 0;

	// read file into circular array
	while(file.good()){
		getline(file,L[size%k]);
		size++;
	}

//	print_state(file);

	// compute start of circular array, and size of it
	int start = size > k ? (size % k) : 0;
	int count = min(k,size);

	// print elements in order they were read
	for(int i=0;i<count;i++){
		cout<<L[(start + i)%k]<<endl;
	}
}

int main(){

	cout<<"enter k: "<<endl;
	int k;
	cin>>k;
	printLastKLines("/home/cvora/workspace/CodingInterviewQ/C-C++/IO/PrintLastKLinesOfFile.cpp",k);

	return 0;
}
