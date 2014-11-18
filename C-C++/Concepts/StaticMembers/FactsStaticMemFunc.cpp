/*
 * FactsStaticMemFunc.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: cvora
 */

//Some interesting facts about static member functions in C++
//1) static member functions do not have this pointer.
//For example following program fails in compilation with error “`this’ is unavailable for static member functions “

#include<iostream>
class Test {
   static Test * fun() {
     return this; // compiler error
   }
};

int main()
{
   getchar();
   return 0;
}
//2) A static member function cannot be virtual (See this G-Fact)
//
//3) Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration.
//For example, following program fails in compilation with error “‘void Test::fun()’ and `static void Test::fun()’ cannot be overloaded ”

#include<iostream>
class Test {
   static void fun() {}
   void fun() {} // compiler error
};

int main()
{
   getchar();
   return 0;
}
//4) A static member function can not be declared const, volatile, or const volatile.
//For example, following program fails in compilation with error “static member function `static void Test::fun()’ cannot have `const’ method qualifier ”

#include<iostream>
class Test {
   static void fun() const { // compiler error
     return;
   }
};

int main()
{
   getchar();
   return 0;
}


