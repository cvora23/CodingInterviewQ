/*
 * SharedLibraries.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 * Working with Shared Libraries | Set 1
3.6
This article is not for those algo geeks. If you are interested in systems related stuff, just read on…

Shared libraries are useful in sharing code which is common across many applications. For example,
it is more economic to pack all the code related to TCP/IP implementation in a shared library.
However, data can’t be shared as every application needs its own set of data.
Applications like, browser, ftp, telnet, etc… make use of the shared ‘network’ library to elevate specific functionality.

Every operating system has its own representation and tool-set to create shared libraries. More or less the concepts are same.
On Windows every object file (*.obj, *.dll, *.ocx, *.sys, *.exe etc…) follow a format called Portalbe Executable.
Even shared libraries (called as Dynamic Linked Libraries or DLL in short) are also represented in PE format.
The tool-set that is used to create these libraries need to understand the binary format. Linux variants follow a
format called Executable and Linkable Format (ELF). The ELF files are position independent (PIC) format.
Shared libraries in Linux are referred as shared objects (generally with extension *.so).
These are similar to DLLs in Windows platform. Even shared object files follow the ELF binary format.

Remember, the file extensions (*.dll, *.so, *.a, *.lib, etc…) are just for programmer convenience.
They don’t have any significance. All these are binary files. You can name them as you wish.
Yet ensure you provide absolute paths in building applications.

In general, when we compile an application the steps are simple. Compile, Link and Load. However, it is not simple.
These steps are more versatile on modern operating systems.

When you link your application against static library, the code is part of your application. There is no dependency.
Even though it causes the application size to increase, it has its own advantages. The primary one is speed as there
will be no symbol (a program entity) resolution at runtime. Since every piece of code part of the binary image,
such applications are independent of version mismatch issues. However, the cost is on fixing an issue in library code.
If there is any bug in library code, entire application need to be recompiled and shipped to the client.
In case of dynamic libraries, fixing or upgrading the libraries is easy. You just need to ship the updated shared libraries.
The application need not to recompile, it only need to re-run. You can design a mechanism where we don’t need to restart the application.

When we link an application against a shared library, the linker leaves some stubs (unresolved symbols) to be filled at
application loading time. These stubs need to be filled by a tool called, dynamic linker at run time or at application
 loading time. Again loading of a library is of two types, static loading and dynamic loading. Don’t confuse between
 static loading vs static linking and dynamic loading vs dynamic linking.

For example, you have built an application that depends on libstdc++.so which is a shared object (dynamic libary).
How does the application become aware of required shared libraries? (If you are interested, explore the tools tdump
from Borland tool set, objdump or nm or readelf tools on Linux).

Static loading:

In static loading, all of those dependent shared libraries are loaded into memory even before the application starts execution.
If loading of any shared library fails, the application won’t run.
A dynamic loader examines application’s dependency on shared libraries. If these libraries are already loaded into the memory,
the library address space is mapped to application virtual address space (VAS) and the dynamic linker does relocation of unresolved symbols.
If these libraries are not loaded into memory (perhaps your application might be first to invoke the shared library),
the loader searches in standard library paths and loads them into memory, then maps and resolves symbols.
Again loading is big process, if you are interested write your own loader :).
While resolving the symbols, if the dynamic linker not able to find any symbol (may be due to older version of shared library),
the application can’t be started.
Dynamic Loading:

As the name indicates, dynamic loading is about loading of library on demand.
For example, if you want a small functionality from a shared library. Why should it be loaded at the application load time
and sit in the memory? You can invoke loading of these shared libraries dynamically when you need their functionality.
This is called dynamic loading. In this case, the programmer aware of situation ‘when should the library be loaded’.
The tool-set and relevant kernel provides API to support dynamic loading, and querying of symbols in the shared library.


Prior to that we need to understand how a program is loaded into memory, various (basic) steps involved in the process.

Let us see a typical “Hello World” program in C. Simple Hello World program screen image is given below.

Hello World

We were compiling our code using the command “gcc -o sample shared.c” When we compile our code, the compiler won’t
resolve implementation of the function printf(). It only verifies the syntactical checking. The tool chain leaves a
stub in our application which will be filled by dynamic linker. Since printf is standard function the compiler
implicitly invoking its shared library. More details down.

We are using ldd to list dependencies of our program binary image. In the screen image, we can see our sample program
depends on three binary files namely, linux-vdso.so.1, libc.so.6 and /lib64/ld-linux-x86-64.so.2.

The file VDSO is fast implementation of system call interface and some other stuff, it is not our focus
(on some older systems you may see different file name in liue of *.vsdo.*). Ignore this file. We have interest in the other two files.

The file libc.so.6 is C implementation of various standard functions. It is the file where we see printf definition
needed for our Hello World. It is the shared library needed to be loaded into memory to run our Hello World program.

The third file /lib64/ld-linux-x86-64.so.2 is infact an executable that runs when an application is invoked.
When we invoke the program on bash terminal, typically the bash forks itself and replaces its address space with
image of program to run (so called fork-exec pair). The kernel verifies whether the libc.so.6 resides in the memory.
If not, it will load the file into memory and does the relocation of libc.so.6 symbols. It then invokes the
dynamic linker (/lib64/ld-linux-x86-64.so.2) to resolve unresolved symbols of application code (printf in the present case).
 Then the control transfers to our program main. (I have intensionally omitted many details in the process,
 our focus is to understand basic details).

Creating our own shared library:

Let us work with simple shared library on Linux. Create a file library.c with the following content.

library

The file library.c defines a function signum which will be used by our application code. Compile the file library.c file
using the following command.

gcc -shared -fPIC -o liblibrary.so library.c

The flag -shared instructs the compiler that we are building a shared library. The flag -fPIC is to generate position
independent code (ignore for now). The command generates a shared library liblibrary.so in the current working directory.
We have our shared object file (shared library name in Linux) ready to use.

Create another file application.c with the following content.

application

In the file application.c we are invoking the function signum which was defined in a shared library.
Compile the application.c file using the following command.

gcc application.c -L /home/geetanjali/coding/ -llibrary -o sample

The flag -llibrary instructs the compiler to look for symbol definitions that are not available in the current code
(signum function in our case). The option -L is hint to the compiler to look in the directory followed by the option
for any shared libraries (during link time only). The command generates an executable named as “sample“.

If you invoke the executable, the dynamic linker will not be able to find the required shared library. By default
it won’t look into current working directory. You have to explicitly instruct the tool chain to provide proper paths.
The dynamic linker searches standard paths available in the LD_LIBRARY_PATH and also searches in system cache
(for details explore the command ldconfig). We have to add our working directory to the LD_LIBRARY_PATH environment variable.
The following command does the same.

export LD_LIBRARY_PATH=/home/geetanjali/coding/:$LD_LIBRARY_PATH

You can now invoke our executable as shown.

./sample

Sample output on my system is shown below.

output

Note: The path /home/geetanjali/coding/ is working directory path on my machine. You need to use your working directory
path where ever it is being used in the above commands.


 *
 */


int main(){


	return 0;

}
