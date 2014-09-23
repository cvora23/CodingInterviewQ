/*
 * InsertionSort.cpp
 *
 *  Created on: Sep 16, 2013
 *      Author: cvora
 */

#include <stdio.h>

void insertion_sort(long [], long);

int main()
{
  long array[100], n, c, d, swap;

  printf("Enter number of elements\n");
  scanf("%ld", &n);

  printf("Enter %ld integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%ld", &array[c]);

  insertion_sort(array, n);

  printf("Sorted list in ascending order:\n");

  for ( c = 0 ; c < n ; c++ )
     printf("%ld\n", array[c]);

  return 0;
}

/*
 * Algorithm

Insertion sort algorithm somewhat resembles selection sort.
Array is imaginary divided into two parts - sorted one and unsorted one.
At the beginning, sorted part contains first element of the array and unsorted one contains the rest.
At every step, algorithm takes first element in the unsorted part and inserts it to the
right place of the sorted one. When unsorted part becomes empty, algorithm stops.

http://www.algolist.net/Algorithms/Sorting/Insertion_sort

 */

void insertion_sort(long array[], long n)
{
  long c, d, t;

  for (c = 1 ; c <= n - 1; c++)
  {
    d = c;

    while ( d > 0 && array[d] < array[d-1])
    {
      t          = array[d];
      array[d]   = array[d-1];
      array[d-1] = t;
      d--;
    }
  }
}






