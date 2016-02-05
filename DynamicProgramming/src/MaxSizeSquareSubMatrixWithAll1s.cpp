/*
 * MaxSizeSquareSubMatrixWithAll1s.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: chintan
 */

#include <vector>
#include <iostream>
#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include "require.h"

using namespace std;

bool checkIfAllOnes(vector<vector<int> >matrix,int startRow,int endRow,int startColumn,int endColumn){

	for(int i=startRow;i<=endRow;i++){
		for(int j=startColumn;j<=endColumn;j++){
			if(matrix[i][j] == 0){
				return false;
			}
		}
	}

	return true;
}
// Simple Method - O(n2) complexity
int maxSizeSquareSubMatrixWithAll1s(vector<vector<int> >matrix,int noRows,int noColumns){

	int startRow = 0,endRow=0,startCol=0,endCol=0;
	int finalStartRow = 0,finalEndRow=0,finalStartCol=0,finalEndCol=0;

	int noConsecutiveOnes = 0;
	bool firstOneFound = false;
	int maxSize = 0;
	int sizeofMatrix = 0;
	for(int i=0;i<noRows;i++){
		for(int j=0;j<noColumns;j++){

			if(matrix[i][j] == 1 && firstOneFound == false){
				startRow = i;
				startCol = j;
				endCol = j;
				firstOneFound = true;
				noConsecutiveOnes++;
			}
			else if(matrix[i][j] == 1){
				endCol = j;
				noConsecutiveOnes++;
			}else if(matrix[i][j] == 0){
				firstOneFound = false;


				startRow=0;
				endRow=0;
				startCol=0;
				endCol=0;
				noConsecutiveOnes=0;

			}
			if(noConsecutiveOnes>0){
				endRow = startRow + (endCol-startCol);
				if(endRow < noRows){
					if(checkIfAllOnes(matrix,startRow,endRow,startCol,endCol)){

						sizeofMatrix = (endRow - startRow+1)*(endCol-startCol+1);
						if(sizeofMatrix>maxSize){
							maxSize = sizeofMatrix;
							finalStartRow = startRow;
							finalEndRow = endRow;
							finalStartCol = startCol;
							finalEndCol = endCol;
//							cout<<"---------------------"<<endl;
//							cout<<"i = "<<i<<" j= "<<j<<endl;
//							cout<<"Found a sub-matrix with all 1's"<<endl;
//							cout<<"Start Row = "<<startRow<<endl;
//							cout<<"End Row = "<<endRow<<endl;
//							cout<<"Start Col = "<<startCol<<endl;
//							cout<<"End Col = "<<endCol<<endl;
//							cout<<"Size of Matrix = "<<maxSize<<endl;
//							cout<<"---------------------"<<endl<<endl;
						}
					}else{
						noConsecutiveOnes=0;
						startCol = j;
					}
				}
			}

			if(j == noColumns - 1){
				startRow=0;
				endRow=0;
				startCol=0;
				endCol=0;
				noConsecutiveOnes=0;
			}
		}
	}
	cout<<"Start Row = "<<finalStartRow<<endl;
	cout<<"End Row = "<<finalEndRow<<endl;
	cout<<"Start Col = "<<finalStartCol<<endl;
	cout<<"End Col = "<<finalEndCol<<endl;
	cout<<"Max Size of Sub-Square Matrix = "<<maxSize<<endl;
	return maxSize;
}

int main(){

	// TEST-1
	{
		std::vector<vector<int> > vec;
		  // Set up sizes. (HEIGHT x WIDTH)
		vec.resize(6);
		  for (int i = 0; i < 6; ++i){
			  vec[i].resize(5);
	//			  std::cout<<vec[i].size()<<endl;
		  }

		int row[6][5] = {
							{0 , 1 , 1  ,0 , 1 },
							{1 , 1 , 0  ,1 , 0 },
							{0,  1 , 1  ,1 , 0 },
							{1 , 1 , 1  ,1 , 0 },
							{1 , 1 , 1  ,1 , 1 },
							{0 , 0 , 0  ,0 , 0 }
						};

		for(int i=0;i<6;i++){
			for(int j=0;j<5;j++){
				vec[i][j] = row[i][j];
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}

		cout<<"Max size square sub matrix is: "<<maxSizeSquareSubMatrixWithAll1s(vec,6,5)<<endl;

	}

	// TEST-2
	{
		std::vector<vector<int> > vec;
		  // Set up sizes. (HEIGHT x WIDTH)
		vec.resize(6);
		  for (int i = 0; i < 6; ++i){
			  vec[i].resize(5);
	//			  std::cout<<vec[i].size()<<endl;
		  }

		int row[6][5] = {
							{1 , 1 , 1  ,0 , 0 },
							{0 , 1 , 1  ,0 , 0 },
							{0,  0 , 0  ,0 , 0 },
							{0 , 0 , 0  ,0 , 0 },
							{0 , 0 , 0  ,0 , 0 },
							{0 , 0 , 0  ,0 , 0 }
						};

		for(int i=0;i<6;i++){
			for(int j=0;j<5;j++){
				vec[i][j] = row[i][j];
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}

		cout<<"Max size square sub matrix is: "<<maxSizeSquareSubMatrixWithAll1s(vec,6,5)<<endl;

	}

	return 0;

}


