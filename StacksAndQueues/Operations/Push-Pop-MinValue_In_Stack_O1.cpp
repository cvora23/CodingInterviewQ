#include<iostream>
#include<stdlib.h>

// Cracking the Coding Interview Solution 3.2

/*
Design and Implement Special Stack Data Structure | Added Space Optimized Version
Question: Design a Data Structure SpecialStack that supports all
the stack operations like push(), pop(), isEmpty(), isFull() and an
additional operation getMin() which should return minimum element from
the SpecialStack. All these operations of SpecialStack must be O(1).
To implement SpecialStack, you should only use standard Stack data
structure and no other data structure like arrays, list, .. etc.

Example:

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, which is the minimum
element in the current stack.

If we do pop two times on stack, the stack becomes
29  --> TOP
19
118
18

When getMin() is called, it should return 18 which is the minimum
in the current stack.


Solution: Use two stacks: one to store actual stack elements and
other as an auxiliary stack to store minimum values. The idea is
to do push() and pop() operations in such a way that the top of
auxiliary stack is always the minimum. Let us see how push() and pop() operations work.

Push(int x) // inserts an element x to Special Stack
1) push x to the first stack (the stack with actual elements)
2) compare x with the top element of the second stack (the auxiliary stack). Let the top element be y.
…..a) If x is smaller than y then push x to the auxiliary stack.
…..b) If x is greater than y then push y to the auxiliary stack.

int Pop() // removes an element from Special Stack and return the removed element
1) pop the top element from the auxiliary stack.
2) pop the top element from the actual stack and return it.

The step 1 is necessary to make sure that the auxiliary stack is also updated for future operations.

int getMin() // returns the minimum element from Special Stack
1) Return the top element of auxiliary stack.

We can see that all above operations are O(1).
Let us see an example. Let us assume that both stacks are initially
empty and 18, 19, 29, 15 and 16 are inserted to the SpecialStack.

When we insert 18, both stacks change to following.
Actual Stack
18 <--- top
Auxiliary Stack
18 <---- top

When 19 is inserted, both stacks change to following.
Actual Stack
19 <--- top
18
Auxiliary Stack
18 <---- top
18

When 29 is inserted, both stacks change to following.
Actual Stack
29 <--- top
19
18
Auxiliary Stack
18 <---- top
18
18

When 15 is inserted, both stacks change to following.
Actual Stack
15 <--- top
29
19
18
Auxiliary Stack
15 <---- top
18
18
18

When 16 is inserted, both stacks change to following.
Actual Stack
16 <--- top
15
29
19
18
Auxiliary Stack
15 <---- top
15
18
18
18
Following is C++ implementation for SpecialStack class.
In the below implementation, SpecialStack inherits from Stack and
has one Stack object min which work as auxiliary stack.
 */

#include<iostream>
#include<stdlib.h>
#include <stack>

using namespace std;

/* A simple stack class with basic stack funtionalities */
class Stack
{
private:
    static const int max = 100;
    int arr[max];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
};

/* Stack's member method to check if the stack is iempty */
bool Stack::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

/* Stack's member method to check if the stack is full */
bool Stack::isFull()
{
    if(top == max - 1)
        return true;
    return false;
}

/* Stack's member method to remove an element from it */
int Stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow";
        abort();
    }
    int x = arr[top];
    top--;
    return x;
}

/* Stack's member method to insert an element to it */
void Stack::push(int x)
{
    if(isFull())
    {
        cout<<"Stack Overflow";
        abort();
    }
    top++;
    arr[top] = x;
}

/* A class that supports all the stack operations and one additional
  operation getMin() that returns the minimum element from stack at
  any time.  This class inherits from the stack class and uses an
  auxiliarry stack that holds minimum elements */
class SpecialStack: public Stack
{
    Stack min;
public:
    int pop();
    void push(int x);
    int getMin();
};

/* SpecialStack's member method to insert an element to it. This method
   makes sure that the min stack is also updated with appropriate minimum
   values */
void SpecialStack::push(int x)
{
    if(isEmpty()==true)
    {
        Stack::push(x);
        min.push(x);
    }
    else
    {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if( x < y )
          min.push(x);
        else
          min.push(y);
    }
}

/* SpecialStack's member method to remove an element from it. This method
   removes top element from min stack also. */
int SpecialStack::pop()
{
    int x = Stack::pop();
    min.pop();
    return x;
}

/* SpecialStack's member method to get minimum element from it. */
int SpecialStack::getMin()
{
    int x = min.pop();
    min.push(x);
    return x;
}

class SpecialStackVer2{

public:

	void push(int elem){
		stack1.push(elem);
		if(stack2.empty()){
			stack2.push(elem);
		}else if(elem<getMin()){
			stack2.push(elem);
		}
	}

	int pop(){

		int poppedElem;
		poppedElem = stack1.top();
		stack1.pop();
		if(poppedElem == getMin()){
			stack2.pop();
		}
		return poppedElem;
	}

	int getMin(){
		return stack2.top();
	}

private:
	std::stack<int>stack1;
	std::stack<int>stack2;
};

/* Driver program to test SpecialStack methods */
int main()
{
	{
		SpecialStack s;
		s.push(18);
		s.push(19);
		s.push(224);
		s.push(15);
		s.push(14);

		cout<<s.getMin()<<endl;
		s.pop();
		cout<<s.getMin()<<endl;
		s.pop();
		cout<<s.getMin()<<endl;

		s.push(5);
		cout<<s.getMin()<<endl;
	}

	{
		SpecialStackVer2 s;
		s.push(10);
		s.push(20);
		s.push(30);
		cout<<s.getMin()<<endl;
		s.push(5);
		cout<<s.getMin()<<endl;
	}

    return 0;
}
