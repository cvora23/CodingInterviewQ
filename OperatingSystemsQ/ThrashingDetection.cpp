/*
 * ThrashingDetection.cpp
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
 *How would you detect the thrashing phenomena occurring in OS efficiently?
 */

/*
 * Here is my understanding:

First of all, what is thrashing? Thrashing usually refers to a phenomena in memory and storage.
It occurs when OS spends most of time on handling page faults(paging in or paging out) rather than getting anything done. For example:

process A has some pages in hard drive and gets a page fault.
The missing page(not in memory) needs to be swapped into memory.
Suppose the memory is full, pages belong to process B need to be swapped out.
Then process B needs to run, so its pages need to be swapped in and the process A's pages that were just swapped in need to be swapped out
This could happen indefinitely until the issue is resolved or one of the process finishes its job.
As we can see the performance is terrible, we need to detect the problem first before solve it(or least alleviate it).
Kernel usually keep track of the number page-in and page-out, if the number is too high, the physical memory is almost
full and CPU utilization is low, the thrashing is happening. There should be a formula to determine thrashing based on
number of page-in and page-out in certain period, etc. In userland, there are some tools like vmstat and atop to help us detect thrashing.

When thrashing is detected, different OSes may deal with it in different ways. We could either kill a process or swap a
process completely into secondary storage. Additionally, we could also add more RAM to the machine:)
 */


int main(){


	return 0;

}
