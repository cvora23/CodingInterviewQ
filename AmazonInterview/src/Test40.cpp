/*
 * Test40.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: chintan
 */
/*
 * Given n (of size m) Linked lists

Print all set(head of linked list) of link list that intersect with each other.

e.g.

1-->2-->3-->4-->5
6-->7-->8-->4-->5
8->9->10->11->12
13->14->15->12
16->17->18

1 6
8 13
16
 */

#include <list>
#include <map>
#include <vector>
#include <iostream>
#include "require.h"

using namespace std;

void printAllSetOfIntersections(std::vector<std::vector<int> >listOfLists,
		int noRows,int noColumns){

	std::map<int,std::vector<int> >hashTable;
	std::map<int,std::vector<int> >::iterator hashTableItr;

	for(int i=0;i<noRows;i++){
		for(int j=0;j<noColumns;j++){
			hashTableItr = hashTable.find(listOfLists[i][j]);
			if(hashTableItr == hashTable.end()){
				hashTable[listOfLists[i][j]].push_back(listOfLists[i][0]);
			}else{
				hashTableItr->second.push_back(listOfLists[i][0]);
			}
		}
	}

	for(hashTableItr = hashTable.begin();
			hashTableItr != hashTable.end();hashTableItr++){
		//cout<<hashTableItr->second.size()<<endl;
		if(hashTableItr->second.size()>1){
			printArray2(hashTableItr->second,hashTableItr->second.size());
		}
	}

}


int main(){

	// TEST-1
	/*
	 * 	1-->2-->3-->4-->5
		6-->7-->8-->4-->9
		8->9->10->11->12
		13->14->15->34->23
		16->17->18->43->123
	 */
	{
		std::vector<vector<int> > vec;
		  // Set up sizes. (HEIGHT x WIDTH)
		vec.resize(5);
		  for (int i = 0; i < 5; ++i){
			  vec[i].resize(5);
	//			  std::cout<<vec[i].size()<<endl;
		  }

		int row[5][5] = {
						{1,2,3,4,9},
						{6,7,8,4,5},
						{8,9,10,11,12},
						{13,14,15,34,23},
						{16,17,18,43,123}
						};

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				vec[i][j] = row[i][j];
				std::cout<<vec[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		printAllSetOfIntersections(vec,5,5);
	}
return 0;

}
