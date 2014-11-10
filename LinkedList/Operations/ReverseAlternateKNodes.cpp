/*
 * ReverseAlternateKNodes.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */


#include<stdio.h>
#include<stdlib.h>

/**
 * Given a linked list, write a function reveres every alternate k nodes
 * (where k is an input to the function) in an efficient way.
 * Example: k =3
 * Inputs: 1->2->3->4->5->6->7->8->9>NULL
 * Output: 3->2->1->4->5->6->9->8->7->NULL
 */

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/**
 * algo:
 * 1: Reverse first k nodes.
 * 2: In the modified list head points to the kth node. So change next
 * 		of head to (k+1)th node.
 * 3: MOve the current current pointer to skip next k nodes.
 * 4: Call the function recursively for rest of the n - 2k nodes.
 * 5: Return the new head of the list.
 */

/* Reverses alternate k nodes and
   returns the pointer to the new head node */
struct node *kAltReverse(struct node *head, int k)
{
    struct node* current = head;
    struct node* next;
    struct node* prev = NULL;
    int count = 0;

    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }

    /* 2) Now head points to the kth node.  So change next
       of head to (k+1)th node*/
    if(head != NULL)
      head->next = current;

    /* 3) We do not want to reverse next k nodes. So move the current
        pointer to skip next k nodes */
    count = 0;
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }

    /* 4) Recursively call for the list starting from current->next.
       And make rest of the list as next of first node */
    if(current !=  NULL)
       current->next = kAltReverse(current->next, k);

    /* 5) prev is new head of the input list */
    return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
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
void printList(struct node *node)
{
    int count = 0;
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
        count++;
    }
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
    int k = 3;

    // create a list 1->2->3->4->5...... ->20
    for(int i = 20; i > 0; i--)
      push(&head, i);

     printf("\n Given linked list \n");
     printList(head);
     head = kAltReverse(head, k);


     printf("\n \n k = %d \n",k);

     printf("\n Modified Linked list \n");
     printList(head);

     getchar();
     return(0);
}


