/*
 * StaticDataMem.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: cvora
 */

/*
 * Static data members in C++
Predict the output of following C++ program:

#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A's Constructor Called " << endl;  }
};

class B
{
    static A a;
public:
    B() { cout << "B's Constructor Called " << endl; }
};

int main()
{
    B b;
    return 0;
}
Output:

B's Constructor Called
The above program calls only B’s constructor, it doesn’t call A’s constructor.
The reason for this is simple, static members are only declared in class declaration, not defined.
They must be explicitly defined outside the class using scope resolution operator.
If we try to access static member ‘a’ without explicit definition of it, we will get compilation error.
For example, following program fails in compilation.

#include <iostream>
using namespace std;

class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};

class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};

int main()
{
    B b;
    A a = b.getA();
    return 0;
}
Output:

Compiler Error: undefined reference to `B::a'
If we add definition of a, the program will works fine and will call A’s constructor. See the following program.

#include <iostream>
using namespace std;

class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};

class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};

A B::a;  // definition of a

int main()
{
    B b1, b2, b3;
    A a = b1.getA();

    return 0;
}
Output:

A's constructor called
B's constructor called
B's constructor called
B's constructor called
Note that the above program calls B’s constructor 3 times for 3 objects (b1, b2 and b3),
but calls A’s constructor only once. The reason is, static members are shared among all objects.
That is why they are also known as class members or class fields. Also, static members can be
accessed without any object, see the below program where static member ‘a’ is accessed without any object.

#include <iostream>
using namespace std;

class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};

class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};

A B::a;  // definition of a

int main()
{
    // static member 'a' is accessed without any object of B
    A a = B::getA();

    return 0;
}
Output:

A's constructor called
 */


