/*
 * MinHeapTest.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: cvora
 */

#include <iostream>
#include "MinHeap.h"
#include "require.h"

using namespace std;

int main(int argc, char* argv[])
{
    int array[] = {10, 4, 5, 30, 3, 300};
    cout<<"Array original "<<endl;
    printArray(array,sizeof(array)/sizeof(array[0]));

    cout<<"After min heapifying the array"<<endl;
    MinHeap minHeap(array, 6);
    minHeap.print();

    return 0;
}


