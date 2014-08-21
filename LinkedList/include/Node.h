/*
 * Node.h
 *
 *  Created on: Aug 19, 2014
 *      Author: cvora
 */

#ifndef NODE_H_
#define NODE_H_

#include <stddef.h>

class Node {
private:
	Node* next;
	int data;
public:
	Node():next(NULL),data(-1){}
	void SetData(int data){
		this->data = data;
	}
	void SetNext(Node* next){
		this->next = next;
	}
	int Data(){
		return data;
	}
	Node* Next(){
		return next;
	}
	~Node(){}
};

#endif /* NODE_H_ */
