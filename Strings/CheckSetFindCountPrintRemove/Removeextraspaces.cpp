#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

void RemoveSpaces(char *str)
{
       char *str1 = new char[strlen(str)+1];
       int count = 0;
       int i=0;
       while(*str!=NULL)
       {       
                        
              if(*str == ' ')
              {
				  count++;
				  if(count==1)
				  {
					  str1[i] = *str;
					  i++;
				  }
				  str++;
              }
              else
              {   
                  
                  str1[i] = *str;
                  str++;
                  i++;
                  count = 0;
              }
              
       }
       str1[i] = '\0';
       cout<<str1<<endl;
}
int main()
{
    char *str = new char[100];
    cout<<"Enter the string from which you wanna remove the extra spaces"<<endl;
    gets(str);
    RemoveSpaces(str);
    return 0;
}
