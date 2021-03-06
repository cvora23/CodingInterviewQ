/*
 * DepthFirstTraversal.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: cvora
 */

/*
 * Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree.
 * The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again.
 * To avoid processing a node more than once, we use a boolean visited array.
 * For example, in the following graph, we start traversal from vertex 2.
 * When we come to vertex 0, we look for all adjacent vertices of it. 2 is also an adjacent vertex of 0.
 * If we don’t mark visited vertices, then 2 will be processed again and it will become a non-terminating process.
 * Depth First Traversal of the following graph is 2, 0, 1, 3
 *
 *  0 --------------> 1
 *    ^            /
 *  | |          /
 *  | |		   /
 *  | |      /
 *  | |    /
 *  v |  /
 *     <
 *  2 --------------->3@
 */

/*
 * Following is C++ implementation of simple Depth First Traversal. The implementation uses adjacency list
 * representation of graphs. STL‘s list container is used to store lists of adjacent nodes.
 */

#include<iostream>
#include<list>
#include<stack>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtilIterative(int v, bool visited[]);  // A Iterative function used by DFS
    void DFSUtilRecursive(int v, bool visited[]);  // A Iterative function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int s,bool recursive = true);    // DFS traversal of the vertices reachable from s
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

void Graph::DFSUtilRecursive(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
        	DFSUtilRecursive(*i, visited);
}

void Graph::DFSUtilIterative(int s,bool visited[]){
    stack <int> S;
    S.push(s);
    int u;
    bool allVisited = true;

    while(!S.empty())
    {
    	allVisited = true;
    	u = S.top();
    	if(!visited[u])
    	{
        	cout<<u<<" ";
        	visited[u] = true;
    	}

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            if(!visited[*i])
            {
            	S.push(*i);
            	allVisited = false;
            	break;
            }
        }

        if(allVisited == true)
        {
        	S.pop();
        	allVisited = false;
        }
    }

}


// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v,bool recursive)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    if(recursive){
    	cout<<endl<<"calling the recursive DFS helper utility. So no Stack required "<<endl;
        // Call the recursive helper function to print DFS traversal
        DFSUtilRecursive(v, visited);
    }else{
    	cout<<endl<<"calling the iterative DFS helper utility. So Stack required "<<endl;
        for(int i = 0; i < V; i++)
            visited[i] = false;
        // Call the iterative helper function to print DFS traversal
    	DFSUtilIterative(v, visited);
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

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2,true);
    g.DFS(2,false);

    return 0;
}

