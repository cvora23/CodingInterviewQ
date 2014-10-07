/*
 * GraphBuildingInC.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: cvora
 */

/*
 * Graph is a data structure that consists of following two components:
	1. A finite set of vertices also called as nodes.
	2. A finite set of ordered pair of the form (u, v) called as edge.
	The pair is ordered because (u, v) is not same as (v, u) in case of directed graph(di-graph).
	The pair of form (u, v) indicates that there is an edge from vertex u to vertex v.
	The edges may contain weight/value/cost.

	Graphs are used to represent many real life applications: Graphs are used to represent networks.
	The networks may include paths in a city or telephone network or circuit network.
	Graphs are also used in social networks like linkedIn, facebook. For example, in
	facebook, each person is represented with a vertex(or node). Each node is a structure
	and contains information like person id, name, gender and locale. This can be easily
	viewed by http://graph.facebook.com/barnwal.aashish where barnwal.aashish is the profile name.

	Following is an example undirected graph with 5 vertices.

	0 ------- 1
	|		/ |  \
	|	 /	  |   2
	| /       |  /
	4---------3

	Following two are the most commonly used representations of graph.
	1. Adjacency Matrix
	2. Adjacency List
	There are other representations also like, Incidence Matrix and Incidence List.
	The choice of the graph representation is situation specific. It totally depends
	on the type of operations to be performed and ease of use.

	a) Adjacency Matrix:
	=================
	Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph.
	Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from
	vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric.
	Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w,
	then there is an edge from vertex i to vertex j with weight w.

	The adjacency matrix for the above example graph is:
		  	 0  1  2  3  4

		0	[0, 1, 0, 0, 1],
        1	[1, 0, 0, 1, 1],
        2	[0, 1, 0, 1, 0],
        3	[0, 1, 1, 0, 1],
        4	[1, 1, 0, 1, 0]


        Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time.
        Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1).

		Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges),
		it consumes the same space. Adding a vertex is O(V^2) time.

	a) Adjacency List:
	=====================
	An array of linked lists is used. Size of the array is equal to number of vertices.
	Let the array be array[]. An entry array[i] represents the linked list of vertices
	adjacent to the ith vertex. This representation can also be used to represent a weighted graph.
	The weights of edges can be stored in nodes of linked lists. Following is adjacency list
	representation of the above graph.

	[0]->1->4->NULL
	[1]->0->4->2->3->NULL
	[2]->1->3->NULL
	[3]->1->4->2->NULL
	[4]->3->0->1->NULL

	Pros: Saves space O(|V|+|E|) . In the worst case, there can be C(V, 2) number of edges in
	a graph thus consuming O(V^2) space. Adding a vertex is easier.

	Cons: Queries like whether there is an edge from vertex u to vertex v are not
	efficient and can be done O(V).

 */

// A C Program to demonstrate adjacency list representation of graphs

#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}

