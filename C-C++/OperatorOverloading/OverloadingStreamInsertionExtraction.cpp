/*
 * OverloadingStreamInsertionExtraction.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: cvora
 */

/*
 * Overloading stream insertion (<<) and extraction (>>) operators in C++
July 16, 2014
In C++, stream insertion operator “<<” is used for output and extraction operator “>>” is used for input.

We must know following things before we start overloading these operators.
1) cout is an object of ostream class and cin is an object istream class
2) These operators must be overloaded as a global function. And if we want to allow them to access private data members of
class, we must make them friend.


Why these operators must be overloaded as global?
In operator overloading, if an operator is overloaded as member, then it must be a member of
the object on left side of the operator. For example, consider the statement “ob1 + ob2″
(let ob1 and ob2 be objects of two different classes). To make this statement compile, we
must overload ‘+’ in class of ‘ob1′ or make ‘+’ a global function.
The operators ‘<<' and '<<' are called like 'cout << ob1' and 'cin >> ob1'.
So if we want to make them a member method, then they must be made members of
ostream and istream classes, which is not a good option most of the time.
Therefore, these operators are overloaded as global functions with two parameters,
cout and object of user defined class.

Following is complete C++ program to demonstrate overloading of << and >> operators.

#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)
    {  real = r;   imag = i; }
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in,  Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag << endl;
    return out;
}

istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imagenory Part ";
    in >> c.imag;
    return in;
}

int main()
{
   Complex c1;
   cin >> c1;
   cout << "The complex object is ";
   cout << c1;
   return 0;
}
Output:

Enter Real Part 10
Enter Imagenory Part 20
The complex object is 10+i20

 */


