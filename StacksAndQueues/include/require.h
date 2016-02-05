/*
 * require.h
 *
 *  Created on: Aug 14, 2014
 *      Author: cvora
 */
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Test for error conditions in programs
// Local "using namespace std" for old compilers

#ifndef REQUIRE_H_
#define REQUIRE_H_

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <math.h>
#include <iostream>

inline void require(bool requirement,
  const std::string& msg = "Requirement failed"){
  using namespace std;
  if (!requirement) {
    fputs(msg.c_str(), stderr);
    fputs("\n", stderr);
    exit(1);
  }
}

inline void requireArgs(int argc, int args,
  const std::string& msg =
    "Must use %d arguments") {
  using namespace std;
   if (argc != args + 1) {
     fprintf(stderr, msg.c_str(), args);
     fputs("\n", stderr);
     exit(1);
   }
}

inline void requireMinArgs(int argc, int minArgs,
  const std::string& msg =
    "Must use at least %d arguments") {
  using namespace std;
  if(argc < minArgs + 1) {
    fprintf(stderr, msg.c_str(), minArgs);
    fputs("\n", stderr);
    exit(1);
  }
}

inline void assure(std::ifstream& in,
  const std::string& filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "Could not open file %s\n",
      filename.c_str());
    exit(1);
  }
}

inline void assure(std::ofstream& out,
  const std::string& filename = "") {
  using namespace std;
  if(!out) {
    fprintf(stderr, "Could not open file %s\n",
      filename.c_str());
    exit(1);
  }
}

int getRand(int num=10){
	return rand()%num;
}

template <typename Type>
void printArray(Type array[],int size){

using namespace std;

	for(int i=0;i<size;i++){
		cout<<array[i]<< " ";
	}
	cout<<endl;
}

template <typename Type>
void printArray2(Type &array,int size){
using namespace std;

	for(int i=0;i<size;i++){
		cout<<array[i]<< " ";
	}
	cout<<endl;
}

template <typename Type>
void printArray3(Type &array,int size){
using namespace std;

	typename Type::iterator myItr = array.begin();
	while(myItr != array.end()){
		cout<<*myItr<< " ";
		myItr++;
	}
	cout<<endl;
}

#endif /* REQUIRE_H_ */
