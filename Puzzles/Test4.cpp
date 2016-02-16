/*
 * Test4.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: chintan
 */

/*The following is a description of the instance of this famous puzzle involving
 * 2 eggs and a building with 100 floors.
Suppose that we wish to know which stories in a 100-story building are safe to
drop eggs from, and which will cause the eggs to break on landing.
What strategy should be used to drop eggs such that total number of
drops in worst case is minimized and we find the required floor.
We may make a few assumptions:
An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If an egg breaks when dropped, then it would break if dropped from a higher floor.
If an egg survives a fall then it would survive a shorter fall.
 *
 *
 * If only one egg is available and we wish to be sure of obtaining the right
 * result, the experiment can be carried out in only one way. Drop the egg from the
 * first-floor window; if it survives, drop it from the second floor window
 * . Continue upward until it breaks. In the worst case, this method may require 100 droppings.
 * Suppose 2 eggs are available. What is the least number of egg-droppings that is
 * guaranteed to work in all cases?
 * The problem is not actually to find the critical floor, but merely to decide
 * floors from which eggs should be dropped so that total number of trials are minimized.
 * If we use Binary Search Method to find the floor and we start from 50’th floor,
 * then we end up doing 50 comparisons in worst case. The worst case happens
 * when the required floor is 49’th floor.
 *
 * Optimized Method:
 *
The idea is to do optimize the solution using below equation:
Let we make our first attempt on x'th floor.

If it breaks, we try remaining (x-1) floors one by one.
So in worst case, we make x trials.

If it doesn’t break, we jump (x-1) floors (Because we have
already made one attempt and we don't want to go beyond
x attempts.  Therefore (x-1) attempts are available),
    Next floor we try is floor x + (x-1)

Similarly, if this drop does not break, next need to jump
up to floor x + (x-1) + (x-2), then x + (x-1) + (x-2) + (x-3)
and so on.

Since the last floor to be tired is 100'th floor, sum of
series should be 100 for optimal value of x.

 x + (x-1) + (x-2) + (x-3) + .... + 1  = 100

 x(x+1)/2  = 100
         x = 13.651

Therefore, we start trying from 14'th floor. If Egg breaks
we one by one try remaining 13 floors.  If egg doesn't break
we go to 27th floor.
If egg breaks on 27'th floor, we try floors form 15 to 26.
If egg doesn't break on 27'th floor, we go to 39'th floor.

An so on...

Video: https://www.youtube.com/watch?v=ZuyUh3pegVo
 *
 */


