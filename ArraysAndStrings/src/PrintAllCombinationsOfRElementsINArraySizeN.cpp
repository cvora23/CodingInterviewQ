/*
 * PrintAllCombinationsOfRElementsINArraySizeN.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: cvora
 */

/*
 * Print all possible combinations of r elements in a given array of size n
Given an array of size n, generate and print all possible combinations of r elements in array.
For example, if input array is {1, 2, 3, 4} and r is 2,
then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.

Following are two methods to do this.

Method 1 (Fix Elements and Recur)
We create a temporary array ‘data[]’ which stores all outputs one by one.
The idea is to start from first index (index = 0) in data[], one by one fix
elements at this index and recur for remaining indexes. Let the input array be {1, 2, 3, 4, 5}
and r be 3. We first fix 1 at index 0 in data[], then recur for remaining indexes, then we fix 2
at index 0 and recur. Finally, we fix 3 and recur for remaining indexes. When number of elements
in data[] becomes equal to r (size of a combination), we print data[].

Following diagram shows recursion tree for same input.

http://www.geeksforgeeks.org/wp-content/uploads/combination.png

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
    /*
     * could anyone explain the condition (end-i+1>=r-index)?

    Its pretty confusing.. Instead of i<=end && end-i+1 >= r-index you could understand that as i <= end-(r-index)+1
    which means the following:

    Lets take [1,2,3,4,5] and r = 3. While picking up the first element (index = 0) we dont need to go through 4 and 5.
    lets suppose we considered the 1st element as 1. Then, we dont want to pick the 2nd element as 5 at any case ([1,5, ?] not possible).
    So the picking up a digit is really depending on end, r and index. We are excluding last r-index elements at the end.
    So it becomes i <= end-(r-index)+1.

    In the 2nd method also we could write,
    if (i >= n) return; to if (i >= n-(r-index)+1) return; by the same logic which is more efficient.

    */

    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

/*
 * Method 2 (Include and Exclude every element)
Like the above method, We create a temporary array data[]. The idea here is similar to Subset Sum Problem.
We one by one consider every element of input array, and recur for two cases:

1) The element is included in current combination (We put the element in data[] and
increment next available index in data[])
2) The element is excluded in current combination (We do not put the element and do not change index)

When number of elements in data[] become equal to r (size of a combination), we print it.

This method is mainly based on Pascal’s Identity, i.e. ncr = n-1cr + n-1cr-1

Following is C++ implementation of method 2.
 */

// Program to print all combination of size r in an array of size n
#include<stdio.h>
void combinationUtil2(int arr[],int n,int r,int index,int data[],int i);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination2(int arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];

    // Print all combination using temprary array 'data[]'
    combinationUtil2(arr, n, r, 0, data, 0);
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil2(int arr[], int n, int r, int index, int data[], int i)
{
    // Current cobination is ready, print it
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ",data[j]);
        printf("\n");
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n)
        return;

    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil2(arr, n, r, index+1, data, i+1);

    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil2(arr, n, r, index, data, i+1);
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 2, 3};
    int r = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
}
