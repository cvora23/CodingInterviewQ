/*
 * FunctionOverloadingReturnType.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Function overloading and return type
In C++ and Java, functions can not be overloaded if they differ only in the return type.

For example, the following program C++ and Java programs fail in compilation.

C++ Program

#include<iostream>
int foo() {
    return 10;
}

char foo() {  // compiler error; new declaration of foo()
    return 'a';
}

int main()
{
    char x = foo();
    getchar();
    return 0;
}
Java Program

// filename Main.java
public class Main {
    public int foo() {
        return 10;
    }
    public char foo() { // compiler error: foo() is already defined
        return 'a';
    }
    public static void main(String args[])
    {
    }
}
 */


