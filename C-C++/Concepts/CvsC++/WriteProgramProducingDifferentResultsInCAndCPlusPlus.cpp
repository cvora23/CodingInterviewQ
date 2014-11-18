/*
 * WriteProgramProducingDifferentResultsInCAndCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Write a program that produces different results in C and C++
Write a program that compiles and runs both in C and C++, but produces different results when compiled by C and C++ compilers.

There can be many such programs, following are some of them.

1) Character literals are treated differently in C and C++. In C character literals like ‘a’, ‘b’, ..etc are treated as integers,
while as characters in C++. (See this for details)

For example, the following program produces sizeof(int) as output in C, but sizeof(char) in C++.

#include<stdio.h>
int main()
{
  printf("%d", sizeof('a'));
  return 0;
}
2) In C, we need to use struct tag whenever we declare a struct variable. In C++, the struct tag is not necessary.
For example, let there be a structure for Student. In C, we must use ‘struct Student‘ for Student variables.
In C++, we can omit struct and use ‘Student‘ only.
Following is a program that is based on the fact and produces different outputs in C and C++.
It prints sizeof(int) in C and sizeof(struct T) in C++.

#include <stdio.h>
int T;

int main()
{
    struct T { double x; };  // In C++, this T hides the global variable T,
                            // but not in C
    printf("%d", sizeof(T));
    return 0;
}

3) Types of boolean results are different in C and C++. Thanks to Gaurav Jain for suggesting this point.

// output = 4 in C (which is size of int)
printf("%d", sizeof(1==1));

// output = 1 in c++ (which is the size of boolean datatype)
cout << sizeof(1==1);
 */


