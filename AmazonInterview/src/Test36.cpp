//Sort a matrix such that rows in ascending order and columns should be in descending order.

#include <vector>
#include <iostream>
#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include "require.h"

using namespace std;

void sortMatrix(vector<vector<int> >&matrix,int noRows,int noColumns){

	std::vector<int>tempVec;

	for(int i=0;i<noRows;i++){
		for(int j=0;j<noColumns;j++){
			tempVec.push_back(matrix[i][j]);
		}
	}

	// sort the 1-D vector
	std::sort(tempVec.begin(),tempVec.end(),std::greater<int>());
	printArray2(tempVec,tempVec.size());

	// insert the elements starting from last row.

	for(int i=noRows-1;i>=0;i--){
		for(int j=0;j<noColumns;j++){
			cout<<tempVec.back()<<endl;
			matrix[i][j] = tempVec.back();
			tempVec.pop_back();
		}
	}

}

int main(){

	// TEST-1
	{
		std::vector<vector<int> > vec;
		  // Set up sizes. (HEIGHT x WIDTH)
		vec.resize(4);
		  for (int i = 0; i < 4; ++i){
			  vec[i].resize(5);
	//			  std::cout<<vec[i].size()<<endl;
		  }

		int row[4][5] = {
						{56,534,1,23,45},
						{0,2,34,56,444},
						{6,789,45,89,12},
						{3420,335,4645,34534,5}
						};
		cout<<"Before Sorting Rows - Ascending and Columns - Descending"<<std::endl;

		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				vec[i][j] = row[i][j];
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}

		sortMatrix(vec,4,5);

		cout<<"After Sorting Rows - Ascending and Columns - Descending"<<std::endl;

		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}


	return 0;

}
