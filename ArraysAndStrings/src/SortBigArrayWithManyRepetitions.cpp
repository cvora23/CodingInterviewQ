/*
 * SortBigArrayWithManyRepetitions.cpp
 *
 *  Created on: Dec 4, 2017
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
 * How to sort a big array with many repetitions?
3.1
Consider a big array where elements are from a small set and in any range, i.e. there are many repetitions.
How to efficiently sort the array?

Example:
Input:  arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1}
Output: arr[] = {1, 1, 1, 1, 1, 12, 12, 12, 100, 100, 100, 100}
We strongly recommend you to minimize your browser and try this yourself first.

A Basic Sorting algorithm like MergeSort, HeapSort would take O(nLogn) time where n is number of elements, can we do better?

A Better Solution is to use Self-Balancing Binary Search Tree like AVL or Red-Black to sort in O(n Log m) time
where m is number of distinct elements. The idea is to extend tree node to have count of keys also.

struct Node
{
   int key;
   struct Node *left. *right;
   int count;  // Added to handle duplicates

   // Other tree node info for balancing like height in AVL
}
Below is complete algorithm using AVL tree.
1) Create an empty AVL Tree with count as an additional field.
2) Traverse input array and do following for every element ‘arr[i]’
…..a) If arr[i] is not present in tree, then insert it and initialize count as 1
…..b) Else increment its count in tree.
3) Do Inorder Traversal of tree. While doing inorder put every key its count times in arr[].

The 2nd step takes O(n Log m) time and 3rd step takes O(n) time. So overall time complexity is O(n Log m)

We can also use Hashing to solve above problem in O(n + m Log m) time.
1) Create an empty hash table. Input array values are stores as key and their counts are stored as value in hash table.
2) For every element ‘x’ of arr[], do following
…..a) If x ix present in hash table, increment its value
…..b) Else insert x with value equals to 1.
3) Consider all keys of hash table and sort them.
4) Traverse all sorted keys and print every key its value times.

Time complexity of 2nd step is O(n) under the assumption that hash search and insert take O(1) time.
Step 3 takes O(m Log m) time where m is total number of distinct keys in input array. Step 4 takes O(n) time.
So overall time complexity is O(n + m Log m).

Program implementation using Hash Table

 */


#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void sort(int arr[], int n)
{
   //1. Create an empty hash table.
    map<int, int> count;

    //2. Input array values are stores as key and their
    //counts are stored as value in hash table.
    for (int i=0; i<n; i++)
        count[arr[i]]++;

    map<int, int>::iterator it;
    int index = 0;

    //3. Consider all keys of hash table and sort them.
    //In std::map, keys are already sorted.

    //4. Traverse all sorted keys and print every key its value times.
    for (it=count.begin(); it!=count.end(); ++it)
    {
        while(it->second--)
        arr[index++]=it->first;
    }
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
        cout << endl;
 }

// Driver program to test above function.
int main()
{
    int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Input array is\n";
    printArray(arr, n);

    sort(arr, n);

    cout << "Sorted array is\n";
    printArray(arr, n);

    return 0;
}
