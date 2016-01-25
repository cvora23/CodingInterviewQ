/*
 * Test23.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: chintan
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool verify(const string& str) {
	stack<char> s;
	int i;

	for (i = 0; i < str.size(); i++) {
		if (str[i] == '<' || str[i] == '[' || str[i] == '(') {
			s.push(str[i]);
		} else if (str[i] == '>') {
			if (s.size() == 0 || s.top() != '<') return false;
			s.pop();
		} else if (str[i] == ']') {
			if (s.size() == 0 || s.top() != '[') return false;
			s.pop();
		} else if (str[i] == ')') {
			if (s.size() == 0 || s.top() != '(') return false;
			s.pop();
		}
	}
	if (s.size() > 0) return false;

	return true;
}

int main(){

	cout<<verify("<ad675+-fkmfd>")<<endl;
	cout<<verify("<[((kskfhdbh7)")<<endl;
	cout<<verify("[<<((shfs8))>>]")<<endl;
}

