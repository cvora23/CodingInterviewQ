/*
 * ReferencesCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * References in C++
When a variable is declared as reference, it becomes an alternative name for an existing variable.
A variable can be declared as reference by putting ‘&’ in the declaration.

#include<iostream>
using namespace std;

int main()
{
  int x = 10;

  // ref is a reference to x.
  int& ref = x;

  // Value of x is now changed to 20
  ref = 20;
  cout << "x = " << x << endl ;

  // Value of x is now changed to 30
  x = 30;
  cout << "ref = " << ref << endl ;

  return 0;
}
Output:

 x = 20
ref = 30
Following is one more example that uses references to swap two variables.

#include<iostream>
using namespace std;

void swap (int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

int main()
{
    int a = 2, b = 3;
    swap( a, b );
    cout << a << " " << b;
    return 0;
}
Output:

 3 2
 */


