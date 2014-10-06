/*
 * SizeOfTree.cpp
 *
 *  Created on: Sep 9, 2013
 *      Author: cvora
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Size is number of elements present in tree
 *
 * Size of below is 5
            1
          /   \
        2      3
      /  \
    4     5
 */

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

/*
 * ALGO:
 * 1: If tree is empty then return 0
 * 2: Else
 * 		a: Get the size of left subtree recursively i.e; call
 * 			size(tree-left-subtree)
 * 		b: Get the size of right subtree recursively i.e; call
 * 			size(tree-right->subtree)
 * 		c: Calculate the size of tree as following;
 * 			tree_size = size(left-subtree) + size(right-subtree) + 1
 * 	3: Return tree_size
 */

/* Computes the number of nodes in a tree. */
int size(struct node* node)
{
  if (node==NULL)
    return 0;
  else
    return(size(node->left) + 1 + size(node->right));
}

/* Driver program to test size function*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Size of the tree is %d", size(root));
  getchar();
  return 0;
}

