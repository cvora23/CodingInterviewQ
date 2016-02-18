/*
 * Test11.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: chintan
 */

/*
 * stream of numbers coming, get 'n' min elements at any point of time
 */

#include <iostream>
#include "ModifiedMaxHeap.h"
#include "require.h"

using namespace std;

int main(int argc, char* argv[])
{
	int myInts[] = {2,3,5,6,7,8,1,8,3,4,67,0};
	std::vector<int>input(myInts, myInts + sizeof(myInts) / sizeof(int) );

    cout<<"Array original "<<endl;
    printArray2(input,input.size());
	unsigned int maxSize = 3;
    ModifiedMaxHeap maxHeap(maxSize);
	for (unsigned int i = 0; i < input.size(); i++)
	{
		//cout << "Adding " << input[i] << endl;
		maxHeap.Insert(input[i]);
	}
	cout<<"Minimum 3 Values from Stream of bytes"<<endl;
	maxHeap.print();

    return 0;
}

/*
 *
 * Another Soln
 *
 * class Reservoir{

public:

    Reservoir(int n){
        size = n;
    }

    // put the number in stream in reservoir
    void put(int n){
        reservoir.push_back(n);
        sort(reservoir.begin(), reservoir.end());
        if(reservoir.size() >= size){
            reservoir.resize(size);
        }
    }

    // get the nth largest number
    int get(){
        return reservoir.back();
    }

private:
    int size;
    vector<int> reservoir;
};
 */

