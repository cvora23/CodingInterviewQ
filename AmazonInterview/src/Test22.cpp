/*
 * Test22.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: chintan
 */

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <iostream>
#include "require.h"

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

// A helper function that stores inorder traversal of a tree rooted with node
void storeInorder(struct node* node, std::set<int>& inorder)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    storeInorder(node->left, inorder);
    /* insert the element into set container to make sure we avoid duplicates.*/
    inorder.insert(node->data);
    /* now recur on right child */
    storeInorder(node->right, inorder);
}

void printSetElements(std::set<int> myset){
	std::set<int>::iterator iter;
	for(iter=myset.begin(); iter!=myset.end();++iter){
	    std::cout<<(*iter)<<std::endl;
	}
}

bool areIdenticalTrees(struct node* tree1,struct node* tree2){

	if(tree1 == NULL || tree2 == NULL){
		return false;
	}

	std::set<int> inorder1,inorder2;
	storeInorder(tree1,inorder1);
	storeInorder(tree2,inorder2);

	printSetElements(inorder1);
	printSetElements(inorder2);

	return (inorder1 == inorder2);
}

/* Driver program to test above functions*/
int main()
{
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

    /* Create following tree as second BT
             80
           /   \
          40    120
     */

    struct node *root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);

    std::cout<<"Are Identical Trees result "<<areIdenticalTrees(root1,root2)<<std::endl;

    /* Create following tree as second BT
             1
           /   \
          3     4
        /  \
       6    5
    */
    struct node *root3  = newNode(1);
    root3->left         = newNode(3);
    root3->right        = newNode(4);
    root3->left->left   = newNode(6);
    root3->left->right  = newNode(5);

    std::cout<<"Are Identical Trees result "<<areIdenticalTrees(root1,root3)<<std::endl;

    return 0;
}



