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

// A utility function to print inorder traversal of a Binary Tree
void printInorder (treeNode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
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

    printInorder(p);

    return 0;
}
