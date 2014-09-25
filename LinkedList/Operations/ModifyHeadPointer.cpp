/*
 * ModifyHeadPointer.cpp
 *
 *  Created on: Sep 5, 2013
 *      Author: cvora
 */




#include <stdio.h>
#include <stdlib.h>
/* structure of a linked list node */
struct node
{
    int data;
    struct node *next;
};
// function to delete first node
void deleteFirst(struct node **head_ref)
{
    if(*head_ref != NULL)
    {
       // store the old value of pointer to head pointer
       struct node *temp = *head_ref;
       // Change head pointer to point to next node
       *head_ref = (*head_ref)->next;
       // delete memory allocated for the previous head node
       free(temp);
    }
}
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning of the Doubly Linked List */
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
/* Function to print nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
/* Driver program to test above functions */
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    printf("\n Original Linked list ");
    printList(head);
    deleteFirst(&head);
    printf("\n Linked List after deleting first node: ");
    printList(head);
    deleteFirst(&head);

    return 0;
}
