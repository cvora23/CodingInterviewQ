/*
 * Interrupts.cpp
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
 * What is interrupt? How does interrupt work?
 *
 */

/*
 * Basically an interrupt is a signal to notify kernel(processor) that something needs to be handled as soon as possible.
 * It's called interrupt because kernel(processor) may suspend what it is running to handle the interrupt event(by calling ISR) and then resume its execution.
 * There are two types of interrupts: hardware interrupt(which caused by external device, like keyboard, mouse, disk, etc)
 * and software interrupt(which caused by program, like system call, divide-by-zero)
 */

/*
 * Why sleeping in ISR (interrupt service routine) is not recommended ?
 *
 */

/*
 * Interrupts usually need to be handled as fast as possible, if an ISR goes sleeping, it will be put into sleeping queue,
 * and then put into running queue after sleeping finishes, then get CPU to run as soon as the scheduler allows it.
 * The whole process will definitely be time-consuming.
 * Also, an ISR may disable other interrupted, if the ISR goes sleeping, then no other interrupts could be
 * handled until the ISR gets CPU to run again and then re-enables them, then kernel performance be terrible.
 *
 * first of all the interrupt service routine, is not executed in a proper thread context, it is rather executed
 * on top of any thread that was running when the interrupt occurred. One of the consequences is, that preemptive scheduling
 * is not available within an ISR until the interrupt service routine is done, this is, because ISRs are designed to respond
 * quickly to hardware activities, get data in (hopefully using lock less buffers) and leave heavier weight communication,
 * such as transferring data into a larger buffer or dealing with higher level protocols such as IP or TCP in an interrupt service thread,
 * which is usually a thread with definable priority. The ISR is supposed to be the tiniest possible part of code used to communicate
 * with the hardware. Sometimes, in embedded systems for example, with some cumbersome chips, you need to wait very short and respond
 * to the hardware. This is sometimes optimized by looping and checking a tick counter, blocking a complete core for some hundred nanoseconds.
 * It's obviously doesn't scale very well and must be avoided. edited: obviously details vary very much from OS to OS, especially with RTOS ISR code is criticial
 *
 */

int main(){


	return 0;

}
