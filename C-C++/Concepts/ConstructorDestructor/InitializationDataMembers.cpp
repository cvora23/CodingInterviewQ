/*
 * InitializationDataMembers.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: cvora
 */

/*
 * Initialization of data members
In C++, class variables are initialized in the same order as they appear in the class declaration.

Consider the below code.

#include<iostream>

using namespace std;

class Test {
  private:
    int y;
    int x;
  public:
    Test() : x(10), y(x + 10) {}
    void print();
};

void Test::print()
{
   cout<<"x = "<<x<<" y = "<<y;
}

int main()
{
    Test t;
    t.print();
    getchar();
    return 0;
}
The program prints correct value of x, but some garbage value for y, because y is initialized before x as it appears before in the class declaration.

So one of the following two versions can be used to avoid the problem in above code.

// First: Change the order of declaration.
class Test {
  private:
    int x;
    int y;
  public:
    Test() : x(10), y(x + 10) {}
    void print();
};
// Second: Change the order of initialization.
class Test {
  private:
    int y;
    int x;
  public:
    Test() : x(y-10), y(20) {}
    void print();
};
 */


