/*
 * ModifiedMaxHeap.h
 *
 *  Created on: Jan 20, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_MODIFIEDMAXHEAP_H_
#define INCLUDE_MODIFIEDMAXHEAP_H_

#include "MaxHeap.h"

class ModifiedMaxHeap : public MaxHeap{

private:
	int max_size;

public:

	ModifiedMaxHeap(int max_size = 10);
	virtual ~ModifiedMaxHeap();

	void Insert(int newValue);
	void DeleteMax(int newVal = 0);
};


#endif /* INCLUDE_MODIFIEDMAXHEAP_H_ */
