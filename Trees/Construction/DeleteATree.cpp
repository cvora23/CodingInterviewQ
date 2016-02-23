/*
 * DeleteATree.cpp
 *
 *  Created on: Sep 9, 2013
 *      Author: cvora
 */


#include<stdio.h>
#include<stdlib.h>


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

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

/*
 * ALGO:
 * To delete a tree we must traverse all the nodes of the tree and delete them one by one.
 * So which traversal we should use – Inorder or Preorder or Postorder.
 * Answer is simple – Postorder, because before deleting the parent node we should delete
 * its children nodes first
 * We can delete tree with other traversals also with extra space complexity but
 * why should we go for other traversals if we have Postorder available which does
 * the work without storing anything in same time complexity.
 */

/*  This function is same as deleteTree() in the previous program */
void _deleteTree(struct node* node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    printf("\n Deleting node: %d", node->data);
    free(node);
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(struct node** node_ref)
{
  _deleteTree(*node_ref);
  *node_ref = NULL;
}

/* Driver program to test deleteTree function*/
int main()
{
    struct node *root 		= 	newNode(1);
    root->left            	= 	newNode(2);
    root->right         	= 	newNode(3);
    root->left->left     	= 	newNode(4);
    root->left->right   	= 	newNode(5);

    // Note that we pass the address of root here
    deleteTree(&root);
    printf("\n Tree deleted ");

    getchar();
    return 0;
}


