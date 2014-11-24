/*
 * MergeSort.cpp
 *
 *  Created on: Sep 16, 2013
 *      Author: cvora
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y);
void mergesort(int a[], int low, int high);
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
    mergesort(list,0,SIZE-1);

    printf(" \n The list after sorting:\n");
    display(list,SIZE);
}

void merge(int a[], int low, int mid, int high)
{
    int b[10000];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}

/*
 * Algorithm

Conceptually, a merge sort works as follows

Merge sort incorporates two main ideas to improve its runtime:

Example: Using merge sort to sort a list of integers contained in an array:

Suppose we have an array A with n indices ranging from A0 to An − 1.
We apply merge sort to A(A0..Ac − 1) and A(Ac..An − 1) where c is the integer part of n / 2.
When the two halves are returned they will have been sorted.
They can now be merged together to form a sorted array.

https://www.princeton.edu/~achaney/tmve/wiki100k/docs/Merge_sort.html
http://upload.wikimedia.org/wikipedia/commons/e/e6/Merge_sort_algorithm_diagram.svg

 *
 */

void mergesort(int a[], int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

void display(int list[],const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",list[i]);
}



