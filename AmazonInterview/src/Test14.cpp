/*
 * Test14.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: chintan
 */

#include<iostream>
#include <list>
#include <stack>
#include "EmployeeRecordVertice.h"
using namespace std;

// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
    list<EmployeeRecordVertice>employeeRecords;
    // Pointer to an array containing adjacency listsList
    list<int> *adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<std::string> &Stack);

    // function to add an edge to graph
   void addEdge(int v, int w);

   int getUniqueIndexOfBoss(std::string reportsTo);
   std::string getFirstName(int index);
   std::string getLastName(int index);
public:
    Graph(list<EmployeeRecordVertice>employeeRecords);   // Constructor

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

Graph::Graph(list<EmployeeRecordVertice>employeeRecords)
{
    this->employeeRecords = employeeRecords;
    V = employeeRecords.size();
    adj = new list<int>[V];

    /*
     * Starting adding edges based on employee record list
     */
//    cout<<"Adding Edges"<<endl;

	int index = 0;
	int bossIndex = 0;
    for(list<EmployeeRecordVertice>::iterator it =employeeRecords.begin();
    		it != employeeRecords.end();it++){
    	bossIndex = getUniqueIndexOfBoss(it->getReportsTo());
//    	cout<<it->getFirstName()<<" index of "<<index<<" "<<it->getReportsTo()<<
//    			" With index of "<< bossIndex<<endl;
    	if(bossIndex != -1)
    		addEdge(getUniqueIndexOfBoss(it->getReportsTo()),index);
    	index++;
    }
}

int Graph::getUniqueIndexOfBoss(std::string reportsTo ){
	int index = -1;
	if(!reportsTo.empty()){
		index = 0;
	    for(list<EmployeeRecordVertice>::iterator it =employeeRecords.begin();
	    		it != employeeRecords.end();it++){
	    	if(it->getEmpId().compare(reportsTo) == 0){
	    		break;
	    	}
	    	index++;
	    }
	}
   return index;
}

std::string Graph::getFirstName(int index){
	int tempIndex = 0;
	std::string firstNameString = "";
    for(list<EmployeeRecordVertice>::iterator it =employeeRecords.begin();
    		it != employeeRecords.end();it++){
    	if(tempIndex == index){
    		firstNameString.assign(it->getFirstName());
    		break;
    	}
    	tempIndex++;
    }
   return firstNameString;
}

std::string Graph::getLastName(int index){
	int tempIndex = 0;
	std::string lastNameString = "";
    for(list<EmployeeRecordVertice>::iterator it =employeeRecords.begin();
    		it != employeeRecords.end();it++){
    	if(tempIndex == index){
    		lastNameString.assign(it->getLastName());
    		break;
    	}
    	tempIndex++;
    }
   return lastNameString;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<std::string> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(getFirstName(v) +" "+ getLastName(v));
}

// The function to do Topological Sort. It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<std::string> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++){
      if (visited[i] == false){
          topologicalSortUtil(i, visited, Stack);
      }
    }

    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " "<<endl;
        Stack.pop();
    }
}

int main(){

	list<EmployeeRecordVertice>employeeRecords;
	EmployeeRecordVertice a("Mc Grill","Mc","Grill","Karmon");
	EmployeeRecordVertice b("Karmon","Zech","Karmon","Joe");
	EmployeeRecordVertice c("Mithun","Try","Mithun","Joe");
	EmployeeRecordVertice d("Joe","Top","Joe","");
	EmployeeRecordVertice e("Zara","Aman","Zara","Mc Grill");
	EmployeeRecordVertice f("Fizzy","Dude","Fizzy","Mc Grill");
	employeeRecords.push_back(a);
	employeeRecords.push_back(b);
	employeeRecords.push_back(c);
	employeeRecords.push_back(d);
	employeeRecords.push_back(e);
	employeeRecords.push_back(f);

	Graph graph(employeeRecords);
	graph.topologicalSort();
	return 0;
}



