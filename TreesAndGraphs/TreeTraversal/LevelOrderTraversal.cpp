/*
 * LevelOrderTraversal.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */


#include <stdio.h>
#include <stdlib.h>

/*
 * Let us consider the below tree for example

            1
          /   \
        2      3
      /  \
    4     5

    Level order traversal of the above tree is 1 2 3 4 5

	Level order traversal of a tree is breadth first traversal for the tree.

    */

#define MAX_Q_SIZE 500


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the furthest leaf node.*/
int height(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(node->left);
     int rheight = height(node->right);

     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->data);
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}

/**
 * Algo 1:
 * There are basically two functions in this method. One is to print
 * all nodes at a given level (printGivenLevel) , and other is to print
 * level order traversal of the tree (printLevelOrder1) .
 * printLevelOrder1 makes use of printGivenLevel to print nodes at all levels
 * one by one starting from root.
 */

/*Function to print level order traversal of tree
printLevelorder(tree)
for d = 1 to height(tree)
   printGivenLevel(tree, d);

Function to print all nodes at a given level
printGivenLevel(tree, level)
if tree is NULL then return;
if level is 1, then
    print(tree->data);
else if level greater than 1, then
    printGivenLevel(tree->left, level-1);
    printGivenLevel(tree->right, level-1);
    */

/* Function to print level order traversal a tree*/
void printLevelOrder1(struct node* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}


/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
  struct node **queue =
   (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);

  *front = *rear = 0;
  return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
  queue[*rear] = new_node;
  (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
  (*front)++;
  return queue[*front - 1];
}

/*
 * For each node, first the node is visited and then it’s child nodes are put in a FIFO queue.
 * 1) Create an empty queue q
 * 2) temp_node = root // start from root
 * 3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children (first left then right children) to q
    c) Dequeue a node from q and assign it’s value to temp_node
 */

/* Given a binary tree, print its nodes in level order
   using array for implementing queue */
void printLevelOrder2(struct node* root)
{
  int rear, front;
  struct node **queue = createQueue(&front, &rear);
  struct node *temp_node = root;

  while(temp_node)
  {
    printf("%d ", temp_node->data);

    /*Enqueue left child */
    if(temp_node->left)
      enQueue(queue, &rear, temp_node->left);

    /*Enqueue right child */
    if(temp_node->right)
      enQueue(queue, &rear, temp_node->right);

    /*Dequeue node and make it temp_node*/
    temp_node = deQueue(queue, &front);
  }
}

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

/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Level Order traversal of binary tree is \n");
  printLevelOrder1(root);

  printf(" \n Level Order traversal of binary tree is \n");
  printLevelOrder2(root);

  getchar();
  return 0;
}
