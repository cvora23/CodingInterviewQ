/*
 * LCAinBST.cpp
 *
 *  Created on: Sep 9, 2013
 *      Author: cvora
 */


// A recursive C program to find LCA of two nodes n1 and n2.
#include <stdio.h>
#include <stdlib.h>

/*
 *
            20
          /   \
        8      22
      /  \
     4    12
         /  \
        10   14

Given values of two nodes in a Binary Search Tree, write a c
program to find the Lowest Common Ancestor (LCA). You may assume that both
the values exist in the tree.
The function prototype should be as follows:

 struct node *lca(node* root, int n1, int n2)
 n1 and n2 are two given values in the tree with given root.
 For example, consider the BST in diagram, LCA of 10 and 14 is 12 and LCA of 8 and 14 is 8.

Following is definition of LCA from Wikipedia:
Let T be a rooted tree. The lowest common ancestor between two nodes n1
and n2 is defined as the lowest node in T that has both n1 and n2 as
descendants (where we allow a node to be a descendant of itself).
The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that
is located farthest from the root. Computation of lowest common ancestors
may be useful, for instance, as part of a procedure for determining the
distance between pairs of nodes in a tree: the distance from n1 to n2 can
be computed as the distance from the root to n1, plus the distance from the
root to n2, minus twice the distance from the root to their lowest common ancestor.
 */

struct node
{
    int data;
    struct node* left, *right;
};

/*
 * ALGO1:
 * If we are given a BST where every node has parent pointer,
 * then LCA can be easily determined by traversing up using parent pointer
 * and printing the first intersecting node.
 */


/*
 * ALGO2:
 * We can solve this problem using BST properties. We can recursively traverse the BST from root.
 * The main idea of the solution is, while traversing from top to bottom, the first node
 * n we encounter with value between n1 and n2, i.e., n1 < n < n2 or same as one of the
 * n1 or n2, is LCA of n1 and n2 (assuming that n1 < n2). So just recursively traverse
 * the BST in, if node's value is greater than both n1 and n2 then our LCA lies in left
 * side of the node, if it's is smaller than both n1 and n2, then LCA lies on right side.
 * Otherwise root is LCA (assuming that both n1 and n2 are present in BST)
 *
 */
/* Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
struct node *lca1(struct node* root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca1(root->left, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca1(root->right, n1, n2);

    return root;
}

/*
 * ALGO3:
 * SAME ABOVE SOLUTION - ITERATIVE THOUGH
 */
/* Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
struct node *lca2(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
         // If both n1 and n2 are greater than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
           root = root->left;

        // If both n1 and n2 are smaller than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
           root = root->right;

        else break;
    }
    return root;
}


/* Helper function that allocates a new node with the given data.*/
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = node->right = NULL;
    return(node);
}

/* Driver program to test mirror() */
int main()
{
    // Let us construct the BST shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct node *t;
    t= lca1(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca1(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca1(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    t= lca2(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca2(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca2(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    getchar();
    return 0;
}
