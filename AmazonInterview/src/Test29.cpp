/*
 * Test29.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: chintan
 */
/*
 * 	In a string detect the smallest window length with highest number of distinct
	characters. For eg. A = “aabcbcdbca”, then ans would be 4 as of “dbca”
 */

#include <string>
#include <iostream>
#include <map>

using namespace std;

int smallestWinDistinctChars(string ipStr){

	unsigned int startIndex = 0;
	unsigned maxLen = 1;
	std::map<char,std::pair<unsigned int,unsigned int> >charTable;
	std::map<char,std::pair<unsigned int,unsigned int> >::iterator charTableItr;

	for(unsigned int i=0;i<ipStr.size();i++){
		//cout<<ipStr[i]<<endl;
		/*
		 * first time inserting the character
		 */
		charTableItr = charTable.find(ipStr[i]);
		if(charTableItr == charTable.end()){
			charTable.insert(std::pair<char,std::pair<unsigned int,unsigned int> >(
					ipStr[i],std::pair<unsigned int,unsigned int>(1,i)));
		}
		/*
		 * character was found again
		 */
		else{
//			cout<<"Character Found again"<<endl;
//			cout<<"startIndex = "<<startIndex<<endl;
			// update startIndex only if character found is inside the window
			if(charTableItr->second.second>=startIndex){
				startIndex = charTableItr->second.second+1;
			}
			charTableItr->second.second = i;
		}
		// update maxLen if necessary
		if((i-startIndex+1)>maxLen){

//			cout<<"StartIndex = "<<startIndex<<endl;
//			cout<<"EndIndex = "<<i<<endl;
//			cout<<"MaxLen = "<<maxLen<<endl;
			maxLen = (i-startIndex+1);
		}
	}
	cout<<"StartIndex = "<<startIndex<<endl;
	cout<<"EndIndex = "<<startIndex+maxLen-1<<endl;
	cout<<"MaxLen = "<<maxLen<<endl;
	return maxLen;
}


int main(){

	smallestWinDistinctChars("aabcdbcdbcae");
	smallestWinDistinctChars("aabcbcdbca");
	smallestWinDistinctChars("bcccf");
	smallestWinDistinctChars("aaaaa");

	return 0;
}


