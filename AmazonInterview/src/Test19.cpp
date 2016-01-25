/*
 * Test19.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: chintan
 */

/*
 * 	Given a linkedlist, write an algorithm to divide the linkedlist into two linkedlists,
    the first contains the Fibonacci numbers in the list and the second contains
    the non-Fibonacci numbers. Test the algorithm after developing the code
 */

#include <iostream>
#include <math.h>
#include <vector>
#include "require.h"

// A utility function that returns true if x is perfect square
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}

// Returns true if n is a Fibinacci Number, else false
bool isFibonacci(int n)
{
    // n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perferct square
    return isPerfectSquare(5*n*n + 4) ||
           isPerfectSquare(5*n*n - 4);
}

void splitLinkedList(std::vector<int>num){
	std::vector<int>nonFibonnaci;
	std::vector<int>fibonnaci;

	for(unsigned int i=0;i<num.size();i++){
		if(isFibonacci(num[i])){
			fibonnaci.push_back(num[i]);
		}else{
			nonFibonnaci.push_back(num[i]);
		}
	}
	printArray2(fibonnaci,fibonnaci.size());
	printArray2(nonFibonnaci,nonFibonnaci.size());
}

int main(){
	{
		int myInts[] = { 6, 7, 1, 3, 2, 4, 5, 2, 3, 1, 2, 5 };
		std::vector<int>input(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(input,input.size());
		splitLinkedList(input);
	}
	return 0;
}
