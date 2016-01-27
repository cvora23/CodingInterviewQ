/*
 * Test32.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: chintan
 */

#include <iostream>
#include <vector>
#include <queue>
#include "BTree.h"
#include "require.h"

std::vector<int> getLevelValues(struct node* root){
	std::vector<int>retVec;
	std::deque<struct node*> myDeQueue;
	struct node* temp = NULL;
	int count = 0;

	if(root != NULL){
		count++;
		myDeQueue.push_back(root);
	}

	while(count != 0){
		int newCount = 0;
		int currTotal = 0;
		for(int i=0;i<count;i++){
			temp = myDeQueue.front();
			myDeQueue.pop_front();
			currTotal += temp->data;
			if(temp->left){
				myDeQueue.push_back(temp->left);
				newCount++;
			}
			if(temp->right){
				myDeQueue.push_back(temp->right);
				newCount++;
			}
		}
		count = newCount;
		retVec.push_back(currTotal);
	}
	return retVec;
}

int main(){

	   /* Create following tree as first BT
	            5
	          /   \
	        1      6
	       / \	  / \
	      5  4   3	 6

	    */
	    struct node *root1  = newNode(5);
	    root1->left         = newNode(1);
	    root1->right        = newNode(6);
	    root1->left->left   = newNode(5);
	    root1->left->right  = newNode(4);
	    root1->right->left   = newNode(3);
	    root1->right->right  = newNode(6);

	    std::vector<int> retVec = getLevelValues(root1);
	    printArray2(retVec,retVec.size());

	return 0;
}
