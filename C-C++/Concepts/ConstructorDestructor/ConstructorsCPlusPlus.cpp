/*
 * ConstructorsCPlusPlus.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: cvora
 */

/*
 *What is constructor?
A constructor is a member function of a class which initializes objects of a class.
Following is a simple example to demonstrate constructors in C++.

#include<iostream>
using namespace std;

class Point
{
private:
    int x, y;
public:
    //Constructor
    Point(int x1, int y1) { x = x1; y = y1; }

    int getX()            {  return x; }
    int getY()            {  return y; }
};

int main()
{
    Point p1(10, 15); // constructor is called here

    // Let us access values assigned by constructor
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();

    return 0;
}
Output:

p1.x = 10, p1.y = 15

How constructors are different from a normal member function?
A constructor is different from normal functions in following ways:
(i) Constructor has same name as the class itself
(ii) Constructors don’t have return type
(iii) A constructor is automatically called when an object is created.
(iv) If we do not specify a constructor, C++ compiler generates a default constructor for us
(expects no parameters and has an empty body).


Can we have more than one constructors in a class?
We can have more than one constructor in a class, as long as each has a different list of arguments.


#include<iostream>
using namespace std;

class Point
{
private:
    int x, y;
public:
    // Two constructors
    Point(int x1, int y1) { x = x1; y = y1; }
    Point()               {x = 0; y = 0; }

    int getX()            {  return x; }
    int getY()            {  return y; }
};

int main()
{
    Point p1(10, 15); // first constructor is called here
    Point p2; // Second constructor is called here

    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

    return 0;
}
Output:

p1.x = 10, p1.y = 15
p2.x = 0, p2.y = 0
 */


