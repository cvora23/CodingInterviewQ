/*
 * RemoveBandAC.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: cvora
 */

/*
 * Given a string, eliminate all “b” and “ac” in the string,
 * you have to replace them in-place, and you are only
 * allowed to iterate over the string once.
 * The two conditions are:
	1. Filtering of all ‘b’ and ‘ac’ should be in single pass
	2. No extra space allowed.

The approach is to use two index variables i and j. We move forward in string using ‘i’
and add characters using index j except ‘b’ and ‘ac’. The trick here is how to track ‘a’
before ‘c’. An interesting approach is to use a two state machine. The state is maintained to
TWO when previous character is ‘a’, otherwise state is ONE.
1) If state is ONE, then do NOT copy the current character to output if one of the following conditions is true
	…a) Current character is ‘b’ (We need to remove ‘b’)
	…b) Current character is ‘a’ (Next character may be ‘c’)
2) If state is TWO and current character is not ‘c’, we first need to make sure
that we copy the previous character ‘a’. Then we check the current character,
if current character is not ‘b’ and not ‘a’, then we copy it to output.

 *
 */

#include <iostream>

using namespace std;
#define ONE 1
#define TWO 2

// The main function that removes occurences of "a" and "bc" in input string
void stringFilter(char *str)
{
    // state is initially ONE (The previous character is not a)
    int state = ONE;

    // i and j are index variables, i is used to read next character of input
    // string, j is used for indexes of output string (modified input string)
    int j = 0;

    // Process all characters of input string one by one
    for (int i = 0; str[i] != '\0'; i++)
    {
        /* If state is ONE, then do NOT copy the current character to output if
           one of the following conditions is true
           ...a) Current character is 'b' (We need to remove 'b')
           ...b) Current character is 'a' (Next character may be 'c') */
        if (state == ONE && str[i] != 'a' && str[i] != 'b')
        {
            str[j] = str[i];
            j++;
        }

        // If state is TWO and current character is not 'c' (otherwise
        // we ignore both previous and current characters)
        if (state == TWO && str[i] != 'c')
        {
            // First copy the previous 'a'
            str[j] = 'a';
            j++;

            // Then copy the current character if it is not 'a' and 'b'
            if (str[i] != 'a' && str[i] != 'b')
            {
                str[j] = str[i];
                j++;
            }
        }

        // Change state according to current character
        state = (str[i] == 'a')? TWO: ONE;
    }

    // If last character was 'a', copy it to output
    if (state == TWO)
    {
        str[j] = 'a';
        j++;
    }

    // Set the string terminator
    str[j] = '\0';
}

/* Driver program to check above functions */
int main()
{
    char str1[] = "ad";
    stringFilter(str1);
    cout << str1 << endl;

    char str2[] = "acbac";
    stringFilter(str2);
    cout << str2 << endl;

    char str3[] = "aaac";
    stringFilter(str3);
    cout << str3 << endl;

    char str4[] = "react";
    stringFilter(str4);
    cout << str4 << endl;

    char str5[] = "aa";
    stringFilter(str5);
    cout << str5 << endl;

    char str6[] = "ababaac";
    stringFilter(str6);
    cout << str6 << endl;

    return 0;
}


