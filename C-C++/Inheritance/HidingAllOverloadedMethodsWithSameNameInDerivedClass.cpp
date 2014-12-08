/*
 * HidingAllOverloadedMethodsWithSameNameInDerivedClass.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Hiding of all overloaded methods with same name in base class
In C++, if a derived class redefines base class member method then all the base class methods with sane
name become hidden in derived class.
For example, the following program doesn’t compile. In the following program, Derived redefines Base’s
method fun() and this makes fun(int i) hidden.

#include<iostream>

using namespace std;

class Base
{
public:
    int fun()
    {
        cout<<"Base::fun() called";
    }
    int fun(int i)
    {
        cout<<"Base::fun(int i) called";
    }
};

class Derived: public Base
{
public:
    int fun()
    {
        cout<<"Derived::fun() called";
    }
};

int main()
{
    Derived d;
    d.fun(5);  // Compiler Error
    return 0;
}
Even if the signature of the derived class method is different, all the overloaded methods in base class
become hidden. For example, in the following program, Derived::fun(char ) makes both Base::fun() and
Base::fun(int ) hidden.

#include<iostream>

using namespace std;

class Base
{
public:
    int fun()
    {
        cout<<"Base::fun() called";
    }
    int fun(int i)
    {
        cout<<"Base::fun(int i) called";
    }
};

class Derived: public Base
{
public:
    int fun(char c)  // Makes Base::fun() and Base::fun(int ) hidden
    {
        cout<<"Derived::fun(char c) called";
    }
};

int main()
{
    Derived d;
    d.fun();  // Compiler Error
    return 0;
}
Note that the above facts are true for both static and nonstatic methods.
 */


