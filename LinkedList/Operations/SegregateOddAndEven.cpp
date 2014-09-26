/*
 * SegregateOddAndEven.cpp
 *
 *  Created on: Sep 5, 2013
 *      Author: cvora
 */


#include <stdio.h>
#include <stdlib.h>

/**
 * Given a linked list of integers, write a function to modify
 * the linked list such that all even numbers appear before all odd
 * numbers in modified linked list.
 * Also keep order of even and odd numbers.
 *
 * Examples:
 * Input: 17->15->8->12->10->5->4->1->7->6->NULL
 * Output: 8->12->10->4->6->17->15->5->1->7->NULL
 */

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};

/**
 * Algo2:
 * Split into odd and even linked list and merge.
 */

/*
 * Algo1:
 * 1: Get the pointer to the last node
 * 2: Move all the odd nodes to the end
 * 		a) Consider all odd nodes before the first even node and move them to end
 * 		b) Change head pointer to point to first even node.
 * 		c) Consider all nodes after first even node and move them to the end
 */
void segregateEvenOdd(struct node **head_ref)
{
    struct node *end = *head_ref;

    struct node *prev = NULL;
    struct node *curr = *head_ref;

    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;

    struct node *new_end = end;

    /* Consider all odd nodes before the first even node
       and move then after end */
    while (curr->data %2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }

    // 10->8->17->17->15
    /* Do following steps only if there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to point to first even node */
        *head_ref = curr;

        /* now current points to the first even node */
        while (curr != end)
        {
            if ( (curr->data)%2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between prev and current */
                prev->next = curr->next;

                /* Make next of curr as NULL  */
                curr->next = NULL;

                /* Move curr to end */
                new_end->next = curr;

                /* make curr as new end of list */
                new_end = curr;

                /* Update current pointer to next of the moved node */
                curr = prev->next;
            }
        }
    }

    /* We must have prev set before executing lines following this
       statement */
    else prev = curr;

    /* If there are more than 1 odd nodes and end of original list is
      odd then move this node to end to maintain same order of odd
      numbers in modified list */
    if (new_end!=end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
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
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    /* Let us create a sample linked list as following
      0->2->4->6->8->10->11 */

    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
    push(&head,3);
    printf("\n Original Linked list ");
    printList(head);

    segregateEvenOdd(&head);

    printf("\n Modified Linked list ");
    printList(head);

    return 0;
}

