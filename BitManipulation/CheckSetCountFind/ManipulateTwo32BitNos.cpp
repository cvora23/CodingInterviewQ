/*
 * ManipulateTwo32BitNos.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: cvora
 */

#include <iostream>

using namespace std;

/**
 * You are given two 32-bit numbers N and M and two bit positions
 * i and j. write a method to insert M into N such that M starts at
 * bit j and ends at bit i. You can assume that bits j through i have enough
 * space to fit all of M.
 * Eg:
 * Input N = 10000000000, M = 10011, i = 2, j = 6
 * Output N = 10001001100
 *
 * Note: i and j starting from right position going left-wards.
 */
// Cracking the Code Interview 5.1 Solution

int updateBits(int n,int m,int i,int j){
	/*
	 * Create a mask to clear bits i through j in n
	 * Example: i = 2, j = 4. Result should be 11100011.
	 * For simplicity, we'll use just 8 bits for the example
	 */
	int allOnes = ~0; // will equal sequence of all 1s

	// 1s before position j, then 0s. left = 11100000
	int left = allOnes << (j+1);

	// 1s after position i. right = 00000011
	int right = ((1<<i) - 1);

	// All 1s, except for 0s between i and j. mask = 11100011
	int mask = left | right;

	// Clear bits j through i then put m in there
	int n_cleared = n & mask; // Clear bits j through i
	int m_shifted = m << i; // Move m into correct position

	return n_cleared | m_shifted; // OR them, and we are done !!
}

int main(){
	/*
	 * Eg:
	 * Input N = 11111111, M = 00001110, i = 0, j = 5
	 * Output N = 11001110
	 */
	cout<<updateBits(0x000000FF,0x0000000E,0,5)<<endl;
	return 0;

}


