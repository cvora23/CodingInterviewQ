/*
 * FindPathFromCornerCellToMiddleCellInMaze.cpp
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
 * Find paths from corner cell to middle cell in maze

Given a square maze containing positive numbers, find all paths from a corner cell (any of the extreme four corners) to the middle cell.
We can move exactly n steps from a cell in 4 directions i.e. North, East, West and South where n is value of the cell,

We can move to mat[i+n][j], mat[i-n][j], mat[i][j+n], and mat[i][j-n] from a cell mat[i][j] where n is value of mat[i][j].

Example

Input:  9 x 9 maze
[ 3, 5, 4, 4, 7, 3, 4, 6, 3 ]
[ 6, 7, 5, 6, 6, 2, 6, 6, 2 ]
[ 3, 3, 4, 3, 2, 5, 4, 7, 2 ]
[ 6, 5, 5, 1, 2, 3, 6, 5, 6 ]
[ 3, 3, 4, 3, 0, 1, 4, 3, 4 ]
[ 3, 5, 4, 3, 2, 2, 3, 3, 5 ]
[ 3, 5, 4, 3, 2, 6, 4, 4, 3 ]
[ 3, 5, 1, 3, 7, 5, 3, 6, 4 ]
[ 6, 2, 4, 3, 4, 5, 4, 5, 1 ]

Output:
(0, 0) -> (0, 3) -> (0, 7) ->
(6, 7) -> (6, 3) -> (3, 3) ->
(3, 4) -> (5, 4) -> (5, 2) ->
(1, 2) -> (1, 7) -> (7, 7) ->
(7, 1) -> (2, 1) -> (2, 4) ->
(4, 4) -> MID

The idea is to use backtracking. We start with each corner cell of the maze and recursively checks if it leads to the solution or not.
Following is the Backtracking algorithm –

If destination is reached

print the path
Else

Mark current cell as visited and add it to path array.
Move forward in all 4 allowed directions and recursively check if any of them leads to a solution.
If none of the above solutions work then mark this cell as not visitedand remove it from path array.

 */

// Rows and columns in given maze
#define N 9

// check whether given cell is a valid cell or not.
bool isValid(set<pair<int, int> > visited,
             pair<int, int> pt)
{
    // check if cell is not visited yet to
    // avoid cycles (infinite loop) and its
    // row and column number is in range
    return (pt.first >= 0) && (pt.first  < N) &&
           (pt.second >= 0) && (pt.second < N) &&
           (visited.find(pt) == visited.end());
}

// Function to print path from source to middle coordinate
void printPath(list<pair<int, int> > path)
{
    for (auto it = path.begin(); it != path.end(); it++)
        cout << "(" << it->first << ", "
             << it->second << ") -> ";

    cout << "MID" << endl << endl;
}

// For searching in all 4 direction
int row[] = {-1, 1, 0, 0};
int col[] = { 0, 0, -1, 1};

// Cordinates of 4 corners of matrix
int _row[] = { 0, 0, N-1, N-1};
int _col[] = { 0, N-1, 0, N-1};

void findPathInMazeUtil(int maze[N][N],
                list<pair<int, int> > &path,
                set<pair<int, int> > &visited,
                pair<int, int> &curr)
{
    // If we have reached the destination cell.
    // print the complete path
    if (curr.first == N / 2 && curr.second == N / 2)
    {
        printPath(path);
        return;
    }

    // consider each direction
    for (int i = 0; i < 4; ++i)
    {
        // get value of current cell
        int n = maze[curr.first][curr.second];

        // We can move N cells in either of 4 directions
        int x = curr.first + row[i]*n;
        int y = curr.second + col[i]*n;

        // Constructs a pair object with its first element
        // set to x and its second element set to y
        pair<int, int> next = make_pair(x, y);

        // if valid pair
        if (isValid(visited, next))
        {
            // mark cell as visited
            visited.insert(next);

            // add cell to current path
            path.push_back(next);

            // recuse for next cell
            findPathInMazeUtil(maze, path, visited, next);

            // backtrack
            path.pop_back();

            // remove cell from current path
            visited.erase(next);
        }
    }
}

// Function to find a path from corner cell to
// middle cell in maze contaning positive numbers
void findPathInMaze(int maze[N][N])
{
    // list to store complete path
    // from source to destination
    list<pair<int, int> > path;

    // to store cells already visisted in current path
    set<pair<int, int> > visited;

    // Consider each corners as the starting
    // point and search in maze
    for (int i = 0; i < 4; ++i)
    {
        int x = _row[i];
        int y = _col[i];

        // Constructs a pair object
        pair<int, int> pt = make_pair(x, y);

        // mark cell as visited
        visited.insert(pt);

        // add cell to current path
        path.push_back(pt);

        findPathInMazeUtil(maze, path, visited, pt);

        // backtrack
        path.pop_back();

        // remove cell from current path
        visited.erase(pt);
    }
}

int main()
{
    int maze[N][N] =
    {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
    };

    findPathInMaze(maze);

    return 0;
}
