/*
 * CheckIfLeavesAtSameLevel.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

// C program to check if all leaves are at same level
#include <stdio.h>
#include <stdlib.h>

/*
 * Given a Binary Tree, check if all leaves are at same level or not.

          12
        /    \
      5       7
    /          \
   3            1
  Leaves are at same level

          12
        /    \
      5       7
    /
   3
   Leaves are Not at same level


          12
        /
      5
    /   \
   3     9
  /      /
 1      2
 Leaves are at same level
 */

// A binary tree node
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
 * The idea is to first find level of the leftmost leaf and store
 * it in a variable leafLevel. Then compare level of all other leaves
 * with leafLevel, if same, return true, else return false. We traverse
 * the given Binary Tree in Preorder fashion. An argument leaflevel is
 * passed to all calls. The value of leafLevel is initialized as 0 to
 * indicate that the first leaf is not yet seen yet. The value is updated
 * when we find first leaf. Level of subsequent leaves (in preorder) is
 * compared with leafLevel.
 */

/* Recursive function which checks whether all leaves are at same level */
bool checkUtil(struct Node *root, int level, int *leafLevel)
{
    // Base case
    if (root == NULL)  return true;

    // If a leaf node is encountered
    if (root->left == NULL && root->right == NULL)
    {
        // When a leaf node is found first time
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return true;
        }

        // If this is not first leaf node, compare its level with
        // first leaf's level
        return (level == *leafLevel);
    }

    // If this node is not leaf, recursively check left and right subtrees
    return checkUtil(root->left, level+1, leafLevel) &&
           checkUtil(root->right, level+1, leafLevel);
}

/* The main function to check if all leafs are at same level.
   It mainly uses checkUtil() */
bool check(struct Node *root)
{
   int level = 0, leafLevel = 0;
   return checkUtil(root, level, &leafLevel);
}

// Driver program to test above function
int main()
{
    // Let us create tree shown in third example
    struct Node *root = newNode(12);
    root->left = newNode(5);
    root->right = newNode(7);
    root->left->left = newNode(3);
    if (check(root))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");
    getchar();
    return 0;
}


