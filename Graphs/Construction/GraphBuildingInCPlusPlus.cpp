/*
 * GraphBuildingInCPlusPlus.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: cvora
 */

#include<iostream>
#include <list>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void printGraph(); // Print adjacency list of the graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::printGraph(){
    int v;
    list<int>::iterator i;
    for (v = 0; v < V; ++v)
    {
    	cout<<"\n Adjacency list of vertex %d\n head "<<v;

    	for(i = adj[v].begin(); i != adj[v].end(); ++i){
    		cout<<"-> "<<*i;
    	}

    	cout<<endl;
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // print the adjacency list representation of the above graph
    g.printGraph();

    return 0;
}
