/*
 * GetLevelOfNodeInBinaryTree.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: cvora
 */

#include<stdio.h>

/**
 * Maximum depth or height of the below tree is 3.
            3
          /   \
        2      5
      /  \
    1     4

	For example, consider the following tree. If the input key is 3, then your
	function should return 1. If your input key is 4, then your function should
	return 3. And for key which is not present in key, then your function should
	return 0.
 */


/* A tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/*
 * The idea is to start from the root and level as 1.
 * If the key matches with root’s data, return level.
 * Else recursively call for left and right subtrees with level as level + 1.
 */

/* Helper function for getLevel().  It returns level of the data if data is
   present in tree, otherwise returns 0.*/
int getLevelUtil(struct node *node, int data, int level)
{
    if (node == NULL)
        return 0;

    if (node->data == data)
        return level;

    int downlevel = getLevelUtil(node->left, data, level+1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(node->right, data, level+1);
    return downlevel;
}

/* Returns level of given data value */
int getLevel(struct node *node, int data)
{
    return getLevelUtil(node,data,1);
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
    struct node *root = new struct node;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    for (x = 1; x <=5; x++)
        printf(" Level of %d is %d\n", x, getLevel(root, x));

    getchar();
    return 0;
}


