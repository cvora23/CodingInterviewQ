/*
 * NthNodeFromEnd.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

#include<stdio.h>
#include<stdlib.h>

// Solution Cracking the Coding Interview 2.2

/* Link list node */
struct node
{
  int data;
  struct node* next;
};

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


// Iterative solutions 1

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast1(struct node* head, int n)
{
    int len = 0, i;
    struct node *temp = head;

    // 1) count the number of nodes in Linked List
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    // check if value of n is not more than length of the linked list
    if (len < n)
      return;

    temp = head;

    // 2) get the (n-len+1)th node from the begining
    for (i = 1; i < len-n+1; i++)
       temp = temp->next;

    printf ("Node no. %d from last is %d \n",n, temp->data);

    return;
}

// Recursive solutions 1

void printNthFromLast2(struct node* head, int n)
{
    static int i = 0;
    if(head == NULL)
       return;
    printNthFromLast2(head->next, n);
    if(++i == n)
       printf("%d", head->data);
}

//Recursive solution 2
/* Function to get the nth node from the last of a linked list*/
struct node* printAndGetNthFromLast3(struct node *head, int n)
{
  struct node *main_ptr = head;
  struct node *ref_ptr = head;

  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return NULL;
        }
        ref_ptr = ref_ptr->next;
        count++;
     } /* End of while*/

     while(ref_ptr != NULL)
     {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
     }
     printf("Node no. %d from last is %d \n",
              n, main_ptr->data);
  }
  return main_ptr;
}

/* Drier program to test above function*/
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;

  // create linked 35->15->4->20
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 35);

  printNthFromLast1(head, 2);
  printNthFromLast2(head, 5);
  printAndGetNthFromLast3(head, 2);

  getchar();
  return 0;
}




