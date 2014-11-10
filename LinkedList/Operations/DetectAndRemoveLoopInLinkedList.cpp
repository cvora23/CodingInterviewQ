/*
 * DetectAndRemoveLoopInLinkedList.cpp
 *
 *  Created on: Sep 5, 2013
 *      Author: cvora
 */
// Solution Cracking the Coding Interview 2.6


/**
 * Find loop in linked list
 */

#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to remove loop. Used by detectAndRemoveLoop() */
void removeLoop1(struct node *, struct node *);
void removeLoop2(struct node *, struct node *);
void removeLoop3(struct node *, struct node *);

/* This function detects and removes loop in the list
   If loop was there in the list then it returns 1,
   otherwise returns 0 */
/*
 * PART1: Detect if linked list has a loop
 * An easy way to detect if a linked list has a loop is through FastRunner/SlowRunner approach. FastRunner
 * moves two steps at a time, SlowRunner moves one step. Much like two cars racing cars around a track
 * at different steps, they must eventually meet.
 * An astute reader may wonder if FastRunner might "hop over" SlowRunner completely, without ever
 * colliding. That's not possible. Suppose that FastRunner did hop over SlowRunner, such that
 * SlowRunner is at spot i and FastRunner is at spot i+1. In previous step, SlowRunner would be at
 * spot i-1 and FastRunner would be at ((i+1)-2) or sport i-1. That is why they would have collided.
 *
 * PART2: When do they collide?
 * Let's assume that the linked list has a "non-looped" part of size k.
 * If we apply our algorithm from part1, when will FastRunner and SlowRunner collide?
 *
 * We know for every p steps that SlowRunner takes, FastRunner takes 2p steps. Therefore when SlowRunner
 * enters the looped portion after k steps, FastRunner has taken 2k steps and must be 2k-k or k steps into the
 * looped portion. Since k might be larger than the loop length, we should actually write this as mod(k,LOOP_SIZE)steps,
 * which we will denote as K.
 *
 * At each subsequent step, FastRunner and SlowRunner get either one step farther away or one step closer.
 * That is because we are in a circle, when A move q steps away from B, it is also moving q steps closer to B.
 * Facts:
 * 1: SlowRnner is 0 steps into the loop
 * 2: FastRunner is K steps into the loop.
 * 3: SlowRunner is K steps behind FastRunner.
 * 4: FastRunner is LOOP_SIZE - K steps behind SlowRunner.
 * 5: FastRunner catches up to SlowRunner at a rate of 1 step per unit of time.
 *
 * So when would they meet? Well if FastRunner is LOOP_SIZE - K steps behind SlowRunner,
 * and FastRunner catches up at a rate of 1 step per unit of time, then they meet after
 * LOOP_SIZE - K steps. At this point, they will be K steps before the head of the loop.
 * Lets call this collision point.
 *
 * PART3: How to find start of the loop?
 * We know that CollisionSpot is K Nodes before Start of the loop.
 * Because K = mod(k,LOOP_SIZE) (or in other words, k = K + M * LOOP_SIZE, for any
 * integer M), it is also correct to say that it is k nodes from loop start.
 * Therefore both CollisionSpot and lInkedlistHead are k nodes from start of the loop.
 * Now if we keep one pointer at CollisionSpot and move the other one to LinkedListHead,
 * they will each be k nodes from LoopStart. Moving two pointers at the same speed will
 * cause them to collide again - this time after k steps, at which point they
 * will be both at LoopStart. All we have to do is return this node.
 */
int detectAndRemoveLoop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;

        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p)
        {
        	removeLoop3(slow_p, list);

            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }

    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop1(struct node *loop_node, struct node *head)
{
   struct node *ptr1;
   struct node *ptr2;

   /* Set a pointer to the beginning of the Linked List and
      move it one by one to find the first node which is
      part of the Linked List */
   ptr1 = head;
   while(1)
   {
     /* Now start a pointer from loop_node and check if it ever
       reaches ptr2 */
     ptr2 = loop_node;
     while(ptr2->next != loop_node && ptr2->next != ptr1)
     {
         ptr2 = ptr2->next;
     }

     /* If ptr2 reahced ptr1 then there is a loop. So break the
        loop */
     if(ptr2->next == ptr1)
        break;

     /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
     else
       ptr1 = ptr1->next;
   }

   /* After the end of loop ptr2 is the last node of the loop. So
     make next of ptr2 as NULL */
   ptr2->next = NULL;
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop2(struct node *loop_node, struct node *head)
{
    struct node *ptr1 = loop_node;
    struct node *ptr2 = loop_node;

    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }

    // Fix one pointer to head
    ptr1 = head;

    // And the other pointer to k nodes after head
    ptr2 = head;
    for(i = 0; i < k; i++)
      ptr2 = ptr2->next;

    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while(ptr2 != ptr1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Get pointer to the last node
    ptr2 = ptr2->next;
    while(ptr2->next != ptr1)
       ptr2 = ptr2->next;

    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop3(struct node *loop_node, struct node *head){
    struct node *ptr1 = head;
    struct node *prev = loop_node;
    while(loop_node != ptr1){
    	ptr1 = ptr1->next;
    	prev = loop_node;
    	loop_node = loop_node ->next;
    }
    prev->next = NULL;
}

/* UTILITY FUNCTIONS */
/* Given a reference (pointer to pointer) to the head
  of a list and an int, pushes a new node on the front
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

/* Function to print linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    printf("Linked List after removing loop \n");
    printList(head);

    getchar();
    return 0;
}


