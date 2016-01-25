/*
 * ModifiedMaxHeap.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: chintan
 */

#include "ModifiedMaxHeap.h"
#include <iostream>

ModifiedMaxHeap::ModifiedMaxHeap(int max_size):MaxHeap(){
	this->max_size = max_size;
}

ModifiedMaxHeap::~ModifiedMaxHeap(){

}

void ModifiedMaxHeap::Insert(int newValue){
    int length = _vector.size();

	if(length <max_size){
	    _vector.push_back(newValue);
	    BubbleUp(length);
	}else if(newValue < GetMax()){
		DeleteMax(newValue);
	}
}

void ModifiedMaxHeap::DeleteMax(int newVal){
    int length = _vector.size();

    if(length == 0)
    {
        return;
    }

    _vector[0] = newVal;

    BubbleDown(0);

}

