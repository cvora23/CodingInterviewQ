/*
 * SortedInsert.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

/* Program to insert in a sorted list */
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsert(struct node** head_ref, struct node* new_node)
{
  struct node* current;
  /* Special case for the head end */
  if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
  {
    new_node->next = *head_ref;
    *head_ref = new_node;
  }
  else
  {
    /* Locate the node before the point of insertion */
    current = *head_ref;
    while (current->next!=NULL && current->next->data < new_node->data)
    {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */

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

/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    int value_to_insert;

    /* Use push() to construct below list
     2->5->7->10->15  */
    push(&head, 15);
    push(&head, 10);
    push(&head, 7);
    push(&head, 5);
    push(&head, 2);

    /* Let us try inserting 9 */
    value_to_insert = 9;
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = value_to_insert;

    printf("\n List before insertion of %d \n", value_to_insert);
    printList(head);

    sortedInsert(&head, new_node);

    printf("\n List after insertion of %d \n", value_to_insert);
    printList(head);

    getchar();
    return 1;
}



