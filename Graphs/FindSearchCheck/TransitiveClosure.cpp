/*
 * TransitiveClosure.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: cvora
 */

/*
 * Given a directed graph, find out if a vertex j is reachable from another vertex i for
 * all vertex pairs (i, j) in the given graph. Here reachable mean that there is a path
 * from vertex i to j. The reach-ability matrix is called transitive closure of a graph.
 * The graph is given in the form of adjacency matrix say ‘graph[V][V]‘ where graph[i][j] is
 * 1 if there is an edge from vertex i to vertex j or i is equal to j, otherwise graph[i][j] is 0.
 */

/*
 * Floyd Warshall Algorithm can be used, we can calculate the distance matrix dist[V][V] using Floyd Warshall,
 * if dist[i][j] is infinite, then j is not reachable from i, otherwise j is reachable and value of dist[i][j]
 * will be less than V.
 * Instead of directly using Floyd Warshall, we can optimize it in terms of space and time,
 * for this particular problem. Following are the optimizations:
 * 1) Instead of integer resultant matrix (dist[V][V] in floyd warshall), we can create a boolean
 * reach-ability matrix reach[V][V] (we save space). The value reach[i][j] will be 1 if j is
 * reachable from i, otherwise 0.
 * 2) Instead of using arithmetic operations, we can use logical operations. For arithmetic operation ‘+’,
 * logical and ‘&&’ is used, and for min, logical or ‘||’ is used. (We save time by a constant factor.
 * Time complexity is same though)
 *
 * https://www.youtube.com/watch?v=EMAoMMsA5Jg&list=PLtmtQ-7tmfUvbO1XKiqqXzpWOvrTev5_e
 */


// Program for transitive closure using Floyd Warshall Algorithm
#include<stdio.h>

// Number of vertices in the graph
#define V 4

// A function to print the solution matrix
void printSolution(int reach[][V]);

// Prints transitive closure of graph[][] using Floyd Warshall algorithm
void transitiveClosure(int graph[][V])
{
    /* reach[][] will be the output matrix that will finally have the shortest
      distances between every pair of vertices */
    int reach[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have reachability values for all
      pairs of vertices such that the reachability values consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on a path from i to j,
                // then make sure that the value of reach[i][j] is 1
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(reach);
}

/* A utility function to print solution */
void printSolution(int reach[][V])
{
    printf ("Following matrix is transitive closure of the given graph\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf ("%d ", reach[i][j]);
        printf("\n");
    }
}

// driver program to test above function
int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };

    // Print the solution
    transitiveClosure(graph);
    return 0;
}

/*
 * Output:
Following matrix is transitive closure of the given graph
1 1 1 1
0 1 1 1
0 0 1 1
0 0 0 1
Time Complexity: O(V^3) where V is number of vertices in the given graph.
 */

