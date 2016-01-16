/*
 * Point.h
 *
 *  Created on: Jan 16, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_POINT_H_
#define INCLUDE_POINT_H_

class Point{

public:

	Point(int x=0,int y=0);
	void setX(int x=0);
	void setY(int y=0);
	void setXY(int x,int y);
	int getX()const;
	int getY()const;
private:

	int x;
	int y;

};

inline Point::Point(int x,int y){
	this->x = x;
	this->y = y;
}

inline void Point::setX(int x){
	this->x = x;
}

inline void Point::setY(int y){
	this->y = y;
}

inline int Point::getX()const{
	return x;
}

inline int Point::getY()const{
	return y;
}

inline void Point::setXY(int x,int y){
	this->x = x;
	this->y = y;
}



#endif /* INCLUDE_POINT_H_ */
