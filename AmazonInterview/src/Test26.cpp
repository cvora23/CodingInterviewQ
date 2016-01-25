/*
 * Test26.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: chintan
 */

/*
 * Implement a function that returns the i-th most popular item sold at Amazon.
You cannot rely on any libraries.

class Item {
String itemId;
int quantitySold;
}

**
* Find the ith most popular item in the list.
*
String find(List<Item> items, int i) {
your code goes here
}
 */

#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef struct _Item{
	std::string itemId;
	int qtySold;
}Item;

// write a < operator for Item

class MyMaxHeap
{
protected:
    vector<Item> _vector;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void Heapify();

public:
    MyMaxHeap(Item* array, int length);
    MyMaxHeap(const vector<Item>& vector);
    MyMaxHeap();
    friend bool operator< (Item &cC1, Item &cC2);
    friend std::ostream& operator<<(std::ostream& os, const Item& dt);

    std::string findMostPopularItem(int position);
    virtual ~ MyMaxHeap();

    void print();

    virtual void Insert(Item newValue);
    Item GetMax();
    virtual void DeleteMax();
};

bool operator< (Item &cC1, Item &cC2)
{
    return cC1.qtySold < cC2.qtySold;
}

std::ostream& operator<<(std::ostream& os, const Item& pt)
{
    os << "{ "<<pt.itemId << ',' << pt.qtySold << " }";
    return os;
}


MyMaxHeap::MyMaxHeap(Item* array, int length) : _vector(length)
{
    for(int i = 0; i < length; ++i)
    {
        _vector.push_back(array[i]);
    }

    Heapify();
}

MyMaxHeap::MyMaxHeap(const vector<Item>& vector) : _vector(vector)
{
    Heapify();
}

MyMaxHeap::MyMaxHeap()
{
}

MyMaxHeap::~MyMaxHeap()
{

}

void MyMaxHeap::Heapify()
{
    int length = _vector.size();
    for(int i=length-1; i>=0; --i)
    {
        BubbleDown(i);
    }
}

void MyMaxHeap::BubbleDown(int index)
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
    	Item temp = _vector[index];
        _vector[index] = _vector[maxIndex];
        _vector[maxIndex] = temp;
        BubbleDown(maxIndex);
    }
}

void MyMaxHeap::BubbleUp(int index)
{
    if(index == 0)
        return;

    int parentIndex = (index-1)/2;

    if(_vector[parentIndex] < _vector[index])
    {
        //need to swap
    	Item temp = _vector[parentIndex];
        _vector[parentIndex] = _vector[index];
        _vector[index] = temp;
        BubbleUp(parentIndex);
    }
}

void MyMaxHeap::Insert(Item newValue)
{
    int length = _vector.size();
    _vector[length] = newValue;

    BubbleUp(length);
}

Item MyMaxHeap::GetMax()
{
    return _vector[0];
}

void MyMaxHeap::DeleteMax()
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

void MyMaxHeap::print(){
	for(unsigned int i=0;i<_vector.size();i++){
		cout<<_vector[i]<< " ";
	}
	cout<<endl;
}

// this functions deletes all max. We could probably store it and re-insert
std::string MyMaxHeap::findMostPopularItem(int position){
	Item retVal;
	for(int i=0;i<position;i++){
		retVal = GetMax();
		DeleteMax();
	}
	return retVal.itemId;
}

int main(){
	Item ItemList[8] = { {"a",5},
						{"b",6},
						{"c",8},
						{"d",3},
						{"e",4},
						{"f",1},
						{"g",10},
						{"h",12},
						};
	std::vector<Item>items(ItemList, ItemList + 8);
	MyMaxHeap myMaxHeap(items);
	std::cout<<myMaxHeap.findMostPopularItem(6)<<endl;
	return 0;

}
