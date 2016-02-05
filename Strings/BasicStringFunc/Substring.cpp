#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int flag = 1;

void Substring(char *str1,char *str2)
{
     int length1 = strlen(str1);
     int length2 = strlen(str2);
     for(int i=0;i<length1;i++)
     {
		 for(int j=0;j<length2;j++)
		 {
			 if(str1[i+j]==str2[j])
			 flag = 0;
			 else
			 flag = 1;
		 }
		 if(flag == 0)
			 break;
     }
     if(flag == 0)
     cout<<"String "<<str2<<" found in String "<<str1<<endl;
     else
     cout<<"No substring found"<<endl;
}


int main()
{   
    char *str1 = new char[100];
    char *str2 = new char[100];
    cout<<"Enter the first string"<<endl;
    gets(str1);  
    cout<<"Enter the second string"<<endl;
    gets(str2);
    Substring(str1,str2);
    return 0;
}
