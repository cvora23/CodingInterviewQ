/*
 * CoinChange.cpp
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
 * Dynamic Programming | Set 7 (Coin Change)
3.7
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm}
valued coins, how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
1) Optimal Substructure
To count total number solutions, we can divide all set solutions in two sets.
1) Solutions that do not contain mth coin (or Sm).
2) Solutions that contain at least one Sm.
Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).

Therefore, the problem has optimal substructure property as the problem can be solved using solutions to subproblems.

2) Overlapping Subproblems
Following is a simple recursive implementation of the Coin Change problem.
 *
 */


namespace Recursion{

	// Returns the count of ways we can
	// sum S[0...m-1] coins to get sum n
	int count( int S[], int m, int n )
	{
		// If n is 0 then there is 1 solution
		// (do not include any coin)
		if (n == 0)
			return 1;

		// If n is less than 0 then no
		// solution exists
		if (n < 0)
			return 0;

		// If there are no coins and n
		// is greater than 0, then no
		// solution exist
		if (m <=0 && n >= 1)
			return 0;

		// count is sum of solutions (i)
		// including S[m-1] (ii) excluding S[m-1]
		return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
	}

}

/*
 * It should be noted that the above function computes the same subproblems again and again.
 * See the following recursion tree for S = {1, 2, 3} and n = 5.
The function C({1}, 3) is called two times. If we draw the complete tree, then we can see that there
are many subproblems being called more than once.
C() --> count()
                             C({1,2,3}, 5)
                           /             \
                         /                 \
             C({1,2,3}, 2)                 C({1,2}, 5)
            /       \                      /      \
           /         \                    /         \
C({1,2,3}, -1)  C({1,2}, 2)        C({1,2}, 3)    C({1}, 5)
               /    \             /     \           /     \
             /       \           /       \         /        \
    C({1,2},0)  C({1},2)   C({1,2},1) C({1},3)    C({1}, 4)  C({}, 5)
                   / \     / \        /\         /     \
                  /   \   /   \     /   \       /       \
                .      .  .     .   .     .   C({1}, 3) C({}, 4)
                                               / \
                                              /   \
                                             .      .
Since same suproblems are called again, this problem has Overlapping Subprolems property.
So the Coin Change problem has both properties (see this and this) of a dynamic programming problem.
Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by
constructing a temporary array table[][] in bottom up manner.
 */

namespace DP{

	int count( int S[], int m, int n )
	{
		// table[i] will be storing the number of solutions for
		// value i. We need n+1 rows as the table is constructed
		// in bottom up manner using the base case (n = 0)
		int table[n+1];

		// Initialize all table values as 0
		memset(table, 0, sizeof(table));

		// Base case (If given value is 0)
		table[0] = 1;

		// Pick all coins one by one and update the table[] values
		// after the index greater than or equal to the value of the
		// picked coin
		for(int i=0; i<m; i++)
			for(int j=S[i]; j<=n; j++)
				table[j] += table[j-S[i]];

		return table[n];
	}

}

int main(){


	return 0;

}
