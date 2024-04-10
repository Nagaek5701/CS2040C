#include "graph.h"
#include "shortest_path.h"
#include "heap.hpp"

Path shortestPath(const Graph& g, int source, int dest) {

	int numVertex = g.num_vertices();
	int infinity = -99999;
	int distance = 0;
	vector<int> path;
	Heap<GraphEdge> pQueue; //construct pQueue of graph edges
	int* shortestDist = new int[numVertex];
	int* ExtractedVerts = new int[numVertex];
	int* parentVerts = new int[numVertex]; //to keep track of path taken
	


	//set shortest distance for all vertices to infinity first:
	for (int v = 0; v < numVertex; v++) {
		shortestDist[v] = infinity; //initally all set to infinity
		ExtractedVerts[v] = false; //no vertices have been extracted yet
		parentVerts[v] = NULL;
	}
	//set shortest dist of starting vertex in pQueue = 0;
	shortestDist[source] = 0;
	parentVerts[source] = -5; // special parent index for source

	//Insert the source vertex into queue:
	pQueue.insert(GraphEdge(source, shortestDist[source]));

	int destDist = shortestDist[dest];


	//Start Algorithm:
	while (!pQueue.empty()) {
		GraphEdge currentNode = pQueue.extractMax(); // returns the node with the smallest dist from source.
		int currentVert = currentNode.dest(); // index of the current node
		ExtractedVerts[currentVert] = true; //mark as extracted
		int currentDist = -currentNode.weight(); //-ve of weight of the edge to the current node.

		if (currentVert == dest) {
			destDist = shortestDist[currentVert];
			break;
		}

		//get all the neighbouring nodes, update their dist and add to pqueue
		forward_list<GraphEdge> neighbours = g.edges_from(currentVert);

		forward_list<GraphEdge>::iterator node;
		for (node = neighbours.begin(); node != neighbours.end(); node++) {

			if (!ExtractedVerts[node->dest()] && shortestDist[currentVert] - node->weight() > shortestDist[node->dest()]) {
				shortestDist[node->dest()] = (shortestDist[currentVert] - node->weight()); //relaxing the edge
				pQueue.insert(GraphEdge(node->dest(), shortestDist[currentVert] - node->weight()));//add updated dist to queue
				parentVerts[node->dest()] = currentVert;
			}

		}
	}
	//working backwards from dest node:
	int tempIdx = dest;
	if (ExtractedVerts[dest] == true) {
		while (parentVerts[tempIdx] != -5) {
			path.insert(path.begin(), tempIdx);
			tempIdx = parentVerts[tempIdx]; //set current index to parent to trace back
		}
		path.insert(path.begin(), source); //adding the source vertex to the path;

	}
	else
		throw std::out_of_range("Path does not exist");
	

	return Path(-destDist, path);

}
