/*
 * LongestCommonSubsequence.cpp
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
 * We have discussed Overlapping Subproblems and Optimal Substructure properties in Set 1 and Set 2 respectively.
 * We also discussed one example problem in Set 3. Let us discuss Longest Common Subsequence (LCS) problem
 * as one more example problem that can be solved using Dynamic Programming.

LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
So a string of length n has 2^n different possible subsequences.

It is a classic computer science problem, the basis of diff (a file comparison program that outputs the differences between two files),
and has applications in bioinformatics.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

The naive solution for this problem is to generate all subsequences of both given sequences and find the longest matching subsequence.
This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a
Dynamic Programming (DP) Problem.

1) Optimal Substructure:
Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively.
And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).

If last characters of both sequences match (or X[m-1] == Y[n-1]) then
L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])

If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then
L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2])

Examples:
1) Consider the input strings “AGGTAB” and “GXTXAYB”. Last characters match for the strings. So length of LCS can be written as:
L(“AGGTAB”, “GXTXAYB”) = 1 + L(“AGGTA”, “GXTXAY”)

2) Consider the input strings “ABCDGH” and “AEDFHR. Last characters do not match for the strings. So length of LCS can be written as:
L(“ABCDGH”, “AEDFHR”) = MAX ( L(“ABCDG”, “AEDFHR”), L(“ABCDGH”, “AEDFH”) )

So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.

2) Overlapping Subproblems:
Following is simple recursive implementation of the LCS problem. The implementation simply follows the recursive structure mentioned above.

 */

namespace Recursion{

	int max(int a, int b);

	/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
	int lcs( char *X, char *Y, int m, int n )
	{
	   if (m == 0 || n == 0)
		 return 0;
	   if (X[m-1] == Y[n-1])
		 return 1 + lcs(X, Y, m-1, n-1);
	   else
		 return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
	}

	/* Utility function to get max of 2 integers */
	int max(int a, int b)
	{
		return (a > b)? a : b;
	}

}
/*
 * Time complexity of the above naive recursive approach is O(2^n) in worst case and worst case happens
 * when all characters of X and Y mismatch i.e., length of LCS is 0.
Considering the above implementation, following is a partial recursion tree for input strings “AXYT” and “AYZX”

                         lcs("AXYT", "AYZX")
                       /
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
In the above partial recursion tree, lcs(“AXY”, “AYZ”) is being solved twice. If we draw the complete recursion tree,
then we can see that there are many subproblems which are solved again and again. So this problem has Overlapping Substructure property
and recomputation of same subproblems can be avoided by either using Memoization or Tabulation.
Following is a tabulated implementation for the LCS problem.

https://www.youtube.com/watch?v=NnD96abizww

 */

namespace DP{
	/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
	int lcs( char *X, char *Y, int m, int n )
	{
		int L[m+1][n+1];
		int i, j;

		/* Following steps build L[m+1][n+1] in bottom up fashion. Note
		  that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
		for (i=0; i<=m; i++)
		{
		 for (j=0; j<=n; j++)
		 {
		   if (i == 0 || j == 0)
			 L[i][j] = 0;

		   else if (X[i-1] == Y[j-1])
			 L[i][j] = L[i-1][j-1] + 1;

		   else
			 L[i][j] = max(L[i-1][j], L[i][j-1]);
		 }
		}
		// Following code is used to print LCS
		int index = L[m][n];

		// Create a character array to store the lcs string
		char lcs[index+1];
		lcs[index] = '\0'; // Set the terminating character

		// Start from the right-most-bottom-most corner and
		// one by one store characters in lcs[]
		i = m, j = n;
		while (i > 0 && j > 0)
		{
		 // If current character in X[] and Y are same, then
		 // current character is part of LCS
		 if (X[i-1] == Y[j-1])
		 {
			 lcs[index-1] = X[i-1]; // Put current character in result
			 i--; j--; index--;     // reduce values of i, j and index
		 }

		 // If not same, then find the larger of two and
		 // go in the direction of larger value
		 else if (L[i-1][j] > L[i][j-1])
			i--;
		 else
			j--;
		}

		// Print the lcs
		cout << "LCS of " << X << " and " << Y << " is " << lcs;

	   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	   return L[m][n];
	}

	/* Utility function to get max of 2 integers */
	int max(int a, int b)
	{
		return (a > b)? a : b;
	}

}

/* Driver program to test above function */
int main()
{
	{
	  char X[] = "AGGTAB";
	  char Y[] = "GXTXAYB";
	  int m = strlen(X);
	  int n = strlen(Y);
	  DP::lcs(X, Y, m, n);
	}

  return 0;
}
