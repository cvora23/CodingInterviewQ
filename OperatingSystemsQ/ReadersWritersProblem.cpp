/*
 * ReadersWritersProblem.cpp
 *
 *  Created on: Nov 11, 2017
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
 * Readers-Writers Problem | Set 1 (Introduction and Readers Preference Solution)
2.7
Consider a situation where we have a file shared between many people.

If one of the people tries editing the file, no other person should be reading or writing at the same time,
otherwise changes will not be visible to him/her.
However if some person is reading the file, then others may read it at the same time.
Precisely in OS we call this situation as the readers-writers problem

Problem parameters:

One set of data is shared among a number of processes
Once a writer is ready, it performs its write. Only one writer may write at a time
If a process is writing, no other process can read it
If at least one reader is reading, no other process can write
Readers may not write and only read
Solution when Reader has the Priority over Writer

Here priority means, no reader should wait if the share is currently opened for reading.

Three variables are used: mutex, wrt, readcnt to implement solution

semaphore mutex, wrt; // semaphore mutex is used to ensure mutual exclusion when readcnt is updated i.e.
when any reader enters or exit from the critical section and semaphore wrt is used by both readers and writers
int readcnt;  //    readcnt tells the number of processes performing read in the critical section, initially 0
Functions for sempahore :

– wait() : decrements the semaphore value.

– signal() : increments the semaphore value.

Writer process:

Writer requests the entry to critical section.
If allowed i.e. wait() gives a true value, it enters and performs the write. If not allowed, it keeps on waiting.
It exits the critical section.
do {
    // writer requests for critical section
    wait(wrt);

    // performs the write

    // leaves the critical section
    signal(wrt);

} while(true);
Reader process:

Reader requests the entry to critical section.
If allowed:
it increments the count of number of readers inside the critical section. If this reader is the first reader entering,
it locks the wrt semaphore to restrict the entry of writers if any reader is inside.
It then, signals mutex as any other reader is allowed to enter while others are already reading.
After performing reading, it exits the critical section. When exiting, it checks if no more reader is inside,
it signals the semaphore “wrt” as now, writer can enter the critical section.
If not allowed, it keeps on waiting.
do {

   // Reader wants to enter the critical section
   wait(mutex);

   // The number of readers has now increased by 1
   readcnt++;

   // there is atleast one reader in the critical section
   // this ensure no writer can enter if there is even one reader
   // thus we give preference to readers here
   if (readcnt==1)
      wait(wrt);

   // other readers can enter while this current reader is inside
   // the critical section
   signal(mutex);

   // current reader performs reading here
   wait(mutex);   // a reader wants to leave

   readcnt--;

   // that is, no reader is left in the critical section,
   if (readcnt == 0)
       signal(wrt);         // writers can enter

   signal(mutex); // reader leaves

} while(true);
Thus, the mutex ‘wrt‘ is queued on both readers and writers in a manner such that preference is given to readers
if writers are also there. Thus, no reader is waiting simply because a writer has requested to enter the critical section.
 */


int main(){


	return 0;

}
