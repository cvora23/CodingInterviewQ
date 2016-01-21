/*
 * MinHeap.h
 *
 *  Created on: Nov 3, 2014
 *      Author: cvora
 */

#ifndef INCLUDE_MAXHEAP_H_
#define INCLUDE_MAXHEAP_H_

#include "vector"
using namespace std;

/**
 *
 * Introduction
 * A max binary heap is an efficient data structure based on a binary tree.
 * A max binary heap can be used to find the C (where C <= n) smallest
 * numbers out of n input numbers without sorting the entire input.
 *
 * Background
 * There are several background topics I need to cover here: binary heap,
 * a binary tree representation using an array and the complexity of constructing the heap.
 *
 * First the binary heap, a binary heap is a complete binary tree, in which every
 * node is greater than its left and right child nodes.
 * It is easy to see, due to this definition, that the maximum value of the
 * entire heap will always be the root.
 *
 * The second topic is binary tree representation using an array,
 * basically the rules are as follows:
 * 	1: The left child of node in index i is: 2*i+1
 * 	2: The right child of node in index i is: 2*i+2
 * 	3: The parent of the node in index i is: (int)((i-1)/2)
 * The root of the tree is in index 0, its left child is in index 1
 * and its right child is in index 2 and so on.
 *
 * The third topic is construction of the heap, before explaining how the heap is built,
 * I'll explain two operations, which help performing all the operations available for
 * the heap data structure:
 *
 * 1: BubbleDown - BubbleDown of a node means: if the node is violating the max heap rule, meaning it is not greater
 * than both its children, switch it with its maximum child node. Continue doing this recursively until the node
 * is no longer violating the heap rule.
 * Each switch of the node lowers its level by 1, so at most there can be log(n) switches in a single BubbleDown operation.
 * 2: BubbleUp - BubbleUp is similar to the BubbleDown, only here we test violation of the heap rule between the node
 * and its parent, if such a violation exists, we switch the node with its parent. Once again, continue doing so
 * recursively until the node no longer violates the heap rule. The complexity of the BubbleUp is also log(n)
 * since that is the maximum switches that can performed in a single BubbleUp operation.
 *
 * The main operations of the heap are insert and delete max, here is the
 * The algorithm for insert operation:
 * Insert the new value at the last position in the array (which means adding a new leaf in the lowest
 * level of the tree). The only violation of the heap can be at the last leaf.
 * Perform BubbleUp operation of the new leaf. This will fix all violations of the heap.
 * Therefore, insert operation complexity is log(n).
 *
 * The algorithm for the delete max operation:
 * Remove the root node.
 * Move the value in the last index of the array (the last leaf in the lowest level of the tree)
 * to the root position (index 0 in the array). The only violation of the heap is at the root.
 * Decrease the array size by 1.
 * Perform BubbleDown operation on the root. This will fix all violations of the heap.
 * Therefore, delete min operation complexity is also log(n).
 *
 * Now it is finally time to talk about heap construction (also called heapify):
 * The trivial way to construct the heap would be to call insert on every element of the array,
 * this will give us n*log(n) complexity.
 *
 * There is a much more efficient way to construct the heap:
 * Go over all elements of the array from last to first.
 * For each element, call BubbleDown on the element.
 */

class MaxHeap
{
protected:
    vector<int> _vector;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void Heapify();

public:
    MaxHeap(int* array, int length);
    MaxHeap(const vector<int>& vector);
    MaxHeap();

    virtual ~ MaxHeap();

    void print();

    virtual void Insert(int newValue);
    int GetMax();
    virtual void DeleteMax(int newVal=0);
};



#endif /* INCLUDE_MAXHEAP_H_ */
