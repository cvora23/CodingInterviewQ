/*
 * MergeLinkListAtAlternatePositions.cpp
 *
 *  Created on: Sep 5, 2013
 *      Author: cvora
 */

/*
 * Merge a linked list into another linked list at alternate positions
Given two linked lists, insert nodes of second list into first list at
alternate positions of first list.
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6,
the first list should become 5->12->7->10->17->2->13->4->11->6 and second list
should become empty. The nodes of second list should only be inserted when there
are positions available. For example, if the first list is 1->2->3 and
second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and
second list to 7->8.

Use of extra space is not allowed (Not allowed to create additional nodes), i.e.,
insertion must be done in-place.
Expected time complexity is O(n) where n is number of nodes in first list.

The idea is to run a loop while there are available positions in first
loop and insert nodes of second list by changing pointers.
 */

#include <stdio.h>
#include <stdlib.h>

// A nexted list node
struct node
{
    int data;
    struct node *next;
};

/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}

/* Utility function to print a singly linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function that inserts nodes of linked list q into p at alternate
// positions. Since head of first list never changes and head of second list
// may change, we need single pointer for first list and double pointer for
// second list.
void merge(struct node *p, struct node **q)
{
     struct node *p_curr = p, *q_curr = *q;
     struct node *p_next, *q_next;

     // While therre are avialable positions in p
     while (p_curr != NULL && q_curr != NULL)
     {
         // Save next pointers
         p_next = p_curr->next;
         q_next = q_curr->next;

         // Make q_curr as next of p_curr
         p_curr->next = q_curr;  // Change next pointer of p_curr
         q_curr->next = p_next;  // Change next pointer of q_curr

         // Update current pointers for next iteration
         p_curr = p_next;
         q_curr = q_next;
    }

    *q = q_curr; // Update head pointer of second list
}

// Driver program to test above functions
int main()
{
     struct node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("First Linked List:\n");
     printList(p);

     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("Second Linked List:\n");
     printList(q);

     merge(p, &q);

     printf("Modified First Linked List:\n");
     printList(p);

     printf("Modified Second Linked List:\n");
     printList(q);

     getchar();
     return 0;
}

