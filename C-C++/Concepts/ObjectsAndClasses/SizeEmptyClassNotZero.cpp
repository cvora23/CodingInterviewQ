/*
 * SizeEmptyClassNotZero.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */


/*
 * Why is the size of an empty class not zero in C++?
Predict the output of following program?

#include<iostream>
using namespace std;

class Empty {};

int main()
{
  cout << sizeof(Empty);
  return 0;
}
Output:

1
Size of an empty class is not zero. It is 1 byte generally.
It is nonzero to ensure that the two different objects will have different addresses.
See the following example.

#include<iostream>
using namespace std;

class Empty { };

int main()
{
    Empty a, b;

    if (&a == &b)
      cout << "impossible " << endl;
    else
      cout << "Fine " << endl;

   return 0;
}
Output:

Fine
For the same reason (different objects should have different addresses),
“new” always returns pointers to distinct objects. See the following example.

#include<iostream>
using namespace std;

class Empty { };

int main()
{
    Empty* p1 = new Empty;
    Empty* p2 = new Empty;

    if (p1 == p2)
        cout << "impossible " << endl;
    else
        cout << "Fine " << endl;

    return 0;
}
Output:

Fine
Now guess the output of following program (This is tricky)

#include<iostream>
using namespace std;

class Empty { };

class Derived: Empty { int a; };

int main()
{
    cout << sizeof(Derived);
    return 0;
}
Output (with GCC compiler. See this):

4
Note that the output is not greater than 4. There is an interesting rule that says
that an empty base class need not be represented by a separate byte.
So compilers are free to make optimization in case of empty base classes.
As an excercise, try the following program on your compiler.

// Thanks to Venki for suggesting this code.
#include <iostream>
using namespace std;

class Empty
{};

class Derived1 : public Empty
{};

class Derived2 : virtual public Empty
{};

class Derived3 : public Empty
{
    char c;
};

class Derived4 : virtual public Empty
{
    char c;
};

class Dummy
{
    char c;
};

int main()
{
    cout << "sizeof(Empty) " << sizeof(Empty) << endl;
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
    cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;

    return 0;
}
 */

