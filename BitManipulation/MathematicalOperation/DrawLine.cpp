/*
 * DrawLine.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

// Cracking the Code Interview 5.8 Solution

/*
 * 	A monochrome screen is stored as a single array of bytes,
 * 	allowing eight consecutive pixels to be stored in one byte.
 * 	The screen has width w,where w is divisible
	by8(that is,no byte will be split across rows).The height of the screen,of course,
	can be derived from the length of the array and the width.Implement a function
	drawHorizontalLine(byte[] screen,int width,int xl,int x2,int y)
	which draws a horizontal line from (x1,y) to (x2,y).
 */

#include <iostream>
#include <stdint.h>

using namespace std;

/*
 * 	A naive solution to the problem is straight forward: iterate in a for loop from xl to x2,
	setting each pixel along the way.But that's hardly any fun,is it?(Nor is it very efficient.)
	A better solution is to recognize that if x1 and x2 are far away from each other,several
	full bytes will be contained between them.These full bytes can be set one at a time by
	doing screen[byte_pos] = 0xFF.The residual start and end of the line can be set
	using masks
 */

// eg: width = 16, x1 = 3, x2 = 11, y = 0 (This are all pixel values)
void drawLine(uint8_t screen[],int width,int x1,int x2,int y){

	int start_offset = x1%8; // start_offset = 3
	int first_full_byte = x1/8; // first_full_byte = 0

	if(start_offset != 0){
		first_full_byte++; // first_full_byte = 1
	}

	int end_offset = x2%8; // end_offset = 3
	int last_full_byte = x2/8; // last_full_byte = 1

	if(end_offset != 7){
		last_full_byte--; // last_full_byte = 0
	}

	// Set full bytes
	for(int b = first_full_byte;b<=last_full_byte;b++){
		screen[(width/8)*y + b] = 0xFF;
	}

	// create masks for start and end of line
	uint8_t start_mask = (uint8_t) ((uint8_t)255 >> start_offset); // start_mask = 0001111
	uint8_t end_mask = (uint8_t)  ~((uint8_t)255 >> (end_offset + 1)); // end_mask = 11110000

	// Set start and end of line
	if((x1/8) == (x2/8)){ // x1 and x2 are in the same byte
		uint8_t mask = (uint8_t) (start_mask & end_mask);
		int byte_number = (width/8)*y + first_full_byte - 1;
		screen[byte_number] |= mask;
	}else{
		if(start_offset != 0){
			int byte_number = (width/8)*y + first_full_byte - 1;
			screen[byte_number] |= start_mask;
		}
		if(end_offset != 7){
			int byte_number = (width/8)*y + last_full_byte + 1;
			screen[byte_number] |= end_mask;
		}
	}
}

int main(){

	uint8_t screen[4] = {0};
	drawLine(screen,16,3,7,0);

	for(int i=0;i<4;i++){
		cout<<hex<<(int)screen[i]<<endl;
	}

	return 0;
}

