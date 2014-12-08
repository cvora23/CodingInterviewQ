/*
 * VirtualCopyContructor.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * In the virtual constructor idiom we have seen the way to construct an object whose type is not determined until runtime.
 * Is it possible to create an object without knowing it’s exact class type? The virtual copy constructor address this question.

Sometimes we may need to construct an object from another existing object. Precisely the copy constructor does the same.
The initial state of new object will be based on another existing object state. The compiler places call to copy constructor
when an object being instantiated from another object. However, the compiler needs concrete type information to invoke
appropriate copy constructor.

#include <iostream>
using namespace std;

class Base
{
public:
    //
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived created" << endl;
    }

    Derived(const Derived &rhs)
    {
        cout << "Derived created by deep copy" << endl;
    }

    ~Derived()
    {
        cout << "Derived destroyed" << endl;
    }
};

int main()
{
    Derived s1;

    Derived s2 = s1;  // Compiler invokes "copy constructor"
                      // Type of s1 and s2 are concrete to compiler

    // How can we create Derived1 or Derived2 object
    // from pointer (reference) to Base class pointing Derived object?

    return 0;
}
What if we can’t decide from which type of object, the copy construction to be made? For example, virtual constructor
creates an object of class hierarchy at runtime based on some input. When we want to copy construct an object from
another object created by virtual constructor, we can’t use usual copy constructor. We need a special cloning function
that can duplicate the object at runtime.

As an example, consider a drawing application. You can select an object already drawn on the canvas and paste one more
instance of the same object. From the programmer perspective, we can’t decide which object will be copy-pasted as it is
runtime decision. We need virtual copy constructor to help.

Similarly, consider clip board application. A clip board can hold different type of objects, and copy objects from
existing objects, pastes them on application canvas. Again, what type of object to be copied is a runtime decision.
Virtual copy constructor fills the gap here. See the example below,

#include <iostream>
using namespace std;

//// LIBRARY SRART
class Base
{
public:
    Base() { }

    virtual // Ensures to invoke actual object destructor
        ~Base() { }

    virtual void ChangeAttributes() = 0;

    // The "Virtual Constructor"
    static Base *Create(int id);

    // The "Virtual Copy Constructor"
    virtual Base *Clone() = 0;
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }

    Derived1(const Derived1& rhs)
    {
        cout << "Derived1 created by deep copy" << endl;
    }

    ~Derived1()
    {
        cout << "~Derived1 destroyed" << endl;
    }

    void ChangeAttributes()
    {
        cout << "Derived1 Attributes Changed" << endl;
    }

    Base *Clone()
    {
        return new Derived1(*this);
    }
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }

    Derived2(const Derived2& rhs)
    {
        cout << "Derived2 created by deep copy" << endl;
    }

    ~Derived2()
    {
        cout << "~Derived2 destroyed" << endl;
    }

    void ChangeAttributes()
    {
        cout << "Derived2 Attributes Changed" << endl;
    }

    Base *Clone()
    {
        return new Derived2(*this);
    }
};

class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << endl;
    }

    Derived3(const Derived3& rhs)
    {
        cout << "Derived3 created by deep copy" << endl;
    }

    ~Derived3()
    {
        cout << "~Derived3 destroyed" << endl;
    }

    void ChangeAttributes()
    {
        cout << "Derived3 Attributes Changed" << endl;
    }

    Base *Clone()
    {
        return new Derived3(*this);
    }
};

// We can also declare "Create" outside Base.
// But is more relevant to limit it's scope to Base
Base *Base::Create(int id)
{
    // Just expand the if-else ladder, if new Derived class is created
    // User need not be recompiled to create newly added class objects

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

//// UTILITY SRART
class User
{
public:
    User() : pBase(0)
    {
        // Creates any object of Base heirarchey at runtime

        int input;

        cout << "Enter ID (1, 2 or 3): ";
        cin >> input;

        while( (input !=  1) && (input !=  2) && (input !=  3) )
        {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }

        // Create objects via the "Virtual Constructor"
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

    void Action()
    {
        // Duplicate current object
        Base *pNewBase = pBase->Clone();

        // Change its attributes
        pNewBase->ChangeAttributes();

        // Dispose the created object
        delete pNewBase;
    }

private:
    Base *pBase;
};

//// UTILITY END

//// Consumer of User (UTILITY) class
int main()
{
    User *user = new User();

    user->Action();

    delete user;
}
User class creating an object with the help of virtual constructor. The object to be created is based on user input.
Action() is making duplicate of object being created and modifying it’s attributes. The duplicate object being created
with the help of Clone() virtual function which is also considered as virtual copy constructor.
The concept behind Clone() method is building block of prototype pattern.
 */


