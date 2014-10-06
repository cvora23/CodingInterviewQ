/*
 * BInaryTreeFromLinkedListRepresentation.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: cvora
 */

// C++ program to create a Complete Binary tree from its Linked List
// Representation
#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
 * Given Linked List Representation of Complete Binary Tree, construct the Binary tree.
 * A complete binary tree can be represented in an array in the following approach.

 If root node is stored at index i, its left, and right children are stored at indices 2*i+1, 2*i+2
 respectively.
 Suppose tree is represented by a linked list in same way, how do we convert this into normal
 linked representation of binary tree where every node has data, left and right pointers?
 In the linked list representation, we cannot directly access the children of the current
 node unless we traverse the list.
 */

// Linked list node
struct ListNode
{
    int data;
    ListNode* next;
};

// Binary tree node structure
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left, *right;
};

// Function to insert a node at the beginning of the Linked List
void push(struct ListNode** head_ref, int new_data)
{
    // allocate node and assign data
    struct ListNode* new_node = new ListNode;
    new_node->data = new_data;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref)    = new_node;
}

// method to create a new binary tree node from the given data
BinaryTreeNode* newBinaryTreeNode(int data)
{
    BinaryTreeNode *temp = new BinaryTreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/*
 * We are mainly given level order traversal in sequential access form.
 * We know head of linked list is always is root of the tree. We take the first
 * node as root and we also know that the next two nodes are left and right children
 * of root. So we know partial Binary Tree. The idea is to do Level order traversal
 * of the partially built Binary Tree using queue and traverse the linked list at the
 * same time. At every step, we take the parent node from queue, make next two nodes
 * of linked list as children of the parent node, and enqueue the next two nodes to queue.
 */
/*
 * ALGO:
 *  1. Create an empty queue.
	2. Make the first node of the list as root, and enqueue it to the queue.
	3. Until we reach the end of the list, do the following.
		………a. Dequeue one node from the queue. This is the current parent.
		………b. Traverse two nodes in the list, add them as children of the current parent.
		………c. Enqueue the two nodes into the queue.
 */

// converts a given linked list representing a complete binary tree into the
// linked representation of binary tree.
void convertList2Binary(ListNode *head, BinaryTreeNode* &root)
{
    // queue to store the parent nodes
    queue<BinaryTreeNode *> q;

    // Base Case
    if (head == NULL)
    {
        root = NULL; // Note that root is passed by reference
        return;
    }

    // 1.) The first node is always the root node, and add it to the queue
    root = newBinaryTreeNode(head->data);
    q.push(root);

    // advance the pointer to the next node
    head = head->next;

    // until the end of linked list is reached, do the following steps
    while (head)
    {
        // 2.a) take the parent node from the q and remove it from q
        BinaryTreeNode* parent = q.front();
        q.pop();

        // 2.c) take next two nodes from the linked list. We will add
        // them as children of the current parent node in step 2.b. Push them
        // into the queue so that they will be parents to the future nodes
        BinaryTreeNode *leftChild = NULL, *rightChild = NULL;
        leftChild = newBinaryTreeNode(head->data);
        q.push(leftChild);
        head = head->next;
        if (head)
        {
            rightChild = newBinaryTreeNode(head->data);
            q.push(rightChild);
            head = head->next;
        }

        // 2.b) assign the left and right children of parent
        parent->left = leftChild;
        parent->right = rightChild;
    }
}


// Utility function to traverse the binary tree after conversion
void inorderTraversal(BinaryTreeNode* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

// Driver program to test above functions
int main()
{
    // create a linked list shown in above diagram
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    BinaryTreeNode *root;
    convertList2Binary(head, root);

    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);
    return 0;
}
