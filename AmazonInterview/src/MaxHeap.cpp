/*
 * MinHeap.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: cvora
 */

#include "MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap(int* array, int length) : _vector(length)
{
    for(int i = 0; i < length; ++i)
    {
        _vector.push_back(array[i]);
    }

    Heapify();
}

MaxHeap::MaxHeap(const vector<int>& vector) : _vector(vector)
{
    Heapify();
}

MaxHeap::MaxHeap()
{
}

MaxHeap::~MaxHeap()
{

}

void MaxHeap::Heapify()
{
    int length = _vector.size();
    for(int i=length-1; i>=0; --i)
    {
        BubbleDown(i);
    }
}

void MaxHeap::BubbleDown(int index)
{
    int length = _vector.size();
    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    if(leftChildIndex >= length)
        return; //index is a leaf

    int maxIndex = index;

    if(_vector[index] < _vector[leftChildIndex])
    {
    	maxIndex = leftChildIndex;
    }

    if((rightChildIndex < length) && (_vector[maxIndex] < _vector[rightChildIndex]))
    {
    	maxIndex = rightChildIndex;
    }

    if(maxIndex != index)
    {
        //need to swap
        int temp = _vector[index];
        _vector[index] = _vector[maxIndex];
        _vector[maxIndex] = temp;
        BubbleDown(maxIndex);
    }
}

void MaxHeap::BubbleUp(int index)
{
    if(index == 0)
        return;

    int parentIndex = (index-1)/2;

    if(_vector[parentIndex] < _vector[index])
    {
        //need to swap
        int temp = _vector[parentIndex];
        _vector[parentIndex] = _vector[index];
        _vector[index] = temp;
        BubbleUp(parentIndex);
    }
}

void MaxHeap::Insert(int newValue)
{
    int length = _vector.size();
    _vector[length] = newValue;

    BubbleUp(length);
}

int MaxHeap::GetMax()
{
    return _vector[0];
}

void MaxHeap::DeleteMax(int)
{
    int length = _vector.size();

    if(length == 0)
    {
        return;
    }

    _vector[0] = _vector[length-1];
    _vector.pop_back();

    BubbleDown(0);
}

void MaxHeap::print(){
	for(unsigned int i=0;i<_vector.size();i++){
		cout<<_vector[i]<< " ";
	}
	cout<<endl;
}



