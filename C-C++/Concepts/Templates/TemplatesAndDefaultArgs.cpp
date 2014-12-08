/*
 * TemplatesAndDefaultArgs.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Default parameters for templates in C++:
Like function default arguments, templates can also have default arguments.
For example, in the following program, the second parameter U has the default value as char.

#include<iostream>
using namespace std;

template<class T, class U = char> class A
{
public:
    T x;
    U y;
};

int main()
{
    A<char> a;
    A<int, int> b;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
    return 0;
}
Output: (char takes 1 byte and int takes 4 bytes)
2
8

Also, similar to default function arguments, if one template parameter has a default argument,
then all template parameters following it must also have default arguments. For example,
the compiler will not allow the following program:

#include<iostream>
using namespace std;

template<class T = char, class U, class V = int> class A  // Error
{
   // members of A
};

int main()
{

}
 */



