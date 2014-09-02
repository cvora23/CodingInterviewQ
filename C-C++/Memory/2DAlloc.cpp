/*
 * 2DAlloc.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: cvora
 */

// Cracking the Coding Interview - Sol 13.10


#include <cstdlib>

using namespace std;

int** Alloc2DSol1(int noRows,int noColumns){
	int **rowPtr;
	int i;
	rowPtr = (int**)malloc(noRows * sizeof(int*));
	for(int i = 0;i<noRows;i++){
		rowPtr[i] = (int*)malloc(noColumns * sizeof(int*));
	}
	return rowPtr;
}

void DeAlloc2DSol1(int** rowPtr,int noRows){
	for(int i = 0;i<noRows;i++){
		free(rowPtr[i]);
	}
	free(rowPtr);
}

int** Alloc2DSol2(int noRows,int noColumns){
	int i;
	int header = noRows * sizeof(int*);
	int data = noRows * noColumns * sizeof(int);
	int** rowPtr = (int**)malloc(header + data);
	if(rowPtr == NULL){
		return NULL;
	}

	int* buf = (int*)(rowPtr + noRows);
	for(i = 0;i<noRows;i++){
		rowPtr[i] = buf + i * noColumns;
	}
	return rowPtr;
}

int main(){

	return 0;
}


