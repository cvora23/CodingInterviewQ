/*
 * GetRankGivenStreamOfNumbers.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: cvora
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

/* just add elements to test */
/* NOTE: A sorted array results in skewed tree */
int ele[] = { 20, 8, 22, 4, 12, 10, 14 };

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
		int right_rank = root->right == NULL ? -1:getRank(root->right,d);
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

