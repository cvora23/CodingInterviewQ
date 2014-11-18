/*
 * OverloadingInheritance.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Does overloading work with Inheritance?
If we have a function in base class and a function with same name in derived class,
can the base class function be called from derived class object? This is an interesting
question and as an experiment predict the output of the following C++ program.
#include <iostream>
using namespace std;
class Base
{
public:
    int f(int i)
    {
        cout << "f(int): ";
        return i+3;
    }
};
class Derived : public Base
{
public:
    double f(double d)
    {
        cout << "f(double): ";
        return d+3.3;
    }
};
int main()
{
    Derived* dp = new Derived;
    cout << dp->f(3) << '\n';
    cout << dp->f(3.3) << '\n';
    delete dp;
    return 0;
}
The output of this program is:

f(double): 6.3
f(double): 6.6
Instead of the supposed output:

f(int): 6
f(double): 6.6
Overloading doesn’t work for derived class in C++ programming language.
There is no overload resolution between Base and Derived. The compiler looks into the scope of Derived,
finds the single function “double f(double)” and calls it. It never disturbs with the (enclosing)
scope of Base. In C++, there is no overloading across scopes – derived class scopes are not an
exception to this general rule. (See this for more examples)

Reference: technical FAQs on www.stroustrup.com

Now consider Java version of this program:

class Base
{
    public int f(int i)
    {
        System.out.print("f (int): ");
        return i+3;
    }
}
class Derived extends Base
{
    public double f(double i)
    {
        System.out.print("f (double) : ");
        return i + 3.3;
    }
}
class myprogram3
{
    public static void main(String args[])
    {
        Derived obj = new Derived();
        System.out.println(obj.f(3));
        System.out.println(obj.f(3.3));
    }
}
The output of the above program is:

f (int): 6
f (double): 6.6
So in Java overloading works across scopes contrary to C++. Java compiler determines correct
version of the overloaded method to be executed at compile time based upon the type of argument
used to call the method and parameters of the overloaded methods of both these classes receive
the values of arguments used in call and executes the overloaded method.

Finally, let us try the output of following C# program:

using System;
class Base
{
    public int f(int i)
    {
        Console.Write("f (int): ");
        return i + 3;
    }
}
class Derived : Base
{
    public double f(double i)
    {
        Console.Write("f (double) : ");
        return i+3.3;
    }
}
class MyProgram
{
    static void Main(string[] args)
    {
        Derived obj = new Derived();
        Console.WriteLine(obj.f(3));
        Console.WriteLine(obj.f(3.3));
        Console.ReadKey(); // write this line if you use visual studio
    }
}
Note: Console.ReadKey() is used to halt the console. It is similar to getch as in C/C++.
The output of the above program is:

f(double) : 6.3
f(double):  6.6
instead of the assumed output

f(int) : 6
f(double) : 6.6
The reason is same as explained in C++ program. Like C++, there is no overload resolution between
class Base and class Derived. In C#, there is no overloading across scopes derived class scopes are
not an exception to this general rule. This is same as C++ because C# is designed to be much closer
to C++, according to the Anders hejlsberg the creator of C# language.
 */


