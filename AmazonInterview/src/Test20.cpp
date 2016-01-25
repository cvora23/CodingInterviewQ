/*
 * Test20.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: chintan
 */

#include <vector>
#include <queue>
#include <string>
#include <iostream>

/*
 * Input argument of a method is a list of char array. The method have to print
all the possible combination of input char(s)...For example if the input
argument has ['A','B','C','D'] the output should be
A,B,C,AB,AC,AD,BC,BD,CD,ABC,ABD,ACD,BCD,ABCD
 */

using namespace std;

void printCombination(vector<char> arr) {
	queue< pair<string, int> > q;
	string str;
	unsigned int i;

	str = "";
	for (i = 0; i < arr.size(); i++) {
		q.push(make_pair(str + arr[i], i));
	}

	while (q.size()) {
		str = q.front().first;
		i = q.front().second + 1;
		q.pop();
		for (; i < arr.size(); i++) {
			q.push(make_pair(str + arr[i], i));
		}
		cout << str;
		if (q.size()) cout << ",";
	}
	cout << "\n";
}


int main(){

	vector<char>input;
	input.push_back('A');
	input.push_back('B');
	input.push_back('C');
	input.push_back('D');

	printCombination(input);

	return 0;
}


