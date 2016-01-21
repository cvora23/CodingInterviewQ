/*
 * Test6.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: chintan
 */

/*
 * 6: Given a circular linked list. Find the longest sequence of numbers, where a
   sequence starts with any number, for example 3, and ends when you see that number
   again,another 3.
   Imagine the circular linked list
   3 8 9 7 2 1 3 4 6 [3] same as first element .i.e three.
   The longest sequence would be 3 8 9 7 2 1 , the other candidate being 3 4 6
   Finding for instance,starting at 8 and getting to the same 8 wouldn't count as a valid sequence.
 *
 */

#include "CQueue.h"

int main(){

	CQueue a ( 9 ) ;
	a.addq ( 3 ) ;
	a.addq ( 6 ) ;
	a.addq ( 3 ) ;
	a.addq ( 7 ) ;
	a.addq ( 7 ) ;
	a.addq ( 1 ) ;
	a.addq ( 5 ) ;
	a.addq ( 4 ) ;
	a.addq ( 6 ) ;

	cout << "Elements in the circular queue after addition: " ;
	a.display( ) ;
	a.longSeq();
	return 0;
}


