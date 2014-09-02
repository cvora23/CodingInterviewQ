/*
 * AlignedMalloc.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: cvora
 */

#include <cstdlib>

// Aligned malloc sol1 with problem for free becuause we need to free that extra
// (alignment -1) bytes which we allocated to make sure its divisible by alignment
void* aligned_malloc_sol1(size_t required_bytes,size_t alignment){
	int offset = alignment - 1;
	void* p = (void*)malloc(required_bytes+offset);
	void* q = (void*) (((size_t)(p) + offset) & ~(offset));
	return q;
}


void * aligned_malloc_sol2(size_t required_bytes,size_t alignment){
	void* p1 ; // original block
	void** p2; // aligned block
	int offset = alignment - 1 + sizeof(void*);
	if((p1 = (void*)malloc(required_bytes+offset)) == NULL){
		return NULL;
	}
	p2 = (void**)(((size_t)(p1) + offset) & ~(offset));
	p2[-1] = p1;
	return p2;
}

void aligned_free_sol2(void* p2){
	// for consistency, we use the same names as aligned_malloc_sol2
	void* p1 = ((void**)p2)[-1];
	free(p1);
}

int main(){

	return -1;

}
