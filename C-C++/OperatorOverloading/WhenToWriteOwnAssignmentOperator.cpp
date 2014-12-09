/*
 * WhenToWriteOwnAssignmentOperator.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: cvora
 */

/*
 * When should we write our own assignment operator in C++?
The answer is same as Copy Constructor. If a class doesn’t contain pointers, then there is no need to
write assignment operator and copy constructor. The compiler creates a default copy constructor and
assignment operators for every class. The compiler created copy constructor and assignment operator
may not be sufficient when we have pointers or any run time allocation of resource like file handle,
a network connection..etc. For example, consider the following program.

#include<iostream>
using namespace std;

// A class without user defined assignment operator
class Test
{
    int *ptr;
public:
    Test (int i = 0)      { ptr = new int(i); }
    void setValue (int i) { *ptr = i; }
    void print()          { cout << *ptr << endl; }
};

int main()
{
    Test t1(5);
    Test t2;
    t2 = t1;
    t1.setValue(10);
    t2.print();
    return 0;
}
Output of above program is “10”. If we take a look at main(), we modified ‘t1′ using setValue() function,
but the changes are also reflected in object ‘t2′. This type of unexpected changes cause problems.
Since there is no user defined assignment operator in the above program, compiler creates a default
assignment operator, which copies ‘ptr’ of right hand side to left hand side. So both ‘ptr’s start
pointing to the same location.

We can handle the above problem in two ways.

1) Do not allow assignment of one object to other object. We can create our own dummy assignment
operator and make it private.

2) Write your own assignment operator that does deep copy.

Same is true for Copy Constructor.

Following is an example of overloading assignment operator for the above class.

#include<iostream>
using namespace std;

class Test
{
    int *ptr;
public:
    Test (int i = 0)      { ptr = new int(i); }
    void setValue (int i) { *ptr = i; }
    void print()          { cout << *ptr << endl; }
    Test & operator = (const Test &t);
};

Test & Test::operator = (const Test &t)
{
   // Check for self assignment
   if(this != &t)
     *ptr = *(t.ptr);

   return *this;
}

int main()
{
    Test t1(5);
    Test t2;
    t2 = t1;
    t1.setValue(10);
    t2.print();
    return 0;
}
Output

5
We should also add a copy constructor to the above class, so that the statements like “Test t3 = t4;”
also don’t cause any problem.

Note the if condition in assignment operator. While overloading assignment operator, we must check for
self assignment. Otherwise assigning an object to itself may lead to unexpected results (See this).
Self assignment check is not necessary for the above ‘Test’ class, because ‘ptr’ always points to
one integer and we may reuse the same memory. But in general, it is a recommended practice to do
self-assignment check.

 *
 */


