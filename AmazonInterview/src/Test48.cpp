/*
 * Test48.cpp
 *
 *  Created on: Feb 13, 2016
 *      Author: chintan
 */
/*
 * Serialize and Deserialize a Binary Tree
Serialization is to store tree in a file so that it
can be later restored. The structure of tree must be maintained.
Deserialization is reading tree back from file.

If given Tree is Binary Search Tree?
If the given Binary Tree is Binary Search Tree, we can store it by either
storing preorder or postorder traversal.
In case of Binary Search Trees, only preorder or postorder traversal
is sufficient to store structure information.

=============================
Construct BST from given preorder traversal
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50},
then the output should be root of following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50

 */

#include "BTree.h"
#include <stack>
#include <vector>
#include "require.h"

/*
 * Following is a stack based iterative solution that works in O(n) time.

1. Create an empty stack.

2. Make the first value as root. Push it to the stack.

3. Keep on popping while the stack is not empty and the next value is greater than stack’s top value.
 Make this value as the right child of the last popped node. Push the new node to the stack.

4. If the next value is less than the stack’s top value,
make this value as the left child of the stack’s top node. Push the new node to the stack.

5. Repeat steps 3 and 4 until there are no items remaining in pre[].
 */

struct node* generateBinarySearchTree(std::vector<int>pre){
	struct node* root = NULL;
	std::stack<node*>mStack;
	root = newNode(pre[0]);
	mStack.push(root);
	// Iterate through rest of the size-1 items of given preorder array
	for(unsigned int i=1;i<pre.size();i++){
		struct node* val = NULL;
		// Keep on popping while the next value is greater than
		// stack's top value.
		while(!mStack.empty() && pre[i] > mStack.top()->data){
			val = mStack.top();
			mStack.pop();
		}
		 // Make this greater value as the right child and push it to the stack
		if(val != NULL){
			val->right = newNode(pre[i]);
			mStack.push(val->right);
		}
		// If the next value is less than the stack's top value, make this value
		// as the left child of the stack's top node. Push the new node to stack
		else{
			mStack.top()->left = newNode(pre[i]);
			mStack.push(mStack.top()->left);
		}
	}
	return root;
}

int main(){

	{
		int myInts[] = {10, 5, 1, 7, 40, 50};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		struct node* root = generateBinarySearchTree(arr1);
		printInorder(root);
	}

	return 0;

}

