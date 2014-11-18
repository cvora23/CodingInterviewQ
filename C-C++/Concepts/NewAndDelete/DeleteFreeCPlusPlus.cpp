/*
 * DeleteFreeCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */


/*
 * delete and free() in C++
In C++, delete operator should only be used either for the pointers pointing to
the memory allocated using new operator or for a NULL pointer, and free() should only
be used either for the pointers pointing to the memory allocated using malloc() or for a NULL pointer.

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x;
    int *ptr1 = &x;
    int *ptr2 = (int *)malloc(sizeof(int));
    int *ptr3 = new int;
    int *ptr4 = NULL;

    // delete Should NOT be used like below because x is allocated on stack frame
    delete ptr1;

    // delete Should NOT be used like below because x is allocated using malloc()
    delete ptr2;

    // Correct uses of delete
    delete ptr3;
    delete ptr4;

    getchar();
    return 0;
}
 */

