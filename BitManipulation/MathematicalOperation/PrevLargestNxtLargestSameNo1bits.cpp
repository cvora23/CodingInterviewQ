/*
 * PrevLargestNxtLargestSameNo1bits.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: cvora
 */
#include <iostream>
#include <stdint.h>

// Cracking the Code Interview 5.3 Solution

using namespace std;

uint32_t getNext(uint32_t n){
	// Compute c0 and c1
	int c = n;
	int c0 = 0;
	int c1 = 0;

	while(((c & 1) == 0) && (c != 0)){
		c0++;
		c >>= 1;
	}

	while((c &1) == 1){
		c1++;
		c >>= 1;
	}

	// Error: if n == 11...1100...00, then there is no bigger number with same number 1s
	if(c0 + c1 == 31 || c0 + c1 == 0){
		return -1;
	}

	int p = c0+c1; // position of right most non-trailing zero

	n |= (1<<p); // flip rightmost non-trailing zero
	n &= ~((1 << p) - 1); //Clear all bits to the right of p
	n |= (1 << (c1 - 1)) - 1; // Insert c1-1 ones on the right
	return n;
}

uint32_t getPrev(uint32_t n){
	int temp = n;
	int c0 = 0;
	int c1 = 0;

	while((temp & 1) ==1){
		c1++;
		temp >>= 1;
	}

	if(temp == 0){
		return -1;
	}

	while(((temp & 1) == 0) && (temp != 0)){
		c0++;
		temp >>= 1;
	}

	int p = c0 + c1; // position of rightmost non-trailing one
	n &= ((~0) << (p + 1));; // clears from bit p onwards

	int mask = (1 << (c1 + 1)) - 1; // Sequence of c1 + 1 ones;
	n |= mask << (c0 - 1);

	return n;
}

int main(){

	cout<<getNext(13984)<<endl;
	cout<<getPrev(13984)<<endl;

	return 0;
}


