/*
 * CanStaticFunctionsBeVirtual.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * In C++, a static member function of a class cannot be virtual. For example, below program gives compilation error.

#include<iostream>

using namespace std;

class Test
{
   public:
      // Error: Virtual member functions cannot be static
      virtual static void fun()  { }
};
Also, static member function cannot be const and volatile. Following code also fails in compilation.

#include<iostream>

using namespace std;

class Test
{
   public:
      // Error: Static member function cannot be const
      static void fun() const { }
};
 */


