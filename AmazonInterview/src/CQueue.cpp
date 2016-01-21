/*
 * CQueue.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: chintan
 */

#include "CQueue.h"


CQueue :: CQueue( int maxsize )
{
	MAX = maxsize ;
	arr = new int [ MAX ];
	front = rear = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
}
void CQueue :: addq ( int item )
{
	if ( ( rear + 1 ) % MAX == front )
	{
		cout << "\nQueue is full" ;
		return ;
	}
	rear = ( rear + 1 ) % MAX;
	arr[rear] = item ;
	if ( front == -1 )
		front = 0 ;
}
int CQueue :: delq( )
{
	int data ;
	if ( front == -1 )
	{
		cout << "\nQueue is empty" ;
		return -1 ;
	}

	data = arr[front] ;
	arr[front] = 0 ;
	if ( front == rear )
	{
		front = -1 ;
		rear = -1 ;
	}
	else
		front = ( front + 1 ) % MAX;
	return data ;
}
void CQueue :: display( )
{
	cout << endl ;
	int tempFront = front;
	do{
		cout << arr[tempFront] << "  " ;
		tempFront = (tempFront + 1) % MAX;
	}while(tempFront != front);

	cout << endl ;
}

void CQueue :: insertIntoMap(int element,int index){

	seqCounter[element].push_back(index);

}

void CQueue :: iterateInCqAndInsertIntoMap(){

	/*
	 * insert all the elements and their index positions
	 */
	cout << endl ;
	int tempFront = front;
	do{
		insertIntoMap(arr[tempFront],tempFront);
		tempFront = (tempFront + 1) % MAX;
	}while(tempFront != front);
}

void CQueue :: longSeq(){

	int startingIndex = -1,endingIndex = -1,element = -1;
	int longSeqLen = 0;
	 iterateInCqAndInsertIntoMap();
	 for(seqCounterItr = seqCounter.begin();seqCounterItr != seqCounter.end(); seqCounterItr++){
//		cout << "Element: "<<seqCounterItr->first;
//		cout << " Indexes: ";
		std::list<int>::iterator it = seqCounterItr->second.begin();
		int prev = 0,next = 0;
		prev = seqCounterItr->second.front();
		it++;
		for (;it != seqCounterItr->second.end(); it++){
//			    std::cout << *it << ' ';
			    next = *(it);
			    if((next - prev) > longSeqLen){
			    	longSeqLen = (next - prev) + 1;
			    	startingIndex = prev;
			    	endingIndex = next;
			    	element = seqCounterItr->first;
			    }
			    prev = next;
		}

		if((seqCounterItr->second.size()>1) &&
				((MAX-seqCounterItr->second.back()) + seqCounterItr->second.front() + 1) > longSeqLen){
//	    	cout<<"Element is: "<<seqCounterItr->first<<endl;
			longSeqLen = ((MAX-seqCounterItr->second.back()) + seqCounterItr->second.front()) + 1;
			startingIndex = seqCounterItr->second.back();
			endingIndex = seqCounterItr->second.front();
			element = seqCounterItr->first;
		}
//		cout<<endl;
	 }

	 cout<<"Element = "<<element<<endl;
	 cout<<"longSeqLen = "<<longSeqLen<<endl;
	 cout<<"startingIndex = "<<startingIndex<<endl;
	 cout<<"endingIndex = "<<endingIndex<<endl;

	 cout<<endl;

}




