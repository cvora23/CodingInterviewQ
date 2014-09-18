/*
 * StringInterleavingOfOtherTwoStrings.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: cvora
 */


#include<stdio.h>

/**
 * 	Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B.
	C is said to be interleaving A and B, if it contains all characters of A and B and order
	of all characters in individual strings is preserved.

	Example:

	Input: str1 = "AB",  str2 = "CD"
	Output:
		ABCD
		ACBD
		ACDB
		CABD
		CADB
		CDAB

	Input: str1 = "AB",  str2 = "C"
	Output:
		ABC
		ACB
		CAB

 */

/**
 * Solution:
	Pick each character of C one by one and match it with the first character in A.
	If it doesn’t match then match it with first character of B. If it doesn’t even
	match first character of B, then return false. If the character matches with first
	character of A, then repeat the above process from second character of C, second
	character of A and first character of B. If first character of C matches with the
	first character of B (and doesn’t match the first character of A), then repeat the
	above process from the second character of C, first character of A and second
	character of B. If all characters of C match either with a character of A or a
	character of B and length of C is sum of lengths of A and B, then C is an
	interleaving A and B.
 */

// Returns true if C is an interleaving of A and B, otherwise
// returns false
bool isInterleaved (char *A, char *B, char *C)
{
    // Iterate through all characters of C.
    while (*C != 0)
    {
        // Match first character of C with first character of A,
        // If matches them move A to next
        if (*A == *C)
            A++;

        // Else Match first character of C with first character of B,
        // If matches them move B to next
        else if (*B == *C)
            B++;

        // If doesn't match with either A or B, then return false
        else
            return false;

        // Move C to next for next iteration
        C++;
    }

    // If A or B still have some characters, then length of C is smaller
    // than sum of lengths of A and B, so return false
    if (*A || *B)
        return false;

    return true;
}

// Driver program to test above functions
int main()
{
    char *A = "AB";
    char *B = "CD";
    char *C = "ACBG";
    if (isInterleaved(A, B, C))
        printf("%s is interleaved of %s and %s \n", C, A, B);
    else
        printf("%s is not interleaved of %s and %s \n", C, A, B);

    A = "AB";
    B = "C";
    C = "ACB";

    if (isInterleaved(A, B, C))
        printf("%s is interleaved of %s and %s \n", C, A, B);
    else
        printf("%s is not interleaved of %s and %s \n", C, A, B);

    return 0;
}

