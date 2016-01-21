/*
 * BTree.h
 *
 *  Created on: Jan 19, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_BTREE_H_
#define INCLUDE_BTREE_H_

#include <stdio.h>
#include <stdlib.h>
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* neighbor;
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
  node->neighbor = NULL;
  return(node);
}


#endif /* INCLUDE_BTREE_H_ */
