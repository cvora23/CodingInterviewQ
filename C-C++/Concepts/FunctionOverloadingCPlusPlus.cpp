/*
 * FunctionOverloadingCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Function Overloading in C++
May 28, 2014
Function overloading is a feature in C++ where two or more functions can have the same name but different parameters.

Function overloading can be considered as an example of polymorphism feature in C++.

Following is a simple C++ example to demonstrate function overloading.

#include <iostream>
using namespace std;

void print(int i) {
  cout << " Here is int " << i << endl;
}
void print(double  f) {
  cout << " Here is float " << f << endl;
}
void print(char* c) {
  cout << " Here is char* " << c << endl;
}

int main() {
  print(10);
  print(10.10);
  print("ten");
  return 0;
}

Output:

Here is int 10
Here is float 10.1
Here is char* ten


 */



