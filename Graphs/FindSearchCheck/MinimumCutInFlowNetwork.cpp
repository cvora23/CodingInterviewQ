/*
 * MinimumCutInFlowNetwork.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: cvora
 */

/*
 * In a flow network, an s-t cut is a cut that requires the source ‘s’ and the sink ‘t’
 * to be in different subsets, and it consists of edges going from the source’s side to
 * the sink’s side. The capacity of an s-t cut is defined by the sum of capacity of each
 * edge in the cut-set. (Source: Wiki)
 * The problem discussed here is to find minimum capacity s-t cut of the given network.
 * Expected output is all edges of the minimum cut.
 * For example, in the following flow network,
 * example s-t cuts are {{0 ,1}, {0, 2}}, {{0, 2}, {1, 2}, {1, 3}}, etc.
 * The minimum s-t cut is {{1, 3}, {4, 3}, {4 5}} which has capacity as 12+7+4 = 23.
 *
 * http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/minCut.png
 *
 *
 * Minimum Cut and Maximum Flow
 * Like Maximum Bipartite Matching, this is another problem which can solved
 * using Ford-Fulkerson Algorithm. This is based on max-flow min-cut theorem.
 * The max-flow min-cut theorem states that in a flow network, the amount of
 * maximum flow is equal to capacity of the minimum cut. See CLRS book for proof of this theorem.
 * From Ford-Fulkerson, we get capacity of minimum cut.
 * How to print all edges that form the minimum cut? The idea is to use residual graph.
 * Following are steps to print all edges of minimum cut.
 * 1) Run Ford-Fulkerson algorithm and consider the final residual graph.
 * 2) Find the set of vertices that are reachable from source in the residual graph.
 * 3) All edges which are from a reachable vertex to non-reachable vertex are minimum cut edges.
 *    Print all such edges.
 */

// C++ program for finding minimum cut using Ford-Fulkerson
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

// Number of vertices in given graph
#define V 6

/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
int bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
void dfs(int rGraph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}

// Prints the minimum s-t cut
void minCut(int graph[V][V], int s, int t)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[V][V]; // rGraph[i][j] indicates residual capacity of edge i-j
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];  // This array is filled by BFS and to store path

    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }

    // Flow is maximum now, find vertices reachable from s
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);

    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (visited[i] && !visited[j] && graph[i][j])
              cout << i << " - " << j << endl;

    return;
}

// Driver program to test above functions
int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    minCut(graph, 0, 5);

    return 0;
}
