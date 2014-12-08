/*
 * CatchingBaseAndDerivedClassesAsExceptions.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * Catching base and derived classes as exceptions
Exception Handling – catching base and derived classes as exceptions:

If both base and derived classes are caught as exceptions then catch block of derived class must appear before the base class.

If we put base class first then the derived class catch block will never be reached.
For example, following C++ code prints “Caught Base Exception”

#include<iostream>
using namespace std;

class Base {};
class Derived: public Base {};
int main()
{
   Derived d;
   // some other stuff
   try {
       // Some monitored code
       throw d;
   }
   catch(Base b) {
        cout<<"Caught Base Exception";
   }
   catch(Derived d) {  //This catch block is NEVER executed
        cout<<"Caught Derived Exception";
   }
   getchar();
   return 0;
}
In the above C++ code, if we change the order of catch statements then both catch statements become
reachable. Following is the modifed program and it prints “Caught Derived Exception”

#include<iostream>
using namespace std;

class Base {};
class Derived: public Base {};
int main()
{
   Derived d;
   // some other stuff
   try {
       // Some monitored code
       throw d;
   }
   catch(Derived d) {
        cout<<"Caught Derived Exception";
   }
   catch(Base b) {
        cout<<"Caught Base Exception";
   }
   getchar();
   return 0;
}
In Java, catching a base class exception before derived is not allowed by the compiler itself. In C++,
compiler might give warning about it, but compiles the code.
For example, following Java code fails in compilation with error message “exception Derived has
already been caught”

//filename Main.java
class Base extends Exception {}
class Derived extends Base  {}
public class Main {
  public static void main(String args[]) {
    try {
       throw new Derived();
    }
    catch(Base b) {}
    catch(Derived d) {}
  }
}
 */


