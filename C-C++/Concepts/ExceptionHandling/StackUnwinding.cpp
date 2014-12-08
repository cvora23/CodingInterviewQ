/*
 * StackUnwinding.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * The process of removing function entries from function call stack at run time is called Stack Unwinding.
 * Stack Unwinding is generally related to Exception Handling. In C++, when an exception occurs, the function
 * call stack is linearly searched for the exception handler, and all the entries before the function with
 * exception handler are removed from the function call stack. So exception handling involves Stack
 * Unwinding if exception is not handled in same function (where it is thrown).

For example, output of the following program is:

 f3() Start
 f2() Start
 f1() Start
 Caught Exception: 100
 f3() End
#include <iostream>

using namespace std;

// A sample function f1() that throws an int exception
void f1() throw (int) {
  cout<<"\n f1() Start ";
  throw 100;
  cout<<"\n f1() End ";
}

// Another sample function f2() that calls f1()
void f2() throw (int) {
  cout<<"\n f2() Start ";
  f1();
  cout<<"\n f2() End ";
}

// Another sample function f3() that calls f2() and handles exception thrown by f1()
void f3() {
  cout<<"\n f3() Start ";
  try {
    f2();
  }
  catch(int i) {
   cout<<"\n Caught Exception: "<<i;
  }
  cout<<"\n f3() End";
}

// A driver function to demonstrate Stack Unwinding  process
int main() {
  f3();

  getchar();
  return 0;
}
In the above program, when f1() throws exception, its entry is removed from the function call stack (because it f1()
doesn’t contain exception handler for the thrown exception), then next entry in call stack is looked for exception
handler. The next entry is f2(). Since f2() also doesn’t have handler, its entry is also removed from function
call stack. The next entry in function call stack is f3(). Since f3() contains exception handler, the catch block
inside f3() is executed, and finally the code after catch block is executed. Note that the following lines inside
f1() and f2() are not executed at all.

//inside f1()
  cout<<"\n f1() End ";

//inside f2()
  cout<<"\n f2() End ";
On a side note, if there were some local class objects inside f1() and f2(), destructors for those local objects
would have been called in Stack Unwinding process.

Stack Unwinding also happens in Java when exception is not handled in same function.
 */


