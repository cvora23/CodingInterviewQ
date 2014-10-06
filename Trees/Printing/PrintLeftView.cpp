/*
 * PrintLeftView.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */



#include<stdio.h>
#include<stdlib.h>

/*
 * Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes
 * visible when tree is visited from left side. Left view of following tree is 12, 10, 25.

          12
       /     \
     10       30
            /    \
          25      40

The left view contains all nodes that are first nodes in their levels.
A simple solution is to do level order traversal and print the first node in every level.
 */

struct node
{
	int data;
	struct node* left,*right;
};

// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/*
 * The problem can also be solved using simple recursive traversal.
 * We can keep track of level of a node by passing a parameter to all recursive calls.
 * The idea is to keep track of maximum level also. Whenever we see a node whose level
 * is more than maximum level so far, we print the node because this is the first node
 * in its level (Note that we traverse the left subtree before right subtree).
 * Following is C implementation of this approach.
 */
// Recursive function to print left view of a binary tree.
void leftViewUtil(struct node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;

    // If this is the first node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }

    // Recur for left and right subtrees
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}

// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// Driver Program to test above functions
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    leftView(root);

    return 0;
}
