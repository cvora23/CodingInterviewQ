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
void quickSort(int list[],int m,int n);
void display(int list[],const int n);

int main()
{
    const int SIZE = 10;
    int list[SIZE];

    int i = 0;

    /* generates random numbers and fill the list */
    for(i = 0; i < SIZE; i++ )
        list[i] = rand();

    printf("The list before sorting is:\n");
    display(list,SIZE);

    /* sort the list using quicksort algorithm */
    quickSort(list,0,SIZE-1);

    printf("The list after sorting:\n");
    display(list,SIZE);
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

void quickSort(int array[], int start, int end)
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
				cout<<"Looking from left first element greater than pivot "<<pivot<<" is "<<array[i]<<endl;
				while (array[k] > pivot && k >= start && k >= i) 	// from the right, look for the first
					k--;                                        	// element not greater than the pivot
				cout<<"Looking from right first element less than or equal to pivot "<<pivot<<" is "<<array[k]<<endl;
				if (k > i)                                       	// if the left seek index is still smaller than
					swap(&array[i],&array[k]);                      // the right index, swap the corresponding elements
			}
			swap(&array[start],&array[k]);          				// after the indices have crossed, swap the last element in
																	// the left partition with the pivot
			display(array,10);
			quickSort(array, start, k - 1); 						// quicksort the left partition
			quickSort(array, k + 1, end);   						// quicksort the right partition
        }
        else    													// if there is only one element in the partition, do not do any sorting
        {
			return;    												// the array is sorted, so exit
        }
}


void display(int list[],const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",list[i]);
    printf("\n");
}
