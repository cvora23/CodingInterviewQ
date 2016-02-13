/*
 * IntersectionPointOfTwoLinkedList.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */



#include<stdio.h>
#include<stdlib.h>

/*
 * There are two singly linked lists in a system. By some programming error
 * the end node of one of the linked list got linked into the second list, forming a inverted
 * Y shaped list. Write a program to get the point where two link list merge.
 */

/* Link list node */
struct node
{
  int data;
  struct node* next;
};

/* Function to get the counts of node in a linked list */
int getCount(struct node* head);

/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int _getIntesectionNode(int d, struct node* head1, struct node* head2);


/**
 * METHOD 1 (Simply use two loops)
 * O(mn)
 * Use 2 nested for loops. Outer loop will be for each node of the 1st
 * list and inner loop will be for 2nd list. In the inner loop, check if
 * any of nodes of 2nd list is same as the current node of first linked list.
 * Time complexity of this method will be O(mn) where m and n are the number of nodes in two lists.
 */

/*
 * METHOD 2 (Mark visited nodes)
 * This solution requires modifications to basic linked list data structure. Have a visited flag
 * with each node. Traverse the first linked list and keep marking visited nodes.
 * Now traverse second linked list, if you see a visited node again then there is an intersection point,
 * return the intersection node. This solution works in O(m+n) but requires additional
 * information with each
 * node. A variation of this solution that doesn't require modification to
 * basic data structure can be implemented
 * using hash. Traverse the first linked list and store the addresses of
 * visited nodes in a hash. Now traverse
 * the second linked list and if you see an address that already exists in a
 * hash then return the intersection node.
 */

/**
 * METHOD 3(Using difference of node counts)
 * 1: Get count of nodes in first list, let count be c1.
 * 2: Get count of nodes in second list, let count be c2.
 * 3: Get the difference of counts d = abs(c1 - c2)
 * 4: Now traverse the bigger list from first node till d nodes so that
 * 	  from here onwards both the lists have equal no of nodes.
 * 5: Then we can traverse both the lists in parallel till we come across
 * 	  a common node. (Note that getting a common node is done by comparing addresses of the nodes.
 */

/* function to get the intersection point of two linked
   lists head1 and head2 */
int getIntesectionNode(struct node* head1, struct node* head2)
{
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;

  if(c1 > c2)
  {
    d = c1 - c2;
    return _getIntesectionNode(d, head1, head2);
  }
  else
  {
    d = c2 - c1;
    return _getIntesectionNode(d, head2, head1);
  }
}

/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int _getIntesectionNode(int d, struct node* head1, struct node* head2)
{
  int i;
  struct node* current1 = head1;
  struct node* current2 = head2;

  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  return -1; }
    current1 = current1->next;
  }

  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1->data;
    current1= current1->next;
    current2= current2->next;
  }

  return -1;
}

/* Takes head pointer of the linked list and
   returns the count of nodes in the list */
int getCount(struct node* head)
{
  struct node* current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

/* IGNORE THE BELOW LINES OF CODE. THESE LINES
   ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main()
{
  /*
    Create two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
  */

  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;

  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));

  getchar();
}

