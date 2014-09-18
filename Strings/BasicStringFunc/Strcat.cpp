#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

char* StrCat(char* str1,char* str2)
{
	int str1len = strlen(str1);
	for(unsigned int j=0;j<strlen(str2);j++)
	{
		str1[str1len+j] = str2[j];
	}
	str1[strlen(str1)+strlen(str2)] = '\0';
	return str1;
}

int main()
{   
    char *str1 = new char[100];
    cout<<"Enter the first string"<<endl;
    gets(str1);
    char *str2 = new char[100];
    cout<<"Enter the second string"<<endl;
    gets(str2);
    char* outStr = StrCat(str1,str2);
    cout<<str1<<endl;
    return 0;
}
