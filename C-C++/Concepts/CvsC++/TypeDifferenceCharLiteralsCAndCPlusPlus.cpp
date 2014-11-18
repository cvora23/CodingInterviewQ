/*
 * TypeDifferenceCharLiteralsCAndCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Type difference of character literals in C and C++
Every literal (constant) in C/C++ will have a type information associated with it.

In both C and C++, numeric literals (e.g. 10) will have int as their type. It means sizeof(10) and sizeof(int) will return same value.

However, character literals (e.g. ‘V’) will have different types, sizeof(‘V’) returns different values in C and C++.
In C, a character literal is treated as int type where as in C++, a character literal is treated as char type
(sizeof(‘V’) and sizeof(char) are same in C++ but not in C).

int main()
{
   printf("sizeof('V') = %d sizeof(char) = %d", sizeof('V'), sizeof(char));
   return 0;
}
Result of above program:

C result – sizeof(‘V’) = 4 sizeof(char) = 1

C++ result – sizeof(‘V’) = 1 sizeof(char) = 1

Such behaviour is required in C++ to support function overloading. An example will make it more clear.
Predict the output of the following C++ program.

void foo(char c)
{
   printf("From foo: char");
}
void foo(int i)
{
   printf("From foo: int");
}

int main()
{
   foo('V');
   return 0;
}
The compiler must call

void foo(char);
since ‘V’ type is char.
 */


