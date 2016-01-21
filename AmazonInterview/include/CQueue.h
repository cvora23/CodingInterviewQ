/*
 * CQueue.h
 *
 *  Created on: Jan 19, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_CQUEUE_H_
#define INCLUDE_CQUEUE_H_

#include <iostream>
#include <map>
#include <list>      // std::pair, std::get
using namespace std;

class CQueue
{
	private :
		int *arr ;
		int front, rear ;
		int MAX;
		std::map<int,std::list<int> >seqCounter;
		std::map<int,std::list<int> >::iterator seqCounterItr;
		void iterateInCqAndInsertIntoMap();
		void insertIntoMap(int element,int index);
	public :
		CQueue( int maxsize = 10 ) ;
		void addq ( int item ) ;
		int delq( ) ;
		void display( ) ;
		void longSeq();
} ;

#endif /* INCLUDE_CQUEUE_H_ */
