/*
 * Test2.cpp
 *
 *  Created on: Jan 15, 2016
 *      Author: chintan
 */

#include <iostream>

/*
 * Given a number (200), compare it to four variables (E.G A,B,C,D)
   and return true if they are all equal to the given number.
   Do this in the most efficient way, and if possible without if statements.
 */

bool checkSameAsNumber(int a,int b,int c,int d,int num){

	return ( (a^b^c^d^num)  == num);

}

int main(){

	//TEST 1
	std::cout<<checkSameAsNumber(1,2,3,4,5)<<std::endl;
	//TEST 2
	std::cout<<checkSameAsNumber(5,5,5,5,5)<<std::endl;
	return 0;

}


