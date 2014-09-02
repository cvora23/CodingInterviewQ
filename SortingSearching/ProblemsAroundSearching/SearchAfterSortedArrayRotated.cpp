/*
 * SearchAfterSortedArrayRotated.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

#include <iostream>

using namespace std;

int search(int a[],int left,int right,int x){
	int mid = (left + right)/2;
	if(x == a[mid]){
		//found element
		return mid;
	}
	if(right < left){
		return -1; // Error
	}
	/* Either left or right half must be normally ordered. Find
	 * out which side is normally ordered, and
	 * then use the normally ordered half to figure out which side
	 * to find x.
	 */
	if(a[left] < a[mid]){
		//left is normally ordered
		if(x >= a[left] && x <= a[mid]){
			return search(a,left,mid-1,x); // search left
		}else{
			return search(a,mid+1,right,x); // search right
		}
	}else if(a[mid] < a[left]){
		//right is normally ordered
		if(x >= a[mid] && x<= a[right]){
			return search(a,mid + 1,right,x); // search right
		}else{
			return search(a,left,mid - 1,x); // search left
		}
	}else if(a[left] == a[mid]){
		// left half is all repeats
		if(a[mid] != a[right]){
			// If right is different; search it
			return search(a,mid+1,right,x); // search right
		}else{
			// else, we have to search both halves
			int result = search(a,left,mid-1,x); // search left
			if(result == -1){
				return search(a,mid+1,right,x); // search right
			}else{
				return result;
			}
		}
	}
	return -1;
}

int main(){

	int array1[] = {10,15,20,0,5};
	int array2[] = {50,5,20,30,40};
	int array3[] = {2,2,2,3,4,2};

	cout<<array1[search(array1,0,sizeof(array1)/sizeof(array1[0]),5)]<<endl;
	cout<<search(array2,0,sizeof(array2)/sizeof(array2[0]),5)<<endl;
	cout<<search(array3,0,sizeof(array3)/sizeof(array3[0]),5)<<endl;

	return 0;
}


