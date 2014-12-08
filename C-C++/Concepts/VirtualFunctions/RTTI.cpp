/*
 * RTTI.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * RTTI (Run-time type information) in C++
In C++, RTTI (Run-time type information) is available only for the classes which have at least one virtual function.

For example, dynamic_cast uses RTTI and following program fails with error “cannot dynamic_cast `b’
(of type `class B*’) to type `class D*’ (source type is not polymorphic) ” because there is no
virtual function in the base class B.

#include<iostream>

using namespace std;

class B { };
class D: public B {};

int main()
{
  B *b = new D;
  D *d = dynamic_cast<D*>(b);
  if(d != NULL)
    cout<<"works";
  else
    cout<<"cannot cast B* to D*";
  getchar();
  return 0;
}
Adding a virtual function to the base class B makes it working.

#include<iostream>

using namespace std;

class B { virtual void fun() {} };
class D: public B { };

int main()
{
  B *b = new D;
  D *d = dynamic_cast<D*>(b);
  if(d != NULL)
    cout<<"works";
  else
    cout<<"cannot cast B* to D*";
  getchar();
  return 0;
}
 */


