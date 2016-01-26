/*
 * Test9.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: chintan
 */

#include <iostream>
#include <queue>
#include "BTree.h"
#include <utility>

/*
 * You have a BST and you need to assign an appropriate value to neighbor of
   all nodes (Explained in below example)
   Node Structure
   node {
        node leftChild,
        node rightChild,
        T data,
        node neighbor
   }
	A
	/ \
	B C
	/ \ \
	D E F

	Based on above tree,

	Node: Neighbor
	A: NULL
	B: C
	D: E
	E: F
 */

/* Given a binary tree, print its nodes in level order
   using array for implementing queue */
void printNeighbors(struct node* root)
{
  struct node *temp_node = root;
  int level = 0;
  std::deque< std::pair<int,struct node*> >mydeque;
  std::pair<int,struct node*> pairVal;
  mydeque.push_back(std::make_pair(level,temp_node));
  std::deque< std::pair<int,struct node*> >::iterator prevItr,nextItr;
  while(!mydeque.empty())
  {
	prevItr = mydeque.begin();
	pairVal.first = prevItr->first;
	pairVal.second = prevItr->second;
	mydeque.pop_front();
	temp_node = pairVal.second;
    printf("Node: %d \n", pairVal.second->data);
    nextItr = mydeque.begin();
    if(nextItr != mydeque.end()){
    	if(pairVal.first == nextItr->first){
    		printf("Neighbor: %d\n",nextItr->second->data);
    	}
    }
    /*Enqueue left child */
    if(temp_node->left)
    	  mydeque.push_back(std::make_pair(pairVal.first+1,temp_node->left));

    /*Enqueue right child */
    if(temp_node->right)
    	mydeque.push_back(std::make_pair(pairVal.first+1,temp_node->right));

  }
}


/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  printNeighbors(root);
  return 0;
}



