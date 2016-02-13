/*
 * UnboundedBinarySearch.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: cvora
 */
/*
 * Unbounded Binary Search Example (Find the point where a monotonically
 * increasing function becomes positive first time)
 * Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’
 * as input and returns an integer as output.
 * The function is monotonically increasing with respect to value of x, i.e.,
 * the value of f(x+1) is greater than f(x)
 * for every input x. Find the value ‘n’ where f() becomes positive for the first time.
 * Since f() is monotonically increasing, values of f(n+1), f(n+2),… must be positive
 * and values of f(n-2), f(n-3), .. must be negative.
 * Find n in O(logn) time, you may assume that f(x) can be evaluated in O(1) time for any input x.
 * A simple solution is to start from i equals to 0 and one by one calculate value of f(i)
 * for 1, 2, 3, 4 .. etc until we find a positive f(i). This works, but takes O(n) time.
 */

/*
 * Can we apply Binary Search to find n in O(Logn) time? We can’t directly apply Binary Search as
 * we don’t have an upper limit or high index. The idea is to do repeated doubling until we find a
 * positive value, i.e., check values of f() for following values until f(i) becomes positive.

  f(0)
  f(1)
  f(2)
  f(4)
  f(8)
  f(16)
  f(32)
  ....
  ....
  f(high)
  Let 'high' be the value of i when f() becomes positive for first time.
  Can we apply Binary Search to find n after finding ‘high’? We can apply Binary Search now,
  we can use ‘high/2′ as low and ‘high’ as high indexes in binary search.
  The result n must lie between ‘high/2′ and ‘high’.
  Number of steps for finding ‘high’ is O(Logn). So we can find ‘high’ in O(Logn) time.
  What about time taken by Binary Search between high/2 and high? The value of ‘high’
  must be less than 2*n. The number of elements between high/2 and high must be O(n).
  Therefore, time complexity of Binary Search is O(Logn) and overall
  time complexity is 2*O(Logn) which is O(Logn).

 */

#include <stdio.h>
int binarySearch(int low, int high); // prototype

// Let's take an example function as f(x) = x^2 - 10*x - 20
// Note that f(x) can be any monotonocally increasing function
int f(int x) { return (x*x - 10*x - 20); }

// Returns the value x where above function f() becomes positive
// first time.
int findFirstPositive()
{
    // When first value itself is positive
    if (f(0) > 0)
        return 0;

    // Find 'high' for binary search by repeated doubling
    int i = 1;
    while (f(i) <= 0)
        i = i*2;

    //  Call binary search
    return binarySearch(i/2, i);
}

// Searches first positive value of f(i) where low <= i <= high
int binarySearch(int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low)/2; /* mid = (low + high)/2 */

        // If f(mid) is greater than 0 and one of the following two
        // conditions is true:
        // a) mid is equal to low
        // b) f(mid-1) is negative
        if (f(mid) > 0 && (mid == low || f(mid-1) <= 0))
            return mid;

        // If f(mid) is smaller than or equal to 0
        if (f(mid) <= 0)
            return binarySearch((mid + 1), high);
        else // f(mid) > 0
            return binarySearch(low, (mid -1));
    }

    /* Return -1 if there is no positive value in given range */
    return -1;
}

/* Driver program to check above functions */
int main()
{
    printf("The value n where f() becomes positive first is %d",
           findFirstPositive());
    return 0;
}
