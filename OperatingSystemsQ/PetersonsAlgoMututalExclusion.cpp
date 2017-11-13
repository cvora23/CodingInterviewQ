/*
 * PetersonsAlgoMututalExclusion.cpp
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
 * Peterson’s Algorithm for Mutual Exclusion | Set 1 (Basic C implementation)
3.2
Problem: Given 2 process i and j, you need to write a program that can guarantee mutual exclusion between
the two without any additional hardware support.

Solution: There can be multiple ways to solve this problem, but most of them require additional hardware support.
The simplest and the most popular way to do this is by using Peterson Algorithm for mutual Exclusion.
It was developed by Peterson in 1981 though the initial work in this direction by done by Theodorus Jozef
Dekker who came up with Dekker’s algorithm in 1960, which was later refined by Peterson and came to be known as Peterson’s Algorithm.

Basically, Peterson’s algorithm provides guaranteed mutual exclusion by using only the shared memory. It uses two ideas in the algorithm,

Willingness to acquire lock.
Turn to acquire lock.
Prerequisite : Multithreading in C

Explanation:

The idea is that first a thread expresses its desire to acquire lock and sets flag[self] = 1 and then gives
the other thread a chance to acquire the lock. If the thread desires to acquire the lock, then, it gets the lock
and then passes the chance to the 1st thread. If it does not desire to get the lock then the while loop breaks
and the 1st thread gets the chance.
 */


#include <stdio.h>
#include <pthread.h>

int flag[2];
int turn;
const int MAX = 1e9;
int ans = 0;

#include <pthread.h>
#include <assert.h>
#include <sched.h>

void Pthread_mutex_lock(pthread_mutex_t *m)
{
    int rc = pthread_mutex_lock(m);
    assert(rc == 0);
}

void Pthread_mutex_unlock(pthread_mutex_t *m)
{
    int rc = pthread_mutex_unlock(m);
    assert(rc == 0);
}

void Pthread_create(pthread_t *thread, const pthread_attr_t *attr,
           void *(*start_routine)(void*), void *arg)
{
    int rc = pthread_create(thread, attr, start_routine, arg);
    assert(rc == 0);
}

void Pthread_join(pthread_t thread, void **value_ptr)
{
    int rc = pthread_join(thread, value_ptr);
    assert(rc == 0);
}

void lock_init()
{
    // Initialize lock by reseting the desire of
    // both the threads to acquire the locks.
    // And, giving turn to one of them.
    flag[0] = flag[1] = 0;
    turn = 0;
}

// Executed before entering critical section
void lock(int self)
{
    // Set flag[self] = 1 saying you want to acquire lock
    flag[self] = 1;

    // But, first give the other thread the chance to
    // acquire lock
    turn = 1-self;

    // Wait until the other thread looses the desire
    // to acquire lock or it is your turn to get the lock.
    while (flag[1-self]==1 && turn==1-self) ;
}

// Executed after leaving critical section
void unlock(int self)
{
    // You do not desire to acquire lock in future.
    // This will allow the other thread to acquire
    // the lock.
    flag[self] = 0;
}

// A Sample function run by two threads created
// in main()
void* func(void *s)
{
    int i = 0;
    int self = (int *)s;
    printf("Thread Entered: %d\n", self);

    lock(self);

    // Critical section (Only one thread
    // can enter here at a time)
    for (i=0; i<MAX; i++)
        ans++;

    unlock(self);
}

// Driver code
int main()
{
    // Initialized the lock then fork 2 threads
    pthread_t p1, p2;
    lock_init();

    // Create two threads (both run func)
    pthread_create(&p1, NULL, func, (void*)0);
    pthread_create(&p2, NULL, func, (void*)1);

    // Wait for the threads to end.
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",
                                        ans, MAX*2);

    return 0;
}
