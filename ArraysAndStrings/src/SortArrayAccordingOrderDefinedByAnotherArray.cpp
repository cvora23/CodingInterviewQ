/*
 * SortArrayAccordingOrderDefinedByAnotherArray.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: cvora
 */

/*
 * Sort an array according to the order defined by another array
 * Given two arrays A1[] and A2[], sort A1 in such a way that the
 * relative order among the elements will be same as those are in A2.
 * For the elements not present in A2, append them at last in sorted order.
 * Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
 * A2[] = {2, 1, 8, 3}
 * Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}
 * The code should handle all cases like number of elements in A2[] may be more
 * or less compared to A1[]. A2[] may have some elements which may not be
 * there in A1[] and vice versa is also possible.
 */

/*
 * Method 1 (Using Sorting and Binary Search)
 * Let size of A1[] be m and size of A2[] be n.
 * 1) Create a temporary array temp of size m and copy contents of A1[] to it.
 * 2) Create another array visited[] and initialize all entries in it as false.
 * visited[] is used to mark those elements in temp[] which are copied to A1[].
 * 3) Sort temp[]
 * 4) Initialize the output index ind as 0.
 * 5) Do following for every element of A2[i] in A2[]
 * …..a) Binary search for all occurrences of A2[i] in temp[], if present then copy all
 * occurrences to A1[ind] and increment ind. Also mark the copied elements visited[]
 * 6) Copy all unvisited elements from temp[] to A1[].
 *
 * Time complexity: The steps 1 and 2 require O(m) time.
 * Step 3 requires O(mLogm) time. Step 5 requires O(nLogm) time.
 * Therefore overall time complexity is O(m + nLogm).
 *
 */

// A C++ program to sort an array according to the order defined
// by another array
#include <iostream>
#include <algorithm>
using namespace std;

/* A Binary Search based function to find index of FIRST occurrence
  of x in arr[].  If x is not present, then it returns -1 */
int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high-low)/2;  /* (low + high)/2; */
        if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        return first(arr, low, (mid -1), x, n);
    }
    return -1;
}

// Sort A1[0..m-1] according to the order defined by A2[0..n-1].
void sortAccording(int A1[], int A2[], int m, int n)
{
    // The temp array is used to store a copy of A1[] and visited[]
    // is used mark the visited elements in temp[].
    int temp[m], visited[m];
    for (int i=0; i<m; i++)
    {
        temp[i] = A1[i];
        visited[i] = 0;
    }

    // Sort elements in temp
    sort(temp, temp + m);

    int ind = 0;  // for index of output which is sorted A1[]

    // Consider all elements of A2[], find them in temp[]
    // and copy to A1[] in order.
    for (int i=0; i<n; i++)
    {
        // Find index of the first occurrence of A2[i] in temp
        int f = first(temp, 0, m-1, A2[i], m);

        // If not present, no need to proceed
        if (f == -1) continue;

        // Copy all occurrences of A2[i] to A1[]
        for (int j = f; (j<m && temp[j]==A2[i]); j++)
        {
            A1[ind++] = temp[j];
            visited[j] = 1;
        }
    }

    // Now copy all items of temp[] which are not present in A2[]
    for (int i=0; i<m; i++)
        if (visited[i] == 0)
            A1[ind++] = temp[i];
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above function.
int main()
{
    int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int m = sizeof(A1)/sizeof(A1[0]);
    int n = sizeof(A2)/sizeof(A2[0]);
    cout << "Sorted array is \n";
    sortAccording(A1, A2, m, n);
    printArray(A1, m);
    return 0;
}


