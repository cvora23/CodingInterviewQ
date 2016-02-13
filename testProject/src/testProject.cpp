//============================================================================
// Name        : testProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <list>

/*
 * A container used to print list elements for different test cases.
 */
template <typename Type>
void printContainer(Type &array,int size){
using namespace std;

	typename Type::iterator myItr = array.begin();
	while(myItr != array.end()){
		cout<<*myItr<< " ";
		myItr++;
	}
	cout<<endl;
}
/*
 * Algorithm:
 * 1: We first get the forward iterator and reverse iterator for the given list
 * 2: Then we iterate over half the length of the list with forward iterator moving forward
 *  from front of the list and reverse iterator moving backwards from end of list.
 * 3: While iterating over the elements we copy the elements into the output list.
 * 4: At end the output list will have shuffled list elements.
 *
 * Time Complexity is: 0(N) - actually O(N/2)
 * Space Complexity is: O(N)
 */

/*
 * Function shuffles the list and prints the shuffled list
 */
void shuffleList(std::list<int>ipList){

	//output list
	std::list<int> opList;
	// fwd and rev iterator for list
	std::list<int>::iterator fit;
	std::list<int>::reverse_iterator rit;
	//init
	fit=ipList.begin();
	rit=ipList.rbegin();

	for(unsigned int i=0;i<ipList.size()/2;i++,++fit,++rit){
		opList.push_back(*fit);
		opList.push_back(*rit);
	}
	//if there are odd number of elements in list
	// make sure to add the last middle element left
	if(ipList.size()%2 == 1){
		opList.push_back(*fit);
	}
	// printing the values.
	printContainer(opList,opList.size());

}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	char* p1 = (char*)"Hello";
	char* p2 = (char*)"World";

	//char* p3 = p1+p2;

	int arr[] = {0,1,2,3,4};

	cout<<arr<<endl;
	cout<<arr+1<<endl;
	// TEST1
	{
		std::list<int>ipList;
		ipList.push_back(10);
		ipList.push_back(11);
		ipList.push_back(12);
		ipList.push_back(13);
		ipList.push_back(14);
		ipList.push_back(15);
		ipList.push_back(16);
		ipList.push_back(17);
		ipList.push_back(18);
		ipList.push_back(19);
		shuffleList(ipList);
	}
	// TEST2
	{
		std::list<int>ipList;
		ipList.push_back(10);
		ipList.push_back(11);
		ipList.push_back(12);
		ipList.push_back(13);
		ipList.push_back(14);
		ipList.push_back(15);
		ipList.push_back(16);
		ipList.push_back(17);
		ipList.push_back(18);
		ipList.push_back(19);
		ipList.push_back(20);
		shuffleList(ipList);
	}
	return 0;
}
