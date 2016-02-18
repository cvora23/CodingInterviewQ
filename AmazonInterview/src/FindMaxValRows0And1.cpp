/*
 * Test13.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: chintan
 */
/*
 *  Given 2D Array of only 0s and 1s, Find the row which gives max decimal value.

Input: int array[3][3] = {{0,1,0,}{1,1,0},{1,0,1}};
Output : 2(second row)...decimal value is 6
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int findMaxDecimalValue(std::vector< std::vector<int> >vec){
	int maxDecimalVal= -1;int runTotal = 0;
	for(unsigned int i=0;i<vec.size();i++){
		for(unsigned int j=0;j<vec[i].size();j++){
			//cout<<vec[i][j]<<endl;
			runTotal += vec[i][vec[i].size()-1-j] * pow(2,int(j));
		}
		if(runTotal > maxDecimalVal){
			maxDecimalVal = runTotal;
			runTotal = 0;
		}
	}
	return maxDecimalVal;
}

int main(){

	int myInts[] = {0,1,0,1,1,0,1,1,1};
	std::vector<int>input(myInts, myInts + sizeof(myInts) / sizeof(int) );
	std::vector<vector<int> > vec;

	  // Set up sizes. (HEIGHT x WIDTH)
	vec.resize(3);
	  for (int i = 0; i < 3; ++i)
		  vec[i].resize(3);

	int row = 0,col=0;
	for(int i=0;i<input.size();i++){
		vec[row][col++] = input[i];
		if(col%3 == 0){
			row++;
			col = 0;
		}
	}

	cout<<findMaxDecimalValue(vec)<<endl;


	return 0;
}
