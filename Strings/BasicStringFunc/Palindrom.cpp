#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

/*
 * C Program to Check if a Given String is Palindrome
Given a string, write a c function to check if it is palindrome or not.
A string is said to be palindrome if reverse of the string is same as string.
For example, “abba” is palindrome, but “abbc” is not palindrome.
 */

int IsPalindromeConsideringSpace(char *str)
{
	int flag = 0;
    int length = strlen(str);
    for(int i=0;i<length/2;i++)
    {
            if(str[i]==str[length-1-i])
            flag = 1;
            else
            {
                flag =0;
                break;
            }
    }
    return flag;
}

int IsPalindromeWithoutSpace(char *str)
{  
	char *newstr = new char[strlen(str)];
	int i=0;
	/**
	 * Removing Spaces
	 */
	while(*str!='\0')
	{
		if(*str==' ')
		str++;
		newstr[i] = *str;
		str++;
		i++;
	}
	newstr[i] = '\0';
	return IsPalindromeConsideringSpace(newstr);
}

int main()
{   
    char *str = new char;
    cout<<"Enter the string"<<endl;
    gets(str);
    int result;
    result = IsPalindromeWithoutSpace(str);
    if(result==0)
    cout<<"The given string is not a palindrome"<<endl;
    else
    cout<<"The given string is a palindrome"<<endl;
    return 0;
}
