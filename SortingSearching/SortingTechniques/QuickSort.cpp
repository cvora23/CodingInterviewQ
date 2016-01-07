/*
 * QuickSort.cpp
 *
 *  Created on: Sep 16, 2013
 *      Author: cvora
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void swap(int *x,int *y);
int choose_pivot(int i,int j );
void quickSortSol1(int list[],int m,int n);
void quickSortSol2(int list[],int m,int n);
void display(int list[],const int n);


int main()
{
    const int SIZE = 10;
    int list1[SIZE],list2[SIZE];

    int i = 0;

    /* generates random numbers and fill the list */
    for(i = 0; i < SIZE; i++ )
        list1[i] = rand();

    printf("The list1 before sorting is:\n");
    display(list1,SIZE);

    /* sort the list using quicksort algorithm */
    quickSortSol1(list1,0,SIZE-1);

    printf("The list1 after sorting:\n");
    display(list1,SIZE);

    /* generates random numbers and fill the list */
    for(i = 0; i < SIZE; i++ )
    	list2[i] = rand();

    printf("The list2 before sorting is:\n");
    display(list2,SIZE);

    /* sort the list using quicksort algorithm */
    quickSortSol1(list2,0,SIZE-1);

    printf("The list2 after sorting:\n");
    display(list2,SIZE);

}

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

/*
 * Quicksort
==============================

Quicksort is a fast sorting algorithm, which is used not only for educational purposes,
but widely applied in practice. On the average, it has O(n log n) complexity,
making quicksort suitable for sorting big data volumes.
The idea of the algorithm is quite simple and once you realize it,
 you can write quicksort as fast as bubble sort.

Algorithm
=========================

The divide-and-conquer strategy is used in quicksort. Below the recursion step is described:
1: Choose a pivot value. We take the value of the middle element as pivot value,
   but it can be any value, which is in range of sorted values, even if it doesn't present in the array.
2: Partition. Rearrange elements in such a way, that all elements which are lesser
   than the pivot go to the left part of the array and all elements greater than
   the pivot, go to the right part of the array. Values equal to the pivot can
   stay in any part of the array. Notice, that array may be divided in non-equal parts.
3: Sort both parts. Apply quicksort algorithm recursively to the left and the right parts.

Partition algorithm in detail
==========================================
There are two indices i and j and at the very beginning of the partition algorithm
i points to the first element in the array and j points to the last one.
Then algorithm moves i forward, until an element with value greater or
equal to the pivot is found. Index j is moved backward, until an element
with value lesser or equal to the pivot is found. If i ≤ j then they are
swapped and i steps to the next position (i + 1), j steps to the previous
one (j - 1). Algorithm stops, when i becomes greater than j.

After partition, all values before i-th element are less or equal than
the pivot and all values after j-th element are greater or equal to the pivot.

 */

//recursive solution 1 with pivot element as the first element
void quickSortSol1(int array[], int start, int end)
{
	int i = start;                          					// index of left-to-right scan
	int k = end;                            					// index of right-to-left scan

	if (end - start >= 1)                   					// check that there are at least two elements to sort
	{
		int pivot = array[start];       						// set the pivot as the first element in the partition

		while (k > i)                   						// while the scan indices from left and right have not met,
		{
			while (array[i] <= pivot && i <= end && k > i)  	// from the left, look for the first
				i++;                                    		// element greater than the pivot
			//cout<<"Looking from left first element greater than pivot "<<pivot<<" is "<<array[i]<<endl;
			while (array[k] > pivot && k >= start && k >= i) 	// from the right, look for the first
				k--;                                        	// element not greater than the pivot
			//cout<<"Looking from right first element less than or equal to pivot "<<pivot<<" is "<<array[k]<<endl;
			if (k > i)                                       	// if the left seek index is still smaller than
				swap(&array[i],&array[k]);                      // the right index, swap the corresponding elements
		}
		swap(&array[start],&array[k]);          				// after the indices have crossed, swap the last element in
																// the left partition with the pivot
		//display(array,10);
		quickSortSol1(array, start, k - 1); 						// quicksort the left partition
		quickSortSol1(array, k + 1, end);   						// quicksort the right partition
	}
	else    													// if there is only one element in the partition, do not do any sorting
	{
		return;    												// the array is sorted, so exit
	}
}

//recursive solution 2 with pivot element as the middle element
void quickSortSol2(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
    	  quickSortSol2(arr, left, j);
      if (i < right)
    	  quickSortSol2(arr, i, right);
}



void display(int list[],const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",list[i]);
    printf("\n");
}
