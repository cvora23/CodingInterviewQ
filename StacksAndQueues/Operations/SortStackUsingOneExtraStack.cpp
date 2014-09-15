/*
 * SortStackUsingOneExtraStack.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: cvora
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// Cracking the Coding Interview Solution 3.6

/* structure of a stack node */
struct sNode
{
   int data;
   struct sNode *next;
};

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
  /* allocate node */
  struct sNode* new_node =
            (struct sNode*) malloc(sizeof(struct sNode));

  if(new_node == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }

  /* put in the data  */
  new_node->data  = new_data;

  /* link the old list off the new node */
  new_node->next = (*top_ref);

  /* move the head to point to the new node */
  (*top_ref)    = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
  int res;
  struct sNode *top;

  /*If stack is empty then error */
  if(*top_ref == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}

void printStack(struct sNode* top_ref){
	while(top_ref){
		cout<<top_ref->data<<endl;
		top_ref = top_ref->next;
	}
}

/* Peek for top element from stack*/
int peek(struct sNode* top_ref){
	if(top_ref)
		return top_ref->data;
}

struct sNode* sort(struct sNode* top_ref){
	struct sNode* r = NULL;
	while(top_ref){
		int tmp = pop(&top_ref);
		while(r && peek(r) > tmp){
			push(&top_ref,pop(&r));
		}
		push(&r,tmp);
	}
	return r;
}

int main(){

    struct sNode *top;
    top = NULL;
    push(&top,6);
    push(&top,5);
    push(&top,4);
    push(&top,2);

    cout<<"Before Sorting"<<endl;
    printStack(top);

    cout<<"After Sorting"<<endl;
    printStack(sort(top));

	return 0;
}
