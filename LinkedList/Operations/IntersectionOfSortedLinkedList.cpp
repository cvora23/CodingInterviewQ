/*
 * IntersectionOfSortedLinkedList.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

/*
 * Given two lists sorted in increasing order, create and return a new list representing
 * the intersection of the two lists. The new list should be made with its own memory - the originals
 * should not be changed.
 * For example, let the first linked list be 1->2->3->4->6 and second linked list be
 * 2->4->6->8, then your function should return a third list as 2->4->6;
 */


#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data);

/*
 * LOOP proceeds removing one node from either 'a' or 'b' and adding to the result.
 */
/* This solution uses the local reference */
struct node* sortedIntersect1(struct node* a, struct node* b)
{
  struct node* result = NULL;
  struct node** lastPtrRef = &result;

  /* Advance comparing the first nodes in both lists.
    When one or the other list runs out, we're done. */
  while (a!=NULL && b!=NULL)
  {
    if (a->data == b->data)
    {
      /* found a node for the intersection */
      push(lastPtrRef, a->data);
      lastPtrRef = &((*lastPtrRef)->next);
      a = a->next;
      b = b->next;
    }
    else if (a->data < b->data)
      a=a->next;       /* advance the smaller list */
    else
      b=b->next;
  }
  return(result);
}
//recursive solution with same idea as above
struct node *sortedIntersect2(struct node *a, struct node *b)
{
    /* base case */
    if (a == NULL || b == NULL)
        return NULL;

    /* If both lists are non-empty */

    /* advance the smaller list and call recursively */
    if (a->data < b->data)
        return sortedIntersect2(a->next, b);

    if (a->data > b->data)
        return sortedIntersect2(a, b->next);

    // Below lines are executed only when a->data == b->data
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a->data;

    /* advance both lists and call recursively */
    temp->next = sortedIntersect2(a->next, b->next);
    return temp;
}


/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
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

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node != NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

/* Drier program to test above functions*/
int main()
{
  /* Start with the empty lists */
  struct node* a = NULL;
  struct node* b = NULL;
  struct node *intersect = NULL;

  /* Let us create the first sorted linked list to test the functions
   Created linked list will be 1->2->3->4->5->6 */
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  /* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);

  /* Find the intersection two linked lists */
  intersect = sortedIntersect1(a, b);

  printf("\n Linked list containing common items of a & b \n ");
  printList(intersect);

  /* Find the intersection two linked lists */
  intersect = sortedIntersect2(a, b);

  printf("\n Linked list containing common items of a & b \n ");
  printList(intersect);

  getchar();
}

