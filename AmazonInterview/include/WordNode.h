/*
 * WordNode.h
 *
 *  Created on: Jan 27, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_WORDNODE_H_
#define INCLUDE_WORDNODE_H_


class WordNode{

public:
	WordNode(std::string word,int numSteps){
		this->word = word;
		this->numSteps = numSteps;
	}

	std::string getWord()const{
		return word;
	}

	int getNumSteps()const{
		return numSteps;
	}

private:
	std::string word;
	int numSteps;
};


#endif /* INCLUDE_WORDNODE_H_ */
