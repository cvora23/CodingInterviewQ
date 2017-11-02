/*
 * BstSequence.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: chivora
 */


/*
 *
 *   A binary search tree was created by traversing through an array from left to right and inserting each element.
 *   Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.
 *
 *                  2
 *                *  *
 *               *    *
 *              *      *
 *             1        3
 *
 *
 *             Above Tree can be represented as:
 *
 *             Array 1 : {2,1,3}
 *             Array 2 : {2,3,1}
 */

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<list>
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

using namespace std;

/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};

struct TNode* newNode(int data);

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

void insert(struct TNode **q,int num)
{
     if(*q==NULL)
     {
		 *q = (struct TNode *)malloc(sizeof(struct TNode));
		 (*q)->left = NULL;
		 (*q)->data = num;
		 (*q)->right = NULL;
     }
     else
     {
         if(num<((*q)->data))
        	 insert(&((*q)->left),num);
         else
        	 insert(&((*q)->right),num);
     }
     return;
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder (TNode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
/*
 *
I assume you want a list of all sequences which will generate the same BST.
In this answer, we will use Divide and Conquer.
We will create a function findAllSequences(Node *ptr) which takes a node pointer as input and returns all the distinct
sequences which will generate the subtree hanging from ptr. This function will return a Vector of Vector of int, i.e.
vector<vector<int>> containing all the sequences.

The main idea for generating sequence is that root must come before all its children.

Algorithm:

Base Case 1:
If ptr is NULL, then return a vector with an empty sequence.

if (ptr == NULL) {
    vector<int> seq;
    vector<vector<int> > v;
    v.push_back(seq);
    return v;
}
Base Case 2:
If ptr is a leaf node, then return a vector with a single sequence. Its Trivial that this sequence will contain only a single element,
i.e. value of that node.

if (ptr -> left == NULL && ptr -> right == NULL) {
    vector<int> seq;
    seq.push_back(ptr -> val);
    vector<vector<int> > v;
    v.push_back(seq);
    return v;
}

Divide Part (this part is very simple.)
We assume that we have a function that can solve this problem, and thus we solve it for left sub tree and right sub tree.

vector<vector<int> > leftSeq  = findAllSeq(ptr -> left);
vector<vector<int> > rightSeq = findAllSeq(ptr -> right);

Merging the two solution.(The crux is in this step.)
Till now we have two set containing distinct sequences:
i. leftSeq  - all sequences in this set will generate left subtree.
ii. rightSeq - all sequences in this set will generate right subtree.
Now each sequence in left subtree can be merged with each sequence of right subtree. While merging we should be careful that the
relative order of elements is preserved. Also in each of the merged sequence we will add the value of current node in the
beginning because root must come before all children.

Pseudocode for Merge

vector<vector<int> > results
for all sequences L in leftSeq
    for all sequences R in rightSeq
        create a vector flags with l.size() 0's and R.size() 1's
        for all permutations of flag
            generate the corresponding merged sequence.
            append the current node's value in beginning
            add this sequence to the results.
return results.

Explaination: Let us take a sequence, say L(of size n) from the set leftSeq, and a sequence, say R(of size m) from set rightSeq.
Now these two sequences can be merged in m+nCn ways!
Proof: After merging, the new sequence will have m + n elements. As we have to maintain the relative order of elements,
so firstly we will fill all n the elements from L in any of n places among total (m+n) places.
After that remaining m places can be filled by elements of R. Thus we have to choose n places from (m+n) places.
To do this, lets create take a Boolean vector, say flags and fill it with n 0's and m 1's.
A value of 0 represents a member from left sequence and a value of 1 represents member from  right sequence.
All what is left is to generate all permutations of this flags vector, which can be done with next_permutation.
Now for each permutation of flags we will have a distinct merged sequence of L and R.
eg: Say L={1, 2, 3} R={4, 5}
so, n=3 and m=2
thus, we can have 3+2C3 merged sequences, i.e. 10.
1.now, Initially flags = {0 0 0 1 1}, filled with 3 0's and 2 1's
this will result into this merged sequence: 1 2 3 4 5
2.after calling nextPermutation we will have
flags = {0 0 1 0 1}
and this will generate sequence: 1 2 4 3 5
3.again after calling nextPermutation we will have
flags = {0 0 1 1 0}
ans this will generate sequence: 1 2 4 5 3
and so on...
 */


vector<vector<int> > findAllSeq(TNode *ptr)
{
	/*
	 * Base Case 1:
	 * If ptr is NULL, then return a vector with an empty sequence.
	 */
    if (ptr == NULL) {
        vector<int> seq;
        vector<vector<int> > v;
        v.push_back(seq);
        return v;
    }

    /*
     * Base Case 2:
     * ptr is a leaf node, then return a vector with a single sequence.
     * Its Trivial that this sequence will contain only a single element,i.e. value of that node.
     */
    if (ptr -> left == NULL && ptr -> right == NULL) {
        vector<int> seq;
        seq.push_back(ptr->data);
        vector<vector<int> > v;
        v.push_back(seq);
        return v;
    }

    /*
     * 	Divide Part (this part is very simple.)
		We assume that we have a function that can solve this problem, and thus we solve it for left sub tree and right sub tree.

		vector<vector<int> > leftSeq  = findAllSeq(ptr -> left);
		vector<vector<int> > rightSeq = findAllSeq(ptr -> right);

		Merging the two solution.(The crux is in this step.)
		Till now we have two set containing distinct sequences:
		i. leftSeq  - all sequences in this set will generate left subtree.
		ii. rightSeq - all sequences in this set will generate right subtree.
		Now each sequence in left subtree can be merged with each sequence of right subtree. While merging we should be careful that the
		relative order of elements is preserved. Also in each of the merged sequence we will add the value of current node in the
		beginning because root must come before all children.
     *
     */
    vector<vector<int> > results, left, right;
    left  = findAllSeq(ptr -> left);
    right = findAllSeq(ptr -> right);
    int size = left[0].size() + right[0].size() + 1;

    vector<bool> flags(left[0].size(), 0);
    for (int k = 0; k < right[0].size(); k++)
        flags.push_back(1);

    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < right.size(); j++) {
            do {
                vector<int> tmp(size);
                tmp[0] = ptr -> data;
                int l = 0, r = 0;
                for (int k = 0; k < flags.size(); k++) {
                    tmp[k+1] = (flags[k]) ? right[j][r++] : left[i][l++];
                }
                results.push_back(tmp);
            } while (next_permutation(flags.begin(), flags.end()));
        }
    }

    return results;
}

int main(){

    srand((unsigned)time(0));
    struct TNode *p;
    p =NULL;
   // cout<<p<<endl;
    int data [10] = {50, 20, 60, 10, 25,70, 5, 15, 65, 8};
    for(int i=0;i<10;i++)
    {
          insert(&p,data[i]);
     //     cout<<p<<endl;
    }

    vector<vector<int> > vec = findAllSeq(p);

    /*
     * print result
     */

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout<<endl;
    }
	return 0;

}




