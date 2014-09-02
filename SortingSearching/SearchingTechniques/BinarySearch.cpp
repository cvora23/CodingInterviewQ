/*
 * BinarySearch.cpp
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

//Iterative Solution
int binarySearch(int a[],int size,int x){
	int low = 0;
	int high = size - 1;
	int mid;

	while(low <= high){
		mid = (low + high)/2;
		if(a[mid] < x){
			low = mid + 1;
		}else if(a[mid] > x){
			high = mid -1 ;
		}else{
			return mid;
		}
	}
	return -1; // Error
}

//Recursive Solution
int binarySearchRecursive(int a[],int x,int low,int high){
	if(low > high)
		return -1; // Error
	int mid = (low + high)/2;
	if(a[mid] < x){
		return binarySearchRecursive(a,x,mid+1,high);
	}else if(a[mid] > x){
		return binarySearchRecursive(a,x,low,mid-1);
	}else{
		return mid;
	}
}

int main(){
    const int SIZE = 10;
    int list[SIZE] ;
    /* generates ascending order numbers and fill the list */
    for(int i = 0; i < SIZE; i++ )
        list[i] = i;
    display(list,SIZE);

    cout<<binarySearch(list,SIZE,2)<<endl;
    cout<<binarySearch(list,SIZE,200)<<endl;

    cout<<binarySearchRecursive(list,2,0,SIZE)<<endl;
    cout<<binarySearchRecursive(list,200,0,SIZE)<<endl;

	return 0;

}


