/*
 * FindNoIslands.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: cvora
 */

/*
 * Given a boolean 2D matrix, find the number of islands.
 * This is an variation of the standard problem: “Counting number of connected components in a undirected graph”.
 * Before we go to the problem, let us understand what is a connected component.
 * A connected component of an undirected graph is a subgraph in which every two vertices are connected
 * to each other by a path(s), and which is connected to no other vertices outside the subgraph.
 * For example, the graph shown below has three connected components.
 *
 * http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/islands.png
 *
 * A graph where all vertices are connected with each other, has exactly one connected component,
 * consisting of the whole graph. Such graph with only one connected component is called as
 * Strongly Connected Graph.
 * The problem can be easily solved by applying DFS() on each component.
 * In each DFS() call, a component or a sub-graph is visited. We will call DFS
 * on the next un-visited component. The number of calls to DFS() gives the
 * number of connected components. BFS can also be used.
 * What is an island?
 * A group of connected 1s forms an island. For example, the below matrix contains 5 islands

	                	{1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1}
 * A cell in 2D matrix can be connected to 8 neighbors. So, unlike standard DFS(),
 * where we recursively call for all adjacent vertices, here we can recursive call
 * for 8 neighbors only. We keep track of the visited 1s so that they are not
 * visited again.
 */

/*
 * Eg:
 * A simple contest, inspired by this stackoverflow question:

You are given an image of a surface photographed by a satellite.
The image is a bitmap where water is marked by '.' and land is marked by '*'.
Adjacent group of '*'s form an island. (Two '*' are adjacent if they are horizontal, vertical or diagonal neighbours).
Your task is to print the number of islands in the bitmap.

Sample Input:

.........**
**......***
...........
...*.......
*........*.
*.........*
*.........*
*.........*
*.........*
*.........*


Sample Output:
5
 */

// Program to count islands in boolean 2D matrix

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
    return (row >= 0) && (row < ROW) &&     // row number is in range
           (col >= 0) && (col < COL) &&     // column number is in range
           (M[row][col] && !visited[row][col]); // value is 1 and not yet visited
}

// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbors as adjacent vertices
void DFS(int M[][COL], int row, int col, bool visited[][COL])
{
    // These arrays are used to get row and column numbers of 8 neighbors
    // of a given cell . Keep checking the 8 neighboring cells horizontally
	// and find rum numbers and cell numbers of the neighboring cells.
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}

// The main function that returns count of islands in a given boolean
// 2D matrix
int countIslands(int M[][COL])
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and travese through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not
            {                              // visited yet, then new island found
                DFS(M, i, j, visited);     // Visit all cells in this island.
                ++count;                   // and increment island count
            }

    return count;
}

// Driver program to test above function
int main()
{
    int M[][COL]= {
    	{1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    printf("Number of islands is: %d\n", countIslands(M));

    return 0;
}




