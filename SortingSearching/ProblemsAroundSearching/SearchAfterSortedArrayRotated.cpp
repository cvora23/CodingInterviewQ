/*
 * SearchAfterSortedArrayRotated.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

// Cracking the coding interview solution 11.3

/**
 * Given a sorted array of n integers that has been rotated an unknown number of
 * times, write code to find an element in the array. You may assure that the array
 * was originally sorted in increasing order.
 */

#include <iostream>

using namespace std;

/**
 * Algo:
 *
 * If this problem smells like binary search to you, you're right !
 * In classic binary search, we compare x with midpoint to figure out if
 * x belongs on the left or right side. The complication here is that the array
 * is rotated and may have an inflection point. Consider, for example, the
 * following two arrays
 * Array1: {10, 15, 20, 0, 5}
 * Array2: {50, 5, 20, 30, 40}
 * Note that both arrays have a midpoint of 20, but 5 appears on left side of one
 * and on the right side of the other. Therefore, comparing x with the midpoint is
 * insufficient.
 * However if we look a bit deeper, we can see that one half of the array must be
 * ordered normally (in increasing order). We can therefore look at the normally ordered
 * half to determine whether we should search the left or right half.
 *
 * For example, if we are searching for 5 in Array1, we can look at the left element (10)
 * and middle element(20). Since 10<20, the left half must be ordered normally. And since 5 is not
 * between those, we know that we must search the right half.
 * In Array2, we can see that since 50<20, the right half must be ordered normally. We turn
 * to the middle (20) and right(40) element to check if 5 would fall between them.
 * The value would not; therefore, we search the left half.
 * The tricky condition is if the left and the middle are identical, as in example array
 * {2,2,2,3,4,2}. In this case, we can check if the rightmost element is different. If it is
 * we can search just the right side. Otherwise we have no choice but to search both the halves.
 *
 */

// Returns the index position of the found element
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


