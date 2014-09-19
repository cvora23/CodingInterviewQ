/*
 * RLE.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: cvora
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <iostream>
#include <string.h>
#include <sstream>      // std::stringstream

#define MAX_RLEN 50

using namespace std;

/* Returns the Run Length Encoded string for the
   source string src */
char *encode(char *src)
{
  int rLen;
  char count[MAX_RLEN];
  int len = strlen(src);

  /* If all characters in the source string are different,
    then size of destination string would be twice of input string.
    For example if the src is "abcd", then dest would be "a1b1c1d1"
    For other inputs, size would be less than twice.  */
  char *dest = (char *)malloc(sizeof(char)*(len*2 + 1));

  int i, j = 0, k;

  /* traverse the input string one by one */
  for(i = 0; i < len; i++)
  {

    /* Copy the first occurrence of the new character */
    dest[j++] = src[i];

    /* Count the number of occurrences of the new character */
    rLen = 1;
    while(i + 1 < len && src[i] == src[i+1])
    {
      rLen++;
      i++;
    }

    /* Store rLen in a character array count[] */
    sprintf(count, "%d", rLen);

    /* Copy the count[] to destination */
    for(k = 0; *(count+k); k++, j++)
    {
      dest[j] = count[k];
    }
  }

  /*terminate the destination string */
  dest[j] = '\0';
  return dest;
}

// Coding Interview questions Solution 1.5

unsigned int countCompression(string str){

	std::stringstream ss;

	if(str.empty()){
		return 0;
	}

	char last = str.at(0);
	unsigned int size = 0;
	int count = 1;
	for(unsigned int i=1;i<str.length();i++){
		if(str.at(i) == last){
			count++;
		}else{
			last = str.at(i);
			ss<<count;
			size += 1 + ss.str().length();
			ss.str("");
			count = 1;
		}
	}
	ss<<count;
	size += 1 + ss.str().length();
	ss.str("");
	cout<<"string size before compression is :"<<str.length()<<endl;

	cout<<"string size after compression is :"<<size<<endl;
	return size;
}

int setChar(char array[],char c,int index,int count){
	array[index++] = c;

	std::stringstream ss;
	ss<<count;
	for(int i=0;i<ss.str().length();i++){
		array[index++] = ss.str().at(i);
	}
	return index;
}

string compressStringRLESol1(string str){
	unsigned int size = countCompression(str);
	if(size >= str.length()){
		return str;
	}
	string mystr;
	std::stringstream ss;
	char last = str.at(0);
	int count = 1;
	for(unsigned int i=1;i<str.length();i++){
		if(str.at(i) == last){
			count++;
		}else{
			mystr.push_back(last);
			ss<<count;
			mystr.append(ss.str());
			ss.str("");
			last = str.at(i);
			count = 1;
		}
	}
	mystr.push_back(last);
	ss<<count;
	mystr.append(ss.str());
	ss.str("");
	return mystr;
}

string compressStringRLESol2(string str){
	unsigned int size = countCompression(str);
	if(size >= str.length()){
		return str;
	}
	char *array= new char[size];
	int index = 0;
	char last = str.at(0);
	int count = 1;
	for(unsigned int i=1;i<str.length();i++){
		if(str.at(i) == last){
			count++;
		}else{
			index = setChar(array,last,index,count);
			last = str.at(i);
			count = 1;
		}
	}
	index = setChar(array,last,index,count);
	array[index] = '\0';
	string myStr;
	myStr.append(array);
	delete array;
	return myStr;
}


/*driver program to test above function */
int main()
{
  char str[] = "geeksforgeeks";
  char *res = encode(str);
  printf("%s", res);
  getchar();
}



