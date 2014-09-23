/*
 * ModifiedBubbleSort.cpp
 *
 *  Created on: Sep 16, 2013
 *      Author: cvora
 */
#include <stdio.h>


void modified_bubble_sort(long [], long);

int main()
{
  long array[100], n, c, d, swap;

  printf("Enter number of elements\n");
  scanf("%ld", &n);

  printf("Enter %ld integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%ld", &array[c]);

  modified_bubble_sort(array, n);

  printf("Sorted list in ascending order:\n");

  for ( c = 0 ; c < n ; c++ )
     printf("%ld\n", array[c]);

  return 0;
}
/*
 * The standard bubble sort can be made more efficient,
 * this improved sorting technique is called the modified bubble sort.
 *  If we make a complete pass of the array elements and do not need
 *  to swap any items, then we know the array must be in order and
 *   we can stop the sort. Also, at the end of each passo ne more item
 *   is in the correct position (starting at the end),
 *   so the list to be sorted can be shortened by one.
 *
 *   http://doyle.wcdsb.ca/ICS4MI/notes/notes%20sort%20modified%20bubble.htm
 *
 */

void modified_bubble_sort(long arr[], long n)
{
    bool swapped = true;
    int j = 0;
    int tmp;
    while (swapped)
    {
	  swapped = false;
	  j++;
	  for (int i = 0; i < n - j; i++)
	  {
		if (arr[i] > arr[i + 1])
		{
		  tmp = arr[i];
		  arr[i] = arr[i + 1];
		  arr[i + 1] = tmp;
		  swapped = true;
		}
	  }
    }
}
