/*
 * MergeSortdBWithSortdA.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

#include <iostream>
#include <stdio.h>

using namespace std;

void display(int list[],const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",list[i]);
    printf("\n");
}

void merge(int a[],int b[],int lastA,int lastB){

	int indexA = lastA - 1; // Index of last element in array A
	int indexB = lastB - 1; // Index of last element in array B
	int indexMerged = lastB + lastA - 1; // end of merged array

	// Merge A and B, starting from last element in each
	while(indexA >= 0 && indexB >= 0){
		// end of a is > than end of b
		if(a[indexA]>b[indexB]){
			a[indexMerged] = a[indexA] ; //copy element
			indexA--;
		}else{
			a[indexMerged] = b[indexB] ; //copy element
			indexB--;
		}
		indexMerged--; // move indices
	}

	while(indexB >= 0){
		a[indexMerged] = b[indexB] ; //copy element
		indexMerged--; // move indices
		indexB--;
	}
}

int main(){

	int a[10] = {1,2,3};
	int b[5] = {2,3,5,8,10};

	display(a,10);
	display(b,5);

	merge(a,b,3,5);
//
	display(a,10);

	return 0;
}

