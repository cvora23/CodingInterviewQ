/*
 * GivenNxNMatrixFindSumAllSubSquaresKxK.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: cvora
 */

/*
 * Given an n x n square matrix, find sum of all sub-squares of size k x k where k is smaller than or equal to n.

Examples

Input:
n = 5, k = 3
arr[][] = { {1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2},
            {3, 3, 3, 3, 3},
            {4, 4, 4, 4, 4},
            {5, 5, 5, 5, 5},
         };
Output:
       18  18  18
       27  27  27
       36  36  36


Input:
n = 3, k = 2
arr[][] = { {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
         };
Output:
       12  16
       24  28
 */


/*
 * A Simple Solution is to one by one pick starting point (leftmost-topmost corner) of
 * all possible sub-squares. Once the starting point is picked, calculate sum of sub-square
 * starting with the picked starting point.
 */

// A simple C++ program to find sum of all subsquares of size k x k
#include <iostream>
using namespace std;

// Size of given matrix
#define n 5

// A simple function to find sum of all sub-squares of size k x k
// in a given square matrix of size n x n
void printSumSimple(int mat[][n], int k)
{
   // k must be smaller than or equal to n
   if (k > n) return;

   // row number of first cell in current sub-square of size k x k
   for (int i=0; i<n-k+1; i++)
   {
      // column of first cell in current sub-square of size k x k
      for (int j=0; j<n-k+1; j++)
      {
          // Calculate and print sum of current sub-square
          int sum = 0;
          for (int p=i; p<k+i; p++)
             for (int q=j; q<k+j; q++)
                 sum += mat[p][q];
           cout << sum << "  ";
      }

      // Line separator for sub-squares starting with next row
      cout << endl;
   }
}

// Driver program to test above function
int main()
{
    int mat[n][n] = {{1, 1, 1, 1, 1},
                     {2, 2, 2, 2, 2},
                     {3, 3, 3, 3, 3},
                     {4, 4, 4, 4, 4},
                     {5, 5, 5, 5, 5},
                    };
    int k = 3;
    printSumSimple(mat, k);
    return 0;
}
