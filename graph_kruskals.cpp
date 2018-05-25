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

int comp(const void *a, const void *b){
	Edge *a1 = (Edge*) a;
	Edge *b1 = (Edge*) b;
	return (a1->weight > b1->weight);
}

int find(int parent[], int i){
	if (parent[i]==-1){
		return i;
	}
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y){
	int xset  = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}

void kruskalMST(Graph *graph){
	int v = graph->v;
	struct Edge result[v];

	int parent[v];
	for (int i=0;i<v;i++) parent[i] = -1;
	qsort(graph->edge, graph->e, sizeof(graph->edge[0]), comp);
	int e=0, i=0;
	while (e<v-1){
		Edge next_edge = graph->edge[i++];

		int src = next_edge.src;
		int dest = next_edge.dest;
		int x = find(parent, src);
		int y =  find(parent, dest);
		if (x==y){
			continue;
		}
		result[e++] = next_edge;
		Union(parent, src, dest);
	}

	for (int i=0;i<v-1;i++){
		cout<<result[i].src<<"--"<<result[i].dest<<" "<<result[i].weight<<endl;
	}
}



int main(int argc, char const *argv[])
{
	
	int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createNewGraph(V, E);
 
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 	
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    kruskalMST(graph);

	return 0;
}