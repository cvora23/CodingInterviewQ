/*
 * Test7.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: chintan
 */

/*
 * Given a 8 by 8 matrix, find all possible paths , moving one cell downwards or
   on cell to the right,(one cell per movement ) from cell 0,0 , to cell 7,7
 *
 */

#include "Point.h"
#include <vector>

#define MAX_X 4
#define MAX_Y 4

void printPath(std::vector<Point>path){
	for(unsigned int i=0;i<path.size();i++){
		std::cout<<path[i]<<" ";
	}
	std::cout<<std::endl;
}

bool validateRightMove(Point& startPoint){
	int y = startPoint.getY();
	if(y + 1 <MAX_Y){
		startPoint.setY(y+1);
		return true;
	}
	return false;
}

bool validateDownMove(Point& startPoint){
	int x = startPoint.getX();
	if(x + 1 <MAX_X){
		startPoint.setX(x+1);
		return true;
	}
	return false;
}

void moveAndPrint(Point& startPoint,const Point& endPoint,std::vector<Point>path,int index){

	//std::cout<<"StartPoint = "<<startPoint<<std::endl;
	//std::cout<<"EndPoint = "<<endPoint<<std::endl;
	path[index] = startPoint;
	if((startPoint.getX() == endPoint.getX()) && (startPoint.getY() == endPoint.getY())){
		//std::cout<<"Reached end point"<<std::endl;
		printPath(path);
		return;
	}
	//path.insert(path.begin()+index,startPoint);
	Point currentPoint = startPoint;
	// validate and move right
	if(validateRightMove(startPoint)){
		//std::cout<<"StartPoint after moving right = "<<startPoint<<std::endl;
		moveAndPrint(startPoint,endPoint,path,index+1);
	}else{
		//std::cout<<"Cant move right from this point"<<std::endl;
	}
	// validate and move down
	if(validateDownMove(currentPoint)){
		//std::cout<<"StartPoint after moving down = "<<startPoint<<std::endl;
		moveAndPrint(currentPoint,endPoint,path,index+1);
	}else{
		//std::cout<<"Cant move down from this point"<<std::endl;
	}
}


int main(){

	Point startPoint(0,0),endPoint(3,3);
	std::vector<Point>path(7);
	moveAndPrint(startPoint,endPoint,path,0);
	return 0;
}


