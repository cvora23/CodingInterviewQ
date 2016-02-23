/*
 * PrivateDestructor.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: cvora
 */

/*
 * Predict the output of following programs.

#include <iostream>
using namespace std;

class Test
{
private:
   ~Test() {}
};
int main()
{ }
The above program compiles and runs fine. It is not compiler error to create private destructors.
What do you say about below program.

#include <iostream>
using namespace std;

class Test
{
private:
   ~Test() {}
};
int main()
{
  Test t;
}
The above program fails in compilation. The compiler notices that the local variable ‘t’ cannot be destructed because
the destructor is private. What about the below program?

#include <iostream>
using namespace std;

class Test
{
private:
   ~Test() {}
};
int main()
{
   Test *t;
}
The above program works fine. There is no object being constructed, the program just creates a pointer of type “Test *”,
so nothing is destructed. What about the below program?

#include <iostream>
using namespace std;

class Test
{
private:
   ~Test() {}
};
int main()
{
   Test *t = new Test;
}
The above program also works fine. When something is created using dynamic memory allocation, it is programmer’s
responsibility to delete it. So compiler doesn’t bother.

The below program fails in compilation. When we call delete, desturctor is called.

#include <iostream>
using namespace std;

class Test
{
private:
   ~Test() {}
};
int main()
{
   Test *t = new Test;
   delete t;
}
We noticed in the above programs, when a class has private destructur, only dynamic objects of that class can be created.
Following is a way to create classes with private destructors and have a function as friend of the class.
The function can only delete the objects.

#include <iostream>

// A class with private destuctor
class Test
{
private:
    ~Test() {}
friend void destructTest(Test* );
};

// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
}

int main()
{
    // create an object
    Test *ptr = new Test;

    // destruct the object
    destructTest (ptr);

    return 0;
}
What is the use of private destructor?
Whenever we want to control destruction of objects of a class, we make the destructor private. For dynamically
created objects, it may happen that you pass a pointer to the object to a function and the function deletes the object.
If the object is referred after the function call, the reference will become dangling. See this for more details.
 */


