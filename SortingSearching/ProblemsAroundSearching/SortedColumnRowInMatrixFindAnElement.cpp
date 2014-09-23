/*
 * SortedColumnRowInMatrixFindAnElement.cpp
 *
 *  Created on: Aug 28, 2014
 *      Author: cvora
 */

// Cracking the coding interview solution 11.8

/*
 * Given an M X N matrix in which each row and each column is sorted in ascending
 * order, write a method to find an element.
 */

#include <iostream>

using namespace std;

/**
 * Algo1:
 * As a first approach, we can do a binary search on every row to find the element.
 * This algo will be O(M log(N)), since there are M rows and it takes O(log(N)) time
 * to search one. This is good approach to mention to your interviewer before you proceed
 * with generating a better algo.
 */

/*
 * Algo2: (Eg : searching for element 55)
 * If we look at the start of a row or start of a column, we can start to deduce the location.
 * If the start of a column is greater than 55, we know that 55 can't be in that column since
 * the start of the column is always the minimum element. Additionally, we know that 55 can't be
 * in any columns on the right, since the first element of each column must
 * increase in size from left to right. Therefore, if the start of column is greater than the element
 * x we are searching for, we need to move further to left.
 * For rows, we can follow identical logic. If the start of the row is bigger than x, then we know
 * we need to move upwards.
 * Observe that we can also make a similar conclusion by looking at the ends of columns or rows.
 * If the end of a column or row is less than x, then we know that we must move down (rows) or to the right
 * (for columns) to find x. This is because the end if always the maximum element.
 * Observations:
 * 1: If the start of a column is greater than x, then x is to the left of the column.
 * 2: If the end of a column is less than x, then x is to the right of the column.
 * 3: If the start of a row is greater than x, then x is above that row.
 * 4: If the end of the row is less than x, then x is below that row.
 */

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
