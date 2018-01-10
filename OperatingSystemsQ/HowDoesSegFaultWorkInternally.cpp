/*
 * HowDoesSegFaultWorkInternally.cpp
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
 * How does segmentation fault work internally?
 *
void main()
{
    int *p = NULL;

    *p = 10;
}
Obviously a segmentation fault will occur when running above program. A message will be printed out:

# ./segfault
Segmentation Fault
#

How does segmentation fault work internally?
When a processor is given a virtual address, it passes the address to MMU which will check if there is a
mapping from the virtual address to physical address by looking up the page table (MMU will check TLB first though ).
If there is no such mapping, the processor will take it as a page fault and subsequently check the page fault is a
valid or not by checking if the address belongs to any segments the process currently has.

When the page fault is valid, which means the page resides in the swap space and needs to be swapped into memory,
the processor will proceed after the page gets swapped in; otherwise, the page fault is invalid, the processor
will send a segmentation fault signal to the process and kills the process by default if there is no signal handler that catches the SIGSEGV signal.

What prints the message "Segmentation Fault"?
Shell that runs the program prints the message "Segmentation Fault". Basically when the process is killed because
of segmentation fault, its parent(the shell in this case) that calls wait() to wait for its termination will get its exit status.
Then the parent knows the reason why the child process is terminated based on the exit status, and prints the message accordingly.
 */


int main(){


	return 0;

}
