/*
 * MallocVsNew.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * malloc() vs new
Following are the differences between malloc() and operator new.

1) new calls constructors, while malloc() does not.
In fact primitive data types (char, int, float.. etc) can
also be initialized with new. For example, below program prints 10.

#include<iostream>

using namespace std;

int main()
{
   int *n = new int(10); // initialization with new()
   cout<<*n;
   getchar();
   return 0;
}
2) new is an operator, while malloc() is a fucntion.

3) new returns exact data type, while malloc() returns void *.
 */


