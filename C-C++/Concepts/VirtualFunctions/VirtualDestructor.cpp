/*
 * VirtualDestructor.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Deleting a derived class object using a pointer to a base class that has a non-virtual destructor results
 * in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.
Source:
https://www.securecoding.cert.org/confluence/display/cplusplus/OOP34-CPP.+Ensure+the+proper+destructor+is+called+for+polymorphic+objects

For example, following program results in undefined behavior. Although the output of following program may be
different on different compilers, when compiled using Dev-CPP, it prints following.
Constructing base
Constructing derived
Destructing base

// A program without virtual destructor causing undefined behavior
#include<iostream>

using namespace std;

class base {
  public:
    base()
    { cout<<"Constructing base \n"; }
    ~base()
    { cout<<"Destructing base \n"; }
};

class derived: public base {
  public:
    derived()
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};

int main(void)
{
  derived *d = new derived();
  base *b = d;
  delete b;
  getchar();
  return 0;
}
Making base class destructor virtual guarantees that the object of derived class is destructed properly, i.e.,
both base class and derived class destructors are called. For example, following program prints:
Constructing base
Constructing derived
Destructing derived
Destructing base

// A program with virtual destructor
#include<iostream>

using namespace std;

class base {
  public:
    base()
    { cout<<"Constructing base \n"; }
    virtual ~base()
    { cout<<"Destructing base \n"; }
};

class derived: public base {
  public:
    derived()
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};

int main(void)
{
  derived *d = new derived();
  base *b = d;
  delete b;
  getchar();
  return 0;
}
As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor
(even if it does nothing). This way, you ensure against any surprises later.
 */


