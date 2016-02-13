#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*
 * To implement the C function ‘strtok’, one doesn’t need to allocate extra memory for the
 *  input string before modifying it, since the caller function is supposed to make copy of
 *   the input string and deallocate the original input string. The function only needs to
 *    define static variables to store the starting of the string.
 */

/**
 * ALGO:
 * Keep record of starting position of non-delimeter character in the string
 * For every position in the string, keep checking the entire delimeter array.
 * If you find the delimeter and its not the end of the string, using the starting location
 * of non-delimeter character, return string with added NULL character.
 */

char *Strtok(char *str,char*delim)
{    
    static int pos;
    static char *s;
    int start = pos;
    if(str!=NULL)
    	s = str;
    int j=0;

	//While not end of string
    while(s[pos]!='\0') 
    {
		j = 0;
		//Comparing of one of the delimiter matches the character in the string
		while(delim[j]!='\0')
		{
			//Pos point to the next location in the string that we have to read
			 if(s[pos]==delim[j])
			 {
				  //Replace the delimiter by \0 to break the string
				  s[pos] = '\0';
				  pos++;

				  //Checking for the case where there is no relevant string before the delimiter.
				  //start specifies the location from where we have to start reading the next character

				  if(s[start]!='\0')
				  {
					  cout<<"RETURNING FROM INSIDE"<<endl;
					  return &s[start];
				  }
				  // this case arises when there is delimeter after
				  // delimeter one-after another.
				  else
				  {
        			  // Move to the next string after the delimiter
					  start = pos;
					  // Decrementing as it will be incremented at the end of the while loop
					  pos--;
					  break;
				  }
			 }
			 j++;
		}
		pos++;
    }//End of Outer while

    s[pos] = '\0';
    if(s[start] == '\0')
    {
    	return NULL;
    }
    else
    {
    	cout<<"RETURNING FROM OUTSIDE"<<endl;
    	return &s[start];
    }
}

int main()
{
    char str[] = "- This, is a sample string";
    char *pch;
    cout<<str<<endl;
    pch = Strtok(str," ,.-");
  //  cout<<pch<<endl;
    while(pch!=NULL)
    {
		cout<<pch<<endl;
		pch = Strtok(NULL," ,.-");
    }
    cout<<str<<endl;
    return 0;
}
