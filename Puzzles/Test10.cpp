/*
 * Test10.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: chintan
 */

/*
 * A car has 4 tyres and 1 spare tyre. Each tyre can travel a
 * maximum distance of 20000 miles before wearing off.
 * What is the maximum distance the car can travel before you are
 * forced to buy a new tyre? You are allowed to change tyres
 * (using the spare tyre) unlimited number of times.
 *
 * Answer: 25000
Divide the lifetime of spare tire into 4 equal part i.e., 5000 and
swap it at each completion of 5000 miles distance.
Let four tyres be A, B, C and D and spare tyre be S.
5000 KMs: Replace A with S.
10000 KMs: Put A back to its original position and replace B with S
15000 KMs: Put B back to its original position and replace C with S
20000 KMs: Put C back to its original position and replace D with S
All tyres are used upto their full strength.
 *
 */



