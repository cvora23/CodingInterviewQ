/*
 * DefaultAssignmentOperatorAndReferences.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: cvora
 */

/*
 * Default Assignment Operator and References
We have discussed assignment operator overloading for dynamically allocated resources here .
This is a an extension of the previous post. In the previous post, we discussed that when we
don’t write our own assignment operator, compiler created assignment operator does shallow copy
and that cause problems. What happens when we have references in our class and there is no user
defined assignment operator. For example, predict the output of following program.

#include<iostream>
using namespace std;

class Test
{
    int x;
    int &ref;
public:
    Test (int i):x(i), ref(x) {}
    void print() { cout << ref; }
    void setX(int i) { x = i; }
};

int main()
{
    Test t1(10);
    Test t2(20);
    t2 = t1;
    t1.setX(40);
    t2.print();
    return 0;
}
Output:

Compiler Error: non-static reference member 'int& Test::ref',
             can't use default assignment operator
Compiler doesn’t creates default assignment operator in following cases

1. Class has a nonstatic data member of a const type or a reference type
2. Class has a nonstatic data member of a type which has an inaccessible copy assignment operator
3. Class is derived from a base class with an inaccessible copy assignment operator

When any of the above conditions is true, user must define assignment operator. For example,
if we add an assignment operator to the above code, the code works fine without any error.

#include<iostream>
using namespace std;

class Test
{
    int x;
    int &ref;
public:
    Test (int i):x(i), ref(x) {}
    void print() { cout << ref; }
    void setX(int i) { x = i; }
    Test &operator = (const Test &t) { x = t.x; return *this; }
};

int main()
{
    Test t1(10);
    Test t2(20);
    t2 = t1;
    t1.setX(40);
    t2.print();
    return 0;
}
Output:

10
 */


