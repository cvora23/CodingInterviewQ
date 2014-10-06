/*
 * SortedOrderPrintOfGivenArrayThatRepresentsBST.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: cvora
 */


#include<stdio.h>

void printSorted(int arr[], int start, int end)
{
  if(start > end)
    return;

  // print left subtree
  printSorted(arr, start*2 + 1, end);

  // print root
  printf("%d  ", arr[start]);

  // print right subtree
  printSorted(arr, start*2 + 2, end);
}

int main()
{
  int arr[] = {4, 2, 5, 1, 3};
  int arr_size = sizeof(arr)/sizeof(int);
  printSorted(arr, 0, arr_size-1);
  getchar();
  return 0;
}

