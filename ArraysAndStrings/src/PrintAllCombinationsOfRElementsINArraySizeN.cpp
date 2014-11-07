/*
 * PrintAllCombinationsOfRElementsINArraySizeN.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: cvora
 */

/*
 * Print all possible combinations of r elements in a given array of size n
Given an array of size n, generate and print all possible combinations of r elements in array.
For example, if input array is {1, 2, 3, 4} and r is 2, then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.

Following are two methods to do this.

Method 1 (Fix Elements and Recur)
We create a temporary array ‘data[]’ which stores all outputs one by one.
The idea is to start from first index (index = 0) in data[], one by one fix
elements at this index and recur for remaining indexes. Let the input array be {1, 2, 3, 4, 5}
and r be 3. We first fix 1 at index 0 in data[], then recur for remaining indexes, then we fix 2
at index 0 and recur. Finally, we fix 3 and recur for remaining indexes. When number of elements
in data[] becomes equal to r (size of a combination), we print data[].

Following diagram shows recursion tree for same input.

http://d2o58evtke57tz.cloudfront.net/wp-content/uploads/combination.png

 */


// Program to print all combination of size r in an array of size n
#include <stdio.h>
void combinationUtil(int arr[], int data[], int start, int end, int index, int r);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];

    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
    // Current combination is ready to be printed, print it
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
}
