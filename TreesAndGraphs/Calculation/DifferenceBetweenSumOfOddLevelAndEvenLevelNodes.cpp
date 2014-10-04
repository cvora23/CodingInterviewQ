/*
 * DifferenceBetweenSumOfOddLevelAndEvenLevelNodes.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

/*
 * Given a a Binary Tree, find the difference between the sum of nodes at
 * odd level and the sum of nodes at even level. Consider root as level 1,
 * left and right children of root as level 2 and so on.
 * For example, in the following tree, sum of nodes at odd level is (5+1+4+8)
 * which is 18. And sum of nodes at even level is (2+6+3+7+9) which is 27. Output
 * for following tree should be 18-27 which is -9.
   	  5
    /   \
   2     6
 /  \     \
1    4     8
    /     / \
   3     7   9


 */


// A recursive program to find difference between sum of nodes at
// odd level and sum at even level
#include <stdio.h>
#include <stdlib.h>

// Binary Tree node
struct node
{
    int data;
    struct node* left, *right;
};

// A utility function to allocate a new tree node with given data
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left =  node->right = NULL;
    return (node);
}

/*
 * ALGO1:
 * 	A straightforward method is to use level order traversal.
 *  In the traversal, check level of current node, if it is odd,
 *  increment odd sum by data of current node, otherwise increment even sum.
 *  Finally return difference between odd sum and even sum.
 */

/*
 * ALGO2:
 *	The problem can also be solved using simple recursive traversal.
 *	We can recursively calculate the required difference as, value of root’s data subtracted
 *	by the difference for subtree under left child and the difference for subtree under right child.
 */

// The main function that return difference between odd and even level nodes
int getLevelDiff(struct node *root)
{
   // Base case
   if (root == NULL)
         return 0;

   // Difference for root is root's data - difference for left subtree - difference for right subtree
   return root->data - getLevelDiff(root->left) - getLevelDiff(root->right);
}

// Driver program to test above functions
int main()
{
    struct node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
    printf("%d is the required difference\n", getLevelDiff(root));
    getchar();
    return 0;
}
