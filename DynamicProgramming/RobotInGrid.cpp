/*
 * RobotInGrid.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: chivora
 */

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>    // std::fill

using namespace std;

/*
 * Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
 * The robot can only move in two directions, right and down, but certain cells are "off limits" such
 * that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.
 */


/*
 * If we picture this grid, the only way to move to spot (r, c) is by moving to one of the adjacent spots: (r-1,c) or(r,c-1).
 * So,we need to find a path to either (r-1,c) or (r,c-1).
 * How do we find a path to those spots?To find a path to (r-1, c) or (r, c -1),
 * we need to move to one of its adjacent cells.
 * So, we need to find a path to a spot adjacent to (r -1, c), which are coordinates (r-2,c) and (r-1,c-1),
 * or a spot adjacent to (r,c-1),which are spots (r-1,c-1)and (r,c-2).
 * Observe that we list the point (r - 1, c -1) twice; we'll discuss that issue later.
 * So then, to find a path from the origin, we just work backwards like this.
 * Starting from the last cell, we try to find a path to each of its adjacent cells.
 * The recursive code below implements this algorithm.
 *
 * This solution is 0 (2 raise to (r +c)), since each path has r+c steps and there are two choices we can make at each step.
 */
namespace Sol1
{

	bool getPath(bool maze[][3],int row,int col,list<std::pair<int,int> > &path){

		if(col<0 || row < 0 || !maze[row][col]){
			return false;
		}

		/*
		 * Base condition
		 */
		bool isAtOrigin = (row == 0) && (col == 0);

		/*
		 * If there's a path from start to here, add my location
		 */
		if(isAtOrigin || getPath(maze,row,col-1,path) || getPath(maze,row-1,col,path)){
			std::pair<int,int>Point = std::make_pair(row,col);
			path.push_back(Point);
			return true;
		}

		return false;

	}

	list<std::pair<int,int> > getPath(bool maze[][3],int rows,int cols){
		list<std::pair<int,int> > path;
		if(getPath(maze,rows,cols,path)){
			return path;
		}
		return path;
	}

}

/*
 * We should look for a faster way.
 * Often, we can optimize exponential algorithms by finding duplicate work. What work are we repeating?
 * If we walk through the algorithm, we'll see that we are visiting squares multiple times.
 * In fact, we visit each square many, many times. After all, we have rc squares but we're doing O(2 raise to (R+C)) work.
 * If we were only visiting each square once, we would probably have an algorithm that was a (rc)
 * (unless we were somehow doing a lot of work during each visit).
 * How does our current algorithm work? To find a path to (r,c),we look for a path to an adjacent coordinate: (r-1,c) or (r,c-1).
 * Of course, if one of those squares is off limits, we ignore it.
 * Then, we look at their adjacent coordinates: (r-2,c), (r-1,c-1), (r-1,c-1), and (r,c-2).
 * The spot (r-1,c-1) appears twice, which means that we're duplicating effort.
 * Ideally, we should remember that we already visited (r-1,c-1) so that we don't waste our time.
 * This is what the dynamic programming algorithm below does.
 */

namespace Sol2{

bool getPath(bool maze[][3],int row,int col,list<std::pair<int,int> > &path,set<std::pair<int,int> > &failedPoints){

	if(col<0 || row < 0 || !maze[row][col]){
		return false;
	}

	std::pair<int,int>Point = std::make_pair(row,col);

	std::set<std::pair<int,int> >::iterator failedPointsItr;
	/*
	 * If we have already visited this cell,return
	 */
	failedPointsItr = failedPoints.find(Point);
	if(failedPointsItr != failedPoints.end()){
		return false;
	}

	bool isAtOrigin = (row == 0) && (col == 0);

	/*
	 * If there's a path from start to here, add my location
	 */
	if(isAtOrigin || getPath(maze,row,col-1,path,failedPoints) || getPath(maze,row-1,col,path,failedPoints)){
		path.push_back(Point);
		return true;
	}

	failedPoints.insert(Point); // cache the result
	return false;

}

list<std::pair<int,int> > getPath(bool maze[][3],int rows,int cols){
	list<std::pair<int,int> > path;
	set<std::pair<int,int> > failedPoints;
	if(getPath(maze,rows,cols,path,failedPoints)){
		return path;
	}
	return path;
}

}

int main(){

	bool maze[3][3];

	maze[0][0] = 1;
	maze[0][1] = 0;
	maze[0][2] = 1;

	maze[1][0] = 1;
	maze[1][1] = 1;
	maze[2][2] = 1;

	maze[2][0] = 0;
	maze[2][1] = 0;
	maze[2][2] = 1;

	// Sol1
	{
		list<std::pair<int,int> > Path = Sol1::getPath(maze,2,2);

		list<std::pair<int,int> >::iterator PathItr;
		for(PathItr = Path.begin();PathItr != Path.end();PathItr++){
			cout<<(*PathItr).first<<" "<<(*PathItr).second<<endl;
		}
	}
	// Sol2
	{
		list<std::pair<int,int> > Path2 = Sol2::getPath(maze,2,2);

		list<std::pair<int,int> >::iterator PathItr2;
		for(PathItr2 = Path2.begin();PathItr2 != Path2.end();PathItr2++){
			cout<<(*PathItr2).first<<" "<<(*PathItr2).second<<endl;
		}
	}

	return 0;

}
