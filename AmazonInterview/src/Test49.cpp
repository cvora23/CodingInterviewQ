/*
 * Test49.cpp
 *
 *  Created on: Feb 13, 2016
 *      Author: chintan
 */

/*
 *Serialize and Deserialize a Binary Tree
Serialization is to store tree in a file so that it can be later restored.
The structure of tree must be maintained. Deserialization is reading tree back from file.

Following are some simpler versions of the problem:

If given Tree is Binary Search Tree?
If the given Binary Tree is Binary Search Tree, we can store
it by either storing preorder or postorder traversal.
In case of Binary Search Trees, only preorder or postorder traversal
is sufficient to store structure information.

If given Binary Tree is Complete Tree?
A Binary Tree is complete if all levels are completely filled
except possibly the last level and all nodes of last level are
as left as possible (Binary Heaps are complete Binary Tree).
For a complete Binary Tree, level order traversal is sufficient
to store the tree. We know that the first node is root, next
two nodes are nodes of next level, next four nodes are nodes of 2nd level and so on.

If given Binary Tree is Full Tree?
A full Binary is a Binary Tree where every node has either
0 or 2 children. It is easy to serialize such trees as every
internal node has 2 children. We can simply store preorder
traversal and store a bit with every node to indicate whether
the node is an internal node or a leaf node.

How to store a general Binary Tree?
A simple solution is to store both Inorder and Preorder traversals.
This solution requires requires space twice the size of Binary Tree.
We can save space by storing Preorder traversal and a marker for NULL pointers.

Let the marker for NULL pointers be '-1'
Input:
     12
    /
  13
Output: 12 13 -1 -1

Input:
      20
    /   \
   8     22
Output: 20 8 -1 -1 22 -1 -1

Input:
         20
       /
      8
     / \
    4  12
      /  \
     10  14
Output: 20 8 4 -1 -1 12 10 -1 -1 14 -1 -1 -1

Input:
          20
         /
        8
      /
    10
    /
   5
Output: 20 8 10 5 -1 -1 -1 -1 -1

Input:
          20
            \
             8
              \
               10
                 \
                  5
Output: 20 -1 8 -1 10 -1 5 -1 -1

 */

// A C++ program to demonstrate serialization and deserialiation of
// Binary Tree

#include <stdio.h>
#include "BTree.h"

#define MARKER -1

// This function stores a tree in a file pointed by fp
void serialize(node *root, FILE *fp)
{
    // If current node is NULL, store marker
    if (root == NULL)
    {
        fprintf(fp, "%d ", MARKER);
        return;
    }

    // Else, store current node and recur for its children
    fprintf(fp, "%d ", root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

// This function constructs a tree from a file pointed by 'fp'
void deSerialize(node *&root, FILE *fp)
{
    // Read next item from file. If theere are no more items or next
    // item is marker, then return
    int val;
    if ( !fscanf(fp, "%d ", &val) || val == MARKER)
       return;

    // Else create node with this item and recur for children
    root = newNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}

/* Driver program to test above functions*/
int main()
{
    // Let us construct a tree shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    // Let us open a file and serialize the tree into the file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);

    // Let us deserialize the storeed tree into root1
    node*root1 = NULL;
    fp = fopen("tree.txt", "r");
    deSerialize(root1, fp);

    printf("Inorder Traversal of the tree constructed from file:\n");
    printInorder(root1);

    return 0;
}
