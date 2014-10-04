#include<iostream>
#include<stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

using namespace std;

struct node
{
       struct node *left;
       int data;
       struct node *right;
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


void insert(struct node **q,int num)
{
     if(*q==NULL)
     {
                 *q = (struct node *)malloc(sizeof(struct node));
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

int minValue(struct node* node) {
  struct node* current = node;
 
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  cout<<current->data<<endl;
  return(current->data);
}
 
int maxValue(struct  node* node) {
  struct node* current = node;
 
  /* loop down to find the leftmost leaf */
  while (current->right != NULL) {
    current = current->right;
  }
  return(current->data);
}
 
/* Returns true if a binary tree is a binary search tree */
int isBST1(struct node* node)
{
  if (node == NULL)
    return(TRUE); 
 
  /* false if the max of the left is > than us */
  if (node->left!=NULL && maxValue(node->left) > node->data)
    return(FALSE); 
 
  /* false if the min of the right is <= than us */
  if (node->right!=NULL && minValue(node->right) < node->data)
  { 
    //cout<<"Here"<<endl;
    return(FALSE); 
  }
 
  /* false if, recursively, the left or right is not a BST */
  if (!isBST1(node->left) || !isBST1(node->right))
  { 
    //cout<<"Here"<<endl;
    return(FALSE); 
    
  }
 
  /* passing all that, it's a BST */
  return(TRUE);
}

bool isBST2(struct node* root)
{
	   static struct node *prev = NULL;

	    // traverse the tree in inorder fashion and keep track of prev node
	    if (root)
	    {
	        if (!isBST2(root->left))
	          return false;

	        // Allows only distinct valued nodes
	        if (prev != NULL && root->data <= prev->data)
	          return false;

	        prev = root;

	        return isBST2(root->right);
	    }

	    return true;
}


int main()
{   

    /* Let us construct the following Tree
      60
     /  \
   55    70
  /     /  \
45     65    80
  */

  struct node *root = newNode(60);

  root->left        = newNode(55);
  root->right       = newNode(70);

  root->left->left  = newNode(45);

  root->right->left  = newNode(65);
  root->right->right  = newNode(80);


#if 0
    struct btree *p;
    p =NULL;
    int number,data;
    cout<<"Enter the number of data items to be inserted"<<endl;
    cin>>number;
   // cout<<p<<endl;
    for(int i=0;i<number;i++)
    {      
          cout<<"Enter the data"<<endl;
          cin>>data;
          insert(&p,data)  ;
     //     cout<<p<<endl;
    }
    if(isBST1(p))
    cout<<"The given Binary Tree is Binary Search Tree"<<endl;
    else
    cout<<"The given Binary Tree is not a Binary Search Tree"<<endl;
#endif

    if(isBST1(root))
    cout<<"The given Binary Tree is Binary Search Tree"<<endl;
    else
    cout<<"The given Binary Tree is not a Binary Search Tree"<<endl;
    if(isBST2(root))
    cout<<"The given Binary Tree is Binary Search Tree"<<endl;
    else
    cout<<"The given Binary Tree is not a Binary Search Tree"<<endl;


    return 0;
}
