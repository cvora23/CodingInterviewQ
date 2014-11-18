/*
 * TypeOfThisPointer.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: cvora
 */

/*
 * Type of ‘this’ pointer in C++
 *
In C++, this pointer is passed as a hidden argument to all non-static member function calls.
The type of this depends upon function declaration. If the member function of a class X is declared const,
the type of this is const X* (see code 1 below), if the member function is declared volatile, the type of
this is volatile X* (see code 2 below), and if the member function is declared const volatile,
the type of this is const volatile X* (see code 3 below).

Code 1

#include<iostream>
class X {
   void fun() const {
    // this is passed as hidden argument to fun().
    // Type of this is const X*
    }
};
Code 2

#include<iostream>
class X {
   void fun() volatile {
     // this is passed as hidden argument to fun().
     // Type of this is volatile X*
    }
};
Code 3

#include<iostream>
class X {
   void fun() const volatile {
     // this is passed as hidden argument to fun().
     // Type of this is const volatile X*
    }
};
 */


