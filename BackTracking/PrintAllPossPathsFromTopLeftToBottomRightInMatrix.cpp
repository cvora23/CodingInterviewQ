/*
 * PrintAllPossPathsFromTopLeftToBottomRightInMatrix.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 * Print all possible paths from top left to bottom right of a mXn matrix
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints
that from each cell you can either move only to right or down.

The algorithm is a simple recursive algorithm, from each cell first print all paths by going down and then print all paths by going right.
Do this recursively for each cell encountered.
 */

void printarr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " "; cout << endl;
}

int r = 2;
int c = 3;

bool isvalid(int i, int j) {
	if(i >= r || j >= c)
	    return false;
	else
	    return true;
}

void solve(int arr[][3], int path[], int index, int i, int j) {

	if(i == r-1 && j == c-1) {
		path[index++] = arr[i][j];
		printarr(path, index);
		return;
	}

	path[index] = arr[i][j];
	if(isvalid(i+1,j))
		solve(arr, path, index+1, i+1, j);
	if(isvalid(i,j+1))
		solve(arr, path, index+1, i, j+1);
}


int main() {

	int arr[2][3] =  { {1, 2, 3},
					   {4, 5, 6}};
	int *path = new int[r*c];
	solve(arr, path, 0, 0, 0);
	//	print(arr, n);
  	return 0;
}
