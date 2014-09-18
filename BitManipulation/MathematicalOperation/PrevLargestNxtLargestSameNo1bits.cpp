/*
 * PrevLargestNxtLargestSameNo1bits.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: cvora
 */
#include <iostream>
#include <stdint.h>

// Cracking the Code Interview 5.3 Solution
/*
 * Given a positive integer, print the previous largest and next largest
 * no with same no of 1bits in their binary representation
 */

/**
 * Brute Force Approach
 * Count the number of 1s in n, and then increment or decrement until
 * you find a number with same number of 1s. Easy but not terribly interesting
 */


using namespace std;

/**
 * We want to make this number bigger (but not too big). We need
 * to keep the same number of ones.
 */

/**
 * ALGORITHM
 * 1: Find the first Non Trailing ZERO position from the right. Lets call it p position
 * 2: Flip the pth bit from 0 to 1
 * 3: Find number of 0's and number of 1's to the right of p. Lets call it C0 and C1s
 * 4: Clear all the bits to the right of p
 * 5: Insert C1-1 ones on the right
 */

int getNext(int n){
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
	if(c0 + c1 == 31 || c0 + c1 == 0 ){
		cout<<"getNext ERROR n = "<<n<<endl;
		return -1;
	}

	int p = c0+c1; // position of right most non-trailing zero

	n |= (1<<p); // flip rightmost non-trailing zero
	n &= ~((1 << p) - 1); //Clear all bits to the right of p
	n |= (1 << (c1 - 1)) - 1; // Insert c1-1 ones on the right
	return n;
}

/**
 * ALGORITHM
 * 1: Find the first Non Trailing ONE position from the right. Lets call it p position
 * 2: Flip the pth bit from 1 to 0
 * 3: Find number of 0's and number of 1's to the right of p. Lets call it C0 and C1s
 * 4: Clear all the bits to the right of p
 * 5: Insert C1+1 ones immediately to the right of position p.
 */

int getPrev(int n){
	int temp = n;
	int c0 = 0;
	int c1 = 0;

	while((temp & 1) ==1){
		c1++;
		temp >>= 1;
	}

	if(temp == 0){
		cout<<"getPrev ERROR n = "<<n<<endl;
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
	cout<<getNext(16)<<endl;
	cout<<getPrev(16)<<endl;
	cout<<getNext(15)<<endl;
	cout<<getPrev(15)<<endl;

	return 0;
}


