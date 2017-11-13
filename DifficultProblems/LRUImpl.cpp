/*
 * LRUImpl.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: cvora
 */

/**
 * Implement LRU Cache
How to implement LRU caching scheme? What data structures should be used?

We are given total possible page numbers that can be referred.
We are also given cache (or memory) size (Number of page frames that cache can hold at a time).
The LRU caching scheme is to remove the least recently used frame when the cache is full and a
new page is referenced which is not there in cache. Please see the Galvin book for more details

We use two data structures to implement an LRU Cache.

1. A Queue which is implemented using a doubly linked list.
The maximum size of the queue will be equal to the total number of frames available (cache size).
The most recently used pages will be near front end and least recently pages will be near rear end.

2. A Hash with page number as key and address of the corresponding queue node as value.

When a page is referenced, the required page may be in the memory. If it is in the memory,
we need to detach the node of the list and bring it to the front of the queue.
If the required page is not in the memory, we bring that in memory. In simple words,
we add a new node to the front of the queue and update the corresponding node address in the hash.
If the queue is full, i.e. all the frames are full, we remove a node from the rear of queue,
and add the new node to the front of queue.


Eg: http://mcicpc.cs.atu.edu/archives/2012/mcpc2012/lru/lru.html
 */

#include<iostream>
#include<unordered_map>
#include<deque>

#define QSIZE 4
using namespace std;

// A FUNCTION TO ADD A PAGE WITH GIVEN 'PAGENUMBER' TO BOTH QUEUE AND HASH
void Enqueue(deque<int>& queue, unordered_map< int,deque<int>::iterator >& hash, int pageNumber)
{
	// IF ALL FRAMES ARE FULL, REMOVE THE PAGE FROM THE BACK OF QUEUE
	// ALSO REMOVE CORRESPONDING ENTRY FROM HASH
	if( queue.size() == QSIZE )
	{
		hash.erase(queue.back());
		queue.pop_back();
	}
	// CREATE A NEW NODE WITH GIVEN PAGE NUMBER,
    // AND ADD THE NEW NODE TO THE FRONT OF QUEUE
	queue.push_front(pageNumber);
	// ALSO ADD HASH ENTRY
	hash.insert(make_pair(pageNumber,queue.begin()));
}

// THIS FUNCTION IS CALLED WHEN A PAGE WITH GIVEN 'PAGENUMBER' IS REFERENCED
// FROM CACHE (OR MEMORY). THERE ARE TWO CASES:
// 1. FRAME IS NOT THERE IN MEMORY, WE BRING IT IN MEMORY AND ADD TO THE FRONT OF QUEUE
// 2. FRAME IS THERE IN MEMORY, WE MOVE THE FRAME TO FRONT OF QUEUE
void ReferencePage(deque<int>& queue, unordered_map< int,deque<int>::iterator >& hash, int pageNumber)
{
	// THE PAGE IS NOT IN CACHE, BRING IT
	if(hash.count(pageNumber) == 0)
	{
		Enqueue( queue, hash, pageNumber );
	}
	//IF PAGE IS THERE IN CACHE
	else
	{
		//GET THE LOCATION OF PAGE IN CACHE
		deque<int>::iterator it = hash.at(pageNumber);
		//IF THE PAGE IS NOT AT FRONT OF CACHE THEN
		if( it != queue.begin() )
		{
			//ERASE THE ENTRY
			queue.erase( it );
			//PUT THE ENTRY AT FRONT OF CACHE
			queue.push_front(pageNumber);
			//UPDATE HASH ENTRY FOR THAT PAGE NUMBER
			hash.at(pageNumber) = queue.begin();
		}
	}
}

//UTILITY TO PRINT A QUEUE
void printQueue(deque<int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop_front();
	}
}

// DRIVER PROGRAM TO TEST ABOVE FUNCTIONS
int main()
{
    deque<int> q;


    // ANY NUMBER OF PAGES CAN BE REFERENCED
	// SIZE OF HASH IS NOT RESTRICTED
	unordered_map < int,deque<int>::iterator > hash;

    // LET US REFER PAGES 1, 2, 3, 1, 4, 5
    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 2);
    ReferencePage( q, hash, 3);
    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 4);
    ReferencePage( q, hash, 5);
    ReferencePage( q, hash, 1);

    // LET US PRINT CACHE FRAMES AFTER THE ABOVE REFERENCED PAGES
    printQueue(q);

    return 0;
}


