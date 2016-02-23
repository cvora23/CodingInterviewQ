/*
 * CountAllPathsFromTopLeftToBottomRightOfMxNMatrix.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: cvora
 */

/*
 * Count all possible paths from top left to bottom right of a mXn matrix
 * The problem is to count all the possible paths from top left to bottom
 * right of a mXn matrix with the constraints that from each cell you can
 * either move only to right or down
 * We have discussed a solution to print all possible paths,
 * counting all paths is easier.
 * Let NumberOfPaths(m, n) be the count of paths to reach row number m and
 * column number n in the matrix, NumberOfPaths(m, n) can be recursively
 * written as following.
 */


#include <iostream>
using namespace std;

// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int  numberOfPaths(int m, int n)
{
   // If either given row number is first or given column number is first
   if (m == 1 || n == 1)
        return 1;

   // If diagonal movements are allowed then the last addition
   // is required.
   return  numberOfPaths(m-1, n) + numberOfPaths(m, n-1);
           // + numberOfPaths(m-1,n-1);
}

int main()
{
    cout << numberOfPaths(3, 3);
    return 0;
}
