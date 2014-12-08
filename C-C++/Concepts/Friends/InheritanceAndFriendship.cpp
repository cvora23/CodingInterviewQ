/*
 * InheritanceAndFriendship.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Inheritance and friendship
In C++, friendship is not inherited. If a base class has a friend function, then the function doesn’t become a
friend of the derived class(es).

For example, following program prints error because show() which is a friend of base class A tries to access
private data of derived class B.

#include <iostream>
using namespace std;

class A
{
  protected:
    int x;
  public:
    A() { x = 0;}
  friend void show();
};

class B: public A
{
  public:
    B() : y (0) {}
  private:
    int y;
};

void show()
{
  B b;
  cout << "The default value of A::x = " << b.x;

  // Can't access private member declared in class 'B'
  cout << "The default value of B::y = " << b.y;
}

int main()
{
  show();
  getchar();
  return 0;
}
 */


