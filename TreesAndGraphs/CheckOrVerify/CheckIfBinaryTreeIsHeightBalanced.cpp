/*
 * CheckIfBinaryTreeIsHeightBalanced.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: cvora
 */

// Cracking the Coding Interview Sol 4.1

/* program to check if a tree is height-balanced or not */
#include<stdio.h>
#include<stdlib.h>
#define bool int

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Returns the height of a binary tree */
int height(struct node* node);

/* Returns true if binary tree with root as root is height-balanced */
bool isBalancedSol1(struct node *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */

   /* If tree is empty then return true */
   if(root == NULL)
    return 1;

   /* Get the height of left and right sub trees */
   lh = height(root->left);
   rh = height(root->right);

   if( abs(lh-rh) <= 1 &&
		   isBalancedSol1(root->left) &&
		   isBalancedSol1(root->right))
     return 1;

   /* If we reach here then tree is not height-balanced */
   return 0;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* returns maximum of two integers */
int max(int a, int b)
{
  return (a >= b)? a: b;
}

/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;

   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(height(node->left), height(node->right));
}

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

int checkHeight(struct node* root){
	if(root == NULL){
		return 0; // Height of 0
	}

	// Check if left is balanced
	int leftHt = checkHeight(root->left);
	if(leftHt == -1){
		return -1; // Not balanced
	}

	// Check if right is balanced
	int rightHt = checkHeight(root->right);
	if(rightHt == -1){
		return -1; // Not balanced
	}

	// Check if current node is balanced
	if(abs(leftHt-rightHt) > 1){
		return -1; // Not balanced
	}else{
		// return height
		return max(leftHt,rightHt) + 1;
	}
}

bool isBalancedSol2(struct node* root){
	if(checkHeight(root) == -1){
		return false;
	}else{
		return true;
	}
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if(isBalancedSol1(root))
      printf("Tree is balanced \n");
    else
      printf("Tree is not balanced \n");

    if(isBalancedSol2(root))
      printf("Tree is balanced \n");
    else
      printf("Tree is not balanced \n");

    getchar();
    return 0;
}



