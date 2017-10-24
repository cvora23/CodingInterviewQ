/*
 * BuildOrder.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: chivora
 */

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

/*
 * ALGORITHM
 * ==========
 * 1. Build a graph where each project is a node and its outgoing edges represent the projects that depend on it.
 * That is, if A has an edge to B (A -> B), it means B has a dependency on A and therefore A must be built before B.
 * Each node also tracks the number of incoming edges.
 * 2. Initialize a buildOrder array.Once we determine a project's build order, we add it to the array.
 * We also continue to iterate through the array, using a toBeProcessed pointer to pOint to the next node to be fully processed.
 * 3. Find all the nodes with zero incoming edges and add those to a buildOrder array. Set a toBeProcessed pointer to the beginning of the array.
 * Repeat until toBeProcessed is at the end ofthe buildOrder:
 * 1. Read node at toBeProcessed.If node is null,then all remaining nodes have a dependency and we have detected a cycle.
 * 2. For each child of node:
 *    » Decrement child. dependencies (the number of incoming edges).
 *    » If child. dependencies is zero, add child to end of buildOrder.
 * 3. Increment toBeProcessed.
 */

class Project{

private:
	list<Project*> children;
	map<string,Project*> projectMap;
	std::string name;
	int dependencies;
public:
	Project(string name = "DUMMY"){
		this->name = name;
		dependencies = 0;
	}

	void addNeighbor(Project* node){
		/*
		 * Add Neighbor if not present
		 */
		if(projectMap.find(node->getName()) == projectMap.end()){
			node->incrementDependencies();
			children.push_back(node);
			projectMap.insert ( std::pair<string,Project*>(node->getName(),node) );
		}
	}

	void incrementDependencies(){
		dependencies++;
	}

	void decrementDependencies(){
		dependencies--;
	}

	string getName(){
		return name;
	}

	list<Project*> getChildren(){
		return children;
	}

	int getNumberDependencies(){
		return dependencies;
	}
};

class Graph{

private:
	list<Project*> nodes;
	map<string,Project*>projectMap;


public:

	Project* getOrCreateNode(string Name="DUMMY")
	{
		/*
		 * If Project not present in map then insert it.
		 */
		if(projectMap.find(Name) == projectMap.end()){
			Project* node = new Project (Name);
			nodes.push_back(node);
			projectMap.insert(std::pair<string,Project*>(Name,node));
		}
		return projectMap.find(Name)->second;
	}


	void addEdge(string startName,string endName){
		Project *start = getOrCreateNode(startName);
		Project *end = getOrCreateNode(endName);
		start->addNeighbor(end);
	}

	list<Project*> getNodes(){
		return nodes;
	}

};

/*
 * Helper function to insert projects with zero dependencies into the order array,
 * starting at index offset
 */
int addNonDependent(vector<Project*> &order,list<Project*> projects,int offset){
	std::list<Project*>::iterator projectsItr;
	for(projectsItr = projects.begin();projectsItr != projects.end() ; projectsItr++){
		if((*projectsItr)->getNumberDependencies() == 0){
			order.push_back((*projectsItr));
			offset++;
		}
	}
	return offset;
}

/*
 * Return a list of projects a correct build order.
 */
vector<Project*> orderProjects(list<Project*> projects){

	vector<Project*> order;

	/*
	 * add "roots" to the build order first
	 */
	int endOfList = addNonDependent(order,projects,0);

	int toBeProcessed = 0;
	while(toBeProcessed < projects.size()){
		Project* current = order[toBeProcessed];
		/*
		 * we have a circular depenency since there are no remaining projects with 0 dependencies
		 */
		if(current == NULL){
			break;
		}
		/*
		 * Remove myself as dependency
		 */
		list<Project*> children = current->getChildren();
		std::list<Project*>::iterator childrenItr;
		for(childrenItr = children.begin();childrenItr != children.end() ; childrenItr++){
			(*childrenItr)->decrementDependencies();
		}

		/*
		 * Add children that have no one depending on them
		 */
		endOfList = addNonDependent(order,children,endOfList);
		toBeProcessed++;
	}

	return order;

}

/*
 * Build the graph, adding edge (a,b) if b is dependent on a. Assumes a pair is listed in "build order"
 * Pair (a,b) in dependencies indicates that b depends on a and a must built before b.
 */

Graph buildGraph(list<string> projects,pair<string,string>dependencies[],int dependencies_size){
	Graph graph;
    std::list<string>::iterator it;
	for (it=projects.begin(); it!=projects.end(); ++it){
		graph.getOrCreateNode(*it);
	}
	for (int i=0;i<dependencies_size;i++){
		graph.addEdge(dependencies[i].first,dependencies[i].second);
	}

	return graph;
}

/*
 * Find a correct build order.
 */
vector<Project*> findBuildOrder(list<string> projects,pair<string,string>dependencies[],int dependencies_size){
	Graph graph = buildGraph(projects,dependencies,dependencies_size);
	return orderProjects(graph.getNodes());
}

int main(){

	list<string>projects;
	projects.push_back("a");
	projects.push_back("b");
	projects.push_back("c");
	projects.push_back("d");
	projects.push_back("e");
	projects.push_back("f");

#define MAX_NUMBER 10
	std::pair <string, string> dependencies[MAX_NUMBER];
	dependencies[0].first = "a";
	dependencies[0].second = "d";
	dependencies[1].first = "f";
	dependencies[1].second = "b";
	dependencies[2].first = "b";
	dependencies[2].second = "d";
	dependencies[3].first = "f";
	dependencies[3].second = "a";
	dependencies[4].first = "d";
	dependencies[4].second = "c";

	vector<Project*> result =  findBuildOrder(projects,dependencies,MAX_NUMBER);

	for(int i=0;i<result.size();i++){
		cout<<result[i]->getName()<<endl;
	}

	return 0;

}
