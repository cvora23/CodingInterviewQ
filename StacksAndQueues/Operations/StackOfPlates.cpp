/*
 * StackOfPlates.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: chivora
 */
#include<iostream>
#include<stdlib.h>
#include <stack>
#include <vector>

using namespace std;

/*
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks
 * and should create a new stack once the previous one exceeds capacity. SetOfStacks. push () and SetOfStacks.
 * pop () should behave identically to a single stack
 * (that is, pop ( ) should return the same values as it would if there were just a single stack).
 *
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 */

class SetOfStacks{
private:
	vector< stack<int> > stackSet;
	unsigned int current_stack;
	unsigned int max_stack_size;

public:

	SetOfStacks(int max_size):current_stack(0),max_stack_size(max_size)
	{
		stackSet.reserve(10);
		stackSet.push_back(stack<int>());
	}

	~SetOfStacks(){
		stackSet.clear();
	}

	void push(int element){
		stackSet[current_stack].push(element);
		if(stackSet[current_stack].size() > max_stack_size){
			stackSet.push_back(stack<int>());
			current_stack++;
			if(current_stack % 10 == 0 && current_stack >= stackSet.size()){
				stackSet.reserve(stackSet.size() + 10);
			}
		}
	}

	int pop(){
		int value = stackSet[current_stack].top();
		stackSet[current_stack].pop();

		if(stackSet[current_stack].size() == 0 && current_stack != 0){
			current_stack--;
		}
		return value;
	}

	int popAt(unsigned int index){
		int value = stackSet[index].top();
		stackSet[index].pop();

		if((stackSet[current_stack].size() == 0) && (index == current_stack) &&
				(current_stack != 0)){
			current_stack--;
		}
		return value;
	}

};

int main(){

	return 0;

}



