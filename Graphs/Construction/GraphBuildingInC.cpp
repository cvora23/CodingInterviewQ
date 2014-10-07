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

 */


