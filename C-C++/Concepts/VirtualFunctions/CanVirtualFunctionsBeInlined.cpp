/*
 * CanVirtualFunctionsBeInlined.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Can virtual functions be inlined?
Virtual functions are used to achieve runtime polymorphism or say late binding or dynamic binding.
Inline functions are used for efficiency. The whole idea behind the inline functions is that whenever
inline function is called code of inline function gets inserted or substituted at the point of inline
function call at compile time. Inline functions are very useful when small functions are frequently used
and called in a program many times.

By default all the functions defined inside the class are implicitly or automatically considered as inline
except virtual functions (Note that inline is a request to the compiler and its compilers choice to do inlining or not).

Whenever virtual function is called using base class reference or pointer it cannot be inlined
(because call is resolved at runtime), but whenever called using the object (without reference or pointer)
of that class, can be inlined because compiler knows the exact class of the object at compile time.

#include <iostream>
using namespace std;
class Base
{
public:
    virtual void who()
    {
        cout << "I am Base\n";
    }
};
class Derived: public Base
{
public:
    void who()
    {
        cout << "I am Derived\n";
    }
};

int main()
{
    // note here virtual function who() is called through
    // object of the class (it will be resolved at compile
    // time) so it can be inlined.
    Base b;
    b.who();

    // Here virtual function is called through pointer,
    // so it cannot be inlined
    Base *ptr = new Derived();
    ptr->who();

    return 0;
}
 */


