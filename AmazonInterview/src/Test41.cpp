/*
 * Test41.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: chintan
 */

/*
 * An array consist of elements whose difference is positive or negative 1.
 * I have to find the given elements without using linear search.
Say
Int arr[]={1,2,3,4,3,4,5,6,7

To find : 6
.
Please provide some one code/algorithm for this problem.

We can first calculate the absolute-difference between first
element and element to be found and move the difference no. of steps.
If all are in continuous increasing or decreasing order element is found.
If order is mixed(increasing + decreasing),We will again calculate the
differnce and continue Till we reach our element or end of array.
Its better than O(n) ,We dont need to traverse the whole array

 */

#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>     /* abs */

using namespace std;

int find(std::vector<int>arr,int element)
{
	int difference=abs(element-arr[0]);
	unsigned int index=0;
	while(index<arr.size())
	{
		while(difference--)
				index++;
		if(arr[index]==element)
		{
			cout<<"element found "<<endl;
			return 0;
		}
		else
			difference=abs(arr[index]-element);
	}
	cout<<"Element not found  "<<endl;
	return 0;
}

int main(){

	int myInts[] = {1,2,3,4,3,4,5,6,7 };
	std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
	find(arr1,6);
	return 0;

}
