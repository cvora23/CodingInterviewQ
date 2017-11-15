/*
 * PureVirtualDestructors.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Can a destructor be pure virtual in C++?
Yes, it is possible to have pure virtual destructor. Pure virtual destructor are legal in standard C++
and one of the most important thing is that if class contains pure virtual destructor it is must to
provide a function body for the pure virtual destructor. This seems strange that how a virtual function
is pure if it requires a function body? But destructors are always called in the reverse order of the
class derivation. That means derived class destructor will be invoked first & then base class destructor
will be called. If definition for the pure virtual destructor is not provided then what function body
will be called during object destruction? Therefore compiler & linker enforce existence of function body for pure virtual destructor.
Consider following program:

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed";
    }
};

int main()
{
    Base *b=new Derived();
    delete b;
    return 0;
}
The linker will produce following error in the above program.

test.cpp:(.text$_ZN7DerivedD1Ev[__ZN7DerivedD1Ev]+0x4c):
undefined reference to `Base::~Base()'
Now if the definition for the pure virtual destructor is provided then the program compiles & runs fine.

#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};
Base::~Base()
{
    std::cout << "Pure virtual destructor is called";
}

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed\n";
    }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}
Output:

~Derived() is executed
Pure virtual destructor is called
It is important to note that class becomes abstract class when it contains pure virtual destructor.
For example try to compile the below program.

#include <iostream>
class Test
{
public:
    virtual ~Test()=0; // Test now becomes abstract class
};
Test::~Test() { }

int main()
{
    Test p;
    Test* t1 = new Test;
    return 0;
}
The above program fails in compilation & shows following error messages.
[Error] cannot declare variable ‘p’ to be of abstract type ‘Test’
[Note] because the following virtual functions are pure within ‘Test':
[Note] virtual Test::~Test()
[Error] cannot allocate an object of abstract type ‘Test’
[Note] since type ‘Test’ has pure virtual functions
 */



