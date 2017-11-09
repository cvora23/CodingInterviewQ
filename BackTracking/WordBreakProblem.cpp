/*
 * WordBreakProblem.cpp
 *
 *  Created on: Nov 9, 2017
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
 * Word Break Problem using Backtracking
3.5
Given a valid sentence without any spaces between the words and a dictionary of valid English words,
find all possible ways to break the sentence in individual dictionary words.

Example

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input: "ilikesamsungmobile"
Output: i like sam sung mobile
        i like samsung mobile

Input: "ilikeicecreamandmango"
Output: i like ice cream and man go
        i like ice cream and mango
        i like icecream and man go
        i like icecream and mango

We start scanning the sentence from left. As we find a valid word, we need to check whether rest of the sentence can make valid words or not.
Because in some situations the first found word from left side can leave a remaining portion which is not further separable.
So in that case we should come back and leave the current found word and keep on searching for the next word.
And this process is recursive because to find out whether the right portion is separable or not, we need the same logic.
So we will use recursion and backtracking to solve this problem. To keep track of the found words we will use a stack.
Whenever the right portion of the string does not make valid words, we pop the top string from stack and continue finding.
 */

/* A utility function to check whether a word
  is present in dictionary or not.  An array of
  strings is used for dictionary.  Using array
  of strings for dictionary is definitely not
  a good idea. We have used for simplicity of
  the program*/
int dictionaryContains(string &word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

//prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);

// Prints all possible word breaks of given string
void wordBreak(string str)
{
    // last argument is prefix
    wordBreakUtil(str, str.size(), "");
}

// result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
    //Process all prefixes one by one
    for (int i=1; i<=n; i++)
    {
        //extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);

        // if dictionary contains this prefix, then we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for this if) and try next
        if (dictionaryContains(prefix))
        {
            // if no more elements are there, print it
            if (i == n)
            {
                // add this element to previous prefix
                result += prefix;
                // print result
                cout << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n-i), n-i,
                                result + prefix + " ");
        }
    }//end for
}//end function

int main()
{
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");

    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}
