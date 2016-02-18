/*
 * Test18.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: chintan
 */
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "require.h"

/*
 *  How to find if a given expression is a valid arithmetic expression?
	Eg:(())()) - Invalid expression, (()()) - Valid expression
 *
 */

bool validateExpression(std::vector<std::string>expression){

	std::map<std::string,int>expTable;
	expTable.insert(std::make_pair("(",0));
	expTable.insert(std::make_pair(")",0));

	for(unsigned int i=0;i<expression.size();i++){

		if(expTable.find(expression[i]) != expTable.end()){
			expTable[expression[i]]++;
			if(expTable[")"] > expTable["("]){
				return false;
			}
		}else{
			//skip
		}
	}

	if(expTable[")"] != expTable["("]){
		return false;
	}
	return true;
}

int main(){

	{
		std::vector<std::string>input;
		std::string myStr[7] = {"(" ,"(" ,")" , ")", "(", ")", ")"};
		for(int i=0;i<7;i++){
			input.push_back(myStr[i]);
		}
		printArray2(input,input.size());

		std::cout<<validateExpression(input)<<std::endl;
	}

	{
		std::vector<std::string>input;

		std::string myStr[6] = {"(" ,"(" ,")" , "(", ")", ")"};
		for(int i=0;i<6;i++){
			input.push_back(myStr[i]);
		}
		printArray2(input,input.size());

		std::cout<<validateExpression(input)<<std::endl;
	}

	{
		std::vector<std::string>input;

		std::string myStr[6] = {"(" ,"(" ,")" , ")", ")", ")"};
		for(int i=0;i<6;i++){
			input.push_back(myStr[i]);
		}
		printArray2(input,input.size());

		std::cout<<validateExpression(input)<<std::endl;
	}

	return 0;

}



