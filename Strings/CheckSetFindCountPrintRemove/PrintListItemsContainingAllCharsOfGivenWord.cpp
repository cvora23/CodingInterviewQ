/*
 * PrintListItemsContainingAllCharsOfGivenWord.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: cvora
 */


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define NO_OF_CHARS 256

/*
 * 1) Initialize a binary map:
        map[256] = {0, 0, ..}
	2) Set values in map[] for the given word "sun"
        map['s'] = 1,  map['u'] = 1,  map['n'] = 1
	3) Store length of the word "sun":
        len = 3 for "sun"
	4) Pick words (or items)one by one from the list
    	a) set count = 0;
    	b) For each character ch of the picked word
         if(map['ch'] is set)
            increment count and unset map['ch']
    	c) If count becomes equal to len (3 for "sun"),
           print the currently picked word.
    	d) Set values in map[] for next list item
          map['s'] = 1,  map['u'] = 1,  map['n'] = 1
 *
 */

/* prints list items having all caharacters of word */
void print(char *list[], char *word, int list_size)
{
  /*Since calloc is used, map[] is initialized as 0 */
  int *map = (int *)calloc(sizeof(int), NO_OF_CHARS);
  int i, j, count, word_size;

  /*Set the values in map */
  for (i = 0; *(word+i); i++)
      map[*(word + i)] = 1;

  /* Get the length of given word */
  word_size = strlen(word);

  /* Check each item of list if has all characters
     of word*/
  for (i = 0; i < list_size; i++)
  {
    for(j = 0, count = 0; *(list[i] + j); j++)
    {
      if(map[*(list[i] + j)])
      {
         count++;

          /* unset the bit so that strings like
            sss not printed*/
         map[*(list[i] + j)] = 0;
      }
    }
    if(count == word_size)
      printf("%s\n ", list[i]);

    /*Re-Set the values in map for next item*/
    for (j = 0; *(word+j); j++)
      map[*(word + j)] = 1;
  }
}

/* Driver program to test to pront printDups*/
int main()
{
  char str[] = "sun";
  char *list[] = {"geeksforgeeks", "unsorted", "sunsday", "just", "sss" };
  print(list, str, 5);
  getchar();
  return 0;
}

