/*
 * DepthOfDepestOddLevelLeafNode.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */


// C program to find depth of the deepest odd level leaf node
#include <stdio.h>
#include <stdlib.h>

/*
 * Write a C code to get the depth of the deepest odd level leaf node in a binary tree.
 * Consider that level starts with 1. Depth of a leaf node is number of nodes on the
 * path from root to leaf (including both leaf and root).
 *
 * For example, consider the following tree.
 * The deepest odd level node is the node with value 9 and depth of this node is 5.
 * 		1
     /   \
    2     3
  /      /  \
 4      5    6
        \     \
         7     8
        /       \
       9         10
                 /
                11
 */

// A utility function to find maximum of two integers
int max(int x, int y) { return (x > y)? x : y; }

// A Binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to allocate a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/*
 * The idea is to recursively traverse the given binary tree and while traversing,
 *  maintain a variable “level” which will store the current node’s level in the tree.
 *  If current node is leaf then check “level” is odd or not.
 *  If level is odd then return it. If current node is not leaf,
 *  then recursively find maximum depth in left and right subtrees, and return maximum of the two depths.
 */

// A recursive function to find depth of the deepest odd level leaf
int depthOfOddLeafUtil(Node *root,int level)
{
    // Base Case
    if (root == NULL)
        return 0;

    // If this node is a leaf and its level is odd, return its level
    if (root->left==NULL && root->right==NULL && (level&1))
        return level;

    // If not leaf, return the maximum value from left and right subtrees
    return max(depthOfOddLeafUtil(root->left, level+1),
               depthOfOddLeafUtil(root->right, level+1));
}

/* Main function which calculates the depth of deepest odd level leaf.
  This function mainly uses depthOfOddLeafUtil() */
int depthOfOddLeaf(struct Node *root)
{
    int level = 1;
    return depthOfOddLeafUtil(root, level);
}

// Driver program to test above functions
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);

    printf("%d is the required depth\n", depthOfOddLeaf(root));
    getchar();
    return 0;
}

