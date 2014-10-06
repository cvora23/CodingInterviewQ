/*
 * LargestBSTinBinaryTree.cpp
 *
 *  Created on: Sep 3, 2013
 *      Author: cvora
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

/*
 Given a Binary Tree, write a function that returns the size of the largest subtree
 which is also a Binary Search Tree (BST). If the complete Binary Tree is BST,
 then return the size of whole tree.
 Examples:

Input:
      5
    /  \
   2    4
 /  \
1    3

Output: 3
The following subtree is the maximum size BST subtree
   2
 /  \
1    3


Input:
       50
     /    \
  30       60
 /  \     /  \
5   20   45    70
              /  \
            65    80
Output: 5
The following subtree is the maximum size BST subtree
      60
     /  \
   45    70
        /  \
      65    80

 *
 */

int max(int x, int y)
{
  return (x < y) ? y : x;
}

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Computes the number of nodes in a tree. */
int size(struct node* node)
{
  if (node==NULL)
    return 0;
  else
    return(size(node->left) + 1 + size(node->right));
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

bool isBST(struct node* root,bool newRootNode = false)
{
	   static struct node *prev = NULL;
	   if(newRootNode)
	   {
		   prev = NULL;
	   }
	    // traverse the tree in inorder fashion and keep track of prev node
	    if (root)
	    {
	        if (!isBST(root->left))
	        {
	          return false;
	        }

	        // Allows only distinct valued nodes
	        if (prev != NULL && root->data <= prev->data)
	        {
	          return false;
	        }

	        prev = root;

	        return isBST(root->right);
	    }

	    return true;
}

/*
 * Method 1 (Simple but inefficient)
	Start from root and do an inorder traversal of the tree. For each node N,
	check whether the subtree rooted with N is BST or not. If BST, then return
	size of the subtree rooted with N. Else, recur down the left and right subtrees
	and return the maximum of values returned by left and right subtrees.
	Time Complexity: The worst case time complexity of this method will be O(n^2).
	Consider a skewed tree for worst case analysis.
 */
int largestBST1(struct node* root)
{
	if(isBST(root,true))
	{
		return size(root);
	}
	else
	{
		return max(largestBST1(root->left),largestBST1(root->right));
	}
}

int largestBST2(struct node* root, int& min, int& max, int& size,struct node* & bstRoot);


struct node* findLargestBSTSubtree(struct node *root,int& maxNodes) {
  struct node *bstRoot = NULL;
  int min, max;
  maxNodes = INT_MIN;
  largestBST2(root, min, max, maxNodes,bstRoot);
  return bstRoot;
}

int largestBST2(struct node* root, int& min, int& max, int& size,struct node* & bstRoot)
{
  if(root == NULL)
    return 0;

  int leftMin = INT_MIN, rightMin = INT_MIN;
  int leftMax = INT_MAX, rightMax = INT_MAX;
  int x,y;

  x = largestBST2(root->left, leftMin, leftMax, size,bstRoot);
  y = largestBST2(root->right, rightMin, rightMax, size,bstRoot);

  if(x==-1 || y ==-1)
    return -1;
  if(x==0)
  {
    leftMax = root->data;
    leftMin = root->data;
  }
  if(y==0)
  {
    rightMin = root->data;
    rightMax = root->data;
  }

  if(root->data < leftMax || root->data > rightMin)
    return -1;

  min = leftMin;
  max = rightMax;


  if(x+y+1 > size){
    size = x+y+1;
    bstRoot = root;
  }
  return x+y+1;
}

void inorder(struct node *q)
{
 if(q!=NULL)
 {
             inorder(q->left);
             printf("%d\n",q->data);
             inorder(q->right);
            //q = q->right;
 }
 else return;
}


/* Driver program to test above functions*/
int main()
{
    /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */

  struct node *root = newNode(50);

  root->left        = newNode(10);
  root->right       = newNode(60);

  root->left->left  = newNode(5);
  root->left->right = newNode(20);

  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);

  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);

  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
  5     65    80
  */
  printf(" Size of the largest BST is %d \n", largestBST1(root));
  int size;
  struct node* largestBSTroot = findLargestBSTSubtree(root,size);
  inorder(largestBSTroot);
  printf(" Size of the largest BST is %d \n",size);
  return 0;
}
