/*
 * IsItPossibleToCallConstructorAndDestructorExplicitly.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Is it possible to call constructor and destructor explicitly?

Constructor is a special member function that is automatically called by compiler when object is created
and destructor is also special member function that is also implicitly called by compiler when object goes
out of scope. They are also called when dynamically allocated object is allocated and destroyed, new operator
allocates storage and calls constructor, delete operator calls destructor and free the memory allocated by new.

Is it possible to call constructor and destructor explicitly?
Yes, it is possible to call special member functions explicitly by programmer. Following program calls constructor
and destructor explicitly.

#include <iostream>
using namespace std;

class Test
{
public:
    Test()  { cout << "Constructor is executed\n"; }
    ~Test() { cout << "Destructor is executed\n";  }
};

int main()
{
    Test();  // Explicit call to constructor
    Test t; // local object
    t.~Test(); // Explicit call to destructor
    return 0;
}
Output:

Constructor is executed
Destructor is executed
Constructor is executed
Destructor is executed
Destructor is executed
When the constructor is called explicitly the compiler creates a nameless temporary object and it is immediately
destroyed. That’s why 2nd line in the output is call to destructor.
Here is a conversation between me and Dr. Bjarne Stroustrup via mail about this topic:

Me: Why C++ allows to call constructor explicitly? Don’t you think that this shouldn’t be?
Dr. Bjarne: No. temporary objects of the class types are useful.

If the destructor is called explicitly on local object it doesn’t mean that the object is destroyed. Local objects
are automatically destroyed by compiler when they go out of scope and this is the guarantee of C++ language.
In general, special member functions shouldn’t be called explicitly.
Constructor and destructor can also be called from the member function of class. See following program:

#include <iostream>
using namespace std;

class Test
{
public:
    Test()  { cout << "Constructor is executed\n"; }
    ~Test() { cout << "Destructor is executed\n";  }
    void show()  {  Test();  this->Test::~Test();  }
};

int main()
{
    Test t;
    t.show();
    return 0;
}
Output:

Constructor is executed
Constructor is executed
Destructor is executed
Destructor is executed
Destructor is executed
Explicit call to destructor is only necessary when object is placed at particular location in memory by using
placement new. Destructor should not be called explicitly when the object is dynamically allocated because
delete operator automatically calls destructor.

As an exercise predict the output of following program:

#include <iostream>
using namespace std;

class Test
{
public:
    Test()  { cout << "Constructor is executed\n"; }
    ~Test() { cout << "Destructor is executed\n";  }
    friend void fun(Test t);
};
void fun(Test t)
{
    Test();
    t.~Test();
}
int main()
{
    Test();
    Test t;
    fun(t);
    return 0;
}
 */


