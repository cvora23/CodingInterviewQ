/*
 * SortStringAnagramically.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: cvora
 */

// Cracking the coding interview solution 11.2
/*
 * Write a method to start an array of strings so that all anagrams are next to
 * each other.
 */

#include <iostream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

/**
 * Algo 1:
 *
 * 1: Problem asks us to group the strings in an array such that anagrams
 * appear next to each other. Note that no specific ordering of the words is
 * required, other than this.
 * 2: One way to do this just apply any standard sorting algo, like merge sort
 * or quick sort, and modify the comparator. This comparator will be used to
 * indicate that two strings are anagrams of each other are equivalent.
 * Easiest way to check if two words are anagrams is to count the occurences of
 * distinct characters in each string and return true if they match. Or,
 * we could just sort the string. After all, two words which are anagrams will
 * look the same once they're sorted.
 */

/**
 * Algo 2:
 *
 * 1: We don't need to fully sort the array. We only need to group the strings
 * in the array by anagram.
 * 2: We can do this by using a hash table which maps sorted version of a word to a list
 * of its anagrams. So for example, acre will map to the list {acre, race, care}.
 * Once we've grouped all the words into these lists by anagram, we can then put them
 * back into the arrays.
 */

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


