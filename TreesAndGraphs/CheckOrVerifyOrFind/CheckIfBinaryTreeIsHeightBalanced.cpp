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

/*
 * Consider a height-balancing scheme where following conditions should be checked to determine
 * if a binary tree is balanced.
	An empty tree is height-balanced. A non-empty binary tree T is balanced if:
	1) Left subtree of T is balanced
	2) Right subtree of T is balanced
	3) The difference between heights of left subtree and right subtree is not more than 1.
 */

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

/*
 * ALGO:
 * To check if a tree is height-balanced, get the height of left and right subtrees.
 *  Return true if difference between heights is not more than 1 and left and right
 *  subtrees are balanced, otherwise return false.
 */

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

/*
 * ALGO:
 * Above solution can be optimized by calculating the height in the
 * same recursion rather than calling height() function separately.
 */
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

    /* Constructed binary tree is
                 1
               /   \
             2      3
           /  \    /
         4     5  6
        /
       7
      */
      struct node *root1 = newNode(1);
      root1->left = newNode(2);
      root1->right = newNode(3);
      root1->left->left = newNode(4);
      root1->left->right = newNode(5);
      root1->right->left = newNode(6);
      root1->left->left->left = newNode(7);

      if(isBalancedSol1(root1))
        printf("Tree is balanced \n");
      else
        printf("Tree is not balanced \n");

      if(isBalancedSol2(root1))
        printf("Tree is balanced \n");
      else
        printf("Tree is not balanced \n");


    getchar();
    return 0;
}



