
#include<iostream>
#include<stddef.h>
#include <stdlib.h>
#include "require.h"

/**
 * Maximum depth or height of the below tree is 3.
            1
          /   \
        2      3
      /  \
    4     5

 */

#define TRUE 1
#define FALSE 0

using namespace std;

struct btree
{
       struct btree *left;
       int data;
       struct btree *right;
};

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

/*
 * Recursively calculates height of left and right subtree of a node and assign
 * height to the node as max of the heights of two children plus 1.
 *
 * ALGO:
 * 1: If tree is empty then return 0
 * 2: Else
 * 		a) Get the max depth of left subtree recursively i.e;
 * 			call maxDepth(tree->left-subtree)
 * 		b) Get the max depth of right subtree recursively i.e;
 * 			call maxDepth(tree->right-subtree)
 * 		c) Get the max of max depths of left and right subtrees and add 1 to it for current node.
 * 		   max_depth = (max depth of left subtree, max depth of right subtree) + 1
 * 		d) return max_depth
 **/
int maxDepth(struct btree *q)
{
     if(q==NULL)
     {
    	 return 0;
     }
     int hL = maxDepth(q->left);
     int hR = maxDepth(q->right);

     if(hL>hR)
     return (hL+1);
     else
     return (hR+1);
     
}

int main()
{   
    struct btree *p;
    p =NULL;
    int number;
    cout<<"Enter the number of data items to be inserted"<<endl;
    cin>>number;
    int* data = new int[number];
    for(int i=0;i<number;i++){
    	data[i] = getRand();
    }
    for(int i=0;i<number;i++){
    	cout<<data[i]<<endl;
    }
    for(int i=0;i<number;i++)
    {      
          insert(&p,data[i]);
    }
    
    cout<<"Depth of the tree is : "<<maxDepth(p)<<endl;
    system("exit");
    return 0;
}
