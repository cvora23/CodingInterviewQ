/*
 * FindTripletFromLinkedListEqualToSum.cpp
 *
 *  Created on: Sep 5, 2013
 *      Author: cvora
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * Given three linked lists, say a, b and c, find one node from each list such that the sum of the
 * values of the nodes is equal to a given number.
 * for example, if the 3 linked lists are 12->6->29, 23->5->8 and 90->20->59 and the given number is
 * 101, the output should be triplet "6 5 90"
 */

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* A utility function to insert a node at the begining of a linked list*/
void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/*
 * ALGO1:
 * A simple method to solve this problem is to run three nested loops. The outmost loop picks an
 * element from list a, middle loop picks an element from b and innermost loop picks from c.
 * The innermost loop also checks whether the sum of values of current nodes of a,b and c is equal to
 * given number. The time complexity of this method will be O(n^3)
 *
 */

/*
 *	ALGO2:
 *	Sorting can be used to reduce the time complexity to O(n*n). Following are the detailed steps.
 *	1: Sort list b in ascending order and list c in descending order.
 *	2: After the b and c are sorted, one by one pick an element from list a and find the pair by
 *	traversing both b and c.
 */
/* A function to chech if there are three elements in a, b and c whose sum
   is equal to givenNumber.  The function assumes that the list b is sorted
   in ascending order and c is sorted in descending order. */
bool isSumSorted(struct node *headA, struct node *headB,
                 struct node *headC, int givenNumber)
{
    struct node *a = headA;

    // Traverse through all nodes of a
    while (a != NULL)
    {
        struct node *b = headB;
        struct node *c = headC;

        // For every node of list a, prick two nodes from lists b abd c
        while (b != NULL && c != NULL)
        {
            // If this a triplet with given sum, print it and return true
            int sum = a->data + b->data + c->data;
            if (sum == givenNumber)
            {
               printf ("Triplet Found: %d %d %d ", a->data, b->data, c->data);
               return true;
            }

            // If sum of this triplet is smaller, look for greater values in b
            else if (sum < givenNumber)
                b = b->next;
            else // If sum is greater, look for smaller values in c
                c = c->next;
        }
        a = a->next;  // Move ahead in list a
    }

    printf ("No such triplet");
    return false;
}


/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* headA = NULL;
    struct node* headB = NULL;
    struct node* headC = NULL;

    /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);

    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);

    /*create another sorted linked list 'c' 8->4->2->1 */
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);

    int givenNumber = 25;

    isSumSorted (headA, headB, headC, givenNumber);

    return 0;
}


