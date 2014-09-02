/*
 * SortedColumnRowInMatrixFindAnElement.cpp
 *
 *  Created on: Aug 28, 2014
 *      Author: cvora
 */

#include <iostream>

using namespace std;

bool findElementSol1(int **matrix,int noRows,int noColumns,int elem){
	int row = 0;
	int col = noColumns - 1;
	while(row < noRows && col >=0){
		if(matrix[row][col] == elem){
			return true; // found element
		}else if(matrix[row][col] > elem){
			col--; // element less than first element in current so it must on left column
		}else{
			row++; // element more than current element in current row so it must be on next row
		}
	}
	return false;
}

int main(){
	int anArray[4][4] =
	{
		{ 15, 30, 40, 85},		// row 0
		{ 20, 35, 80, 95},		// row 1
		{ 30, 55, 95, 105}, 	// row 2
		{ 40, 80, 100,120},		// row 3
	};

    int *b[4];  // surrogate
    for (size_t i = 0; i < 4; ++i)
    {
        b[i] = anArray[i];
    }

	cout<<findElementSol1(b,4,4,55)<<endl;
	cout<<findElementSol1(b,4,4,555)<<endl;
}
