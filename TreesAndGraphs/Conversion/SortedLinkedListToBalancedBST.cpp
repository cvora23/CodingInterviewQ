/*
 * SortedLinkedListToBST.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * Given a Singly Linked List which has data members sorted in ascending order.
 * Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
 *
 * Examples:

Input:  Linked List 1->2->3
Output: A Balanced BST
     2
   /  \
  1    3


Input: Linked List 1->2->3->4->5->6->7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  4   7

Input: Linked List 1->2->3->4
Output: A Balanced BST
      3
    /  \
   2    4
 /
1

Input:  Linked List 1->2->3->4->5->6
Output: A Balanced BST
      4
    /   \
   2     6
 /  \   /
1   3  5
 *
 */

/* Link list node */
struct LNode
{
    int data;
    struct LNode* next;
};

/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};


/* UTILITY FUNCTIONS */

/* A utility function that returns count of nodes in a given Linked List */
int countLNodes(struct LNode *head)
{
    int count = 0;
    struct LNode *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

/* Function to insert a node at the beginging of the linked list */
void push(struct LNode** head_ref, int new_data)
{
    /* allocate node */
    struct LNode* new_node =
        (struct LNode*) malloc(sizeof(struct LNode));
    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct LNode *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
                         malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int getElement(struct LNode* head,int position)
{
	int i = 0;
	while(head->next != NULL && i<position)
	{
		head = head->next;
		i++;
	}
	return head->data;
}
/*
 * Method 1 (Simple)
Following is a simple algorithm where we first find the middle node of list and
make it root of the tree to be constructed.

1) Get the Middle of the linked list and make it root.
2) Recursively do same for left half and right half.
       a) Get the middle of left half and make it left child of the root
          created in step 1.
       b) Get the middle of right half and make it right child of the
          root created in step 1.

Time complexity: O(nLogn) where n is the number of nodes in Linked List.

 *
 */
void sortedListToBSTRecur1(struct LNode* head,struct TNode** root,int start,int end)
{
	int mid;
	int element;
	mid = (start+end)/2;
	static int totalLinkListElements = end;
	if(head == NULL || end<0 || start>=totalLinkListElements || start>end)
	{
		return;
	}
	if(*root == NULL)
	{
		element = getElement(head,mid);
		*root = newNode(element);
	}
	sortedListToBSTRecur1(head,&(*root)->left,start,mid-1);
	sortedListToBSTRecur1(head,&(*root)->right,mid+1,end);
}

struct TNode* sortedListToBST1(struct LNode* head)
{
	int n = countLNodes(head);

	struct TNode* root = NULL;
	sortedListToBSTRecur1(head,&root,0,n);
	return root;
}


/*
 * Method 2 (Tricky)
The method 1 constructs the tree from root to leaves. In this method, we
construct from leaves to root. The idea is to insert nodes in BST in the
same order as the appear in Linked List, so that the tree can be constructed
in O(n) time complexity. We first count the number of nodes in the given Linked List.
Let the count be n. After counting nodes, we take left n/2 nodes and recursively
construct the left subtree. After left subtree is constructed, we allocate memory
for root and link the left subtree with root. Finally, we recursively construct the
right subtree and link it with root.
While constructing the BST, we also keep moving the list head pointer to next so that
we have the appropriate pointer in each recursive call.
 */
/* The main function that constructs balanced BST and returns root of it.
       head_ref -->  Pointer to pointer to head node of linked list
       n  --> No. of nodes in Linked List */
struct TNode* sortedListToBSTRecur2(struct LNode **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;

    /* Recursively construct the left subtree */
    struct TNode *left = sortedListToBSTRecur2(head_ref, n/2);

    /* Allocate memory for root, and link the above constructed left
       subtree with root */
    struct TNode *root = newNode((*head_ref)->data);
    root->left = left;

    /* Change head pointer of Linked List for parent recursive calls */
    *head_ref = (*head_ref)->next;

    /* Recursively construct the right subtree and link it with root
      The number of nodes in right subtree  is total nodes - nodes in
      left subtree - 1 (for root) which is n-n/2-1*/
    root->right = sortedListToBSTRecur2(head_ref, n-n/2-1);

    return root;
}

/* This function counts the number of nodes in Linked List and then calls
   sortedListToBSTRecur() to construct BST */
struct TNode* sortedListToBST2(struct LNode *head)
{
    /*Count the number of nodes in Linked List */
    int n = countLNodes(head);

    /* Construct BST */
    return sortedListToBSTRecur2(&head, n);
}


/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct LNode* head = NULL;

    /* Let us create a sorted linked list to test the functions
     Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\n Given Linked List ");
    printList(head);

    /* Convert List to BST */
    struct TNode *root = sortedListToBST1(head);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
    struct TNode *root1 = sortedListToBST2(head);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root1);
    return 0;
}
