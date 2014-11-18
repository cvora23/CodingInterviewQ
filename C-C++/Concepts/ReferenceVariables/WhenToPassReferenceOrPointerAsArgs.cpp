/*
 * WhenToPassReferenceOrPointer.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * When do we pass arguments by reference or pointer?
In C++, variables are passed by reference due to following reasons:

1) To modify local variables of the caller function: A reference (or pointer) allows called function to modify a local variable of the caller function. For example, consider the following example program where fun() is able to modify local variable x of main().

void fun(int &x) {
    x = 20;
}

int main() {
    int x = 10;
    fun(x);
    cout<<"New value of x is "<<x;
    return 0;
}
Output:
New value of x is 20


2) For passing large sized arguments: If an argument is large, passing by reference (or pointer) is more efficient because only an address is really passed, not the entire object. For example, let us consider the following Employee class and a function printEmpDetails() that prints Employee details.

class Employee {
private:
    string name;
    string desig;

    // More attributes and operations
};

void printEmpDetails(Employee emp) {
     cout<<emp.getName();
     cout<<emp.getDesig();

    // Print more attributes
}
The problem with above code is: every time printEmpDetails() is called, a new Employee abject is constructed that involves creating a copy of all data members. So a better implementation would be to pass Employee as a reference.

void printEmpDetails(const Employee &emp) {
     cout<<emp.getName();
     cout<<emp.getDesig();

    // Print more attributes
}
This point is valid only for struct and class variables as we don’t get any efficiency advantage for basic types like int, char.. etc.


3) To avoid Object Slicing: If we pass an object of subclass to a function that expects an object of superclass then the passed object is sliced if it is pass by value. For example, consider the following program, it prints “This is Pet Class”.

#include <iostream>
#include<string>

using namespace std;

class Pet {
public:
    virtual string getDescription() const {
        return "This is Pet class";
    }
};

class Dog : public Pet {
public:
    virtual string getDescription() const {
        return "This is Dog class";
    }
};

void describe(Pet p) { // Slices the derived class object
    cout<<p.getDescription()<<endl;
}

int main() {
    Dog d;
    describe(d);
    return 0;
}
Output:
This is Pet Class

If we use pass by reference in the above program then it correctly prints “This is Dog Class”. See the following modified program.

#include <iostream>
#include<string>

using namespace std;

class Pet {
public:
    virtual string getDescription() const {
        return "This is Pet class";
    }
};

class Dog : public Pet {
public:
    virtual string getDescription() const {
        return "This is Dog class";
    }
};

void describe(const Pet &p) { // Doesn't slice the derived class object.
    cout<<p.getDescription()<<endl;
}

int main() {
    Dog d;
    describe(d);
    return 0;
}
Output:
This is Dog Class

This point is also not valid for basic data types like int, char, .. etc.


4) To achieve Run Time Polymorphism in a function
We can make a function polymorphic by passing objects as reference (or pointer) to it. For example, in the following program, print() receives a reference to the base class object. print() calls the base class function show() if base class object is passed, and derived class function show() if derived class object is passed.

#include<iostream>
using namespace std;

class base {
public:
    virtual void show() {  // Note the virtual keyword here
        cout<<"In base \n";
    }
};


class derived: public base {
public:
    void show() {
        cout<<"In derived \n";
    }
};

// Since we pass b as reference, we achieve run time polymorphism here.
void print(base &b) {
    b.show();
}

int main(void) {
    base b;
    derived d;
    print(b);
    print(d);
    return 0;
}
Output:
In base
In derived
 */


