/*
 * Test31.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: chintan
 */

#include <list>
#include <iostream>
#include "require.h"

using namespace std;

void reverseList(std::list<int>& ipList,unsigned int n){

	if(n >= ipList.size()){
		cout<<"n can't be larger than size of the list::: Error !!! "<<endl;
		return;
	}
	int startIndex = n-1;
	int endIndex = ipList.size()-n;

	if(startIndex>endIndex){
		int temp = endIndex;
		endIndex = startIndex;
		startIndex = temp;
	}

	std::list<int>::iterator frontItr,backItr;
	frontItr = ipList.begin();
	std::advance(frontItr,startIndex);
	backItr = ipList.begin();
	std::advance(backItr,endIndex);
//
//	cout<<"FontItr value = "<<*frontItr<<endl;
//	cout<<"BackItr value = "<<*backItr<<endl;

	// keep swapping elements from startIndex till endIndex
	for(int i=0;i<(endIndex-startIndex+1)/2;i++){
//		std::cout<<"Swapping elements"<<endl;
		int temp = *frontItr;
		*frontItr = *backItr;
		*backItr = temp;
		frontItr++;
		backItr--;
	}

}

int main(){

	std::list<int>ipList;
	ipList.push_back(1);
	ipList.push_back(2);
	ipList.push_back(3);
	ipList.push_back(4);
	ipList.push_back(5);
	int n = 2;
	printArray3(ipList,ipList.size());
	cout<<"N = "<<n<<endl;
	reverseList(ipList,n);
	printArray3(ipList,ipList.size());

	n = 1;
	cout<<"N = "<<n<<endl;
	reverseList(ipList,n);
	printArray3(ipList,ipList.size());


}


