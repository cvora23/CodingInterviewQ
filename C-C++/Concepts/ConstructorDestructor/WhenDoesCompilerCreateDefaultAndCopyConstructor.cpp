/*
 * WhenDoesCompilerCreateDefaultAndCopyConstructor.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * When does compiler create default and copy constructors in C++?
In C++, compiler creates a default constructor if we don’t define our own constructor (See this).
Compiler created default constructor has empty body, i.e., it doesn’t assign default values to data
members (In java, default constructors assign default values).

Compiler also creates a copy constructor if we don’t write our own copy constructor. Unlike default
constructor, body of compiler created copy constructor is not empty, it copies all data members of
passed object to the object which is being created.

What happens when we write only a copy constructor – does compiler create default constructor?
Compiler doesn’t create a default constructor if we write any constructor even if it is copy constructor.
For example, the following program doesn’t compile.

#include <iostream>
using namespace std;

class Point
{
    int x, y;
public:
   Point(const Point &p) { x = p.x; y = p.y; }
};

int main()
{
    Point p1;  // COMPILER ERROR
    Point p2 = p1;
    return 0;
}
Output:

COMPILER ERROR: no matching function for call to 'Point::Point()
What about reverse – what happens when we write a normal constructor and don’t write a copy constructor?
Reverse is not true. Compiler creates a copy constructor if we don’t write our own.
Compiler creates it even if we have written other constructors in class.
For example, the below program works fine.

#include <iostream>
using namespace std;

class Point
{
    int x, y;
public:
   Point(int i, int j) { x = 10; y = 20; }
   int getX() { return x; }
   int getY() { return y; }
};

int main()
{
    Point p1(10, 20);
    Point p2 = p1; // This compiles fine
    cout << "x = " << p2.getX() << " y = " << p2.getY();
    return 0;
}
Output:

x = 10 y = 20
So we need to write copy constructor only when we have pointers or run time allocation of resource like file
handle, a network connection, etc

 *
 */


