/*
 * FleuryAlgoPrintingEulerianPath.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: cvora
 */


/*
 * Eulerian Path is a path in graph that visits every edge exactly once.
 * Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
 *
 * Following is Fleury’s Algorithm for printing Eulerian trail or cycle
 * (Source http://www.math.ku.edu/~jmartin/courses/math105-F11/Lectures/chapter5-part2.pdf).
 * 1. Make sure the graph has either 0 or 2 odd vertices.
 * 2. If there are 0 odd vertices, start anywhere. If there are 2 odd vertices, start at one of them.
 * 3. Follow edges one at a time. If you have a choice between a bridge and a non-bridge, always choose the non-bridge.
 * 4. Stop when you run out of edges.
 *
 * The idea is, “don’t burn bridges“ so that we can come back to a vertex and traverse remaining edges.
 *
 * Following is C++ implementation of above algorithm. In the following code, it is assumed
 * that the given graph has an Eulerian trail or Circuit. The main focus is to print an Eulerian trail or circuit.
 * We can use isEulerian() to first check whether there is an Eulerian Trail or Circuit in the given graph.
 * We first find the starting point which must be an odd vertex (if there are odd vertices) and store it
 * in variable ‘u’. If there are zero odd vertices, we start from vertex ’0′. We call printEulerUtil()
 * to print Euler tour starting with u. We traverse all adjacent vertices of u, if there is only one
 * adjacent vertex, we immediately consider it. If there are more than one adjacent vertices,
 * we consider an adjacent v only if edge u-v is not a bridge. How to find if a given is edge is bridge?
 * We count number of vertices reachable from u. We remove edge u-v and again count number of reachable
 * vertices from u. If number of reachable vertices are reduced, then edge u-v is a bridge.
 * To count reachable vertices, we can either use BFS or DFS, we have used DFS in the above code.
 * The function DFSCount(u) returns number of vertices reachable from u.
 * Once an edge is processed (included in Euler tour), we remove it from the graph.
 * To remove the edge, we replace the vertex entry with -1 in adjacency list.
 * Note that simply deleting the node may not work as the code is recursive and
 * a parent call may be in middle of adjacency list.
 */

// A C++ program print Eulerian Trail in a given Eulerian or Semi-Eulerian Graph
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;

// A class that represents an undirected graph
class Graph
{
  int V;    // No. of vertices
  list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
  Graph(int V)  { this->V = V;  adj = new list<int>[V];  }
  ~Graph()      { delete [] adj;  }

  // functions to add and remove edge
  void addEdge(int u, int v) {  adj[u].push_back(v); adj[v].push_back(u); }
  void rmvEdge(int u, int v);

  // Methods to print Eulerian tour
  void printEulerTour();
  void printEulerUtil(int s);

  // This function returns count of vertices reachable from v. It does DFS
  int DFSCount(int v, bool visited[]);

  // Utility function to check if edge u-v is a valid next edge in
  // Eulerian trail or circuit
  bool isValidNextEdge(int u, int v);
};

/* The main function that print Eulerian Trail. It first finds an odd
   degree vertex (if there is any) and then calls printEulerUtil()
   to print the path */
void Graph::printEulerTour()
{
  // Find a vertex with odd degree
  int u = 0;
  for (int i = 0; i < V; i++)
      if (adj[i].size() & 1)
        {   u = i; break;  }

  // Print tour starting from oddv
  printEulerUtil(u);
  cout << endl;
}

// Print Euler tour starting from vertex u
void Graph::printEulerUtil(int u)
{
  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
  {
      int v = *i;

      // If edge u-v is not removed and it's a a valid next edge
      if (v != -1 && isValidNextEdge(u, v))
      {
          cout << u << "-" << v << "  ";
          rmvEdge(u, v);
          printEulerUtil(v);
      }
  }
}

// The function to check if edge u-v can be considered as next edge in
// Euler Tout
bool Graph::isValidNextEdge(int u, int v)
{
  // The edge u-v is valid in one of the following two cases:

  // 1) If v is the only adjacent vertex of u
  int count = 0;  // To store count of adjacent vertices
  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
     if (*i != -1)
        count++;
  if (count == 1)
    return true;


  // 2) If there are multiple adjacents, then u-v is not a bridge
  // Do following steps to check if u-v is a bridge

  // 2.a) count of vertices reachable from u
  bool visited[V];
  memset(visited, false, V);
  int count1 = DFSCount(u, visited);

  // 2.b) Remove edge (u, v) and after removing the edge, count
  // vertices reachable from u
  rmvEdge(u, v);
  memset(visited, false, V);
  int count2 = DFSCount(u, visited);

  // 2.c) Add the edge back to the graph
  addEdge(u, v);

  // 2.d) If count1 is greater, then edge (u, v) is a bridge
  return (count1 > count2)? false: true;
}

// This function removes edge u-v from graph.  It removes the edge by
// replacing adjcent vertex value with -1.
void Graph::rmvEdge(int u, int v)
{
  // Find v in adjacency list of u and replace it with -1
  list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
  *iv = -1;

  // Find u in adjacency list of v and replace it with -1
  list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
  *iu = -1;
}

// A DFS based function to count reachable vertices from v
int Graph::DFSCount(int v, bool visited[])
{
  // Mark the current node as visited
  visited[v] = true;
  int count = 1;

  // Recur for all vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (*i != -1 && !visited[*i])
          count += DFSCount(*i, visited);

  return count;
}

// Driver program to test above function
int main()
{
  // Let us first create and test graphs shown in above figure
  Graph g1(4);
  g1.addEdge(0, 1);
  g1.addEdge(0, 2);
  g1.addEdge(1, 2);
  g1.addEdge(2, 3);
  g1.printEulerTour();

  Graph g2(3);
  g2.addEdge(0, 1);
  g2.addEdge(1, 2);
  g2.addEdge(2, 0);
  g2.printEulerTour();

  Graph g3(5);
  g3.addEdge(1, 0);
  g3.addEdge(0, 2);
  g3.addEdge(2, 1);
  g3.addEdge(0, 3);
  g3.addEdge(3, 4);
  g3.addEdge(3, 2);
  g3.addEdge(3, 1);
  g3.addEdge(2, 4);
  g3.printEulerTour();

  return 0;
}

