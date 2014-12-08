/*
 * ExceptionHandlingAndObjectDestruction.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Exception handling and object destruction | Set 1
Predict the output of following C++ program.

#include <iostream>
using namespace std;

class Test {
public:
  Test() { cout << "Constructing an object of Test " << endl; }
  ~Test() { cout << "Destructing an object of Test "  << endl; }
};

int main() {
  try {
    Test t1;
    throw 10;
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
}
Output:

  Constructing an object of Test
  Destructing an object of Test
  Caught 10
When an exception is thrown, destructors of the objects (whose scope ends with the try block) is
automatically called before the catch block gets exectuted. That is why the above program prints
“Destructing an object of Test” before “Caught 10″.

What happens when an exception is thrown from a constructor? Consider the following program.

#include <iostream>
using namespace std;

class Test1 {
public:
  Test1() { cout << "Constructing an Object of Test1" << endl; }
  ~Test1() { cout << "Destructing an Object of Test1" << endl; }
};

class Test2 {
public:
  // Following constructor throws an integer exception
  Test2() { cout << "Constructing an Object of Test2" << endl;
            throw 20; }
  ~Test2() { cout << "Destructing an Object of Test2" << endl; }
};

int main() {
  try {
    Test1 t1;  // Constructed and destructed
    Test2 t2;  // Partially constructed
    Test1 t3;  // t3 is not constructed as this statement never gets executed
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
}
Output:

  Constructing an Object of Test1
  Constructing an Object of Test2
  Destructing an Object of Test1
  Caught 20
Destructors are only called for the completely constructed objects. When constructor of an object
throws an exception, destructor for that object is not called.

As an excecise, predict the output of following program.

#include <iostream>

using namespace std;

class Test {
  static int count;
  int id;
public:
  Test() {
    count++;
    id = count;
    cout << "Constructing object number " << id << endl;
    if(id == 4)
       throw 4;
  }
  ~Test() { cout << "Destructing object number " << id << endl; }
};

int Test::count = 0;

int main() {
  try {
    Test array[5];
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
}

output:

Constructing object number 1
Constructing object number 2
Constructing object number 3
Constructing object number 4
Destructing object number 3
Destructing object number 2
Destructing object number 1
Caught 4


 */

