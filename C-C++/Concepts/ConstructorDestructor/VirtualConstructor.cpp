/*
 * VirtualConstructor.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */
/*
 * Can we make a class constructor virtual in C++ to create polymorphic objects? No. C++ being static typed
 * (the purpose of RTTI is different) language, it is meaningless to the C++ compiler to create an object
 * polymorphically. The compiler must be aware of the class type to create the object. In other words,
 * what type of object to be created is a compile time decision from C++ compiler perspective. If we make
 * constructor virtual, compiler flags an error. In fact except inline, no other keyword is allowed in the
 * declaration of constructor.

In practical scenarios we would need to create a derived class object in a class hierarchy based on some input.
Putting in other words, object creation and object type are tightly coupled which forces modifications to extended.
The objective of virtual constructor is to decouple object creation from it’s type.

How can we create required type of object at runtime? For example, see the following sample program.

#include <iostream>
using namespace std;

//// LIBRARY START
class Base
{
public:

    Base() { }

    virtual // Ensures to invoke actual object destructor
    ~Base() { }

    // An interface
    virtual void DisplayAction() = 0;
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }

    ~Derived1()
    {
        cout << "Derived1 destroyed" << endl;
    }

    void DisplayAction()
    {
        cout << "Action from Derived1" << endl;
    }
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }

    ~Derived2()
    {
        cout << "Derived2 destroyed" << endl;
    }

    void DisplayAction()
    {
        cout << "Action from Derived2" << endl;
    }
};

//// LIBRARY END

class User
{
public:

    // Creates Drived1
    User() : pBase(0)
    {
        // What if Derived2 is required? - Add an if-else ladder (see next sample)
        pBase = new Derived1();
    }

    ~User()
    {
        if( pBase )
        {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }

private:
    Base *pBase;
};

int main()
{
    User *user = new User();

    // Need Derived1 functionality only
    user->Action();

    delete user;
}
In the above sample, assume that the hierarchy Base, Derived1 and Derived2 are part of library code.
The class User is utility class trying to make use of the hierarchy. The main function is consuming Base
hierarchy functionality via User class.

The User class constructor is creating Derived1 object, always. If the User‘s consumer (the main in our case)
needs Derived2 functionality, User needs to create “new Derived2()” and it forces recompilation. Recompiling
is bad way of design, so we can opt for the following approach.

Before going into details, let us answer, who will dictate to create either of Derived1 or Derived2 object?
Clearly, it is the consumer of User class. The User class can make use of if-else ladder to create either
Derived1 or Derived2, as shown in the following sample,

#include <iostream>
using namespace std;

//// LIBRARY START
class Base
{
public:
    Base() { }

    virtual // Ensures to invoke actual object destructor
    ~Base() { }

    // An interface
    virtual void DisplayAction() = 0;
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }

    ~Derived1()
    {
        cout << "Derived1 destroyed" << endl;
    }

    void DisplayAction()
    {
        cout << "Action from Derived1" << endl;
    }
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }

    ~Derived2()
    {
        cout << "Derived2 destroyed" << endl;
    }

    void DisplayAction()
    {
        cout << "Action from Derived2" << endl;
    }
};

//// LIBRARY END

class User
{
public:

    // Creates Derived1 or Derived2 based on input
    User() : pBase(0)
    {
        int input; // ID to distinguish between
                   // Derived1 and Derived2

        cout << "Enter ID (1 or 2): ";
        cin  >> input;

        while( (input !=  1) && (input !=  2) )
        {
            cout << "Enter ID (1 or 2 only): ";
            cin  >> input;
        }

        if( input == 1 )
        {
            pBase = new Derived1;
        }
        else
        {
            pBase = new Derived2;
        }

        // What if Derived3 being added to the class hierarchy?
    }

    ~User()
    {
        if( pBase )
        {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }

private:
    Base *pBase;
};

int main()
{
    User *user = new User();

    // Need either Derived1 or Derived2 functionality
    user->Action();

    delete user;
}
The above code is *not* open for extension, an inflexible design. In simple words, if the library updates
the Base class hierarchy with new class Derived3. How can the User class creates Derived3 object? One way
is to update the if-else ladder that creates Derived3 object based on new input ID 3 as shown below,

#include <iostream>
using namespace std;

class User
{
public:
    User() : pBase(0)
    {
        // Creates Drived1 or Derived2 based on need

        int input; // ID to distinguish between
                   // Derived1 and Derived2

        cout << "Enter ID (1 or 2): ";
        cin  >> input;

        while( (input !=  1) && (input !=  2) )
        {
            cout << "Enter ID (1 or 2 only): ";
            cin  >> input;
        }

        if( input == 1 )
        {
            pBase = new Derived1;
        }
        else if( input == 2 )
        {
            pBase = new Derived2;
        }
        else
        {
            pBase = new Derived3;
        }
    }

    ~User()
    {
        if( pBase )
        {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }

private:
    Base *pBase;
};
The above modification forces the users of User class to recompile, bad (inflexible) design! And won’t close User
class from further modifications due to Base extension.

The problem is with the creation of objects. Addition of new class to the hierarchy forcing dependents of User
class to recompile. Can’t we delegate the action of creating objects to class hierarchy itself or to a function
that behaves virtually? By delegating the object creation to class hierarchy (or to a static function) we can
avoid the tight coupling between User and Base hierarchy. Enough theory, see the following code,

#include <iostream>
using namespace std;

//// LIBRARY START
class Base
{
public:

    // The "Virtual Constructor"
    static Base *Create(int id);

    Base() { }

    virtual // Ensures to invoke actual object destructor
    ~Base() { }

    // An interface
    virtual void DisplayAction() = 0;
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }

    ~Derived1()
    {
        cout << "Derived1 destroyed" << endl;
    }

    void DisplayAction()
    {
        cout << "Action from Derived1" << endl;
    }
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }

    ~Derived2()
    {
        cout << "Derived2 destroyed" << endl;
    }

    void DisplayAction()
    {
        cout << "Action from Derived2" << endl;
    }
};

class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << endl;
    }

    ~Derived3()
    {
        cout << "Derived3 destroyed" << endl;
    }

    void DisplayAction()
    {
        cout << "Action from Derived3" << endl;
    }
};

// We can also declare "Create" outside Base
// But it is more relevant to limit it's scope to Base
Base *Base::Create(int id)
{
    // Just expand the if-else ladder, if new Derived class is created
    // User code need not be recompiled to create newly added class objects

    if( id == 1 )
    {
        return new Derived1;
    }
    else if( id == 2 )
    {
        return new Derived2;
    }
    else
    {
        return new Derived3;
    }
}
//// LIBRARY END

//// UTILITY START
class User
{
public:
    User() : pBase(0)
    {
        // Receives an object of Base heirarchy at runtime

        int input;

        cout << "Enter ID (1, 2 or 3): ";
        cin >> input;

        while( (input !=  1) && (input !=  2) && (input !=  3) )
        {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }

        // Get object from the "Virtual Constructor"
        pBase = Base::Create(input);
    }

    ~User()
    {
        if( pBase )
        {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }

private:
    Base *pBase;
};

//// UTILITY END

//// Consumer of User (UTILITY) class
int main()
{
    User *user = new User();

    // Action required on any of Derived objects
    user->Action();

    delete user;
}
The User class is independent of object creation. It delegates that responsibility to Base, and provides an input
in the form of ID. If the library adds new class Derived4, the library modifier will extend the if-else ladder
inside Create to return proper object. Consumers of User need not recompile their code due to extension of Base.

Note that the function Create used to return different types of Base class objects at runtime. It acts like
virtual constructor, also referred as Factory Method in pattern terminology.

 *
 */



