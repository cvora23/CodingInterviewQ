/*
 * SortStringAnagramically.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

#include <iostream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

void sortStringAnagramically(string array[],int size){

	std::map< string,list<string> >hash;
	std::map< string,list<string> >::iterator hashIterator;

	// group words by anagram
	for(int i=0;i<size;i++){
		string key = array[i];
		std::sort(key.begin(),key.end());
		hashIterator = hash.find(key);
		if(hashIterator == hash.end()){
			hash[key].push_back(array[i]);
		}else{
			hash[key].push_back(array[i]);
		}
	}

	// convert hash table to array
	int index = 0;
	for(hashIterator=hash.begin();hashIterator!=hash.end();++hashIterator){
		list<string> anagrams = hashIterator->second;
		unsigned int anagramSize = anagrams.size();
		for(unsigned int i=0;i<anagramSize;i++){
			array[index++] = anagrams.front();
			anagrams.pop_front();
		}
	}
}

int main(){

	cout<<"BEFORE SORTING ANAGRAMICALLY"<<endl;
	string array[9] = {"Hello","rat","Goodbye","tar","acre","art","hot","race","care"};
	for(int i=0;i<9;i++){
		cout<<array[i]<<endl;
	}

	sortStringAnagramically(array,9);
	cout<<endl<<"AFTER SORTING ANAGRAMICALLY"<<endl;
	for(int i=0;i<9;i++){
		cout<<array[i]<<endl;
	}

	return 0;

}


