#include<iostream>
#include<string.h>
#include <stddef.h>
#include <stdlib.h>     /* malloc, free, rand */
#include "require.h"

using namespace std;


#define TRUE 1
#define FALSE 0
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
              //   cout<<*q<<endl;
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
         //cout<<*q<<endl;
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

void deletetree(struct btree **q)
{
     if(*q==NULL)
     return;
     
     deletetree(&((*q)->left));
     deletetree(&((*q)->right));
     cout<<"Deleting Node "<<(*q)->data<<endl;
     free(*q);
     *q = NULL;
}

int main()
{   
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
          insert(&p,data[i])  ;
     //     cout<<p<<endl;
    }
      //cout<<"In order "<<endl;
      inorder(p);
      cout<<"--------------------------"<<endl;
      cout<<"Now Deleting entire BST"<<endl;
      deletetree(&p);
      cout<<"-----------------------------"<<endl;
      inorder(p);
      return 0;
}
      
