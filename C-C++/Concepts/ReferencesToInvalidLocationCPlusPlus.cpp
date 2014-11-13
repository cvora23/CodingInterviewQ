/*
 * ReferencesToInvalidLocationCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Can references refer to invalid location in C++?
In C++, Reference variables are safer than pointers because reference variables must
be initialized and they cannot be changed to refer to something else once they are initialized.
But there are exceptions where we can have invalid references.

1) Reference to value at uninitialized pointer.

int *ptr;
int &ref = *ptr;  // Reference to value at some random memory location
2) Reference to a local variable is returned.



// This could even return value 10.
 * Reason:
 * Yes, compiler will issue a warning stating that reference to local variable is returned.
 * But, it will execute the code. Here, the stack frame allocated to the function is not
 * cleared until control reaches the end of the program. Each and every time the function is called,
 * a different stack frame is allocated. A different x will be created and thus a different reference
 * (but, to the same integer value) is returned.
 *
int& fun()
{
   int a = 10;
   return a;
}
Once fun() returns, the space allocated to it on stack frame will be taken back.
So the reference to a local variable will not be valid.
 */


