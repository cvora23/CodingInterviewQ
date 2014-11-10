/*
 * DeletingNode.cpp
 *
 *  Created on: Oct 2, 2014
 *      Author: cvora
 */

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "require.h"

using namespace std;


#define TRUE 1
#define FALSE 0
typedef struct btree
{
       struct btree *left;
       int data;
       struct btree *right;
}treeNode;

void insert(struct btree **q,int num)
{
     if(*q==NULL)
     {
		 *q = (struct btree *)malloc(sizeof(struct btree));
		 (*q)->left = NULL;
		 (*q)->data = num;
		 (*q)->right = NULL;
     }
     else
     {
         if(num<((*q)->data))
         insert(&((*q)->left),num);
         else
         insert(&((*q)->right),num);
     }
     return;
}

void inorder(struct btree *q)
{
	 if(q!=NULL)
	 {
		 inorder(q->left);
		 cout<<q->data<<endl;
		 inorder(q->right);
	 }
	 else return;
}

treeNode* FindMin(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
                return FindMin(node->left);
        else
                return node;
}

treeNode* FindMax(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->right) /* Go to the right sub tree to find the max element */
                return FindMax(node->right);
        else
                return node;
}

/**
 * Deleting a Node brings 3 different situations.
 * 1: Node to be deleted is leaf:
 * 		Simple just remove it from the tree.
 * 2: Node to be deleted has only one child.
 * 		Copy the child to the node and delete the child.
 * 3: Node to be deleted has two children
 * 		Find inorder successor of the node. Copy contents
 * 		of the inorder successor to the node and delete the
 * 		inorder successor. Note that inorder predessor can also be
 * 		used.
 *
 * The important thing to note is, inorder successor is needed only
 * when right child is not empty. In this particular case, inorder successor
 * can be obtained by finding the minimum value in right child of the node.
 */

treeNode * Delete(treeNode *node, int data)
{
	treeNode *temp;

	// base case
	if(node==NULL)
	{
		printf("Element Not Found");
	}
	/*
	 * if the key to be deleted is smaller than roots key
	 * then it lies in the left subtree
	 */
	else if(data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	/*
	 * if the key to be deleted is greater than roots key
	 * than it lies in right subtree
	 */
	else if(data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	/**
	 * if the key is same is roots key. Then this is the node
	 * to be deleted.
	 */
	else
	{
		/*
		 * Node with two children: Get the inorder successor (smallest in the right subtree)
		 * Now We can delete this node and replace with either minimum element
		 * in the right sub tree or maximum element in the left subtree
		 * */
		if(node->right && node->left)
		{
			/* Here we will replace with minimum element in the right sub tree */
			temp = FindMin(node->right);
			node -> data = temp->data;
			/* As we replaced it with some other node, we have to delete that node */
			node -> right = Delete(node->right,temp->data);
		}
		else
		{
			/* If there is only one or zero children then we can directly
			   remove it from the tree and connect its parent to its child */
			temp = node;
			if(node->left == NULL)
					node = node->right;
			else if(node->right == NULL)
					node = node->left;
			free(temp); /* temp is longer required */
		}
	}
	return node;

}


int main()
{
    srand((unsigned)time(0));
    struct btree *p;
    p =NULL;
    int number;
    cout<<"Enter the number of data items to be inserted"<<endl;
    cin>>number;
   // cout<<p<<endl;
    int* data = new int[number];
    for(int i=0;i<number;i++){
    	data[i] = getRand();
    }
    for(int i=0;i<number;i++)
    {
          insert(&p,data[i]);
     //     cout<<p<<endl;
    }
      cout<<"In order "<<endl;
      inorder(p);
      cout<<"--------------------------"<<endl;

      cout<<"Enter the data you want to delete"<<endl;
      int num;
      cin>>num;
      cout<<"----------------------------"<<endl;
      p = Delete(p,num);
      inorder(p);
}




