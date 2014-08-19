/*
 * SetZerosInMatrix.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: cvora
 */

// Coding Interview questions Solution 1.7

#include <iostream>
#include <string.h>
#include <sstream>      // std::stringstream
#include "utility.h"

using namespace std;

void setZerosSol1(int** matrix,int size){
	bool* row = new bool[size];
	bool* column = new bool[size];

	// Store the row and column index with value 1s
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(matrix[i][j] == 0){
				row[i] = true;
				column[j] = true;
			}
		}
	}

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(row[i] || column[j]){
				matrix[i][j] = 0;
			}
		}
	}

}

int main(){
	int anArray[4][4] =
	{
		{ 1, 2, 3, 4}, 		// row 0
		{ 5, 0, 7, 8},		// row 1
		{ 9, 10, 11, 12}, 	// row 2
		{13, 14, 15,16},	// row 3
	};

    int *b[4];  // surrogate
    for (size_t i = 0; i < 4; ++i)
    {
        b[i] = anArray[i];
    }

	cout<<"BEFORE ZERO OUT ROW AND COLUMN MATRIX IS"<<endl;
	printMatrix(anArray);

	setZerosSol1(b,4);

	cout<<"AFTER ZERO OUT ROW AND COLUMN MATRIX IS"<<endl;
	printMatrix(anArray);


}



