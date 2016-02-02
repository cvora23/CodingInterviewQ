/*
 * Example45.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: chintan
 */
// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

void permute2(string& str, int l, int r)
{
   int i;
   if (l == r)
	   cout<<str<<endl;
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(&str[l],&str[i]);
          permute2(str, l+1, r);
          swap(&str[l],&str[i]); //backtrack
       }
   }
}


/* Driver program to test above functions */
int main()
{
    char str[] = "AAA";
    int n = strlen(str);
    permute(str, 0, n-1);

    string str1 = "ABBA";
    permute2(str1, 0,str1.size()-1);


    return 0;
}

