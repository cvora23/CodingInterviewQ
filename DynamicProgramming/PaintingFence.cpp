/*
 * PaintingFence.cpp
 *
 *  Created on: Feb 6, 2018
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
 * Painting Fence Algorithm
4
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at
most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

Examples:

Input : n = 2 k = 4
Output : 16
We have 4 colors and 2 posts.
Ways when both posts have same color : 4
Ways when both posts have diff color :
4*(choices for 1st post) * 3(choices for 2nd post) = 12

Input : n = 3 k = 2
Output : 6

Following image depicts the 6 possible ways of painting 3 posts with 2 colors:
http://cdncontribute.geeksforgeeks.org/wp-content/uploads/paintFence.png

Consider the following image in which c, c’ and c” are respective colors of posts i, i-1 and i -2.
http://cdncontribute.geeksforgeeks.org/wp-content/uploads/paintFence1-276x300.png

According to the constraint of the problem, c = c’ = c” is not possible simultaneously, so either c’ != c or c” != c or both.
There are k – 1 possibilities for c’ != c and k – 1 for c” != c.

 diff = no of ways when color of last
        two posts is different
 same = no of ways when color of last
        two posts is same
 total ways = diff + sum

for n = 1
    diff = k, same = 0
    total = k

for n = 2
    diff = k * (k-1) //k choices for
           first post, k-1 for next
    same = k //k choices for common
           color of two posts
    total = k +  k * (k-1)

for n = 3
    diff = [k +  k * (k-1)] * (k-1)
           (k-1) choices for 3rd post
           to not have color of 2nd
           post.
    same = k * (k-1)
           c'' != c, (k-1) choices for it

Hence we deduce that,
total[i] = same[i] + diff[i]
same[i]  = diff[i-1]
diff[i]  = (diff[i-1] + diff[i-2]) * (k-1)
         = total[i-1] * (k-1)

 */

// Returns count of ways to color k posts
// using k colors
long countWays(int n, int k)
{
    // To store results for subproblems
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));

    // There are k ways to color first post
    dp[1] = k;

    // There are 0 ways for single post to
    // violate (same color_ and k ways to
    // not violate (different color)
    int same = 0, diff = k;

    // Fill for 2 posts onwards
    for (int i = 2; i <= n; i++)
    {
        // Current same is same as previous diff
        same = diff;

        // We always have k-1 choices for next post
        diff = dp[i-1] * (k-1);

        // Total choices till i.
        dp[i] = (same + diff);
    }

    return dp[n];
}

// Returns count of ways to color k posts
// using k colors
long countWays2(int n, int k)
{
    // There are k ways to color first post
    long total = k;

    // There are 0 ways for single post to
    // violate (same color_ and k ways to
    // not violate (different color)
    int same = 0, diff = k;

    // Fill for 2 posts onwards
    for (int i = 2; i <= n; i++)
    {
        // Current same is same as previous diff
        same = diff;

        // We always have k-1 choices for next post
        diff = total * (k-1);

        // Total choices till i.
        total = (same + diff);
    }

    return total;
}

// Driver code
int main()
{
	{
	    int n = 3, k = 2;
	    cout << countWays(n, k) << endl;
	}

	{
	    int n = 3, k = 2;
	    cout << countWays2(n, k) << endl;
	}

    return 0;
}
