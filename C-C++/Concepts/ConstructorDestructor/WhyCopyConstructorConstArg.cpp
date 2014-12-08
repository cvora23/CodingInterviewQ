/*
 * WhyCopyConstructorConstArg.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */
/*
 * Why copy constructor argument should be const in C++?
When we create our own copy constructor, we pass an object by reference and we generally pass it as a const reference.
One reason for passing const reference is, we should use const in C++ wherever possible so that objects are not accidentally
modified. This is one good reason for passing reference as const, but there is more to it. For example, predict
the output of following C++ program. Assume that copy elision is not done by compiler.

#include<iostream>
using namespace std;

class Test
{
   // Class data members
public:
   Test(Test &t) { // Copy data members from t}
   Test()        { // Initialize data members  }
};

Test fun()
{
    cout << "fun() Called\n";
    Test t;
    return t;
}

int main()
{
    Test t1;
    Test t2 = fun();
    return 0;
}
Output:

 Compiler Error in line "Test t2 = fun();"
The program looks fine at first look, but it has compiler error. If we add const in copy constructor,
the program works fine, i.e., we change copy constructor to following.

Test(const Test &t) { cout << "Copy Constructor Called\n"; }
Or if we change the line “Test t2 = fun();” to following two lines, then also the program works fine.

Test t2;
t2 = fun();
The function fun() returns by value. So the compiler creates a temporary object which is copied to t2 using copy
constructor in the original program (The temporary object is passed as an argument to copy constructor).
The reason for compiler error is, compiler created temporary objects cannot be bound to non-const references
and the original program tries to do that. It doesn’t make sense to modify compiler created temporary objects
as they can die any moment.
 */

