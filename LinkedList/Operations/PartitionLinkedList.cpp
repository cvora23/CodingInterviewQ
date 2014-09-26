/*
 * PartitionLinkedList.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: cvora
 */
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/*
 * Write code to partition a linked list around a value x, such that all nodes less than x
 * come before all nodes greater than or equal to x.
 */
// Solution Cracking the Coding Interview 2.4

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

/*
 * Rather than shifting and swapping elements, we actually create 2 different linked list:
 * one for elements less than x, and one for elements greater than or equal to x.
 * We iterate through the linked list, inserting elements into our before list or our after
 * list. Once we reach end of linked list and have completed this splitting, we merge two lists.
 */
struct node* partitionListSol1(struct node* head,int val){
	struct node* beforeStart = NULL;
	struct node* beforeEnd = NULL;
	struct node* afterStart = NULL;
	struct node* afterEnd = NULL;

	// Partition List
	while(head != NULL){
		struct node* next = head->next;
		head->next = NULL;
		if(head->data < val){
			if(beforeStart == NULL){
				beforeStart = head;
				beforeEnd = beforeStart;
			}else{
				beforeEnd->next = head;
				beforeEnd = head;
			}
		}else{
			if(afterStart == NULL){
				afterStart = head;
				afterEnd = afterStart;
			}else{
				afterEnd->next = head;
				afterEnd = head;
			}
		}
		head = next;
	}

	if(beforeStart == NULL){
		return afterStart;
	}

	// Merge before list and after list
	beforeEnd->next = afterStart;
	return beforeStart;
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

    printf("\n Before Partitioning \n");
    printList(head);

    /* I m deleting the head itself.
        You can check for more cases */

   printf("\n After Partitioning \n");
   printList(partitionListSol1(head,4));
   getchar();
}



