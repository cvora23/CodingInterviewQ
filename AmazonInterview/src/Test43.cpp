/*
 * Test43.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: chintan
 */

/*
 * Rotate a array by N. N can be smaller of greater than the array length.
e.g {0,1,2,4,5,6,7} N =4 should return {5,6,7,4,0,1,2}.

1) I did this using extra array but next I was asked to do without extra array and in o(n) time.

Method 4(The Reversal Algorithm)
Please read this for first three methods of array rotation.

Algorithm:

rotate(arr[], d, n)
  reverse(arr[], 1, d) ;
  reverse(arr[], d + 1, n);
  reverse(arr[], l, n);
Let AB are the two parts of the input array where A = arr[0..d-1] and B = arr[d..n-1]. The idea of the algorithm is:
Reverse A to get ArB. // Ar is reverse of A //
Reverse B to get ArBr. // Br is reverse of B //
Reverse all to get (ArBr) r = BA.

For arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7
A = [1, 2] and B = [3, 4, 5, 6, 7]
Reverse A, we get ArB = [2, 1, 3, 4, 5, 6, 7]
Reverse B, we get ArBr = [2, 1, 7, 6, 5, 4, 3]
Reverse all, we get (ArBr)r = [3, 4, 5, 6, 7, 1, 2]

 */

// C/C++ program for reversal algorithm of array rotation
#include<stdio.h>

/*Utility function to print an array */
void printArray(int arr[], int size);

/* Utility function to reverse arr[] from start to end */
void rvereseArray(int arr[], int start, int end);

/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n)
{
	if(d>=n){
		d = d-n;
	}
    rvereseArray(arr, 0, d-1);
    rvereseArray(arr, d, n-1);
    rvereseArray(arr, 0, n-1);
}

/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*Function to reverse arr[] from index start to end*/
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;

    leftRotate(arr, d, n);
    printArray(arr, n);

    d = 7;
    leftRotate(arr, d, n);
    printArray(arr, n);

    return 0;
}


