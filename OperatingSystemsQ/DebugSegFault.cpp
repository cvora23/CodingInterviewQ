/*
 * DebugSegFault.cpp
 *
 *  Created on: Jan 2, 2018
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
 * How to debug segmentation fault? What are the best practices to avoid segmentation faults in the code?
 */

/*
 *Look at the core dump file and analyze the stack frame with gdb/ddd etc. If you want to debug something in Kernel
 *Look like OOPs again debugfs/dmesg/octaldump may help. I personally like attaching the JTAG to the embedded hw and
 *Look put the breakpoint and look at all the stack traces, register dumps like ( PC, STACK PTR, CPU status registers ) etc.
 *Look If the crash is random you may want to look into the JTAG ETM and collect the last executed instruction sets etc.
 *Look It may be related to the HW as well. In that case try changing the kernel to single core, reduced clock regime etc.
 */

/*
 * Segmenfault is relatively easy to debug, but hard to avoid.
Segmenfault mostly implies null pointer or wild pointer.

debug:
	core dump file & gdb; debugfs, dmesg
avoid:
	assert() before dereferencing suspective pointers, mainly pointers embedded in structs that are maintained in containers in lists and arrays.
	always remember to initialize pointers properly.
	protect global/shared variables from concurrent threads with mutex,semaphore(avoid shared access if possible).
	do free()s carefully, maybe with proper refcount on objects(also set NULL after free()).
 */

int main(){


	return 0;

}
