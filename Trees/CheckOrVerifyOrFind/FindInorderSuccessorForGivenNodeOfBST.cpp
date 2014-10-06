/*
 * InorderSuccessorOfBST.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: cvora
 */

// Cracking the Coding Interview Sol 4.6

/*
 * In Binary Tree, Inorder successor of a node is the next node in Inorder
 * traversal of the Binary Tree. Inorder Successor is NULL for the last node
 * in Inoorder traversal.In Binary Search Tree, Inorder Successor of an input
 * node can also be defined as the node with the smallest key greater
 * than the key of input node. So, it is sometimes important to find next node
 * in sorted order.
 *
 *
 *          20
          /    \
         8      22
       	/ \
       4   12
          /  \
         10  14

    In the above diagram, inorder successor of 8 is 10, inorder
    successor of 10 is 12 and inorder successor of 14 is 20.
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node * minValue(struct node* node);

/**
 * Using a parent node
 * Method 1 (Uses Parent Pointer)
	In this method, we assume that every node has parent pointer.

	The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

	Input: node, root // node is the node whose Inorder successor is needed.
	output: succ // succ is Inorder successor of node.

	1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
	   Go to right subtree and return the node with minimum key value in right subtree.
	2) If right sbtree of node is NULL, then succ is one of the ancestors. Do following.
	   Travel up using the parent pointer until you see a node which is left child of it’s parent.
	   The parent of such a node is the succ.
 */
struct node * inOrderSuccessor1(struct node *root, struct node *n)
{
  // step 1 of the above algorithm
  if( n->right != NULL )
    return minValue(n->right);

  // step 2 of the above algorithm
  struct node *p = n->parent;
  while(p != NULL && n == p->right)
  {
     n = p;
     p = p->parent;
  }
  return p;
}

/**
 * Without using a parent node
 * Method 2 (Search from root)
	Parent pointer is NOT needed in this algorithm.
	The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

	Input: node, root // node is the node whose Inorder successor is needed.
	output: succ // succ is Inorder successor of node.

	1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
	   Go to right subtree and return the node with minimum key value in right subtree.
	2) If right sbtree of node is NULL, then start from root and use search like technique. Do following.
	   Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise go to left side.

 */
struct node * inOrderSuccessor2(struct node *root, struct node *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return minValue(n->right);

    struct node *succ = NULL;

    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }

    return succ;
}

/* Given a non-empty binary search tree, return the minimum data
    value found in that tree. Note that the entire tree does not need
    to be searched. */
struct node * minValue(struct node* node) {
  struct node* current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

/* Helper function that allocates a new node with the given data and
    NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  node->parent = NULL;

  return(node);
}

/* Give a binary search tree and a number, inserts a new node with
    the given number in the correct place in the tree. Returns the new
    root pointer which the caller should then use (the standard trick to
    avoid using reference parameters). */
struct node* insert(struct node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node */
  if (node == NULL)
    return(newNode(data));
  else
  {
    struct node *temp;

    /* 2. Otherwise, recur down the tree */
    if (data <= node->data)
    {
         temp = insert(node->left, data);
         node->left  = temp;
         temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    }

    /* return the (unchanged) node pointer */
    return node;
  }
}

/* Driver program to test above functions*/
int main()
{
  struct node* root = NULL, *temp, *succ;

  //creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);
  temp = root->left->right->right;

  succ =  inOrderSuccessor1(root, temp);
  if(succ !=  NULL)
    printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
  else
    printf("\n Inorder Successor doesn't exit");


  succ =  inOrderSuccessor2(root, temp);
  if(succ !=  NULL)
    printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
  else
    printf("\n Inorder Successor doesn't exit");


  getchar();
  return 0;
}
