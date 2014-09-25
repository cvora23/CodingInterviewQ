/*
 * IdenticalLinkedList.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */


#include<stdio.h>
#include<stdlib.h>

/* Structure for a linked list node */
struct node
{
  int data;
  struct node *next;
};

/* returns 1 if linked lists a and b are identical, otherwise 0 */
bool areIdentical1(struct node *a, struct node *b)
{
  while(1)
  {
    /* base case */
    if(a == NULL && b == NULL)
    {  return 1; }
    if(a == NULL && b != NULL)
    {  return 0; }
    if(a != NULL && b == NULL)
    {  return 0; }
    if(a->data != b->data)
    {  return 0; }

    /* If we reach here, then a and b are not NULL and their
       data is same, so move to next nodes in both lists */
    a = a->next;
    b = b->next;
  }
}

bool areIdentical2(struct node *a, struct node *b)
{
  if (a == NULL && b == NULL)
  {  return 1;  }
  if (a == NULL && b != NULL)
  {  return 0;  }
  if (a != NULL && b == NULL)
  {  return 0;  }
  if (a->data != b->data)
  {  return 0;  }

  /* If we reach here, then a and b are not NULL and their
       data is same, so move to next nodes in both lists */
  return areIdentical2(a->next, b->next);
}


/* UTILITY FUNCTIONS TO TEST fun1() and fun2() */
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

/* Druver program to test above function */
int main()
{
  struct node *a = NULL;
  struct node *b = NULL;

  /* The constructed linked lists are :
   a: 3->2->1
   b: 3->2->1 */
  push(&a, 1);
  push(&a, 2);
  push(&a, 3);

  push(&b, 1);
  push(&b, 2);
  push(&b, 3);

  if(areIdentical1(a, b) == 1)
    printf(" Linked Lists are identical ");
  else
    printf(" Linked Lists are not identical ");
  if(areIdentical2(a, b) == 1)
    printf(" Linked Lists are identical ");
  else
    printf(" Linked Lists are not identical ");
  getchar();
  return 0;
}

