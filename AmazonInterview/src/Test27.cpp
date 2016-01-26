/*
 * Test27.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: chintan
 */

/*
 * Suppose you are given a puzzle that is represented as a matrix with 0s and 1s,
where a 0 indicates you’re allowed to move into that position and 1 means you’re
not allowed to move in that position. Write a function that given a start position
and an end position, returns a boolean value indicating if there exists a path
from start to end. You are only allowed to move up, down, right or left.
Diagonal movement is not allowed.
 */

#include <vector>
#include <iostream>
#include "Point.h"

using namespace std;

bool getValidUpPoint(Point pt,Point & ret,int maxHeight,int maxWidth){

	int x = pt.getX()-1;
	if(x>=0 && x<maxHeight){
		ret = pt;
		ret.setX(x);
		return true;
	}
	return false;
}

bool getValidDownPoint(Point pt,Point & ret,int maxHeight,int maxWidth){

	int x = pt.getX()+1;
	if(x>=0 && x<maxHeight){
		ret = pt;
		ret.setX(x);
		return true;
	}
	return false;
}
bool getValidRightPoint(Point pt,Point & ret,int maxHeight,int maxWidth){

	int y = pt.getY()+1;
	if(y>=0 && y<maxWidth){
		ret = pt;
		ret.setY(y);
		return true;
	}
	return false;
}
bool getValidLeftPoint(Point pt,Point & ret,int maxHeight,int maxWidth){

	int y = pt.getY()-1;
	if(y>=0 && y<maxWidth){
		ret = pt;
		ret.setY(y);
		return true;
	}
	return false;
}


bool pathExists(vector< vector<int> >puzzle,Point start,Point end){

	bool retVal = false;

	// if end is 1 return false
	if(puzzle[end.getX()][end.getY()] == 1){
		return retVal;
	}
	// if start is equal to end return true
	if(start == end){
		return true;
	}

	// mark it as visited or 1;
	puzzle[start.getX()][start.getY()] = 1;

	int maxHeight = puzzle.size();
	int maxWidth = puzzle[0].size();

	Point ret;
	int prevVal = 1;
	// if valid up point check if path exists on that path.
	if(getValidUpPoint(start,ret,maxHeight,maxWidth)&&
			(puzzle[ret.getX()][ret.getY()] == 0)){
		prevVal = puzzle[ret.getX()][ret.getY()];
		//std::cout<<ret<<endl;
		retVal = pathExists(puzzle,ret,end);
	}
	if(prevVal == 0){
		puzzle[ret.getX()][ret.getY()] = prevVal;
	}
	// if valid down point check if path exists on that path.
	if(retVal == false && getValidDownPoint(start,ret,maxHeight,maxWidth) &&
			(puzzle[ret.getX()][ret.getY()] == 0)){
		prevVal = puzzle[ret.getX()][ret.getY()];
		//std::cout<<ret<<endl;
		retVal = pathExists(puzzle,ret,end);
	}
	if(prevVal == 0){
		puzzle[ret.getX()][ret.getY()] = prevVal;
	}
	// if valid right point check if path exists on that path.
	if(retVal == false && getValidRightPoint(start,ret,maxHeight,maxWidth) &&
			(puzzle[ret.getX()][ret.getY()] == 0)){
		prevVal = puzzle[ret.getX()][ret.getY()];
		//std::cout<<ret<<endl;
		retVal = pathExists(puzzle,ret,end);
	}
	if(prevVal == 0){
		puzzle[ret.getX()][ret.getY()] = prevVal;
	}
	// if valid left point check if path exists on that path.
	if(retVal == false && getValidLeftPoint(start,ret,maxHeight,maxWidth)&&
			(puzzle[ret.getX()][ret.getY()] == 0)){
		prevVal = puzzle[ret.getX()][ret.getY()];
		//std::cout<<ret<<endl;
		retVal = pathExists(puzzle,ret,end);
	}

	return retVal;
}

int main(){
	// TEST 1
	{
		Point start(3,1),end(0,3);

		std::vector<vector<int> > vec;
		  // Set up sizes. (HEIGHT x WIDTH)
		vec.resize(4);
		  for (int i = 0; i < 4; ++i){
			  vec[i].resize(5);
//			  std::cout<<vec[i].size()<<endl;
		  }

		int row[4][5] = {
						{0,0,1,0,1},
						{0,0,0,0,0},
						{0,1,1,1,1},
						{0,1,1,0,0}
						};

		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				vec[i][j] = row[i][j];
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}

		std::cout<<pathExists(vec,start,end)<<std::endl;
	}
	// TEST 2
	{
		Point start(0,0),end(1,2);

		std::vector<vector<int> > vec;
		  // Set up sizes. (HEIGHT x WIDTH)
		vec.resize(4);
		  for (int i = 0; i < 4; ++i){
			  vec[i].resize(5);
//			  std::cout<<vec[i].size()<<endl;
		  }

		int row[4][5] = {
						{0,0,1,1,1},
						{0,1,0,0,0},
						{1,1,1,1,1},
						{0,0,0,0,1}
						};

		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				vec[i][j] = row[i][j];
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}

		std::cout<<pathExists(vec,start,end)<<std::endl;
	}
	// TEST 3
	{
		Point start(0,0),end(2,1);

		std::vector<vector<int> > vec;
		  // Set up sizes. (HEIGHT x WIDTH)
		vec.resize(4);
		  for (int i = 0; i < 4; ++i){
			  vec[i].resize(5);
//			  std::cout<<vec[i].size()<<endl;
		  }

		int row[4][5] = {
						{0,0,1,0,1},
						{0,0,0,0,0},
						{0,1,1,1,1},
						{0,1,1,0,0}
						};

		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				vec[i][j] = row[i][j];
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}

		std::cout<<pathExists(vec,start,end)<<std::endl;
	}

}
