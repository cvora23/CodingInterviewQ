/*
 * utility.h
 *
 *  Created on: Aug 19, 2014
 *      Author: cvora
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>

using namespace std;

template <size_t size_x, size_t size_y>
void printMatrix(int (&anArray)[size_x][size_y])
{
    	for (int nRow = 0; nRow < size_x; nRow++){
    	    for (int nCol = 0; nCol < size_y; nCol++){
    	        cout << anArray[nRow][nCol]<< " ";
    	    }
	        cout << endl;
    	}
}



#endif /* UTILITY_H_ */
