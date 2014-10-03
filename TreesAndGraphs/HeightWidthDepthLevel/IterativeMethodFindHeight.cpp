/*
 * IterativeMethodFindHeight.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

/* Program to find height of the tree by Iterative Method */
#include <iostream>
#include <queue>
using namespace std;


/**
 * There are two conventions to define height of Binary Tree
	1) Number of nodes on longest path from root to the deepest node.
	2) Number of edges on longest path from root to the deepest node.

 * Maximum depth or height of the below tree is 3.
            1
          /   \
        2      3
      /  \
    4     5

 */


// A Binary Tree Node
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

/*
 *  How to find height without recursion? We can use level order traversal to find height without recursion.
 *  The idea is to traverse level by level. Whenever move down to a level, increment height by 1
 *  (height is initialized as 0). Count number of nodes at each level, stop traversing when count
 *  of nodes at next level is 0.
 *
 *  Following is detailed algorithm to find level order traversal using queue.

Create a queue.
Push root into the queue.
height = 0
Loop
	nodeCount = size of queue

        // If number of nodes at this level is 0, return height
	if nodeCount is 0
		return Height;
	else
		increase Height

        // Remove nodes of this level and add nodes of
        // next level
	while (nodeCount > 0)
		pop node from front
		push its children to queue
		decrease nodeCount
       // At this point, queue has nodes of next level
 *
 */

// Iterative method to find height of Bianry Tree
int treeHeight(node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Create an empty queue for level order tarversal
    queue<node *> q;

    // Enqueue Root and initialize height
    q.push(root);
    int height = 0;

    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            return height;

        height++;

        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }
}


// Utility function to create a new tree node
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree is " << treeHeight(root);
    return 0;
}
