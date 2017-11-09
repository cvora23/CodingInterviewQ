/*
 * MatchPatternAndStringWithoutRegEx.cpp
 *
 *  Created on: Nov 8, 2017
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
#include <unordered_map>

using namespace std;

/*
 * Match a pattern and String without using regular expressions
4.3
Given a string, find out if string follows a given pattern or not without using any regular expressions.

Examples:

Input:
string - GraphTreesGraph
pattern - aba
Output:
a->Graph
b->Trees

Input:
string - GraphGraphGraph
pattern - aaa
Output:
a->Graph

Input:
string - GeeksforGeeks
pattern - GfG
Output:
G->Geeks
f->for

Input:
string - GeeksforGeeks
pattern - GG
Output:
No solution exists
Recommended: Please try your approach on {IDE} first, before moving on to the solution.

We can solve this problem with the help of Backtracking. For each character in the pattern, if the character is not seen before,
we consider all possible sub-strings and recurse to see if it leads to the solution or not. We maintain a map that stores
sub-string mapped to a pattern character. If pattern character is seen before, we use the same sub-string present in the map.
If we found a solution, for each distinct character in the pattern, we print string mapped to it using our map.
 */

/*  Function to find out if string follows a given
    pattern or not

    str - given string
    n - length of given string
    i - current index in input string
    pat - given pattern
    m - length of given pattern
    j - current index in given pattern
    map - stores mapping between pattern and string */
bool patternMatchUtil(string str, int n, int i,
                    string pat, int m, int j,
                    unordered_map<char, string>& map)
{
    // If both string and pattern reach their end
    if (i == n && j == m)
        return true;

    // If either string or pattern reach their end
    if (i == n || j == m)
        return false;

    // read next character from the pattern
    char ch = pat[j];

    // if character is seen before
    if (map.find(ch)!= map.end())
    {
        string s = map[ch];
        int len = s.size();

        // consider next len characters of str
        string subStr = str.substr(i, len);

        // if next len characters of string str
        // don't match with s, return false
        if (subStr.compare(s))
            return false;

        // if it matches, recurse for remaining characters
        return patternMatchUtil(str, n, i + len, pat, m,
                                            j + 1, map);
    }

    // If character is seen for first time, try out all
    // remaining characters in the string
    for (int len = 1; len <= n - i; len++)
    {
        // consider substring that starts at position i
        // and spans len characters and add it to map
        map[ch] = str.substr(i, len);

        // see if it leads to the solution
        if (patternMatchUtil(str, n, i + len, pat, m,
                                          j + 1, map))
            return true;

        // if not, remove ch from the map
        map.erase(ch);
    }

    return false;
}

// A wrapper over patternMatchUtil()function
bool patternMatch(string str, string pat, int n, int m)
{
    if (n < m)
    return false;

    // create an empty hashmap
    unordered_map<char, string> map;

    // store result in a boolean variable res
    bool res = patternMatchUtil(str, n, 0, pat, m, 0, map);

    // if solution exists, print the mappings
    for (auto it = map.begin(); res && it != map.end(); it++)
        cout << it->first << "->" << it->second << endl;

    // return result
    return res;
}

// Driver code
int main()
{
    string str = "GeeksforGeeks", pat = "GfG";

    int n = str.size(), m = pat.size();

    if (!patternMatch(str, pat, n, m))
        cout << "No Solution exists";

    return 0;
}
