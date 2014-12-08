/*
 * DefaultArgsVirtualFunction.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Default arguments and virtual function
Predict the output of following C++ program.

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun ( int x = 0 )
    {
        cout << "Base::fun(), x = " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun ( int x )
    {
        cout << "Derived::fun(), x = " << x << endl;
    }
};


int main()
{
    Derived d1;
    Base *bp = &d1;
    bp->fun();
    return 0;
}
Output:

Derived::fun(), x = 0
If we take a closer look at the output, we observe that fun() of derived class is called and default value of
base class fun() is used.
Default arguments do not participate in signature of functions. So signatures of fun() in base class and
derived class are considered same, hence the fun() of base class is overridden. Also, the default value
is used at compile time. When compiler sees that an argument is missing in a function call, it substitutes
the default value given. Therefore, in the above program, value of x is substituted at compile time, and
at run time derived class’s fun() is called.

Now predict the output of following program.

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun ( int x = 0)
    {
        cout << "Base::fun(), x = " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun ( int x = 10 ) // NOTE THIS CHANGE
    {
        cout << "Derived::fun(), x = " << x << endl;
    }
};


int main()
{
    Derived d1;
    Base *bp = &d1;
    bp->fun();
    return 0;
}
The output of this program is same as the previous program. The reason is same, the default value is substituted
at compile time. The fun() is called on bp which is a pointer of Base type. So compiler substitutes 0 (not 10).

In general, it is a best practice to avoid default values in virtual functions to avoid confusion (See this for more details)

 */


