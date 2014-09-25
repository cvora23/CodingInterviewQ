/*
 * CheckIfPalindrome.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

/*
 * Given a singly linked list of characters, write a function that returns true
 * if the given list is palindrome , else false.
 */

// Solution Cracking the Coding Interview 2.7

/* Program to check if a linked list is palindrome */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iostream>

using namespace std;

/* Link list node */
struct node
{
    char data;
    struct node* next;
};

void reverse(struct node**);
bool compareLists(struct node*, struct node *);
int  Count(struct node *q);

/*
 * METOD1 (Use a Stack)
 * A simple solution is to use a stack of list nodes. This mainly involves 3 steps
 * 1:	Traverse the given list from head to tail and push every visited node to stack.
 * 2:	Traverse the list again. For every visited node, pop a node from stack and
 * 		compare data of popped node with currently visited node.
 * 3:	If all nodes matched, then return true, else false.
 *
 * Time complexity is O(n), but it requires O(n) extra space
 *
 */

/**
 * METHOD2 (BY reversing the list)
 * This method takes O(n) time and O(1) extra space.
 * 1: Get the middle of linked list
 * 2: Reverse the second half of linked list.
 * 3: Check if first and second half are identical
 * 4: Construct original linked list by reversing second half again and attaching it back to first
 * half.
 * When no of nodes are even, first and second half contain exactly half nodes. The challenging thing
 * is handling cases where nodes are odd. WE don't want the middle node as part of any of the lists as
 * we are going to compare them for equality. For odd case, we use a separate variable midnode.
 *
 */

/* Function to check if given linked list is
  palindrome or not */
// Iterative approach
bool isPalindromeSol1(struct node *head)
{
    struct node *slow_ptr = head, *fast_ptr = head;
    struct node *second_half, *prev_of_slow_ptr = head;
    struct node *midnode = NULL;  // To handle odd size list
    bool res = true; // initialize result

    if (head!=NULL)
    {
        /* Get the middle of the list. Move slow_ptr by 1
          and fast_ptrr by 2, slow_ptr will have the middle
          node */
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            /*We need previous of the slow_ptr for
             linked lists  with odd elements */
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }


        /* fast_ptr would become NULL when there are even elements in list.
           And not NULL for odd elements. We need to skip the middle node
           for odd case and store it somewhere so that we can restore the
           original list*/
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // Now reverse the second half and compare it with first half
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL; // NULL terminate first half
        reverse(&second_half);  // Reverse the second half
        res = compareLists(head, second_half); // compare

        /* Construct the original list back */
         reverse(&second_half); // Reverse the second half again
         if (midnode != NULL)  // If there was a mid node (odd size case) which
                               // was not part of either first half or second half.
         {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
         }
         else  prev_of_slow_ptr->next = second_half;
    }
    return res;
}

/*
 * METHOD3 (Using recursion)
 * Use two pointers left and right. move right and left using recursion and check for following in each
 * recursive call
 * 1: Sub-list is palindrome
 * 2: Value at current left and right are matching.
 * If both conditions are true then return true.
 *
 * Idea is to use function call stack as container. Recursively traverse till the end of list.
 * When we return from last NULL, we will be at last node. THe last node to be compared with first
 * node of list.
 * In order to access first node of list, we need list head to be available in last call of recursion.
 * Hence we pass head also to the recursive function. If they both match we need to compare (2, n-2) nodes.
 * Again when recursion falls back to (n-2)nd node, we need reference to 2nd node from head. We advance head
 * pointer in previous call, to refer to next node in the list.
 * However the trick in identifying double. Passing single pointer is as good as pass by value, and we will
 * pass same pointer again and again. We need to pass address of head pointer for reflecting the changes
 * in parent recursive calls.
 *
 */
// Recursive solution
bool isPalindromRecurse(struct node *head,int length,struct node** next){
	bool res;
	if(head == NULL || length == 0){
		return true;
	}else if(length == 1){
		*next = head->next;
		return true;
	}else if(length == 2){
			*next = head->next->next;
			return head->data == (*next)->data;
	}
	res = isPalindromRecurse(head->next,length-2,next);
	if(!res){
		cout<<"Length is "<<length<<endl;
		return res;
	}else{
		struct node * temp = *next;
		*next = (*next)->next;
		return head->data == temp->data;
	}
}

bool isPalindromeSol2(struct node *head){
    bool res = true; // initialize result
    struct node *next = head->next;
    res = isPalindromRecurse(head,Count(head),&next);
    return res;
}


/* Function to reverse the linked list  Note that this
    function may change the head */
void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Function to check if two input lists have same data*/
bool compareLists(struct node* head1, struct node *head2)
{
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return 0;
    }

    /* Both are empty return 1*/
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    /* Will reach here when one is NULL
      and other is not */
    return 0;
}

/* Push a node to linked list. Note that this function
  changes the head */
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
}

// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// A utility function to count number of elements in a given linked list
int  Count(struct node *q)
{
     if(q == NULL)
     return 0;
     else
     return 1+Count(q->next) ;
}


/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);

    }
    printList(head);

    isPalindromeSol1(head)? printf("Is Palindrome\n\n"):
                        printf("Not Palindrome\n\n");
    isPalindromeSol2(head)? printf("Is Palindrome\n\n"):
                        printf("Not Palindrome\n\n");
    return 0;
}

