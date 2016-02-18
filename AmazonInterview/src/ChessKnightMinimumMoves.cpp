/*
 * Test2.cpp
 *
 *  Created on: Jan 16, 2016
 *      Author: chintan
 */

/*
   There is a chess board of dimension n X n.
   You are given with 2 squares on that board S(x1,y1) ;M(x2,y2).
   S is a fixed point. M can move diagonally.
   it can move any number of steps or jumps in 1 move .
   Find the minimum number of moves M needs to reach S.
   Similar to a way Bishop moves in game of Chess
*/
#include <iostream>
#include <cmath>
#include <vector>

#include "Point.h"

int getMinimumMove(const Point &a,const Point &b){

	// if they are in same diagonal line
	if(std::abs(long(a.getX()-b.getX())) == std::abs(long(a.getY() - b.getY()))){
		return 1;
	}
	// if they are in same color as the bishop
	else if(int(std::abs(long(a.getX()-b.getX())))%2 == int(std::abs(long(a.getY() - b.getY())))%2){
		return 2;
	}
	// cant reach
	return -1;
}


int main(){

	//Same Diagonal Tests

	// TEST1
	Point a(0,0),b(2,2);
	std::cout<<getMinimumMove(a,b)<<std::endl;

	// TEST 2
	a.setXY(1,1);
	b.setXY(2,0);
	std::cout<<getMinimumMove(a,b)<<std::endl;

	// Same Color Tests

	// TEST 3
	a.setXY(0,0);
	b.setXY(0,2);
	std::cout<<getMinimumMove(a,b)<<std::endl;

	// TEST 4
	a.setXY(0,0);
	b.setXY(0,4);
	std::cout<<getMinimumMove(a,b)<<std::endl;

	// TEST 5
	a.setXY(1,2);
	b.setXY(4,1);
	std::cout<<getMinimumMove(a,b)<<std::endl;

	// Cant Reach Tests
	//TEST 6
	a.setXY(0,0);
	b.setXY(0,1);
	std::cout<<getMinimumMove(a,b)<<std::endl;

	// TEST 7
	a.setXY(0,0);
	b.setXY(1,2);
	std::cout<<getMinimumMove(a,b)<<std::endl;

	// TEST 8
	a.setXY(1,3);
	b.setXY(4,1);
	std::cout<<getMinimumMove(a,b)<<std::endl;

}


