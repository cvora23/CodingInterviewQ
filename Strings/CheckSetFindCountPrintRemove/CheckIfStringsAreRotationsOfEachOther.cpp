/*
 * CheckIfStringsAreRotationsOfEachOther.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: cvora
 */

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/**
 * Algorithm:
 * 1: Concatenate the two given strings str1 and str2 into temp string.
 * 2: Find if str2 is substring of temp strin.
 * 3: If true: Then both the given strings str1 and str2 are rotations of each other or else not.
 */

/* Function checks if passed strings (str1 and str2)
   are rotations of each other */
int areRotations(char *str1, char *str2)
{
  int size1   = strlen(str1);
  int size2   = strlen(str2);
  char *temp;
  void *ptr;

  /* Check if sizes of two strings are same */
  if (size1 != size2)
     return 0;

  /* Create a temp string with value str1.str1 */
  temp   = (char *)malloc(sizeof(char)*(size1*2 + 1));
  temp[0] = '\0';
  strcat(temp, str1);
  strcat(temp, str1);

  /* Now check if str2 is a substring of temp */
  ptr = strstr(temp, str2);

  free(temp); // Free dynamically allocated memory

  /* strstr returns NULL if the second string is NOT a
    substring of first string */
  if (ptr != NULL)
    return 1;
  else
    return 0;
}

/* Driver program to test areRotations */
int main()
{
    char *str1 = "AACD";
    char *str2 = "ACDA";

    if (areRotations(str1, str2))
       printf("Strings are rotations of each other");
    else
       printf("Strings are not rotations of each other");

    getchar();
    return 0;
}

