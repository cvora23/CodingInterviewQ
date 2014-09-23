/*
 * SelectionSort.cpp
 *
 *  Created on: Sep 16, 2013
 *      Author: cvora
 */

#include <stdio.h>

void selection_sort(long [], long);

int main()
{
  long array[100], n, c, d, swap;

  printf("Enter number of elements\n");
  scanf("%ld", &n);

  printf("Enter %ld integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%ld", &array[c]);

  selection_sort(array, n);

  printf("Sorted list in ascending order:\n");

  for ( c = 0 ; c < n ; c++ )
     printf("%ld\n", array[c]);

  return 0;
}

/*
 * Selection Sort

Selection sort is one of the O(n2) sorting algorithms, which makes it quite inefficient for sorting large data volumes.
Selection sort is notable for its programming simplicity and it can over perform other sorts in certain situations
(see complexity analysis for more details).

Algorithm
===================================

The idea of algorithm is quite simple. Array is imaginary divided into two parts - sorted one and unsorted one.
At the beginning, sorted part is empty, while unsorted one contains whole array.
At every step, algorithm finds minimal element in the unsorted part and adds it
to the end of the sorted one. When unsorted part becomes empty, algorithm stops.
When algorithm sorts an array, it swaps first element of unsorted part with minimal
element and then it is included to the sorted part. This implementation of selection sort in not stable.
In case of linked list is sorted, and, instead of swaps, minimal element is linked to the unsorted part,
selection sort is stable.
 *
 */
void selection_sort(long arr[], long n)
{
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) {
	  minIndex = i;
	  for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				  minIndex = j;
	  if (minIndex != i) {
			tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
	  }
    }
}



