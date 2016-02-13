/*
 * FindCommonElementInThreeSortedArray.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: cvora
 */

/*
 * Given three arrays sorted in non-decreasing order, print all common elements in these arrays.

Examples:

ar1[] = {1, 5, 10, 20, 40, 80}
ar2[] = {6, 7, 20, 80, 100}
ar3[] = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20, 80

ar1[] = {1, 5, 5}
ar2[] = {3, 4, 5, 5, 10}
ar3[] = {5, 5, 10, 20}
Outptu: 5, 5
 */


/*
 * A simple solution is to first find intersection of two arrays and store the intersection
 * in a temporary array, then find the intersection of third array and temporary array.
 * Time complexity of this solution is O(n1 + n2 + n3) where n1, n2 and n3 are sizes of
 * ar1[], ar2[] and ar3[] respectively
 */

/*
 * The above solution requires extra space and two loops, we can find the common elements using
 * a single loop and without extra space. The idea is similar to intersection of two arrays.
 * Like two arrays loop, we run a loop and traverse three arrays.
 * Let the current element traversed in ar1[] be x, in ar2[] be y and in ar3[] be z.
 * We can have following cases inside the loop.
 * 1) If x, y and z are same, we can simply print any of them as common element
 * and move ahead in all three arrays.
 * 2) Else If x < y, we can move ahead in ar1[] as x cannot be a common element
 * 3) Else If y < z, we can move ahead in ar2[] as y cannot be a common element
 * 4) Else (We reach here when x > y and y > z), we can simply move ahead in ar3[]
 * as z cannot be a common element.
 */

// C++ program to print common elements in three arrays
#include <iostream>
using namespace std;

// This function prints common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
    // Initialize starting indexes for ar1[], ar2[] and ar3[]
    int i = 0, j = 0, k = 0;

    // Iterate through three arrays while all arrays have elements
    while (i < n1 && j < n2 && k < n3)
    {
         // If x = y and y = z, print any of them and move ahead in all arrays
         if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
         {
        	 cout << ar1[i] << " ";   i++; j++; k++;
         }

         // x < y
         else if (ar1[i] < ar2[j])
             i++;

         // y < z
         else if (ar2[j] < ar3[k])
             j++;

         // We reach here when x > y and z < y, i.e., z is smallest
         else
             k++;
    }
}

// Driver program to test above function
int main()
{
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);

    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
