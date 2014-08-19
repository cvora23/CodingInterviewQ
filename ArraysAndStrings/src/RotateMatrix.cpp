/*
 * RotateMatrix.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: cvora
 */

// Coding Interview questions Solution 1.6

#include <iostream>
#include <string.h>
#include <sstream>      // std::stringstream
#include "utility.h"

using namespace std;


template <size_t size_x,size_t size_y>
void rotateMatrixSol1(int (&matrix)[size_x][size_y]){
	int n = size_x;
	for(int layer = 0;layer <n/2;++layer){
		int first = layer;
		int last = n - 1 - layer;
		for(int i=first;i<last;++i){
			int offset = i - first;
			//save top
			int top = matrix[first][i];
			//left -> top
			matrix[first][i] = matrix[last-offset][first];
			//bottom -> left
			matrix[last-offset][first] = matrix[last][last-offset];
			// right -> bottom
			matrix[last][last-offset] = matrix[i][last];
			// top -> right
			matrix[i][last] = top;
		}
	}
}

int main(){

	int anArray[4][4] =
	{
		{ 1, 2, 3, 4}, 		// row 0
		{ 5, 6, 7, 8},		// row 1
		{ 9, 10, 11, 12}, 	// row 2
		{13, 14, 15,16},	// row 3
	};

	cout<<"BEFORE ROTATION MATRIX IS"<<endl;
	printMatrix(anArray);

	rotateMatrixSol1(anArray);

	cout<<"AFTER ROTATION MATRIX IS"<<endl;
	printMatrix(anArray);

	return 0;

}

