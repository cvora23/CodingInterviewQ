/*
 * SmartPointer.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: cvora
 */

/*
 * Consider the following simple C++ code with normal pointers.

MyClass *ptr = new MyClass();
ptr->doSomething();
//  We must do delete(ptr) to avoid memory leak
Using smart pointers, we can make pointers to work in way that we don’t need to explicitly call delete.
Smart pointer is a wrapper class over a pointer with operator like * and -> overloaded.
The objects of smart pointer class look like pointer, but can do many things that a normal
pointer can’t like automatic destruction (yes, we don’t have to explicitly use delete),
reference counting and more.
The idea is to make a class with a pointer, destructor and overloaded operators like * and ->.
Since destructor is automatically called when an object goes out of scope, the dynamically
allocated memory would automatically deleted (or reference count can be decremented).
Consider the following simple smartPtr class.

#include<iostream>
using namespace std;

class SmartPtr
{
   int *ptr;  // Actual pointer
public:
   // Constructor: Refer http://www.geeksforgeeks.org/g-fact-93/
   // for use of explicit keyword
   explicit SmartPtr(int *p = NULL) { ptr = p; }

   // Destructor
   ~SmartPtr() { delete(ptr); }

   // Overloading dereferencing operator
   int &operator *() {  return *ptr; }
};

int main()
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;

    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, destructor for it is automatically
    // called and destructor does delete ptr.

    return 0;
}
Output:

20


Can we write one smart pointer class that works for all types?
Yes, we can use templates to write a generic smart pointer class. Following C++ code demonstrates the same.

#include<iostream>
using namespace std;

// A generic smart pointer class
template <class T>
class SmartPtr
{
   T *ptr;  // Actual pointer
public:
   // Constructor
   explicit SmartPtr(T *p = NULL) { ptr = p; }

   // Destructor
   ~SmartPtr() { delete(ptr); }

   // Overloading dereferncing operator
   T & operator * () {  return *ptr; }

   // Overloding arrow operator so that members of T can be accessed
   // like a pointer (useful if T represents a class or struct or
   // union type)
   T * operator -> () { return ptr; }
};

int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}
Output:

20
Smart pointers are also useful in management of resources, such as file handles or network sockets.

C++ libraries provide implementations of smart pointers in the form of auto_ptr, unique_ptr, shared_ptr and weak_ptr

 */


