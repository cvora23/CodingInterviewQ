/*
 * VirtualFunctionsDerivedClass.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Virtual functions in derived classes
In C++, once a member function is declared as a virtual function in a base class, it becomes virtual in
every class derived from that base class. In other words, it is not necessary to use the keyword virtual
in the derived class while declaring redefined versions of the virtual base class function.

Source: http://www.umsl.edu/~subramaniana/virtual2.html

For example, the following program prints “C::fun() called” as B::fun() becomes virtual automatically.

#include<iostream>

using namespace std;

class A {
  public:
    virtual void fun()
    { cout<<"\n A::fun() called ";}
};

class B: public A {
  public:
    void fun()
    { cout<<"\n B::fun() called "; }
};

class C: public B {
  public:
    void fun()
    { cout<<"\n C::fun() called "; }
};

int main()
{
   C c; // An object of class C
   B *b = &c; // A pointer of type B* pointing to c
   b->fun();  // this line prints "C::fun() called"
   getchar();
   return 0;
}
 */


