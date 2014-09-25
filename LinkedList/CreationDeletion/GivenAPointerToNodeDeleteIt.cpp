/*
 * GivenAPointerToNodeDeleteIt.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// Solution Cracking the Coding Interview 2.3

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
   struct node* new_node =
             (struct node*) malloc(sizeof(struct node));

   /* put in the data  */
   new_node->data  = new_data;

   /* link the old list off the new node */
   new_node->next = (*head_ref);

   /* move the head to point to the new node */
   (*head_ref)    = new_node;
}

void printList(struct node *head)
{
   struct node *temp = head;
   while(temp != NULL)
   {
      printf("%d  ", temp->data);
      temp = temp->next;
   }
}

/**
 * 	ALGO1:
 *	Simple Solution
 *	===============
 *	Traverse the linked list until you find the node you want to delete.
 *	But this solution requires pointer to head node which contradicts the problem
 *	statement
 *
 *	ALGO2:
 *	Fast Solution
 *	==================
 *	Copy the data from next node to the node to be deleted and delete the
 *	next node.Solution wont work if node to be deleted is the last node
 *	of the list. To make this work we can mark end node as dummy node. But
 *	the programs/functions that are using this function should be modified.
 *
 */
void deleteNodeSol1(struct node *node_ptr)
{
   struct node *temp = node_ptr->next;
   node_ptr->data    = temp->data;
   node_ptr->next    = temp->next;
   free(temp);
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    /* Use push() to construct below list
    1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    printf("\n Before deleting \n");
    printList(head);

    /* I m deleting the head itself.
        You can check for more cases */
    deleteNodeSol1(head);

   printf("\n After deleting \n");
   printList(head);
   getchar();
}


