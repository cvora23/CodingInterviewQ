/*
 * RestrictiveAccessDerivedClassMethod.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * What happens when more restrictive access is given to a derived class method in C++?
We have discussed a similar topic in Java here. Unlike Java, C++ allows to give more restrictive access to
derived class methods. For example the following program compiles fine.

#include<iostream>
using namespace std;

class Base {
public:
    virtual int fun(int i) { }
};

class Derived: public Base {
private:
    int fun(int x)   {  }
};

int main()
{  }
In the above program, if we change main() to following, will get compiler error becuase fun() is private in derived class.

int main()
{
    Derived d;
    d.fun(1);
    return 0;
}


What about the below program?

#include<iostream>
using namespace std;

class Base {
public:
    virtual int fun(int i) { cout << "Base::fun(int i) called"; }
};

class Derived: public Base {
private:
    int fun(int x)   { cout << "Derived::fun(int x) called"; }
};

int main()
{
    Base *ptr = new Derived;
    ptr->fun(10);
    return 0;
}
Output:

 Derived::fun(int x) called
In the above program, private function “Derived::fun(int )” is being called through a base class pointer,
the program works fine because fun() is public in base class. Access specifiers are checked at compile
time and fun() is public in base class. At run time, only the function corresponding to the pointed object
is called and access specifier is not checked. So a private function of derived class is being called
through a pointer of base class.
 */


