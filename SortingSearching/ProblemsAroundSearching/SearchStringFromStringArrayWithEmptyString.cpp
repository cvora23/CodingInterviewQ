/*
 * SearchStringFromStringArrayWithEmptyString.cpp
 *
 *  Created on: Aug 28, 2014
 *      Author: cvora
 */

// Cracking the coding interview solution 11.8
/*
 * Given a sorted array of strings which interspersed with empty
 * strings, write a method to find location of given string
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Algo:
 *
 * If it weren't for the empty strings, we could simply use binary search.
 * We could compare the string to be found str, with the midpoint of the array
 * and go from there.
 * With empty string interspersed, we can implement a simple modification of binary
 * search. All we need to do is fix the comparison against mid, in case mid is an empty
 * string. We simply move mid to the closest non-empty string.
 */

int searchStringR(string strings[],string str,int first,int last){
	if(first > last)
		return -1; // Error
	// Move mid to the middle
	int mid = (last + first)/2;
	// if mid is empty, find closest non-empty string
	if(strings[mid].empty()){
		int left = mid - 1;
		int right = mid + 1;
		while(true){
			if(left < first && right > last){
				return -1;
			}else if(right <= last && !strings[right].empty()){
				mid = right;
				break;
			}else if(left >= first && !strings[left].empty()){
				mid = left;
				break;
			}
			right++;
			left--;
		}
	}

	// check for string, recurse if necessary
	if(str.compare(strings[mid])== 0){
		// found it !!
		return mid;
	}else if(strings[mid].compare(str) < 0){
		// search right
		return searchStringR(strings,str,mid+1,last);
	}else{
		// search left
		return searchStringR(strings,str,first,mid-1);
	}
}

int search(string strings[],int count,string str){
	if(strings == NULL || str == ""){
		return -1;
	}
	return searchStringR(strings,str,0,count-1);
}


int main(){

	string array[8] = {"apple","boy","cat","","dog","egg","fish","race"};
	cout<<search(array,8,"boy")<<endl;
	cout<<search(array,8,"")<<endl;
	cout<<search(array,8,"dracula")<<endl;

}

