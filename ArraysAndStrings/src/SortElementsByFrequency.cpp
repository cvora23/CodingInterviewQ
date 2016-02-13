/*
 * SortElementsByFrequency.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: cvora
 */

/*
 * Sort elements by frequency | Set 1
Asked By Binod

Question:
Print the elements of an array in the decreasing frequency if 2 numbers have
same frequency then print the one which came 1st
E.g. 2 5 2 8 5 6 8 8 output: 8 8 8 2 2 5 5 6.



METHOD 1 (Use Sorting)

  1) Use a sorting algorithm to sort the elements O(nlogn)
  2) Scan the sorted array and construct a 2D array of element and count O(n).
  3) Sort the 2D array according to count O(nlogn).
Example:

  Input 2 5 2 8 5 6 8 8

  After sorting we get
  2 2 5 5 6 8 8 8

  Now construct the 2D array as
  2, 2
  5, 2
  6, 1
  8, 3

  Sort by count
  8, 3
  2, 2
  5, 2
  6, 1

There is one issue with above approach (thanks to ankit for pointing this out).
If we modify the input to 5 2 2 8 5 6 8 8, then we should get 8 8 8 5 5 2 2 6
and not 8 8 8 2 2 5 5 6 as will be the case.
To handle this, we should use indexes in step 3, if two counts are same then we should
first process(or print) the element with lower index.
In step 1, we should store the indexes instead of elements.

  Input 5  2  2  8  5  6  8  8

  After sorting we get
  Element 2 2 5 5 6 8 8 8
  Index   1 2 0 4 5 3 6 7

  Now construct the 2D array as
  Index, Count
  1,      2
  0,      2
  5,      1
  3,      3

  Sort by count (consider indexes in case of tie)
  3, 3
  0, 2
  1, 2
  5, 1

  Print the elements using indexes in the above 2D array.
 *
 */

/*
 * Following is detailed algorithm.
1) Create a BST and while creating BST maintain the count i,e frequency of each coming element in same BST.
This step may take O(nLogn) time if a self balancing BST is used.
2) Do Inorder traversal of BST and store every element and count of each element in an auxiliary array.
Let us call the auxiliary array as ‘count[]’.
Note that every element of this array is element and frequency pair.
This step takes O(n) time.
3) Sort ‘count[]’ according to frequency of the elements.
This step takes O(nLohn) time if a O(nLogn) sorting algorithm is used.
4) Traverse through the sorted array ‘count[]’.
For each element x, print it ‘freq’ times where ‘freq’ is frequency of x. This step takes O(n) time.

Overall time complexity of the algorithm can be minimum O(nLogn) if we use a O(nLogn) sorting algorithm and
use a self balancing BST with O(Logn) insert operation.

 */

// Implementation of above algorithm in C++.
#include <iostream>
#include <stdlib.h>
using namespace std;

/* A BST node has data, freq, left and right pointers */
struct BSTNode
{
    struct BSTNode *left;
    int data;
    int freq;
    struct BSTNode *right;
};

// A structure to store data and its frequency
struct dataFreq
{
    int data;
    int freq;
};

/* Function for qsort() implementation. Compare frequencies to
   sort the array according to decreasing order of frequency */
int compare(const void *a, const void *b)
{
    return ( (*(const dataFreq*)b).freq - (*(const dataFreq*)a).freq );
}

/* Helper function that allocates a new node with the given data,
   frequency as 1 and NULL left and right  pointers.*/
BSTNode* newNode(int data)
{
    struct BSTNode* node = new BSTNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->freq = 1;
    return (node);
}

// A utility function to insert a given key to BST. If element
// is already present, then increases frequency
BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (data == root->data) // If already present
        root->freq += 1;
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to copy elements and their frequencies to count[].
void store(BSTNode *root, dataFreq count[], int *index)
{
    // Base Case
    if (root == NULL) return;

    // Recur for left substree
    store(root->left, count, index);

    // Store item from root and increment index
    count[(*index)].freq = root->freq;
    count[(*index)].data = root->data;
    (*index)++;

    // Recur for right subtree
    store(root->right, count, index);
}

// The main function that takes an input array as an argument
// and sorts the array items according to frequency
void sortByFrequency(int arr[], int n)
{
    // Create an empty BST and insert all array items in BST
    struct BSTNode *root = NULL;
    for (int i = 0; i < n; ++i)
        root = insert(root, arr[i]);

    // Create an auxiliary array 'count[]' to store data and
    // frequency pairs. The maximum size of this array would
    // be n when all elements are different
    dataFreq count[n];
    int index = 0;
    store(root, count, &index);

    // Sort the count[] array according to frequency (or count)
    qsort(count, index, sizeof(count[0]), compare);

    // Finally, traverse the sorted count[] array and copy the
    // i'th item 'freq' times to original array 'arr[]'
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        for (int freq = count[i].freq; freq > 0; freq--)
            arr[j++] = count[i].data;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Driver program to test above functions */
int main()
{
	{
		int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
		int n = sizeof(arr)/sizeof(arr[0]);
		sortByFrequency(arr, n);
		printArray(arr, n);
	}

    int arr[] = {5, 2 ,2, 8, 5, 6, 8, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortByFrequency(arr, n);
    printArray(arr, n);

    return 0;
}


