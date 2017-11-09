/*
 * PalindromePartition.cpp
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
 * Print all palindromic partitions of a string
4
Given a string s, partition s such that every string of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example :

Input  : s = "bcc"
Output : [["b", "c", "c"], ["b", "cc"]]

Input  : s = "geeks"
Output : [["g", "e", "e", "k", "s"],
          ["g", "ee", "k", "s"]]
Recommended: Please try your approach on {IDE} first, before moving on to the solution.

We have to list the all possible partitions so we will think in the direction of recursion.
When we are on index i, we incrementally check all substrings starting from i for being palindromic.
If found, we recursively solve the problem for the remaining string and add this in our solution.

Following is the solution-

We will maintain a 2-dimensional vector for storing all possible partitions and a temporary vector for storing the current partition,
new starting index of string to check partitions as we have already checked partitions before this index.
Now keep on iterating further on string and check if it is palindrome or not.
If it is a palindrome than add this string in current partitions vector. Recurse on this new string if it is not the end of the string.
After coming back again change the current partition vector to the old one as it might have changed in the recursive step.
If we reach the end of string while iterating than we have our partitions in our temporary vector so we will add it in results.
To check whether it’s a palindrome or not, iterate on string by taking two pointers. Initialize the first to start and other to end of string.
If both characters are same increase the first and decrease the last pointer and keep on iterating until first is less than last one.
 */

// Returns true if str is palindrome, else false
bool checkPalindrome(string str)
{
    int len = str.length();
    len--;
    for (int i=0; i<len; i++)
    {
        if (str[i] != str[len])
            return false;
        len--;
    }
    return true;
}

void printSolution(vector<vector<string> > partitions)
{
    for (int i = 0; i < partitions.size(); ++i)
    {
        for(int j = 0; j < partitions[i].size(); ++j)
            cout << partitions[i][j] << " ";
        cout << endl;
    }
    return;
}

// Goes through all indexes and recursively add remaining
// partitions if current string is palindrome.
void addStrings(vector<vector<string> > &v, string &s,vector<string> &temp, int index)
{
    int len = s.length();
    string str;
    vector<string> current = temp;
    if (index == 0)
        temp.clear();
    for (int i = index; i < len; ++i)
    {
        str = str + s[i];
        if (checkPalindrome(str))
        {
            temp.push_back(str);
            if (i+1 < len)
                addStrings(v,s,temp,i+1);
            else
                v.push_back(temp);
            temp = current;
        }
    }
    return;
}

// Generates all palindromic partitions of 's' and
// stores the result in 'v'.
void partition(string s, vector<vector<string> >&v)
{
    vector<string> temp;
    addStrings(v, s, temp, 0);
    printSolution(v);
    return;
}

// Driver code
int main()
{
    string s = "geeks";
    vector<vector<string> > partitions;
    partition(s, partitions);
    return 0;
}
