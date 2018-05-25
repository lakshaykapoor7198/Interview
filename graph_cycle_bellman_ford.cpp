#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int src, dest, weight;
};

struct Graph{
	int v, e;
	Edge *edge;
};

Graph * createNewGraph(int v, int e){
	Graph *graph = (Graph *) malloc(sizeof(Graph));
	graph->v = v;
	graph->e = e;
	graph->edge = (Edge *)malloc(e*sizeof(Edge));
	return graph;
}


bool isNegCycleBellmanFord(Graph *graph, int src){
	int v = graph->v;
	int e = graph->e;
	int dis[v];
	for (int i=0;i<v;i++){
		dis[i]=INT_MAX;
	}
	dis[src]=0;

	for (int i=0;i<v;i++){
		for (int i=0;i<=e;i++){
			int src = graph->edge[i].src;
			int dest = graph->edge[i].dest;
			int weight = graph->edge[i].weight;
			if (dis[src]!=INT_MAX &&  dis[dest]> dis[src]+weight){
				dis[dest]= dis[src]+weight;
			}
		}
	}

	for (int i=0;i<=e;i++){
		int src = graph->edge[i].src;
		int dest = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dis[dest]> dis[src]+weight){
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	
	int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    Graph* graph = createNewGraph(V, E);
 
    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    cout<<isNegCycleBellmanFord(graph, 0)<<endl;
 
	return 0;
}