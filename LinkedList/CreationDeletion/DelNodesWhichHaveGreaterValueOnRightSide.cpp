/*
 * DelNodesWhichHaveGreaterValueOnRightSide.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

/*
 * 	Given a singly linked list, remove all the nodes which have a greater value on right side.

	Examples:
	a) The list 12->15->10->11->5->6->2->3->NULL should be changed to 15->11->6->3->NULL.
	Note that 12, 10, 5 and 2 have been deleted because there is a greater value on the right side.

	When we examine 12, we see that after 12 there is one node with value greater than 12 (i.e. 15),
	so we delete 12.
	When we examine 15, we find no node after 15 that has value greater than 15 so we keep this node.
	When we go like this, we get 15->6->3

	b) The list 10->20->30->40->50->60->NULL should be changed to 60->NULL.
	Note that 10, 20, 30, 40 and 50 have been deleted because they all have a greater value on the right side.

	c) The list 60->50->40->30->20->10->NULL should not be changed.
 */

/*
 * ALGO 1:
 * Method 1 (Simple)
	Use two loops. In the outer loop, pick nodes of the linked list one by one.
	In the inner loop, check if there exist a node whose value is greater than the picked node.
	If there exists a node whose value is greater, then delete the picked node.
	Time Complexity: O(n^2)
 */

/*
 * ALGO 2:
 * Method 2 (Use Reverse)
 *	1. Reverse the list.
	2. Traverse the reversed list. Keep max till now. If next node < max, then delete the next node,
	otherwise max = next node.
	3. Reverse the list again to retain the original order.
 */

#include <stdio.h>
#include <stdlib.h>

/* structure of a linked list node */
struct node
{
     int data;
     struct node *next;
};

/* prototype for utility functions */
void reverseList(struct node **headref);
void _delLesserNodes(struct node *head);

/* Deletes nodes which have a node with greater value node
  on left side */
void delLesserNodes(struct node **head_ref)
{
    /* 1) Reverse the linked list */
    reverseList(head_ref);

    /* 2) In the reversed list, delete nodes which have a node
       with greater value node on left side. Note that head
       node is never deleted because it is the leftmost node.*/
    _delLesserNodes(*head_ref);

    /* 3) Reverse the linked list again to retain the
       original order */
    reverseList(head_ref);
}

/* Deletes nodes which have greater value node(s) on left side */
void _delLesserNodes(struct node *head)
{
     struct node *current = head;

     /* Initialize max */
     struct node *maxnode = head;
     struct node *temp;

     while (current != NULL && current->next != NULL)
     {
         /* If current is smaller than max, then delete current */
         if(current->next->data < maxnode->data)
         {
             temp = current->next;
             current->next = temp->next;
             free(temp);
         }

         /* If current is greater than max, then update max and
            move current */
         else
         {
             current = current->next;
             maxnode = current;
         }

     }
}

/* Utility function to insert a node at the begining */
void push(struct node **head_ref, int new_data)
{
     struct node *new_node =
              (struct node *)malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}

/* Utility function to reverse a linked list */
void reverseList(struct node **headref)
{
     struct node *current = *headref;
     struct node *prev = NULL;
     struct node *next;
     while(current != NULL)
     {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     *headref = prev;
}

/* Utility function to print a linked list */
void printList(struct node *head)
{
     while(head!=NULL)
     {
        printf("%d ",head->data);
        head=head->next;
     }
     printf("\n");
}

/* Driver program to test above functions */
int main()
{
    struct node *head = NULL;

    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);

    printf("Given Linked List: ");
    printList(head);

    delLesserNodes(&head);

    printf("\nModified Linked List: ");
    printList(head);

    getchar();
    return 0;
}
//Output:
//
//Given Linked List: 12 15 10 11 5 6 2 3
//Modified Linked List: 15 11 6 3



