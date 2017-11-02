/*
 * RandomNode.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: chivora
 */

/* One node of a binary tree. The data element stored is a single
 * character.
 */
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<list>
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

using namespace std;

class TreeNode;

class TreeNode {
public:
	int data;
	TreeNode *left;
	TreeNode *right;
	int size;

	TreeNode(int d) {
		data = d;
		size = 1;
		left = NULL;
		right = NULL;
	}

	void insertInOrder(int d) {
		if (d <= data) {
			if (left == NULL) {
				left = new TreeNode(d);
			} else {
				left->insertInOrder(d);
			}
		} else {
			if (right == NULL) {
				right = new TreeNode(d);
			} else {
				right->insertInOrder(d);
			}
		}
		size++;
	}

	int getSize() {
		return size;
	}

	int getData(){
		 return data;
	 }

	TreeNode* find(int d) {
		if (d == data) {
			return this;
		} else if (d <= data) {
			return left != NULL ? left->find(d) : NULL;
		} else if (d > data) {
			return right != NULL ? right->find(d) : NULL;
		}
		return NULL;
	}

	TreeNode* getRandomNode() {
		int leftSize = left == NULL ? 0 : left->getSize();
		int index;
		/* generate secret number between 1 and 10: */
		index = rand() % size;
		if (index < leftSize) {
			return left->getRandomNode();
		} else if (index == leftSize) {
			return this;
		} else {
			return right->getRandomNode();
		}
	}

};

int main(){
	/* initialize random seed: */
	srand (time(NULL));
	TreeNode treeNode(97);
    int data [10] = {50, 20, 60, 10, 25,70, 5, 15, 65, 8};
    for(int i=0;i<10;i++)
    {
    	treeNode.insertInOrder(data[i]);
    }
    TreeNode* random = treeNode.getRandomNode();
    cout<<random->getData()<<endl;
    random = treeNode.getRandomNode();
    cout<<random->getData()<<endl;
    random = treeNode.getRandomNode();
    cout<<random->getData()<<endl;
    random = treeNode.getRandomNode();
    cout<<random->getData()<<endl;
    random = treeNode.getRandomNode();
    cout<<random->getData()<<endl;
    random = treeNode.getRandomNode();
    cout<<random->getData()<<endl;

	return 0;

}


