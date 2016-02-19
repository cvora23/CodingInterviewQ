/*
 * Test52.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: chintan
 */

#include <vector>
#include <stack>
#include "require.h"

void printGreatestElemOnRightSide(std::vector<int>vec){

	std::stack<int>ret;
	ret.push(-1);
	int max_so_far = vec[vec.size()-1];

	for(int i=vec.size()-2;i>=0;i--){
		if(vec[i]>max_so_far){
			max_so_far = vec[i];
			ret.push(-1);
		}else{
			ret.push(max_so_far);
		}
	}

	printStack(ret);

}

void printNextGreatestElemOnRightSide(std::vector<int>vec){

    int element, next;
    std::stack<int>resultStack;
    /* push the first element to stack */
    resultStack.push(vec[0]);

    // iterate for rest of the elements
    for (unsigned int i=1; i<vec.size(); i++)
    {
        next = vec[i];

        if (!resultStack.empty())
        {
            // if stack is not empty, then pop an element from stack
            element = resultStack.top();
            resultStack.pop();

            /* If the popped element is smaller than next, then
                a) print the pair
                b) keep popping while elements are smaller and
                stack is not empty */
            while (element < next)
            {
                printf("\n %d --> %d", element, next);
                if(resultStack.empty())
                   break;
                element = resultStack.top();
                resultStack.pop();
            }

            /* If element is greater than next, then push
               the element back */
            if (element > next)
            	resultStack.push(element);
        }

        /* push next to stack so that we can find
           next greater for it */
        resultStack.push(next);
    }

    /* After iterating over the loop, the remaining
       elements in stack do not have the next greater
       element, so print -1 for them */
    while (!resultStack.empty())
    {
        element = resultStack.top();
        resultStack.pop();
        next = -1;
        printf("\n %d -- %d", element, next);
    }


}

int main(){

	{
		int myInts[] = {2,4,8,10,12,14};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		printGreatestElemOnRightSide(arr1);
	}
	{
		int myInts[] = {4,5,2,25};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		printGreatestElemOnRightSide(arr1);
	}
	{
		int myInts[] = {4,5,2,3};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		printGreatestElemOnRightSide(arr1);
	}
	{
		int myInts[] = {7,5,2,6,25};
		std::vector<int>arr1(myInts, myInts + sizeof(myInts) / sizeof(int) );
		printArray2(arr1,arr1.size());
		printNextGreatestElemOnRightSide(arr1);
	}

}



