#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

void ReverseString(char *str,int start,int end)
{
     char *temp = new char[1];
     int j = 0;
    for(int i=start;i<(start+end)/2;i++)
    {
          temp[0] = str[i];
          str[i] = str[end-1-j];
          str[end-1-j] = temp[0];
          j++;
    }
}

int main()
{   
    char *str = new char;
    cout<<"Enter the string"<<endl;
    gets(str);
    ReverseString(str,0,strlen(str));
    //cout<<str<<endl;
    int start,end;
    start = 0;
    for(int i=0;i<=strlen(str);i++)
    {       
            
            if(str[i] == ' ' || str[i]=='\0')
            {         
 //                     cout<<start<<endl;
 //                     cout<<i<<endl;
                      ReverseString(str,start,i); 
                      start = i+1;
                      //cout<<str<<endl;
            }
    }
    cout<<str<<endl;
    return 0;
    
}



