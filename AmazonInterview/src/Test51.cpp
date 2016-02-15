/*
 * Test51.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: chintan
 */
/*
 * Given the encoding rule:
A -> 0
B -> 1
C -> 2
…
K -> 10
…
Z -> 25
I was supposed to get the number of original strings possible given an encoded input.
E.g., Given input 10, two possible original strings are possible BA and K, the answer is 2.
 */

#include <stack>
#include <vector>
#include <iostream>
#include <map>
#include "require.h"

using namespace std;
std::map<int,char>dictionary;

void pushSingleDigits(std::stack<int>&sd,int number){
	while(number > 0)
	{
	    int digit = number%10;
	    number /= 10;
	    sd.push(digit);
	}
}

std::vector<int> createDoubleDigits(std::vector<int>&singleDigVec){

	std::vector<int>doubleDigVec;
	for(unsigned int i=0;i<=singleDigVec.size()-2;i++)
	{
		int val = singleDigVec[i]*10+singleDigVec[i+1];
		doubleDigVec.push_back(val);
	}
	return doubleDigVec;
}

bool valsInDict(std::vector<int>outputVec){

	for(unsigned int i=0;i<outputVec.size();i++){
		if(dictionary.find(outputVec[i]) == dictionary.end()){
			return false;
		}
	}
	return true;
}

void getUniqueSets(std::vector<int>singeDigVec,std::vector<int>doubleDigVec,
		unsigned int singleDigVecIndx,unsigned int doubleDigVecIndx,std::vector<int>&outputVec,
		unsigned int finalCount,unsigned int numberElemAdded){

	unsigned int oldSingleDigVecIndx = singleDigVecIndx;
	unsigned int oldDoubleDigVecIndx = doubleDigVecIndx;
	unsigned int oldNumberElemAdded = numberElemAdded;

	// print
	if(numberElemAdded == finalCount){
		//cout<<"Printing the unique set now"<<endl;
		//cout<<"finalCount = "<<finalCount<<endl;
		if(valsInDict(outputVec)){
			//printArray2(outputVec,outputVec.size());
			for(unsigned int i=0;i<outputVec.size();i++){
				cout<<dictionary[outputVec[i]];
			}
			cout<<endl;
		}
		return;
	}
	// base case
	if(numberElemAdded > finalCount || singleDigVecIndx>singeDigVec.size() || doubleDigVecIndx>doubleDigVec.size()){
		return;
	}
	// add single digits first
	outputVec.push_back(singeDigVec[singleDigVecIndx]);
	singleDigVecIndx = oldSingleDigVecIndx + 1;
	doubleDigVecIndx = oldDoubleDigVecIndx + 1;
	numberElemAdded =  oldNumberElemAdded + 1;
	getUniqueSets(singeDigVec,doubleDigVec,singleDigVecIndx,doubleDigVecIndx,
			outputVec,finalCount,numberElemAdded);
	outputVec.pop_back();

	if(oldDoubleDigVecIndx<doubleDigVec.size()){
		// add double digits next
		outputVec.push_back(doubleDigVec[oldDoubleDigVecIndx]);
		singleDigVecIndx = oldSingleDigVecIndx + 2;
		doubleDigVecIndx = oldDoubleDigVecIndx + 2;
		numberElemAdded =  oldNumberElemAdded + 2;
		getUniqueSets(singeDigVec,doubleDigVec,singleDigVecIndx,doubleDigVecIndx,
				outputVec,finalCount,numberElemAdded);
		outputVec.pop_back();

	}

}

void buildEncodingDictionary(){

	char initVal = 'A';

	for(int i=0;i<26;i++){
		dictionary.insert(std::pair<int,char>(i,initVal+i));
	}

}


int main(){

	// Build the encoding dictionary
	buildEncodingDictionary();
	// TEST 1 - Input is 10
	{
		std::stack<int>sd;
		int input = 10;
		pushSingleDigits(sd,input);
		//copying stack into vector
		std::vector<int>singleDigVec;
		while(!sd.empty()){
			int top = sd.top();
			singleDigVec.push_back(top);
			sd.pop();
		}
		//cout<<"SINGLE DIGIT ARRAY"<<endl;
		//printArray2(singleDigVec,singleDigVec.size());
		// creating double digit vector
		std::vector<int>doubleDigVec = createDoubleDigits(singleDigVec);
		//cout<<"DOUBLE DIGIT ARRAY"<<endl;
		//printArray2(doubleDigVec,doubleDigVec.size());

		std::vector<int>outputVec;
		cout<<"Input = "<<input<<endl;
		cout<<"Output = "<<endl;
		getUniqueSets(singleDigVec,doubleDigVec,0,0,outputVec,singleDigVec.size(),0);

	}
	// TEST 2 - Input is 1234

	{
		std::stack<int>sd;
		int input = 1234;
		pushSingleDigits(sd,input);
		//copying stack into vector
		std::vector<int>singleDigVec;
		while(!sd.empty()){
			int top = sd.top();
			singleDigVec.push_back(top);
			sd.pop();
		}
		//cout<<"SINGLE DIGIT ARRAY"<<endl;
		//printArray2(singleDigVec,singleDigVec.size());
		// creating double digit vector
		std::vector<int>doubleDigVec = createDoubleDigits(singleDigVec);
		//cout<<"DOUBLE DIGIT ARRAY"<<endl;
		//printArray2(doubleDigVec,doubleDigVec.size());

		std::vector<int>outputVec;
		cout<<"Input = "<<input<<endl;
		cout<<"Output = "<<endl;

		getUniqueSets(singleDigVec,doubleDigVec,0,0,outputVec,singleDigVec.size(),0);

	}

	return 0;

}



