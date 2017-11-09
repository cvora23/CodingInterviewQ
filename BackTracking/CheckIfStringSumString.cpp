/*
 * CheckIfStringSumString.cpp
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
 * Check if a given string is sum-string

Given a string of digits, determine whether it is a ‘sum-string’. A string S is called a sum-string if a rightmost substring
can be written as sum of two substrings before it and same is recursively true for substrings before it.

Examples :

“12243660” is a sum string.
Explanation : 24 + 36 = 60, 12 + 24 = 36

“1111112223” is a sum string.
Explanation: 111+112 = 223, 1+111 = 112

“2368” is not a sum string
In general a string S is called sum-string if it satisfies the following properties:

sub-string(i, x) + sub-string(x+1, j) = sub-string(j+1, l)

AND

sub-string(x+1, j) + sub-string(j+1, l) = sub-string(l+1, m)

AND so on till end.


From the examples, we can see that our decision depends on first two chosen numbers.
So we choose all possible first two number for given string. Then for every chosen two numbers we check whether it
is sum-string or not? So the approach is very simple. We generate all possible first two numbers using two substrings
s1 and s2 using two loops. then we check whether it is possible to make number s3 = (s1 + s2) or not.
If we can make s3 then we recursively check for s2 + s3 so on.

 *
 */

// this is function for finding sum of two
// numbers as string
string string_sum(string str1, string str2)
{
    if (str1.size() < str2.size())
       swap(str1, str2);

    int m = str1.size();
    int n = str2.size();
    string ans = "";

    // sum the str2 with str1
    int carry = 0;
    for (int i = 0; i < n; i++) {

        // Sum of current digits
        int ds = ((str1[m - 1 - i] - '0') +
                  (str2[n - 1 - i] - '0') +
                  carry) % 10;

        carry = ((str1[m - 1 - i] - '0') +
                 (str2[n - 1 - i] - '0') +
                 carry) / 10;

        ans = char(ds + '0') + ans;
    }

    for (int i = n; i < m; i++) {
        int ds = (str1[m - 1 - i] - '0' +
                  carry) % 10;
        carry = (str1[m - 1 - i] - '0' +
                 carry) / 10;
        ans = char(ds + '0') + ans;
    }

    if (carry)
        ans = char(carry + '0') + ans;
    return ans;
}

// Returns true of two substrings of ginven
// lengths of str[beg..] can cause a positive
// result.
bool checkSumStrUtil(string str, int beg,
                     int len1, int len2)
{

    // Finding two substrings of given lengths
    // and their sum
    string s1 = str.substr(beg, len1);
    string s2 = str.substr(beg + len1, len2);
    string s3 = string_sum(s1, s2);

    int s3_len = s3.size();

    // if number of digits s3 is greater then
    // the available string size
    if (s3_len > str.size() - len1 - len2 - beg)
        return false;

    // we got s3 as next number in main string
    if (s3 == str.substr(beg + len1 + len2, s3_len)) {

        // if we reach at the end of the string
        if (beg + len1 + len2 + s3_len == str.size())
            return true;

        // otherwise call recursively for n2, s3
        return checkSumStrUtil(str, beg + len1, len2,
                                              s3_len);
    }

    // we do not get s3 in main string
    return false;
}

// Returns true if str is sum string, else false.
bool isSumStr(string str)
{
    int n = str.size();

    // choosing first two numbers and checking
    // whether it is sum-string or not.
    for (int i = 1; i < n; i++)
        for (int j = 1; i + j < n; j++)
            if (checkSumStrUtil(str, 0, i, j))
                return true;

    return false;
}

// Driver code
int main()
{
    cout << isSumStr("1212243660") << endl;
    cout << isSumStr("123456787");
    return 0;
}
