/*
 * Test24.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: chintan
 */

/*
 * Find the largest substring palindrome in a given string.
	ex: input: abbac output: abba
 */
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int IsPalindromeConsideringSpace(std::string str,int start,int end)
{
	int flag = 0;
	int len = (end-start)+1;
    for(int i=0;i<len/2;i++)
    {
            if(str[start+i]==str[end-i])
            flag = 1;
            else
            {
                flag =0;
                break;
            }
    }
    return flag;
}

std::string largestSubStrPalindrome(std::string str){
unsigned int maxSubStrPalindrome= 0;
std::string largestSubStrPalindrome = "";
for(unsigned int i=0;i<str.length();i++){
	for(unsigned int j=i+1;j<str.length();j++){

		if(IsPalindromeConsideringSpace(str,i,j)){
			if((j-i) > maxSubStrPalindrome){
				cout<<"Palindrome string found starting i = "<<i<<" and ending at"
						"j = "<<j<<endl;
				maxSubStrPalindrome = j-i;
				largestSubStrPalindrome.clear();
				largestSubStrPalindrome = str.substr(i,j-i+1);
			}
		}
	}
}
return largestSubStrPalindrome;

}


int main(){

	std::cout<<largestSubStrPalindrome("abbac")<<std::endl;
	std::cout<<largestSubStrPalindrome("mahaara")<<std::endl;

	return 0;

}
