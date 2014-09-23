/*
 * GetRankGivenStreamOfNumbers.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: cvora
 */

// Cracking the coding interview solution 11.8
/*
 * Imagine you are reading in a stream of integers. Periodically, you wish
 * to be able to look up the rank of a number x (the number of values less than or equal to x).
 * Implement the data structures and algo to support these operations. That is implement the method
 * track(int x), which is called when each number is generated, and the method getRankOfNumber(int x), which
 * returns the number of value less than or equal to x (not including x itself)
 */


#include <iostream>
#include <stdlib.h>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

/* same alias */
typedef struct node_t node_t;

/* Binary tree node */
struct node_t
{
    int data;
    int lCount;

    node_t* left;
    node_t* right;
};

/* Iterative insertion
   Recursion is least preferred unless we gain something
*/
node_t *insert_node(node_t *root, node_t* node)
{
    /* A crawling pointer */
    node_t *pTraverse = root;
    node_t *currentParent = root;

    // Traverse till appropriate node
    while(pTraverse)
    {
        currentParent = pTraverse;

        if( node->data < pTraverse->data )
        {
            /* We are branching to left subtree
               increment node count */
            pTraverse->lCount++;
            /* left subtree */
            pTraverse = pTraverse->left;
        }
        else
        {
            /* right subtree */
            pTraverse = pTraverse->right;
        }
    }

    /* If the tree is empty, make it as root node */
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        /* Insert on left side */
        currentParent->left = node;
    }
    else
    {
        /* Insert on right side */
        currentParent->right = node;
    }

    return root;
}

/* Elements are in an array. The function builds binary tree */
node_t* binary_search_tree(node_t *root, int keys[], int const size)
{
    int iterator;
    node_t *new_node = NULL;

    for(iterator = 0; iterator < size; iterator++)
    {
        new_node = (node_t *)malloc( sizeof(node_t) );

        /* initialize */
        new_node->data   = keys[iterator];
        new_node->lCount = 0;
        new_node->left   = NULL;
        new_node->right  = NULL;

        /* insert into BST */
        root = insert_node(root, new_node);
    }

    return root;
}

/**
 * Algo 1:
 * 1: A relative easy way to implement this would be to have an array that holds all
 * the elements in sorted order. When a new element comes in, we need to shift the other
 * elements to make room. Implementing getRankOfNumber would be quite efficient though.
 * We would simply perform a binary search for n, and return the index. However, this is very
 * inefficient for inserting elements(that is, the track(int x) function). We need a data
 * structure which is good at keeping relative ordering as well as updating when we insert new elements.
 * A BST can just do that
 */

/**
 * Algo 2:
 * Instead of inserting elements into an array, we just insert elements in BST. The method
 * track(int x) will run O(log n) time, where n is the size of the tree (provided, of course,
 * that the tree is balanced.). To find the rank of a number, we could do an-inorder traversal, keeping
 * counter as we traverse. The goal is that , by the time we find x, counter will equal number of
 * elements less than x.
 * As long as we're moving left during searching for x, the counter won't change. Why?
 * Because all the values we're skipping on the right side are greater than x. After all, the very
 * smallest element(with rank 1) is the leftmost side.
 * When we move to the right though, we skip over bunch of elements on the left.
 * All of these elements are less than x, so we'll need to increment counter by number of
 * elements in left subtree.
 * Rather than counting size of left subtree (which would be inefficient), we can track this info
 * as we add new elements into the tree.
 */

int getRank(node_t* root,int d){
	if(!root){
		return -1 ; // Error
	}
	if(d == root->data){
		return root->lCount;
	}else if(d < root->data){
		if(root->left == NULL){
			return -1; // ERROR
		}else{
			return getRank(root->left,d);
		}
	}else{
		int right_rank = (root->right == NULL ? -1:getRank(root->right,d));
		if(right_rank == -1){
			return -1; // ERROR
		}
		else {
			return root->lCount + 1 + right_rank;
		}
	}
}

/* Driver program to test above functions */
int main(void)
{
    /* just add elements to test */
    int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    int i;
    node_t* root = NULL;

    /* Creating the tree given in the above diagram */
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));

    cout<<getRank(root,22)<<endl;
    cout<<getRank(root,4)<<endl;
    cout<<getRank(root,14)<<endl;
    cout<<getRank(root,109)<<endl;
    cout<<getRank(root,20)<<endl;
    cout<<getRank(root,12)<<endl;
    cout<<getRank(root,220)<<endl;
    cout<<getRank(root,8)<<endl;

    return 0;
}

