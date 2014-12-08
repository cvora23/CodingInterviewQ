/*
 * CatchBlockAndTypeConversion.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Catch block and type conversion in C++
Predict the output of following C++ program.

#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 'x';
    }
    catch(int x)
    {
        cout << " Caught int " << x;
    }
    catch(...)
    {
        cout << "Defaule catch block";
    }
}
 Defaule catch block
In the above program, a character ‘x’ is thrown and there is a catch block to catch an int.
One might think that the int catch block could be matched by considering ASCII value of ‘x’.
But such conversions are not performed for catch blocks. Consider the following program as
another example where conversion constructor is not called for thrown object.

#include <iostream>
using namespace std;

class MyExcept1 {};

class MyExcept2
{
public:

    // Conversion constructor
    MyExcept2 (const MyExcept1 &e )
    {
        cout << "Conversion constructor called";
    }
};

int main()
{
    try
    {
        MyExcept1 myexp1;
        throw myexp1;
    }
    catch(MyExcept2 e2)
    {
        cout << "Caught MyExcept2 " << endl;
    }
    catch(...)
    {
        cout << " Defaule catch block " << endl;
    }
    return 0;
}
Defaule catch block
As a side note, the derived type objects are converted to base typr when a derived object is thrown and
there is a catch block to catch base type.
 */


