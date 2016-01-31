/*
 * Test37.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: chintan
 */

/*
 * Print the level of friendship.

Given a person and list of his friends, print all his friends by level of association.

The text file will be like one below

A: B,C,D
D: B,E,F
E: C,F,G

If the input is A, the out put should be:

Level 1 - B,C,D
Level 2 - E,F
Level 3 - G
 */
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <set>

void printLevelOfFriendship(std::map< char,std::list<char> >friendShipMap,char ipChar){

	// USE SET AND QUEUE
	std::queue<char>friendShipMapByLevelQ;
	std::set<char>friendShipMapByLevelSet;
	std::list<char>::iterator listItr;

	std::map< char,std::list<char> >::iterator friendShipMapItr;
	char key;
	if(friendShipMap.find(ipChar) != friendShipMap.end()){

		// Enter the ipChar initially into Queue
		friendShipMapByLevelQ.push(ipChar);

		// Iterate over the queue
		while(!friendShipMapByLevelQ.empty()){
			// get first element from Queue and remove first element too
			key = friendShipMapByLevelQ.front();
			friendShipMapByLevelQ.pop();
			//
			if(key != ipChar){
				std::cout<<key<<std::endl;
			}
			friendShipMapItr = friendShipMap.find(key);
			// If we found the key inside the map
			if(friendShipMapItr != friendShipMap.end()){

				// start inserting all its values from List into a queue and set
				// if not present inside the set.
				for(listItr = friendShipMapItr->second.begin();
						listItr != friendShipMapItr->second.end(); listItr++){
					// if not found in set, insert into set and queue, meaning element
					// was not visited yet.
					if(friendShipMapByLevelSet.find((*listItr)) ==
							friendShipMapByLevelSet.end()){
						friendShipMapByLevelSet.insert((*listItr));
						friendShipMapByLevelQ.push((*listItr));
					}else{
						// else nothing because element was already visited.
					}

				}

			}else{
				// element not present in map
			}

		}


	}else{
		// DO NOTHING
	}

}

/*
 * Another solution
 * =======================
 * Oookay I think BFS traversal will work.
 * However for that we would need to convert the file into a graph
 * and then perform the BFS on it.


So the solution would broadly comprise  of:
A) Convert the file into a graph. Its a one time operation,
once done we won't need to do it again.
B) Starting with the appropriate node in the graph, perform a BFS(using queues)
 */

int main()
{
	std::map< char,std::list<char> >friendShipMap;
	friendShipMap['A'].push_back('B');
	friendShipMap['A'].push_back('C');
	friendShipMap['A'].push_back('D');

	friendShipMap['D'].push_back('B');
	friendShipMap['D'].push_back('E');
	friendShipMap['D'].push_back('F');

	friendShipMap['E'].push_back('C');
	friendShipMap['E'].push_back('F');
	friendShipMap['E'].push_back('G');

	printLevelOfFriendship(friendShipMap,'A');

}
