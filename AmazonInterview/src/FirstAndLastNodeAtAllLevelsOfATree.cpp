/*
 * Test25.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: chintan
 */

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <iostream>
#include <queue>
#include <vector>
#include "require.h"

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                        malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

vector<int> firstLastNodes(TreeNode *root){

	queue<TreeNode*> q;
	vector<int> res;
	int count = 0;

	if(root != NULL) {
		count = 1;
		q.push(root);
	}

	while(count != 0){

		int newcount = 0;
		vector<int> level;

		for(int i = 0; i < count; i++){

			TreeNode *node = q.front();
			q.pop();

			level.push_back(node->val);

			if(node->left != NULL){
				newcount++;
				q.push(node->left);
			}

			if(node->right != NULL){
				newcount++;
				q.push(node->right);
			}
		}

		res.push_back(level.front());	// left node

		if(level.size() >= 2){
			res.push_back(level.back());		// right node
		}

		count = newcount;
	}

	return res;
}

int main(){

	   /* Create following tree as first BT
	            5
	          /   \
	        1      6
	       / \	  / \
	      5  4   3	 6

	    */
	    struct TreeNode *root1  = newNode(5);
	    root1->left         = newNode(1);
	    root1->right        = newNode(6);
	    root1->left->left   = newNode(5);
	    root1->left->right  = newNode(4);
	    root1->right->left   = newNode(3);
	    root1->right->right  = newNode(6);


	    std::vector<int>res = firstLastNodes(root1);
	    printArray2(res,res.size());

	return 0;
}

