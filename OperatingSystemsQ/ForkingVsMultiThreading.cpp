/*
 * ForkingVsMultiThreading.cpp
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
 * Difference between forking and multithreading
 */

/*
 * A fork gives us a brand new process which is a copy of the current process with the same code segment.
 * It looks exactly like the parent process with different process id having it's own memory.
 * Parent process creates a separate address space for the child with same code segments but
 * executes independently of each other. Because the system issues a new memory space and environment for the child process,
 * it is knows as heavy-weight process.
 *
While threads can execute in parallel with same context. Also, memory and other resources are shared between the
threads causing less overhead. A thread process is considered a sibling while a forked process is considered a child.
Also, threads are known as light-weight processes as they don't have any overhead as compared to processes
(as it doesn't issue any separate command for creating completely new virtual address space).
A single process can have multiple threads. For all threads of any process, communication between them is direct.
While process needs some interprocess communication mechanism to talk to other processes.
Thought, threads seem to be more useful for any reason, do note that changes in any thread may lead to changes
in other threads of the same process. While, changes in child processes is independent as parent process has its own execution copy.
 */


int main(){


	return 0;

}
