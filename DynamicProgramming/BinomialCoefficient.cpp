/*
 * BinomialCoefficient.cpp
 *
 *  Created on: Jan 10, 2018
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
 * Following are common definition of Binomial Coefficients.
1) A binomial coefficient C(n, k) can be defined as the coefficient of X^k in the expansion of (1 + X)^n.

2) A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen
from among n objects; more formally, the number of k-element subsets (or k-combinations) of an n-element set.

The Problem
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

1) Optimal Substructure
The value of C(n, k) can be recursively calculated using following standard formula for Binomial Coefficients.

   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1


 */

#include<stdio.h>


/*
 * Following is a simple recursive implementation that simply follows the recursive structure mentioned above.
 */

// Returns value of Binomial Coefficient C(n, k)
namespace Recursive{

	int binomialCoeff(int n, int k)
	{
	  // Base Cases
	  if (k==0 || k==n)
		return 1;

	  // Recur
	  return  binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
	}

}

/*
 * Overlapping Subproblems
It should be noted that the above function computes the same subproblems again and again.
See the following recursion tree for n = 5 an k = 2. The function C(3, 1) is called two times.
For large values of n, there will be many common subproblems.

                             C(5, 2)
                    /                      \
           C(4, 1)                           C(4, 2)
            /   \                          /           \
       C(3, 0)   C(3, 1)             C(3, 1)               C(3, 2)
                /    \               /     \               /     \
         C(2, 0)    C(2, 1)      C(2, 0) C(2, 1)          C(2, 1)  C(2, 2)
                   /        \              /   \            /    \
               C(1, 0)  C(1, 1)      C(1, 0)  C(1, 1)   C(1, 0)  C(1, 1)
Since same suproblems are called again, this problem has Overlapping Subproblems property.
So the Binomial Coefficient problem has both properties (see this and this) of a dynamic programming problem.
Like other typical Dynamic Programming(DP) problems, re-computations of same subproblems can be avoided by constructing a
temporary array C[][] in bottom up manner. Following is Dynamic Programming based implementation
 */

namespace Dp{

	// Prototype of a utility function that returns minimum of two integers
	int min(int a, int b);

	// Returns value of Binomial Coefficient C(n, k)
	int binomialCoeff(int n, int k)
	{
		int C[n+1][k+1];
		int i, j;

		// Caculate value of Binomial Coefficient in bottom up manner
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= min(i, k); j++)
			{
				// Base Cases
				if (j == 0 || j == i)
					C[i][j] = 1;

				// Calculate value using previosly stored values
				else
					C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}

		return C[n][k];
	}

	// A utility function to return minimum of two integers
	int min(int a, int b)
	{
		return (a<b)? a: b;
	}

}

int main(){


	cout<<Recursive::binomialCoeff(5,2)<<endl;
	cout<<Dp::binomialCoeff(5,2)<<endl;

	return 0;

}
