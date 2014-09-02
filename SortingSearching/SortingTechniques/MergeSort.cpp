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

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
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



