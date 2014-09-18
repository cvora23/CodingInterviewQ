/*
 * PrintReverseStringUsingRecursion.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: cvora
 */

# include <stdio.h>
// Coding Interview questions Solution 1.2

/* Function to print reverse of the passed string */
void reverse(char *str)
{
   if(*str)
   {
       reverse(str+1);
       printf("%c", *str);
   }
}

void reverseSol1(char* str){
	char* end = str;
	char temp;
	if(str){
		while(*end)// find end of string
			end++;
		--end; // set one char back, since last char is null

		// swap chars from start of string with end of the string, until pointers meet in the middle.
		while(str<end){
			temp = *str;
			*str++ = *end;
			*end-- = temp;
		}
	}
}


/* Driver program to test above function */
int main()
{
   char a[] = "Geeks for Geeks";
   reverse(a);
   getchar();
   return 0;
}

