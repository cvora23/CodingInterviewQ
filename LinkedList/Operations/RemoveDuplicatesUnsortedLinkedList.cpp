/*
 * RemoveDuplicatesUnsortedLinkedList.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

// Solution Cracking the Coding Interview 2.1

/* Program to remove duplicates in an unsorted array */

#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* A linked list node */
struct node
{
 int data;
 struct node *next;
};

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

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
}

/*
 * In order to remove duplicates from linked list, we need to be able to
 * track duplicates. A simple vector will work well here.
 * WE simply iterate through the linked list, adding each element to
 * the vector. When we discover a duplicate element, we remove the element
 * and continue iterating. WE can do this all in one pass since
 * we are using a linked list.
 * O(n)
 */

// Storing all the unique elements from the list in order in vector
void removeDuplicatesSol1(struct node *start){
	typedef std::vector<int> IntContainer;
	IntContainer vw;
    // Create a temp pointer
	struct node *tmp = start,*prev = start;

    // No nodes or Last node of the list
    if ( tmp == NULL || tmp->next == NULL )
    	return;


    while(tmp!=NULL){

    	if(std::find(vw.begin(),vw.end(),tmp->data)!= vw.end()){
    		prev->next = tmp->next;
    		free(tmp);
    	}else{
    		// add the item
        	prev = tmp;
    		vw.push_back(tmp->data);
    	}

    	tmp = tmp->next;
    }
}

/*
 * If we don't have a buffer, we can iterate with two pointers, current
 * which iterates through the linked list and runner which checks all
 * subsequent nodes for duplicates.
 * O(n^2)
 */
/* Function to remove duplicates from a unsorted linked list */
void removeDuplicatesSol2(struct node *start)
{
  struct node *ptr1, *ptr2, *dup;
  ptr1 = start;

  /* Pick elements one by one */
  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;

     /* Compare the picked element with rest of the elements */
     while(ptr2->next != NULL)
     {
       /* If duplicate then delete it */
       if(ptr1->data == ptr2->next->data)
       {
          /* sequence of steps is important here */
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          free(dup);
       }
       else /* This is tricky */
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}

/* Druver program to test above function */
int main()
{
  struct node *start = NULL;

  /* The constructed linked list is:
   10->12->11->11->12->11->10*/
  push(&start, 10);
  push(&start, 11);
  push(&start, 12);
  push(&start, 11);
  push(&start, 11);
  push(&start, 12);
  push(&start, 10);

  printf("\n Linked list before adding duplicates ");
  printList(start);

  removeDuplicatesSol2(start);

  printf("\n Linked list after removing duplicates ");
  printList(start);
  /* The linked list after removing duplicates should be:
   10->12->11*/


  push(&start, 11);
  push(&start, 11);
  push(&start, 12);
  push(&start, 10);
  printf("\n Linked list after adding duplicates ");
  printList(start);
  /* The constructed linked list is:
   10->12->11->11->10->12->11*/

  removeDuplicatesSol1(start);
  /* The linked list after removing duplicates should be:
   10->12->11*/

  printf("\n Linked list after removing duplicates ");
  printList(start);


  getchar();
}




