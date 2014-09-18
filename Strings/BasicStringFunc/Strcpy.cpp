#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

void Strcpy(char *str,char *str1)
{    
     while(*str!='\0')
     {
          *str1++ = *str++;           
     }
     *str1 = '\0';
}

int main()
{
    char *str = new char[100];
    cout<<"Enter the string you wanna copy into other string"<<endl;
    gets(str);
    char *str1 = new char[strlen(str)+1];
    Strcpy(str,str1);
    cout<<str1<<endl;
    return 0;
}
