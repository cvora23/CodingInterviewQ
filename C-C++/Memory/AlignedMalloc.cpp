/*
 * AlignedMalloc.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: cvora
 */

// Cracking the Coding Interview - Sol 13.9


#include <cstdlib>

/*
 * Typically, with malloc, we do not have control over where the memory is allocated within the heap.
 * We just get a pointer to a block of memory which could start at any memory address within the heap.
 * We need to work with these constraints by requesting enough memory that we can return a memory address
 * which is divisible by the desired value.
 * Suppose we are requesting a 100-byte chunk of memory, and we want it to start at a memory address that
 * is a multiple of 16. How much extra memory would we need to allocate to ensure that we can do so?
 * We would need to allocate an extra 15 bytes. With these 15 bytes, plus another 100 bytes right after that sequence,
 * we know that we would have a memory address divisible by 16 with space for 100 bytes.
 */


/*
 * Steps:
 * 1. We will use malloc routine provided by C to implement the functionality.
 * Allocate memory of size (bytes required + alignment – 1 + sizeof(void*)) using malloc.
 * alignment: malloc can give us any address and we need to find a multiple of alignment.
 * (Therefore, at maximum multiple of alignment, we will be alignment-1 bytes away from any location.)
 * sizeof(size_t): We are returning a modified memory pointer to user, which is different from the one that would be returned by malloc.
 * We also need to extra space to store the address given by malloc, so that we can free memory in
 * aligned_free by calling free routine provided by C.
 * 2. If it returns NULL, then aligned_malloc will fail and we return NULL.
 * 3. Else, find the aligned memory address which is a multiple of alignment (call this p2).
 * 4. Store the address returned by malloc (e.g., p1 is just size_t bytes ahead of p2), which will be required by aligned_free.
 * 5. Return p2.
 */
void * aligned_malloc(size_t required_bytes,size_t alignment){
	void* p1 ; // original block
	void** p2; // aligned block
	int offset = alignment - 1 + sizeof(void*);
	if((p1 = (void*)malloc(required_bytes+offset)) == NULL){
		return NULL;
	}
	/* round up to multiple of offset: add offset and then round down by masking */
	/* Eg: round up to multiple of 16: add 15 and then round down by masking */
	p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
	p2[-1] = p1;
	return p2;
}

void aligned_free(void* p2){
	// for consistency, we use the same names as aligned_malloc
	void* p1 = ((void**)p2)[-1];
	free(p1);
}

int main(int argc, char *argv[]){

	char **endptr;
	int *p = aligned_malloc (100, strtol(argv[1], endptr, 10));

	printf ("%s: %p\n", argv[1], p);
	aligned_free (p);

	return 0;

}
