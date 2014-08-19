/*
 * StringCompressionRLE.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: cvora
 */


// Coding Interview questions Solution 1.5

#include <iostream>
#include <string.h>
#include <sstream>      // std::stringstream

using namespace std;

unsigned int countCompression(string str){

	std::stringstream ss;

	if(str.empty()){
		return 0;
	}

	char last = str.at(0);
	unsigned int size = 0;
	int count = 1;
	for(unsigned int i=1;i<str.length();i++){
		if(str.at(i) == last){
			count++;
		}else{
			last = str.at(i);
			ss<<count;
			size += 1 + ss.str().length();
			ss.str("");
			count = 1;
		}
	}
	ss<<count;
	size += 1 + ss.str().length();
	ss.str("");
	cout<<"string size before compression is :"<<str.length()<<endl;

	cout<<"string size after compression is :"<<size<<endl;
	return size;
}

int setChar(char array[],char c,int index,int count){
	array[index++] = c;

	std::stringstream ss;
	ss<<count;
	for(int i=0;i<ss.str().length();i++){
		array[index++] = ss.str().at(i);
	}
	return index;
}

string compressStringRLESol1(string str){
	unsigned int size = countCompression(str);
	if(size >= str.length()){
		return str;
	}
	string mystr;
	std::stringstream ss;
	char last = str.at(0);
	int count = 1;
	for(unsigned int i=1;i<str.length();i++){
		if(str.at(i) == last){
			count++;
		}else{
			mystr.push_back(last);
			ss<<count;
			mystr.append(ss.str());
			ss.str("");
			last = str.at(i);
			count = 1;
		}
	}
	mystr.push_back(last);
	ss<<count;
	mystr.append(ss.str());
	ss.str("");
	return mystr;
}

string compressStringRLESol2(string str){
	unsigned int size = countCompression(str);
	if(size >= str.length()){
		return str;
	}
	char *array= new char[size];
	int index = 0;
	char last = str.at(0);
	int count = 1;
	for(unsigned int i=1;i<str.length();i++){
		if(str.at(i) == last){
			count++;
		}else{
			index = setChar(array,last,index,count);
			last = str.at(i);
			count = 1;
		}
	}
	index = setChar(array,last,index,count);
	array[index] = '\0';
	string myStr;
	myStr.append(array);
	return myStr;
}

int main(){

	cout<<compressStringRLESol1("HelloBrother")<<endl;
	cout<<compressStringRLESol1("aaaaabbbbgdfgdf")<<endl;
	cout<<compressStringRLESol1("aaaaabbbbgd")<<endl;

	cout<<compressStringRLESol2("HelloBrother")<<endl;
	cout<<compressStringRLESol2("aaaaabbbbgdfgdf")<<endl;
	cout<<compressStringRLESol2("aaaaabbbbgd")<<endl;

	return 0;

}

