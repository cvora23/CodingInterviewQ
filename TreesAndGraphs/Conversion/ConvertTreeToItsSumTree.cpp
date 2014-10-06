/*
 * ConvertTreeToItsSumTree.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: cvora
 */



#include<stdio.h>

/*
 * Given a Binary Tree where each node has positive and negative values.
 * Convert this to a tree where each node contains the sum of the left and
 * right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree

                  10
               /      \
	         -2        6
            /   \      /  \
	       8     -4    7    5
should be changed to

              20(4-2+12+6)
               /      \
	 	 	 4(8-4)     12(7+5)
           /   \      /  \
	 	 0      0    0    0
 */

/* A tree node structure */
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

/*
 * Solution
 * Do a traversal of the given tree. In the traversal, store the old value of
 * the current node, recursively call for left and right subtrees and change the
 * value of current node as sum of the values returned by the recursive calls.
 * Finally return the sum of new value and value (which is sum of values in
 * the subtree rooted with this node).
 */
// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(struct node *node)
{
    // Base case
    if(node == NULL)
      return 0;

    // Store the old value
    int old_val = node->data;

    // Recursively call for left and right subtrees and store the sum as
    // new value of this node
    node->data = toSumTree(node->left) + toSumTree(node->right);

    // Return the sum of values of nodes in left and right subtrees and
    // old_value of this node
    return node->data + old_val;
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
  struct node *temp = new struct node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

/* Driver function to test above functions */
int main()
{
  struct node *root = NULL;
  int x;

  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);

  toSumTree(root);

  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);

  getchar();
  return 0;
}
