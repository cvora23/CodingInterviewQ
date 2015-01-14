/*
 * SingleArrayAsThreeStacks.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: cvora
 */

// Cracking the Coding Interview Solution 3.1

#include <iostream>

using namespace std;

namespace FixedDivisionApproach
{

	int stackSize = 100;
	int *buffer = new int[stackSize*3];
	int stackPointer[] = {-1,-1,-1}; // pointers to track top element

	bool isEmpty(int stackNum){
		return stackPointer[stackNum] == -1;
	}

	// returns index of top of stack "stackNum", in absolute terms
	int absTopOfStack(int stackNum){
		return stackNum*stackSize + stackPointer[stackNum];
	}

	void push(int stackNum,int value){
		// check if we have space
		if(stackPointer[stackNum]+1>= stackSize){
			cout<<"Out of Space"<<endl;
		}
		// Increment stack pointer and then update top value
		stackPointer[stackNum]++;
		buffer[absTopOfStack(stackNum)] = value;
	}

	int pop(int stackNum){
		if(stackPointer[stackNum] == -1){
			cout<<"Trying to pop an empty stack"<<endl;
		}
		int value = buffer[absTopOfStack(stackNum)]; // Get top
		buffer[absTopOfStack(stackNum)] = 0; // clear index
		stackPointer[stackNum]--; // Decrement pointer
		return value;
	}

	int peek(int stackNum){
		int index = absTopOfStack(stackNum);
		return buffer[index];
	}
}


// Driver code to test the above algorithm
int main(){

	for(int i=0;i<10;i++){
		FixedDivisionApproach::push(0,i);
		FixedDivisionApproach::push(1,i);
		FixedDivisionApproach::push(2,i);
	}

	for(int i=0;i<10;i++){
		cout<<FixedDivisionApproach::pop(0)<<endl;
		cout<<FixedDivisionApproach::pop(1)<<endl;
		cout<<FixedDivisionApproach::pop(2)<<endl;
	}

}

