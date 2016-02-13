/*
 * ReferencesVsPointers.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * References vs Pointers
Both references and pointers can be used to change local variables of one function inside another function.
Both of them can also be used to save copying of big objects when passed as arguments to functions or
returned from functions, to get efficiency gain.
Despite above similarities, there are following differences between references and pointers.

References are less powerful than pointers
1) Once a reference is created, it cannot be later made to reference another object; it cannot be reseated.
This is often done with pointers.
2) References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
3) A reference must be initialized when declared. There is no such restriction with pointers

Due to the above limitations, references in C++ cannot be used for implementing data structures like Linked List, Tree, etc.
In Java, references don’t have above restrictions, and can be used to implement all data structures.
References being more powerful in Java, is the main reason Java doesn’t need pointers.

References are safer and easier to use:
1) Safer: Since references must be initialized, wild references like wild pointers are unlikely to exist.
It is still possible to have references that don’t refer to a valid location (See questions 5 and 6 in the below exercise )
2) Easier to use: References don’t need dereferencing operator to access the value.
They can be used like normal variables. ‘&’ operator is needed only at the time of declaration.
Also, members of an object reference can be accessed with dot operator (‘.’),
unlike pointers where arrow operator (->) is needed to access members.

Together with the above reasons, there are few places like copy constructor argument where pointer cannot be used.
Reference must be used pass the argument in copy constructor.
Similarly references must be used for overloading some operators like ++.
 */


//Question 1

//#include<iostream>
//using namespace std;
//
//int &fun()
//{
//    static int x = 10;
//    return x;
//}
//
//int &fun1()
//{
//    int x = 10;
//    return x;
//}
//
//
//int main()
//{
//    fun() = 30;
//    cout << fun()<<endl;
//
//    fun1() = 30;
//    cout << fun1()<<endl;
//
//    int var = fun1();
//    cout << var<<endl;
//
//    return 0;
//}

/*
 * output of fun() is 30. since x is static and function is returning reference to static variable
 * output of fun1() is 10. since x is not static and function is returning reference to local variable
 */

//Question 2

//#include<iostream>
//using namespace std;
//
//int fun(int &x)
//{
//    return x;
//}
//int main()
//{
//    cout << fun(10);
//    return 0;
//}
/*
 * Output: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’
 *
 *
 * To fix it change the fun to
 * int fun(const int &x)
{
    return x;
}
 *
 */

//Question 3

//#include<iostream>
//using namespace std;
//
//void swap(char * &str1, char * &str2)
//{
//  char *temp = str1;
//  str1 = str2;
//  str2 = temp;
//}
//
//int main()
//{
//  char *str1 = "GEEKS";
//  char *str2 = "FOR GEEKS";
//  swap(str1, str2);
//  cout<<"str1 is "<<str1<<endl;
//  cout<<"str2 is "<<str2<<endl;
//  return 0;
//}

/*
 *
 * swapping of values using pointers from a function inside another function. We need to pass reference to pointers.
 *
 * output:
 * str1 is FOR GEEKS
 * str2 is GEEKS
 */

//Question 4
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//   int x = 10; // integer x variable
//   int *ptr = &x; // pointer to integer x
//
//   int  y = 100; // integer y variable
//   int *ptr2 = &y;// pointer to integer y
//
//// int &*ptr1 = ptr; // Compilation error . Corrent way defined below
//
//   // This line means its a different name or reference for ptr
//   int * &ptr1 = ptr; // reference to a integer pointer ptr . ptr and ptr1 both are same. different names thats it.
//
//   ptr1 = ptr2; // reference to integer pointer ptr2. thus reference to a pointer can be reseated.
//   	   	   	   	// not ptr1, ptr2 and ptr are all 3 same. Different names thats it
//
//   cout<<&x<<endl;
//   cout<<&y<<endl;
//   cout<<ptr<<endl;
//   cout<<ptr1<<endl;
//
//}

////Question 5
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//   int *ptr = NULL;
//   int &ref = *ptr;
//   cout << ref;
//}
//
//// output: seg fault. Attempt to de-reference NULL pointer.


