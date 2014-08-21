/*
 * Link.h
 *
 *  Created on: Aug 19, 2014
 *      Author: cvora
 */

#ifndef LIST_H_
#define LIST_H_

#include "Node.h"

class List{
private:
	Node* head;
public:
	List():head(NULL){

	}
	void Print();
	void Append(int data);
	void Delete(int data);
	void DeleteAll();
	Node* GetHead();
};


#endif /* LIST_H_ */
