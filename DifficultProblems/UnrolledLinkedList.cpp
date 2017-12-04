/*
 * UnrolledLinkedList.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 * Unrolled Linked List | Set 1 (Introduction)
 * Like array and linked list, unrolled Linked List is also a linear data structure and is a variant of linked list.
 * Unlike simple linked list, it stores multiple elements at each node. That is, instead of storing single element at a node,
 * unrolled linked lists store an array of elements at a node. Unrolled linked list covers advantages of both array and
 * linked list as it reduces the memory overhead in comparison to simple linked lists by storing multiple elements at each node
 * and it also has the advantage of fast insertion and deletion as that of a linked list.
 *
 * http://www.geeksforgeeks.org/wp-content/uploads/unrolledLinkedList.png
 *
 * Advantages:

Because of the Cache behavior, linear search is much faster in unrolled linked lists.
In comparison to ordinary linked list, it requires less storage space for pointers/references.
It performs operations like insertion, deletion and traversal more quickly than ordinary linked lists (because search is faster).

Disadvantages:

The overhead per node is comparatively high than singly linked lists. Refer an example node in below code.
 *
 */


// C program to implement unrolled linked list
// and traversing it.
#include<stdio.h>
#include<stdlib.h>
#define maxElements 4

// Unrolled Linked List Node
struct Node
{
    int numElements;
    int array[maxElements];
    struct Node *next;
};

/* Function to traverse am unrolled linked list
   and print all the elements*/
void printUnrolledList(struct Node *n)
{
    while (n != NULL)
    {
        // Print elements in current node
        for (int i=0; i<n->numElements; i++)
            printf("%d ", n->array[i]);

        // Move to next node
        n = n->next;
    }
}

// Program to create an unrolled linked list
// with 3 Nodes
int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 Nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Let us put some values in second node (Number
    // of values must be less than or equal to
    // maxElement)
    head->numElements = 3;
    head->array[0] = 1;
    head->array[1] = 2;
    head->array[2] = 3;

    // Link first Node with the second Node
    head->next = second;

    // Let us put some values in second node (Number
    // of values must be less than or equal to
    // maxElement)
    second->numElements = 3;
    second->array[0] = 4;
    second->array[1] = 5;
    second->array[2] = 6;

    // Link second Node with the third Node
    second->next = third;

    // Let us put some values in third node (Number
    // of values must be less than or equal to
    // maxElement)
    third->numElements = 3;
    third->array[0] = 7;
    third->array[1] = 8;
    third->array[2] = 9;
    third->next = NULL;

    printUnrolledList(head);

    return 0;
}
