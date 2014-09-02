/*
 * DeepVsShallowCopy.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: cvora
 */

#include <string.h>
#include <stddef.h>
#include <cstdlib>

using namespace std;

struct Test{
	char* ptr;
};

void shallow_copy(Test& src,Test& dest){
	dest.ptr = src.ptr;
}

void deep_copy(Test& src,Test& dest){
	dest.ptr = (char*)malloc(strlen(src.ptr) + 1);
	strcpy(dest.ptr,src.ptr);
}


int main(){

	return 0;
}

