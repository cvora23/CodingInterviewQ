/*
 * ReverseLevelOrderTraversal.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

// A recursive C program to print REVERSE level order traversal

/*
 * Let us consider the below tree for example

            1
          /   \
        2      3
      /  \
    4     5

    Reverse Level order traversal of the above tree is 4 5 2 3 1

    */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/* A binary tree node has data, pointer to left and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/*Function protoypes*/
void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

/*
 * METHOD1 (Recursive)
 * We can easily modify the method 1 of the normal level order traversal.
 * In method 1, we have a method printGivenLevel() which prints a given level number.
 * The only thing we need to change is, instead of calling printGivenLevel()
 * from first level to last level, we call it from last level to first level.
 */

/* Function to print REVERSE level order traversal a tree*/
void reverseLevelOrder1(struct node* root)
{
    int h = height(root);
    int i;
    for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

/*
 * METHOD 2 (Using Queue and Stack)
 * The method 2 of normal level order traversal can also be easily modified to print level order
 * traversal in reverse order. The idea is to use a stack to get the reverse level order. If we do
 * normal level order traversal and instead of printing a node, push the node to a stack and then print
 * contents of stack, we get “5 4 3 2 1″ for above example tree, but output should be “4 5 2 3 1″.
 * So to get the correct sequence (left to right at every level), we process children of a node in
 * reverse order, we first push the right subtree to stack, then left subtree.
 */

/* Given a binary tree, print its nodes in reverse level order */
void reverseLevelOrder2(node* root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);

    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);

        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT

        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }

    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
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

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Reverse Level Order traversal of binary tree is \n");
    reverseLevelOrder1(root);

    printf("\n Reverse Level Order traversal of binary tree is \n");
    reverseLevelOrder2(root);

    return 0;
}


