/*
 * NameManglingExternCAndCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Name Mangling and extern “C” in C++
C++ supports function overloading, i.e., there can be more than one functions with same name and
differences in parameters. How does C++ compiler distinguishes between different functions
when it generates object code – it changes names by adding information about arguments.
This technique of adding additional information to function names is called Name Mangling.
C++ standard doesn’t specify any particular technique for name mangling, so different
compilers may append different information to function names.

Consider following declarations of function f()

int  f (void) { return 1; }
int  f (int)  { return 0; }
void g (void) { int i = f(), j = f(0); }
A C++ compiler may mangle above names to following (Source: Wiki)

int  __f_v (void) { return 1; }
int  __f_i (int)  { return 0; }
void __g_v (void) { int i = __f_v(), j = __f_i(0); }

How to handle C symbols when linking from C++?
In C, names may not be mangled as C doesn’t support function overloading. So how to make sure that name of a symbol
is not changed when we link a C code in C++. For example, see the following C++ program that uses printf() function of C.

// Save file as .cpp and use C++ compiler to compile it
int printf(const char *format,...);

int main()
{
    printf("GeeksforGeeks");
    return 0;
}
Output:

undefined reference to `printf(char const*, ...)'
        ld returned 1 exit status
The reason for compiler error is simple, name of printf is changed by C++ compiler and it doesn’t
find definition of the function with new name.

The solution of problem is extern “C” in C++. When some code is put in extern “C” block, the C++
compiler ensures that the function names are unmangled – that the compiler emits a binary file with
their names unchanged, as a C compiler would do.

If we change the above program to following, the program works fine and prints “GeeksforGeeks” on console.

// Save file as .cpp and use C++ compiler to compile it
extern "C"
{
    int printf(const char *format,...);
}

int main()
{
    printf("GeeksforGeeks");
    return 0;
}
Output:

GeeksforGeeks


Therefore, all C style header files (stdio.h, string.h, .. etc) have their declarations in extern “C” block.

#ifdef __cplusplus
extern "C" {
#endif
    // Declarations of this file
#ifdef __cplusplus
}
#endif
Following are main points discussed above
1. Since C++ supports function overloading, additional information has to be added to function names
(called name mangling) to avoid conflicts in binary code.
2. Function names may not be changed in C as C doesn’t support function overloading.
To avoid linking problems, C++ supports extern “C” block. C++ compiler makes sure that names inside extern “C” block are not changed.

 */



