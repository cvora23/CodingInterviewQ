/*
 * NthNodeFromEnd.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * Given a Linked list and a number n, write a function that returns the value at the nth node from
 * end of the linked list
 */

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

/*
 * Method1 (Use length of linked list)
 * 1: Calculate length of linked list. Let length be len.
 * 2: Print the (len-n+1)th node from beginning of the Linked list.
 */

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
/*
 * Method1 (Use length of linked list)
 * 1: Calculate length of linked list. Let length be len.
 * 2: Print the (len-n+1)th node from beginning of the Linked list.
 *
 * Complexity is O(n)
 */
void printNthFromLast2(struct node* head, int n)
{
    static int i = 0;
    if(head == NULL)
       return;
    printNthFromLast2(head->next, n);
    if(++i == n)
       printf("%d", head->data);
}

/* Function to get the nth node from the last of a linked list*/
/*
 * Method 3: Maintain two pointers -reference pointer and main pointer. Initialize both reference and main
 * pointers at head. First move reference pointer to n nodes from head. Now move both pointers one by one
 * until reference pointer reaches end. now main pointer will point to nth node from end.
 * Return main pointer.
 */
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

     printf("Here \n");

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




