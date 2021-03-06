/*
 * EuclerianPathAndCircuitUndirectedGraph.cpp
 *
 *  Created on: Oct 12, 2014
 *      Author: cvora
 */

/*
 * Eulerian Path is a path in graph that visits every edge exactly once.
 * Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
 *
 * Examples:
 *
 * 1: http://d2o58evtke57tz.cloudfront.net/wp-content/uploads/Euler1.png
 * 2: http://d2o58evtke57tz.cloudfront.net/wp-content/uploads/Euler2.png
 * 3: http://d2o58evtke57tz.cloudfront.net/wp-content/uploads/Euler3.png
 *
 * How to find whether a given graph is Eulerian or not?
 * The problem is same as following question. “Is it possible to draw a given
 * graph without lifting pencil from the paper and without tracing any of
 * the edges more than once”.
 *
 * A graph is called Eulerian if it has an Eulerian Cycle and called
 * Semi-Eulerian if it has an Eulerian Path.Fortunately, we can find whether a given graph
 * has a Eulerian Path or not in polynomial time. In fact, we can find it in O(V+E) time.
 *
 * Following are some interesting properties of undirected graphs with an Eulerian path and cycle.
 * We can use these properties to find whether a graph is Eulerian or not.
 *
 * Eulerian Cycle
 * ===============
 * An undirected graph has Eulerian cycle if following two conditions are true.
 * ….a) All vertices with non-zero degree are connected. We don’t care about vertices
 * with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
 * ….b) All vertices have even degree.
 *
 * Eulerian Path
 * =================
 * An undirected graph has Eulerian Path if following two conditions are true.
 * ….a) Same as condition (a) for Eulerian Cycle
 * ….b) If zero or two vertices have odd degree and all other vertices have even degree.
 * Note that only one vertex with odd degree is not possible in an undirected graph
 * (sum of all degrees is always even in an undirected graph)
 */

// A C++ program to check if a given graph is Eulerian or not
#include<iostream>
#include <list>
using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; } // To avoid memory leak

     // function to add an edge to graph
    void addEdge(int v, int w);

    // Method to check if this graph is Eulerian or not
    int isEulerian();

    // Method to check if all non-zero degree vertices are connected
    bool isConnected();

    // Function to do DFS starting from v. Used in isConnected();
    void DFSUtil(int v, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool Graph::isConnected()
{
    // Mark all the vertices as not visited
    bool visited[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;

    // Find a vertex with non-zero degree
    for (i = 0; i < V; i++)
        if (adj[i].size() != 0)
            break;

    // If there are no edges in the graph, return true
    if (i == V)
        return true;

    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);

    // Check if all non-zero degree vertices are visited
    for (i = 0; i < V; i++)
       if (visited[i] == false && adj[i].size() > 0)
            return false;

    return true;
}

/* The function returns one of the following values
   0 --> If grpah is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian()
{
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;

    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;

    // If count is more than 2, then graph is not Eulerian
    if (odd > 2)
        return 0;

    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd)? 1 : 2;
}

// Function to run test cases
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "Graph is not Eulerian\n";
    else if (res == 1)
        cout << "Graph has a Euler path\n";
    else
        cout << "Graph has a Euler cycle\n";
}

// Driver program to test above function
int main()
{
    // Let us create and test graphs shown in above figures
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);

    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);

    // Let us create a graph with all veritces
    // with zero degree
    Graph g5(3);
    test(g5);

    return 0;
}


