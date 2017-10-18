/*
 * LittleOrBigEndian.cpp
 *
 *  Created on: Aug 28, 2013
 *      Author: cvora
 */



#include <stdio.h>

/**
 * 	Little and big endian are two ways of storing multibyte data-types
 *  ( int, float, etc). In little endian machines, last byte of binary
 *  representation of the multibyte data-type is stored first.
 *  On the other hand, in big endian machines, first byte of binary representation
 *  of the multibyte data-type is stored first.
 *
 *  Suppose integer is stored as 4 bytes (For those who are using DOS based compilers such as C++ 3.0 , integer is 2 bytes)
 *  then a variable x with value 0x01234567 will be stored as following.
 *
 *  Big Endian
 *  ==============
 *  Address : 0x100 0x101 0x102 0x103
 *  Value   : 01     23    45     67
 *
 *  Little Endian
 *  ===============
 *  Address : 0x100 0x101 0x102 0x103
 *  Value   : 67     23    45     67
 *
 */
/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(unsigned char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

/*
 * In the below program, a character pointer c is pointing to an integer i.
 * Since size of character is 1 byte when the character pointer is
 * de-referenced it will contain only first byte of integer.
 * If machine is little endian then *c will be 1 (because last byte is stored first) and if machine is big endian then *c will be 0
 */
void bigOrLittleEndian()
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)
	   printf("Little endian");
   else
	   printf("Big endian");
}

/*Main function to call above function for 0x01234567*/
int main()
{
   int i = 0x01234567;
   show_mem_rep((unsigned char *)&i, sizeof(i));
   /*
    * When above program is run on little endian machine, gives “67 45 23 01″ as output ,
    * while if it is run on endian machine, gives “01 23 45 67″ as output.
    */
   bigOrLittleEndian();
   getchar();
   return 0;
}

