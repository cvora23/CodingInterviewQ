/*
 * PrintMiddleElement.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * Write a C function to print the middle of given linked list
 */

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/*
 * ALGO1:
 * Traverse the whole linked list and count no of nodes. now traverse the list again
 * till count/2 and return node at count/2
 */

/*
 * ALGO2:
 * Traverse the linked list using two pointers. Move one pointer by one and other
 * pointer by two. When fast pointer reaches end, slow pointer reaches middle of
 * linked list
 */
/* Function to get the middle of the linked list*/
void printMiddle1(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;

    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}

/*
 *	ALGO 3:
 *	Initialize mid element as head and initialize as counter as 0. Traverse the list from head,
 *	while traverse the increment the counter and change mid to mid->next whenever the counter is odd.
 *	So the mid will move only half of the total length of the list.
 */
/* Function to get the middle of the linked list*/
void printMiddle2(struct node *head)
{
    int count = 0;
    struct node *mid = head;

    while (head != NULL)
    {
        /* update mid, when 'count' is odd number */
        if (count & 1)
            mid = mid->next;

        ++count;
        head = head->next;
    }

    /* if empty list is provided */
    if (mid != NULL)
        printf("The middle element is [%d]\n\n", mid->data);
}

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

// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    int i;

    for (i=5; i>0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle1(head);
        printMiddle2(head);

    }

    return 0;
}



