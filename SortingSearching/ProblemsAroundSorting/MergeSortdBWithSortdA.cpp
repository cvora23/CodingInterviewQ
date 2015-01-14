/*
 * MergeSortdBWithSortdA.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

// Cracking the coding interview solution 11.1
/*
 * You are given 2 sorted arrays, A and B, where A has large enough buffer at the
 * end to hold B. Write a method to merge B into A in sorted order.
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

/**
 * 1: Since we know that A has enough buffer at the end, we won't need to allocate additional
 * space. Our logic should involve simply comparing elements of A and B and inserting them in
 * order, until we've exhausted all elements in A and in B. The only issue with this is that if
 * we insert an element into front of A, then we'll have to shift the existing elements backwards to make room for it.
 * Its better to insert elements to the back of the array, where there's empty space.
 * Note that you don't need to copy the contents of A after running out of elements in B.
 * They are already in place.
 */
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
	int b[5] = {1,3,5,8,10};

	display(a,10);
	display(b,5);

	merge(a,b,3,5);
//
	display(a,10);

	return 0;
}

