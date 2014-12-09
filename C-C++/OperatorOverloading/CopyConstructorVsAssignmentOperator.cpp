/*
 * CopyConstructorVsAssignmentOperator.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: cvora
 */

/*
 * Copy constructor vs assignment operator in C++
Difficulty Level: Rookie

Consider the following C++ program.

#include<iostream>
#include<stdio.h>

using namespace std;

class Test
{
public:
   Test() {}
   Test(const Test &t)
   {
      cout<<"Copy constructor called "<<endl;
   }
   Test& operator = (const Test &t)
   {
      cout<<"Assignment operator called "<<endl;
   }
};

int main()
{
  Test t1, t2;
  t2 = t1;
  Test t3 = t1;
  getchar();
  return 0;
}
Output:
Assignment operator called
Copy constructor called

Copy constructor is called when a new object is created from an existing object, as a copy of
the existing object (see this G-Fact). And assignment operator is called when an already initialized
object is assigned a new value from another existing object.

t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);"
 *
 */


