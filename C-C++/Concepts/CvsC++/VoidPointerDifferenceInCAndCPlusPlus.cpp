/*
 * VoidPointerDifferenceInCAndCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * How does “void *” differ in C and C++?
C allows a void* pointer to be assigned to any pointer type without a cast,
whereas C++ does not; this idiom appears often in C code using malloc memory allocation.
For example, the following is valid in C but not C++:

void* ptr;
int *i = ptr; // Implicit conversion from void* to int*
or similarly:

int *j = malloc(sizeof(int) * 5); // Implicit conversion from void* to int*
In order to make the code compile in both C and C++, one must use an explicit cast:

void* ptr;
int *i = (int *) ptr;
int *j = (int *) malloc(sizeof(int) * 5);
 */


