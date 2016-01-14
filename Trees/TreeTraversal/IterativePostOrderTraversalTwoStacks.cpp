/*
 * IterativePostOrderTraversal.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: cvora
 */

// C program for iterative postorder traversal using two stacks
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;

// Maximum stack size
#define MAX_SIZE 100

// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// recursive
void printPostorder(Node* node){

	if(node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout<<"node->data:"<<node->data<<endl;
}

/*
 * Iterative post order is more complex than other two traversals
 * (due to its nature of non-tails recursion, there is an extra statement
 * after the final recursive call to itself). Post order can be done
 * easily using two stacks though. The idea is to push reverse post order
 * traversal to stack. Once we have reverse postorder traversal in a stack,
 * we can just pop all items one by one from the stack and print them,
 * this order of printing will be in post order because of LIFO property
 * of stacks. Now the question is, how to get reverse post order elements
 * in a stack - the other stack is use for this purpose.
 * * Let us consider the below tree for example

            1
          /   \
        2      3
      /  \	  /	\
    4     5  6   7
    For example in the following tree, we need to get 1,3,7,6,2,5,4 in a stack.
    If take a closer look at this sequence, we can observe that this sequence is very similar
    to preorder traversal. The only difference is right child is visited before before left child
    and therefore sequence is root right left instead of root left right. So we can do something
    like iterative preorder traversal with foll differences.
    a) Instead of printing an item, we push it to a stack.
    b) We push left subtree before right subtree.

    Follwoing is complete algo: After step 2, we get reverese postorder traversal in second
    stack. We use first stack to get this order.

    1: Push root to first stack.
    2: Loop while first stack is not empty
    	2.1 Pop a node from first stack and push it to second stack
    	2.2 Push left and right children of popped node to first stack.
    3: Print contents of second stack.
 */
void postOrderIterative(struct Node* root)
{
	std::stack<Node*> s1;
	std::stack<Node*> s2;

	s1.push(root);
	struct Node* node;

	while(!s1.empty()){
		node = s1.top();
		s1.pop();
		s2.push(node);
		if(node->left){
			s1.push(node->left);
		}
		if(node->right){
			s1.push(node->right);
		}
	}

	while(!s2.empty()){
		node = s2.top();
		cout<<" "<<node->data<<" ";
		s2.pop();
	}

}

// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    postOrderIterative(root);

    return 0;
}

