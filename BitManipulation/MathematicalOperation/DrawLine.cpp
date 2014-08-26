/*
 * DrawLine.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

// Cracking the Code Interview 5.8 Solution

#include <iostream>
#include <stdint.h>

using namespace std;

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
		screen[(width/8)*y+(x1/8)] |= mask;
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

	uint8_t screen[32] = {0};
	drawLine(screen,16,3,11,0);

	for(int i=0;i<32;i++){
		cout<<hex<<(int)screen[i]<<endl;
	}

	return 0;
}

